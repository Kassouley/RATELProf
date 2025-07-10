local msgpack = {}

local msgpack_decoder = require ("msgpack_decoder")
local msgpack_encoder = require ("msgpack_encoder")

msgpack.encoder = msgpack_encoder

local function decode_rprof(rprof_rep)
    local data = {}
    data.raw = msgpack_decoder.decode_msgpack_binary(rprof_rep)
    local report_version = data.raw.version

    if report_version then
        local rvmajor = report_version[1]
        local rvminor = report_version[2]
        local rvpatch = report_version[3]

        if  rvmajor ~= ratelprof.consts._VERSION_MAJOR or
            rvminor ~= ratelprof.consts._VERSION_MINOR or
            rvpatch ~= ratelprof.consts._VERSION_PATCH then

            Message:error(string.format(
                "Incompatible report file version: expected %d.%d.%d but got %d.%d.%d.\n" ..
                "Please regenerate the report using the current version of RATELProf.",
                ratelprof.consts._VERSION_MAJOR,
                ratelprof.consts._VERSION_MINOR,
                ratelprof.consts._VERSION_PATCH,
                rvmajor or 0, rvminor or 0, rvpatch or 0
            ))
            os.exit(1)
        end
    else
        Message:error("Missing or malformed report version information in the report file.")
        os.exit(1)
    end

    local cached_trace = {}
    data.get = function(self, domain_name, opt)
        if cached_trace[domain_name] then return cached_trace[domain_name] end
        local ret = {}
        for id, trace in pairs(self.raw.trace_events[domain_name] or {}) do
            if not opt.only_main or trace.phase == "MAIN_PHASE" then
                local opt_start = opt.start
                local opt_stop  = opt.stop
                local start = trace.start
                local stop  = trace.start + trace.dur
                local within_start = not opt_start or start >= opt_start
                local within_stop  = not opt_stop  or stop  <= opt_stop
                if within_start and within_stop then
                    ret[id] = trace
                end
            end
        end
        cached_trace[domain_name] = ret
        return ret
    end

    data.get_constructor_start = function(self)
        return 0 -- App start at 0
    end

    data.get_destructor_stop = function(self)
        return self.raw.lifecycle[ratelprof.consts._IDX_DESTRUCTOR_STOP]
    end

    data.get_main_start = function(self)
        return self.raw.lifecycle[ratelprof.consts._IDX_MAIN_START]
    end

    data.get_main_stop = function(self)
        return self.raw.lifecycle[ratelprof.consts._IDX_MAIN_STOP]
    end

    data.get_app_dur = function(self)
        return self:get_destructor_stop() - self:get_constructor_start()
    end

    local cached_compute_time = nil
    data.get_compute_time = function(self) 
        if cached_compute_time then return cached_compute_time end
        local kernel_data = self.raw.trace_events[ratelprof.consts._ENV.DOMAIN_KERNEL]
        cached_compute_time = ratelprof.utils.compute_total_covered_duration(kernel_data)
        return cached_compute_time
    end

    local cached_copy_time = nil
    data.get_copy_time = function(self)
        if cached_copy_time then return cached_copy_time end
        local copy_data = self.raw.trace_events[ratelprof.consts._ENV.DOMAIN_COPY]
        cached_copy_time = ratelprof.utils.compute_total_covered_duration(copy_data)
        return cached_copy_time
    end

    local cached_gpu_active_time = nil
    data.get_gpu_active_time = function(self)
        if cached_gpu_active_time then return cached_gpu_active_time end
        local kernel_data = self.raw.trace_events[ratelprof.consts._ENV.DOMAIN_KERNEL]
        local copy_data   = self.raw.trace_events[ratelprof.consts._ENV.DOMAIN_COPY]
        cached_gpu_active_time = ratelprof.utils.compute_total_covered_duration(kernel_data, copy_data)
        return cached_gpu_active_time
    end

    data.get_gpu_id = function(self, handle)
        return self.raw.node_id[handle] or string.format('Unknown(%lu)', handle)
    end

    data.get_domain_traced = function (self)
        local domains = {}
        for domain_name, _ in pairs(self.raw.trace_events) do
            table.insert(domains, domain_name)
        end
        return domains
    end

    data.get_app_name = function(self)
        local main_data = self.raw.main_data
        local ret = main_data[1]

        local parts = {}
        for i = 2, #main_data do
            table.insert(parts, main_data[i])
        end
        return table.concat(parts, " ") .. " (ret: " .. ret .. ")"
    end

    data.get_app_date = function(self)
        return os.date("%Y-%m-%d %H:%M:%S", self.raw.experiment_start_epoch / 1e9)
    end

    data.get_tool_version = function(self)
        local v = self.raw.version
        return string.format("%d.%d.%d", v[1], v[2], v[3])
    end


    return data
end


function msgpack.decode (file)
    if ratelprof.fs.has_extension(file, ratelprof.consts._REPORT_EXT) then
        return decode_rprof(file)
    else
        return msgpack_decoder.decode_msgpack_binary(file)
    end
end

msgpack.encode = {}

local str_map       = {}
local reverse_map   = {}
local counter       = 0

local function get_key(s)
    if reverse_map[s] then
        return reverse_map[s]
    end
    counter = counter + 1
    str_map[counter] = string.gsub(s, "%%", "%%%%")
    reverse_map[s] = counter - 1
    return counter - 1
end

function msgpack.encode.get_ext_string_table()
    return str_map
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
    local is_array = ratelprof.utils.is_array(tbl)
    if is_array then
        buf:encode_array(#tbl)
    else
        local count = 0
        for _ in pairs(tbl) do
            count = count + 1
        end
        buf:encode_map(count)
    end

    for k, v in pairs(tbl) do
        -- Encode key if map
        if not is_array then
            if type(k) == "string" then
                encode_ext_string(buf, k)
            elseif ratelprof.utils.is_integer(k) then
                buf:encode_int(k)
            else
                error("Unsupported key type: " .. type(k))
            end
        end

        -- Encode value
        if type(v) == "string" then
            -- buf:encode_string(v)
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


function msgpack.encode.auto_encode(data)
    if type (data) ~= "table" then
        error ("argument data need to be a table")
    end

    local buf =  msgpack_encoder.new(1024, msgpack_encoder.OVERFLOW_REALLOC)
    encode_table(buf, data)
    return buf
end


function msgpack.encode.auto_encode_to_b64(data)
    local buf = msgpack.encode.auto_encode(data)
    local b64_buffer = buf:to_b64()
    buf:free()
    return b64_buffer

end

msgpack.encode.encode_ext_string = encode_ext_string
msgpack.encode.encode_table      = encode_table

return msgpack