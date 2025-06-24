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
            if not opt.is_only_main or trace.phase == "MAIN_PHASE" then
                ret[id] = trace
            end
        end
        cached_trace[domain_name] = ret
        return ret
    end

    data.get_constructor_start = function(self)
        return self.raw.lifecycle[ratelprof.consts._IDX_CONSTRUCTOR_START]
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


function msgpack.decode (msgpack)
    if ratelprof.fs.has_extension(msgpack, ratelprof.consts._REPORT_EXT) then
        return decode_rprof(msgpack)
    else
        return msgpack_decoder.decode_msgpack_binary(msgpack)
    end
end


return msgpack