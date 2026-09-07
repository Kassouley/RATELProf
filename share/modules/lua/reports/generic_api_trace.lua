return function (report)
    local timeunit = report.opt.timeunit
    local domain_id = ratelprof.consts.DOMAIN_FOR_REPORT[report.report_id]

    local data = {}

    report.NAME = ratelprof.consts._DOMAIN_NAME[domain_id]

    report.TYPE = "Traces"

    report.HEADER = {
        "Start ("..timeunit..")",
        "Duration ("..timeunit..")",
        "Name", "Id", "CorrId",
        "PID", "TID"
    }

    report.LOOP_IN = { domain_id }

    report.SORT_BY = { "asc", 1 }

    report.FOR_EACH = function(self, event, rprofrep, pid_key)
        table.insert(data, {
            ratelprof.utils.get_duration(event:start(), timeunit),
            ratelprof.utils.get_duration(event:dur(), timeunit),
            event:name(),
            tostring(event:id()),
            tostring(event:cid()),
            ratelprof.utils.label_unit_with_rank(pid_key),
            tostring(event:tid()),
        })
    end

    report.POST_LOOP = function(self)
        self.data = data
    end
end