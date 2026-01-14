local function get_raw_trace(rprofrep, opt, domain_id)
    local timeunit = opt.timeunit
    local pids = opt.pids

    local data = {}

    rprofrep:for_each_rank(function(rank)
        rprofrep:for_each_pid(function(pid)
            rprofrep:for_each_event({ domain_id }, function(event)
                table.insert(data, {
                    ratelprof.utils.get_duration(event:start(), timeunit),
                    ratelprof.utils.get_duration(event:dur(), timeunit),
                    event:name(),
                    tostring(event:id()),
                    tostring(rprofrep:get_correlated_id(event)),
                    tostring(rank),
                    tostring(pid),
                    tostring(event:tid()),
                })
            end)
        end, pids)
    end)

    return data
end

return function (report)
    local timeunit = report.opt.timeunit
    local domain_id = ratelprof.consts.DOMAIN_FOR_REPORT[report.report_id]

    report.NAME = ratelprof.consts._DOMAIN_NAME[domain_id]

    report.TYPE = "Traces"

    report.HEADER = {
        "Start ("..timeunit..")",
        "Duration ("..timeunit..")",
        "Name",
        "Id",
        "CorrId",
        "Rank",
        "PID",
        "TID"
    }

    report.REQUIRED_DOMAIN = { domain_id }

    report.SORT_BY = { "asc", 1 }

    report.DATA = function (self, rprofrep)
        self.data = get_raw_trace(rprofrep, self.opt, domain_id)
    end
end