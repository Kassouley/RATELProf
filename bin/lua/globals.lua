ratelprof = {}

ratelprof.consts        = require ("consts")

package.cpath = ratelprof.consts._LIBS_DIR.."lua/?.so;" .. package.cpath
package.path  = ratelprof.consts._MODULES_DIR.."lua/?.lua;" .. package.path

require ("utils.string_ext")
require ("utils.table_ext")

Message = require ("utils.Classes.Message"):new()

ratelprof.consts_helper = require ("consts_helper")

ratelprof.utils         = require ("utils.utils")
ratelprof.convert       = require ("utils.convert")
ratelprof.fs            = require ("utils.rfs")
ratelprof.msgpack       = require ("utils.msgpack")

ratelprof.get_opt_val = function (opt_list, name)
    return opt_list[name]
end

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

