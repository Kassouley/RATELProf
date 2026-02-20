ratelprof = {}

require ("utils.string_ext")
require ("utils.table_ext")
require ("utils.Classes.Set")

require ("consts")
require ("consts_reports")

package.cpath = ratelprof.consts._LIBS_DIR.."lua/?.so;" .. package.cpath
package.path  = ratelprof.consts._MODULES_DIR.."lua/?.lua;" .. package.path

Message = require ("utils.Classes.Message"):new()

ratelprof.consts_helper = require ("consts_helper")

ratelprof.utils         = require ("utils.utils")
ratelprof.convert       = require ("utils.convert")
ratelprof.fs            = require ("utils.rfs")
ratelprof.msgpack       = require ("utils.msgpack")

ratelprof.get_opt_val = function (opt_list, name)
    return opt_list[name]
end

ratelprof.profile   = require("commands.profile")
ratelprof.stats     = require("commands.common").stats
ratelprof.analyze   = require("commands.common").analyze
ratelprof.breakdown = require("commands.common").breakdown
ratelprof.summarize = require("commands.summarize")
ratelprof.visualize = require("commands.visualize")

-- MAQAO Implementation
-- ratelprof.get_opt_val = function (opt_list, name)
--     for cmd_name, cmd in ipairs(ratelprof.consts_helper) do
--         if opt_list[cmd_name] then
--             local opt = cmd.opt[name]
--             local shortname = opt.sname
--             local default = opt.default
--             if opt_list[name] then 
--                 return opt_list[name] 
--             elseif opt_list[shortname] then
--                 return opt_list[shortname]
--             else
--                 return default
--             end
--         end
--     end
--     return nil
-- end

