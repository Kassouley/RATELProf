-- preprocess.lua
-- Structure for data preprocessing

local msgpack           = ratelprof.msgpack
local msgpack_encoder   = msgpack.encoder
local encode_ext_string = msgpack.encode.encode_ext_string
local encode_table      = msgpack.encode.encode_table

local preprocess = {}

local function compute_depth (raw_data, group, event, event_id)
    if event == nil then
        return -1
    end
    local depth = 1 + compute_depth (raw_data, group, raw_data[event.corr_id], event.corr_id)
    return depth
end


local kernel_name_cache = {}
local function get_kernel_name(name, opt)
    local cached_name = kernel_name_cache[name]
    if cached_name then return cached_name end
    cached_name = ratelprof.utils.get_kernel_name(name, opt.trunc, opt.mangled) or "N/A"
    kernel_name_cache[name] = cached_name
    return cached_name
end


local function get_last_label(domain_id)
    local last_label = "N/A"
    if ratelprof.consts._ENV.DOMAIN_KERNEL     == domain_id or
       ratelprof.consts._ENV.DOMAIN_BARRIEROR  == domain_id or
       ratelprof.consts._ENV.DOMAIN_BARRIERAND == domain_id then
        last_label = '"Queue ID"'
    elseif ratelprof.consts._ENV.DOMAIN_COPY == domain_id then
        last_label = '"SDMA ID"'
    else
        last_label = "TID"
    end
    return last_label
end



local function get_event_data(data, event, domain_id, opt)
    local event_content  = "N/A"
    local first_value    = nil
    local key            = nil
    local args           = {}
    if ratelprof.consts._ENV.DOMAIN_KERNEL == domain_id then
        event_content  = get_kernel_name(event.args.kernel_name, opt)

        first_value               = data:get_gpu_id(event.args.gpu_id)
        key                       = event.args.queue_id
        args.dispatch_time        = event.args.dispatch_time
        args.wrg                  = event.args.wrg
        args.grd                  = event.args.grd
        args.private_segment_size = event.args.private_segment_size
        args.group_segment_size   = event.args.group_segment_size
        args.kernel_object        = event.args.kernel_object
        args.kernarg_address      = event.args.kernarg_address
        args.sig                  = event.sig

    elseif ratelprof.consts._ENV.DOMAIN_BARRIEROR == domain_id then
        event_content  = "Barrier OR"

        first_value         = data:get_gpu_id(event.args.gpu_id)
        key                 = event.args.queue_id
        args.dispatch_time  = event.args.dispatch_time
        args.dep_signal     = event.args.dep_signal
        args.sig            = event.sig

    elseif ratelprof.consts._ENV.DOMAIN_BARRIERAND == domain_id then
        event_content  = "Barrier AND"

        first_value         = data:get_gpu_id(event.args.gpu_id)
        key                 = event.args.queue_id
        args.dispatch_time  = event.args.dispatch_time
        args.dep_signal     = event.args.dep_signal
        args.sig            = event.sig

    elseif ratelprof.consts._ENV.DOMAIN_COPY == domain_id then
        event_content   = ratelprof.utils.get_copy_name(event.args.src_type, event.args.dst_type)

        local src_agent = event.args.src_agent
        local dst_agent = event.args.dst_agent
        local src_node  = data:get_gpu_id(src_agent)
        local dst_node  = data:get_gpu_id(dst_agent)
        first_value     = data:node_is_gpu(src_node) and src_node or dst_node
        key = event.args.engine_id

        args.src = ratelprof.utils.get_copy_name_from_kind(event.args.src_type) ..
            " Node ID. "..src_node.." ("..src_agent..")"
        args.dst = ratelprof.utils.get_copy_name_from_kind(event.args.dst_type) ..
            " Node ID. "..dst_node.." ("..dst_agent..")"
        args.size       = event.args.size
        args.sig        = event.sig

    else
        event_content   = event.name
        first_value     = event.pid
        key             = event.tid
        args.args       = event.args
    end
    return { event_content = event_content, args = args, first_value = first_value, key = key }
end


local function encode_event_item(buf, event_content, event, args, depth, traces_data)

    if depth > 0 then
        buf:encode_map(8)
    else
        buf:encode_map(7)
    end

    encode_ext_string(buf, "content")
    encode_ext_string(buf, event_content)

    encode_ext_string(buf, "id")
    buf:encode_uint(event.id)

    encode_ext_string(buf, "start")
    buf:encode_uint(event.start)

    if depth > 0 then
        encode_ext_string(buf, "subgroup")
        buf:encode_uint(depth)
    end

    encode_ext_string(buf, "dur")
    buf:encode_uint(event.dur)

    encode_ext_string(buf, "cid")
    buf:encode_uint(event.corr_id)

    encode_ext_string(buf, "loc")
    local entry_point = traces_data:find_entry_point(event)
    encode_ext_string(buf, traces_data:get_location_str(entry_point))

    encode_ext_string(buf, "args")
    encode_table(buf, args)
end


function preprocess.start(traces_data, opt)
    local results = {}

    traces_data:for_each_domain(function(domain_name, domain_id, mpi_rank, events, is_gpu_domain)
        local domain_buffers = {}
        local nitems = {}
        local first_value   = nil
        local raw_data      = traces_data:get_raw(domain_id, mpi_rank)

        for _, event in ipairs(events) do
            local data = get_event_data(traces_data, event, domain_id, opt)

            first_value       = data.first_value
            local key         = data.key

            domain_buffers[key] = domain_buffers[key] or msgpack_encoder.new(1024, msgpack_encoder.OVERFLOW_REALLOC)
            nitems[key] = nitems[key] or 0
            nitems[key] = nitems[key] + 1

            local depth = compute_depth(raw_data, events, event, event.id)
            encode_event_item(domain_buffers[key], data.event_content, event, data.args, depth, traces_data)
        end

        local full_size = 1024
        local nbuf = 0
        for _, buf in pairs(domain_buffers) do
            full_size = full_size + buf:size()
            nbuf = nbuf + 1
        end

        local main_buffer = msgpack_encoder.new(full_size, msgpack_encoder.OVERFLOW_REALLOC)
        main_buffer:encode_array(nbuf)
        for key, buf in pairs(domain_buffers) do
            main_buffer:encode_ext(2, buf)
            main_buffer:encode_int(key)
            main_buffer:encode_uint(nitems[key])
            buf:free()
        end

        local first_label = is_gpu_domain and "GPU" or "PID"
        local last_label  = get_last_label(domain_id)
        local json_string = "{" ..
            first_label..':'..first_value..','..
            'Domain:"'..domain_name..'",'..
            last_label..':"'..main_buffer:to_b64()..'"'..
        "}"
        main_buffer:free()

        results[mpi_rank] = results[mpi_rank] or {}
        if is_gpu_domain then 
            table.insert(results[mpi_rank], 1, json_string)
        else
            table.insert(results[mpi_rank], json_string)
        end
    end)

    local json = ""
    for rank, entry in pairs(results) do
        json = json..'"'..rank..'":['..table.concat(entry, ",")..']'
    end

    return '{'..json..'}'
end

return preprocess