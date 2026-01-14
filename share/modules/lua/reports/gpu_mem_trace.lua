local report_helper = require ("utils.report_helper")

local function get_raw_trace(rprofrep, opt)
    local sizeunit = "MB"
    local timeunit = opt.timeunit
    local gpus     = opt.gpus
    local data = {}

    rprofrep:for_each_rank(function(rank)
        rprofrep:for_each_gpu(function(gpu_id)
            rprofrep:for_each_event({ ratelprof.consts.DOMAIN_COPY_ID }, function(event)
                local args   = event:args()
                local start  = ratelprof.utils.get_duration(event:start(), timeunit)
                local dur    = ratelprof.utils.get_duration(event:dur(), timeunit)
                local dur_s  = ratelprof.utils.get_duration(event:dur(), "sec")
                local size   = ratelprof.utils.get_size(args.size, sizeunit)
                data[#data + 1] = {
                    tostring(rank),
                    tostring(gpu_id),
                    start,
                    dur,
                    tostring(event:id()),
                    tostring(rprofrep:get_correlated_id(event)),
                    size,
                    tonumber(size / dur_s),
                    event:name()
                }
            end)
        end, gpus)
    end)

    return data
end


return function (report)
    local timeunit = report.opt.timeunit
    local sizeunit = "MB"

    report.NAME = "GPU MemOps"

    report.TYPE = "Traces"

    report.HEADER = {
        "Rank",
        "GPU ID",
        "Start ("..timeunit..")",
        "Duration ("..timeunit..")",
        "Id",
        "CorrId",
        "Bytes ("..sizeunit..")",
        "Throughput ("..sizeunit.."ps)",
        "Operation"
    }

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_COPY_ID }

    report.SORT_BY = { "desc", 3 }

    report.DATA = function (self, rprofrep)
        self.data = get_raw_trace(rprofrep, self.opt)
    end
end