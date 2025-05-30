---@diagnostic disable: need-check-nil
-- preprocess.lua
-- Structure for data preprocessing

local msgpack_encoder = require("msgpack_encoder")

local preprocess = {}

local __is_init = false

local function is_init()
    if not __is_init then
        error("preprocess.init() must be called before any preprocess function calls")
    end
end


local event_domains = nil
local domain_maps   = nil
local node_maps     = nil
local lifecycle     = nil

local main_buffer = nil

local depth_map = {}

local normalize_time = nil

local str_map       = {}
local reverse_map   = {}
local counter       = 0

local function get_key(s)
    if reverse_map[s] then
        return reverse_map[s]
    end
    counter = counter + 1
    str_map[counter] = s
    reverse_map[s] = counter - 1
    return counter - 1
end

local function encode_ext_string(buf, str)
    local key = get_key(str)
    local type_code = 1
    local data = msgpack_encoder.new(16, msgpack_encoder.OVERFLOW_REALLOC)
    data:encode_uint(key)
    buf:encode_ext(type_code, data)
    data:free()
end

local function encode_table(buf, tbl)
  local count = 0
  for _ in pairs(tbl) do
    count = count + 1
  end

  buf:encode_map(count)

  for k, v in pairs(tbl) do
    -- Encode key
    if type(k) == "string" then
      encode_ext_string(buf, k)
    elseif ratelprof.utils.is_integer(k) then
      buf:encode_int(k)
    else
      error("Unsupported key type: " .. type(k))
    end

    -- Encode value
    if type(v) == "string" then
      encode_ext_string(buf, v)
    elseif type(v) == "boolean" then
      buf:encode_bool(v)
    elseif v == nil then
      buf:encode_nil()
    elseif type(v) == "table" then
      encode_table(buf, v) -- recursive
    elseif ratelprof.utils.is_integer(v) then
      buf:encode_int(v)
    elseif type(v) == "number" then
      buf:encode_double(v)
    else
      error("Unsupported value type: " .. type(v))
    end
  end
end

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

local function get_id_from_agent (agent)
    if agent == nil then
        error ("agent can't be nil")
    end
    return node_maps[agent]
end

local kernel_name_cache = {}
local function get_kernel_name(name, opt)
    local cached_name = kernel_name_cache[name]
    if cached_name then return cached_name end
    cached_name = ratelprof.utils.get_kernel_name(name, opt.trunc, opt.mangled) or "N/A"
    kernel_name_cache[name] = cached_name
    return cached_name
end


local function get_event_data(event, domain_id, opt)
    local event_content  = "N/A"
    local args           = {}
    if domain_maps[ratelprof.consts._ENV.DOMAIN_KERNEL].id == domain_id then
        event_content  = get_kernel_name(event.args.kernel_name, opt)

        local gpu_agent = event.args.gpu_id
        args.gpu_id               = get_id_from_agent(gpu_agent).." ("..gpu_agent..")"
        args.queue_id             = event.args.queue_id
        args.dispatch_time        = normalize_time(event.args.dispatch_time)
        args.wrg                  = event.args.wrg
        args.grd                  = event.args.grd 
        args.private_segment_size = event.args.private_segment_size
        args.group_segment_size   = event.args.group_segment_size
        args.kernel_object        = event.args.kernel_object
        args.kernarg_address      = event.args.kernarg_address
        args.sig                  = event.sig

    elseif domain_maps[ratelprof.consts._ENV.DOMAIN_BARRIEROR].id == domain_id then
        event_content  = "Barrier OR"

        local gpu_agent = event.args.gpu_id
        args.gpu_id         = get_id_from_agent(gpu_agent).." ("..gpu_agent..")"
        args.queue_id       = event.args.queue_id
        args.dispatch_time  = normalize_time(event.args.dispatch_time)
        args.dep_signal     = event.args.dep_signal
        args.sig            = event.sig

    elseif domain_maps[ratelprof.consts._ENV.DOMAIN_BARRIERAND].id == domain_id then
        event_content  = "Barrier AND"

        local gpu_agent = event.args.gpu_id
        args.gpu_id         = get_id_from_agent(gpu_agent).." ("..gpu_agent..")"
        args.queue_id       = event.args.queue_id
        args.dispatch_time  = normalize_time(event.args.dispatch_time)
        args.dep_signal     = event.args.dep_signal
        args.sig            = event.sig

    elseif domain_maps[ratelprof.consts._ENV.DOMAIN_COPY].id == domain_id then
        event_content   = ratelprof.utils.get_copy_name(event.args.src_type, event.args.dst_type)

        local src_agent = event.args.src_agent
        local dst_agent = event.args.dst_agent
        args.src = ratelprof.utils.get_copy_name_from_kind(event.args.src_type) ..
            " Node ID. "..get_id_from_agent(src_agent).." ("..src_agent..")"
        args.dst = ratelprof.utils.get_copy_name_from_kind(event.args.src_type) ..
            " Node ID. "..get_id_from_agent(dst_agent).." ("..dst_agent..")"
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


local function closure_normalize_time (start_time)
    local constructor_start_time = math.floor(start_time / 1000)
    return function (time)
        return math.floor(time / 1000) - constructor_start_time
    end
end


local function encode_event_item(buf, event, data, events)
    buf:encode_map(7)

    encode_ext_string(buf, "content")
    encode_ext_string(buf, data.event_content)

    encode_ext_string(buf, "id")
    buf:encode_uint(data.id)

    encode_ext_string(buf, "start")
    buf:encode_uint(data.start)
    
    encode_ext_string(buf, "subgroup")
    buf:encode_uint(compute_depth(events, event, data.id))

    encode_ext_string(buf, "dur")
    buf:encode_uint(event.dur)

    encode_ext_string(buf, "cid")
    buf:encode_uint(event.corr_id)

    encode_ext_string(buf, "args")
    encode_table(buf, data.args)
end


function preprocess.init(data)
    event_domains = data.trace_events
    domain_maps   = data.domain_id
    node_maps     = data.node_id
    lifecycle     = data.lifecycle
    normalize_time = closure_normalize_time(lifecycle.constructor_start)
    
    main_buffer = msgpack_encoder.new(1024, msgpack_encoder.OVERFLOW_REALLOC)

    __is_init = true
end

local function print_progress(prefix, current, total)
    local bar_length = 30
    local progress = math.floor((current / total) * bar_length)
    local bar = string.rep("=", progress) .. string.rep(" ", bar_length - progress)
    io.write(string.format("\r%-20s [%s] %d/%d", prefix, bar, current, total))
    io.flush()
end

function preprocess.run(opt)
    is_init()

    local ndomains = 0
    local domain_i = 0
    for _, _ in pairs(event_domains) do
        ndomains = ndomains + 1
    end

    main_buffer:encode_array(ndomains)

    for domain_id, events in pairs(event_domains) do
        print_progress("Domain processed", domain_i, ndomains)
        domain_i = domain_i + 1
        
        local nitems = 0
        local buf = msgpack_encoder.new(1024, msgpack_encoder.OVERFLOW_REALLOC)
        for event_id, event in pairs(events) do
            local event_start = normalize_time(event.start)
            local event_end   = normalize_time(event.start + event.dur)

            local within_start = not opt.start_time or event_start >= opt.start_time
            local within_end   = not opt.end_time   or event_end   <= opt.end_time

            if within_start and within_end then
                nitems = nitems + 1
                local data = get_event_data(event, domain_id, opt)
                data.start = event_start
                data.id = event_id
                encode_event_item(buf, event, data, events)
            end
        end


        local tmp = msgpack_encoder.new(buf:size()+32, msgpack_encoder.OVERFLOW_REALLOC)
        tmp:encode_uint(domain_id)
        tmp:encode_uint(nitems)
        tmp:concat(buf)
        main_buffer:encode_ext(2, tmp)
        buf:free()
        tmp:free()
    end
    print_progress("Preprocessing", ndomains, ndomains)
end

function preprocess.get_data()
    is_init()
    local data = main_buffer:to_b64()
    main_buffer:free()
    return data
end

function preprocess.get_lifecycle_data()
    is_init()
    local lifecycle_table = {
        init_start = normalize_time(lifecycle.constructor_start),
        main_start = normalize_time(lifecycle.main_start),
        main_stop  = normalize_time(lifecycle.main_stop),
        fini_stop  = normalize_time(lifecycle.destructor_stop)
    }
    return JSON:encode(lifecycle_table)
end

function preprocess.get_domain_data()
    is_init()
    local domain_table = {}
    for domain_name, domain in pairs(domain_maps) do
        local domain_id = domain.id
        if (event_domains[domain_id]) then
            domain_table[tostring(domain_id)] = {
                name = ratelprof.consts._DOMAIN_NAME[domain_name],
                desc = domain.desc
            }
        end
    end
    return JSON:encode(domain_table)
end

function preprocess.get_string_map()
    is_init()
    return JSON:encode(str_map)
end

return preprocess