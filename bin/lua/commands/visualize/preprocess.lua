-- preprocess.lua
-- Structure for data preprocessing

local msgpack           = ratelprof.msgpack
local msgpack_encoder   = msgpack.encoder
local encode_ext_string = msgpack.encode.encode_ext_string
local encode_table      = msgpack.encode.encode_table

local preprocess = {}

local depth_map = {}

local function compute_depth (group, event, event_id)
    if event == nil then
        return 1
    end
    if depth_map[event_id] then
        return depth_map[event_id]
    end
    local depth = 1 + compute_depth (group, group[event.corr_id], event.corr_id)
    depth_map[event_id] = depth
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


local function get_event_data(data, event, domain_id, opt)
    local event_content  = "N/A"
    local args           = {}
    if ratelprof.consts._ENV.DOMAIN_KERNEL == domain_id then
        event_content  = get_kernel_name(event.args.kernel_name, opt)

        local gpu_agent = event.args.gpu_id
        args.gpu_id               = data:get_gpu_id(gpu_agent).." ("..gpu_agent..")"
        args.queue_id             = event.args.queue_id
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

        local gpu_agent = event.args.gpu_id
        args.gpu_id         = data:get_gpu_id(gpu_agent).." ("..gpu_agent..")"
        args.queue_id       = event.args.queue_id
        args.dispatch_time  = event.args.dispatch_time
        args.dep_signal     = event.args.dep_signal
        args.sig            = event.sig

    elseif ratelprof.consts._ENV.DOMAIN_BARRIERAND == domain_id then
        event_content  = "Barrier AND"

        local gpu_agent = event.args.gpu_id
        args.gpu_id         = data:get_gpu_id(gpu_agent).." ("..gpu_agent..")"
        args.queue_id       = event.args.queue_id
        args.dispatch_time  = event.args.dispatch_time
        args.dep_signal     = event.args.dep_signal
        args.sig            = event.sig

    elseif ratelprof.consts._ENV.DOMAIN_COPY == domain_id then
        event_content   = ratelprof.utils.get_copy_name(event.args.src_type, event.args.dst_type)

        local src_agent = event.args.src_agent
        local dst_agent = event.args.dst_agent
        args.src = ratelprof.utils.get_copy_name_from_kind(event.args.src_type) ..
            " Node ID. "..data:get_gpu_id(src_agent).." ("..src_agent..")"
        args.dst = ratelprof.utils.get_copy_name_from_kind(event.args.dst_type) ..
            " Node ID. "..data:get_gpu_id(dst_agent).." ("..dst_agent..")"
        args.size       = event.args.size
        args.engine_id  = event.args.engine_id
        args.sig        = event.sig

    else
        event_content   = event.name

        args.pid    = event.pid
        args.tid    = event.tid
        args.args   = event.args
    end
    return { event_content = event_content, args = args }
end


local function encode_event_item(buf, event, data, events, traces_data)
    buf:encode_map(8)

    encode_ext_string(buf, "content")
    encode_ext_string(buf, data.event_content)

    encode_ext_string(buf, "id")
    buf:encode_uint(data.id)

    encode_ext_string(buf, "start")
    buf:encode_uint(event.start)
    
    encode_ext_string(buf, "subgroup")
    buf:encode_uint(compute_depth(events, event, data.id))

    encode_ext_string(buf, "dur")
    buf:encode_uint(event.dur)

    encode_ext_string(buf, "cid")
    buf:encode_uint(event.corr_id)

    encode_ext_string(buf, "loc")
    local entry_point = traces_data:find_entry_point(event)
    encode_ext_string(buf, traces_data:get_location_str(entry_point))

    encode_ext_string(buf, "args")
    encode_table(buf, data.args)
end


function preprocess.get_b64_buffer(traces_data, opt)
    local event_domains = traces_data.raw.trace_events
    local main_buffer =  msgpack_encoder.new(1024, msgpack_encoder.OVERFLOW_REALLOC)

    local _start = ratelprof.get_opt_val(opt, "start")
    if _start then _start = tonumber(_start) end
    local _stop  = ratelprof.get_opt_val(opt, "stop")
    if _stop then _stop = tonumber(_stop) end

    local ndomains = 0
    local domain_i = 0
    for _, _ in pairs(event_domains) do
        ndomains = ndomains + 1
    end

    main_buffer:encode_array(ndomains)

    for domain_id, events in pairs(event_domains) do
        ratelprof.utils.print_progress(domain_i, ndomains, "Preprocessing", "("..domain_id..")")
        domain_i = domain_i + 1
        
        local nitems = 0
        local buf = msgpack_encoder.new(1024, msgpack_encoder.OVERFLOW_REALLOC)
        for event_id, event in pairs(events) do
            local event_start = event.start
            local event_stop  = event.start + event.dur

            local within_start = not _start or event_start >= _start
            local within_stop  = not _stop  or event_stop  <= _stop

            if within_start and within_stop then
                nitems = nitems + 1
                local data = get_event_data(traces_data, event, domain_id, opt)
                data.id = event_id
                encode_event_item(buf, event, data, events, traces_data)
            end
        end


        local tmp = msgpack_encoder.new(buf:size()+32, msgpack_encoder.OVERFLOW_REALLOC)
        encode_ext_string(tmp, domain_id)
        tmp:encode_uint(nitems)
        tmp:concat(buf)
        main_buffer:encode_ext(2, tmp)
        buf:free()
        tmp:free()
    end
    ratelprof.utils.print_progress(ndomains, ndomains, "Preprocessing", "(Done)")

    local b64_buffer = main_buffer:to_b64()
    main_buffer:free()
    return '"'..b64_buffer..'"'
end

return preprocess