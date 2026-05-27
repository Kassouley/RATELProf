return function (report)
    local timeunit = report.opt.timeunit
    local sizeunit = report.opt.sizeunit

    local data = {}

    report.NAME = "GPU MemOps"

    report.TYPE = "Traces"

    report.HEADER = {
        "GPU ID",
        "Start ("..timeunit..")",
        "Duration ("..timeunit..")",
        "Id", "CorrId",
        "Bytes ("..sizeunit..")",
        "Throughput ("..sizeunit.."ps)",
        "Operation"
    }

    report.LOOP_IN = { ratelprof.consts.DOMAIN_MEMORY_ID }

    report.SORT_BY = { "desc", 3 }

    report.FOR_EACH = function(self, event, rprofrep, gpu_key)
        local args   = event:args()
        local start  = ratelprof.utils.get_duration(event:start(), timeunit)
        local dur    = ratelprof.utils.get_duration(event:dur(), timeunit)
        local dur_s  = ratelprof.utils.get_duration(event:dur(), "sec")
        local size   = ratelprof.utils.get_size(args.size, sizeunit)
        data[#data + 1] = {
            ratelprof.utils.label_unit_with_rank(gpu_key),
            start,
            dur,
            tostring(event:id()),
            tostring(rprofrep:get_correlated_id(event)),
            size,
            tonumber(size / dur_s),
            event:name()
        }
    end

    report.POST_LOOP = function(self)
        self.data = data
    end
end