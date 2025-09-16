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
    local group          = nil
    local args           = {}
    if ratelprof.consts._ENV.DOMAIN_KERNEL == domain_id then
        event_content  = get_kernel_name(event.args.kernel_name, opt)

        first_value               = data:get_gpu_id(event.args.gpu_id)
        group                     = event.args.queue_id
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
        group               = event.args.queue_id
        args.dispatch_time  = event.args.dispatch_time
        args.dep_signal     = event.args.dep_signal
        args.sig            = event.sig

    elseif ratelprof.consts._ENV.DOMAIN_BARRIERAND == domain_id then
        event_content  = "Barrier AND"

        first_value         = data:get_gpu_id(event.args.gpu_id)
        group               = event.args.queue_id
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
        group = event.args.engine_id

        args.src = ratelprof.utils.get_copy_name_from_kind(event.args.src_type) ..
            " Node ID. "..src_node.." ("..src_agent..")"
        args.dst = ratelprof.utils.get_copy_name_from_kind(event.args.dst_type) ..
            " Node ID. "..dst_node.." ("..dst_agent..")"
        args.size       = event.args.size
        args.sig        = event.sig

    else
        event_content   = event.name
        first_value     = event.pid
        group           = event.tid
        args.args       = event.args
    end
    return { event_content = event_content, args = args, first_value = first_value, group = group }
end


local DENSITY_GRANULARITY = 1000;

local function init_density(initial_value)
    local density = {}
    for i = 1, DENSITY_GRANULARITY do
        density[i] = initial_value
    end

    return density
end

local function compute_density(density, item, min, max)
    local startX = math.floor(((item.start - min) / (max - min)) * DENSITY_GRANULARITY)
    local stopX  = math.floor(((item.stop  - min) / (max - min)) * DENSITY_GRANULARITY)

    -- TODO (9/9/25) Implement a score system
    local score  = item.score or 1

    for x = startX, stopX do
        density[x] = (density[x] or 0) + score
    end
end

local function encode_event_item(buf, event_data)
    if event_data.subgroup > 0 then
        buf:encode_map(8)
    else
        buf:encode_map(7)
    end

    encode_ext_string(buf, "content")
    encode_ext_string(buf, event_data.content)

    encode_ext_string(buf, "id")
    buf:encode_uint(event_data.id)

    encode_ext_string(buf, "start")
    buf:encode_uint(event_data.start)

    if event_data.subgroup > 0 then
        encode_ext_string(buf, "subgroup")
        buf:encode_uint(event_data.subgroup)
    end

    encode_ext_string(buf, "dur")
    buf:encode_uint(event_data.dur)

    encode_ext_string(buf, "cid")
    buf:encode_uint(event_data.cid)

    encode_ext_string(buf, "loc")
    encode_ext_string(buf, event_data.loc)

    encode_ext_string(buf, "args")
    encode_table(buf, event_data.args)
end


function preprocess.start(traces_data, output, opt)
    local BUCKET_DIR = ".data/buckets/"
    local output_bucket = ratelprof.fs.concat_path(output, BUCKET_DIR)

    local results = {}

    local BUCKET_SIZE = 1e9 -- 1 second

    local files_per_bucket = {}

    local timeline_id = 0
    local nb_timeline = 0

    traces_data:for_each_domain(function(_, _, _, _, _)
        nb_timeline = nb_timeline + 1
    end)

    traces_data:for_each_domain(function(domain_name, domain_id, mpi_rank, events, is_gpu_domain)
        local stack_per_group = {}

        local first_value   = nil
        local raw_data      = traces_data:get_raw(domain_id, mpi_rank)

        local current_bucket = 0

        local function flush_bucket()
            local group_counts, ngroups = {}, 0

            for group, stack in pairs(stack_per_group) do
                local nitems = #stack
                if nitems > 0 then
                    ngroups = ngroups + 1
                    group_counts[group] = nitems
                end
            end

            if ngroups == 0 then return end

            local filename = string.format(output_bucket.."/%d.js", current_bucket)
            local file = files_per_bucket[current_bucket]
            if not file then
                if ratelprof.fs.exists(filename) then
                    ratelprof.fs.rm(filename)
                end
                file = ratelprof.fs.open_file(filename, "a")
                files_per_bucket[current_bucket] = file
                file:write('window.b64_data={')
            end
            file:seek("end")
            file:write(timeline_id..':"')
            file:flush()

            local buf = msgpack_encoder.new(65535, msgpack_encoder.OVERFLOW_APPEND_B64_TO_FILE, filename)
            buf:encode_uint(ngroups)

            for group, nitems in pairs(group_counts) do
                local stack = stack_per_group[group]
                buf:encode_int(group)
                buf:encode_uint(nitems)
                for i = 1, nitems do
                    encode_event_item(buf, stack[i])
                end
            end
            buf:write()
            buf:free()

            file:seek("end")
            file:write('",')
            file:flush()
        end

        local density = init_density(0)

        local old_value = 0 
        for _, event in ipairs(events) do
            
            old_value = ratelprof.utils.print_mem_usage("", old_value)

            local data = get_event_data(traces_data, event, domain_id, opt)

            first_value = data.first_value
            local group = data.group

            -- advance bucket if event.start is outside current range
            while event.start >= current_bucket + BUCKET_SIZE do
                -- flush current bucket
                flush_bucket()

                -- remove finished events from stack
                for g, stack in pairs(stack_per_group) do
                    local new_stack = {}
                    for _, s in ipairs(stack) do
                        if s.start + s.dur >= current_bucket + BUCKET_SIZE then
                            new_stack[#new_stack+1] = s
                        end
                    end
                    stack = nil
                    stack_per_group[g] = new_stack
                end

                -- move to next bucket
                current_bucket = current_bucket + BUCKET_SIZE
            end

            local stack = stack_per_group[group]
            if not stack then
                stack = {}
                stack_per_group[group] = stack
            end

            table.insert(stack, {
                content  = data.event_content,
                group    = group,
                subgroup = compute_depth(raw_data, events, event, event.id),
                start    = event.start,
                dur      = event.dur,
                id       = event.id,
                cid      = event.corr_id,
                loc      = traces_data:get_entry_point_location_str(event),
                args     = data.args,
            })

            compute_density(density, event, 0, traces_data:get_max_stop_time())
        end

        flush_bucket()

        local first_label = is_gpu_domain and "GPU" or "PID"
        local last_label  = get_last_label(domain_id)
        local json_string = "{" ..
            'timeline_id:'..timeline_id..','..
            'rank:'..mpi_rank..','..
            first_label..':'..first_value..','..
            'Domain:"'..domain_name..'",'..
            last_label..':['..table.concat_keys(stack_per_group, ",")..'],'..
            'density'..':['..table.concat(density, ",")..'],'..
        "}"

        if is_gpu_domain then 
            table.insert(results, 1, json_string)
        else
            table.insert(results, json_string)
        end

        timeline_id = timeline_id + 1
    end)

    for _, f in pairs(files_per_bucket) do
        f:write('}')
        f:close()
    end
    
    Message:print("RPROF: Bucket generated to '" .. output_bucket.."'")

    return '['..table.concat(results, ",")..']'
end

return preprocess