ratelprof = {}

require ("utils.string_ext")

Message = require ("utils.Classes.Message"):new()

ratelprof.utils         = require ("utils.utils")
ratelprof.convert       = require ("utils.convert")
ratelprof.fs            = require ("utils.rfs")
ratelprof.consts        = require ("consts")
ratelprof.consts_helper = require ("consts_helper")

package.cpath = ratelprof.consts._LIBS_DIR.."lua/?.so;" .. package.cpath
package.path  = ratelprof.consts._MODULES_DIR.."lua/?.lua;" .. package.path

ratelprof.get_opt_val = function (opt_list, name)
    return opt_list[name]
end

local msgpack_decoder = require ("msgpack_decoder")
local msgpack_encoder = require ("msgpack_encoder")

ratelprof.msgpack = {}
ratelprof.msgpack.decode = function (rprof_rep)
    local data = msgpack_decoder.decode_msgpack_binary(rprof_rep)
    local report_version = data.version

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
    return data
end


ratelprof.msgpack.encoder = msgpack_encoder



-- MAQAO Implementation
-- ratelprof.get_opt_val = function (opt_list, name)
--     local used_cmd = nil
--     for cmd_name, cmd in ipairs(ratelprof.consts_helper) do
--         if opt_list[cmd_name] then
--             local opt = cmd.opt[name]
--             local shortname = opt.sname
--             local default = opt.default
--             if opt_list[name] then 
--                 return options[name] 
--             elseif opt_list[shortname] then
--                 return opt_list[shortname]
--             else
--                 return default
--             end
--         end
--     end
--     return nil
-- end

