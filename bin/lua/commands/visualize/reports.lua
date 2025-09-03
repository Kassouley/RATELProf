local msgpack = ratelprof.msgpack

local reports = {}

function reports.get_csv_data(stats_ret_vals, analyze_ret_vals)

    local function process_reports(reports_ret_vals)
        local content_table = {}
        for rank, report_list in pairs(reports_ret_vals) do
            for report_name, report_ret in pairs(report_list) do
                if not report_ret then
                    error("A report need to have a return value")
                end
                if not report_ret.skip then
                    local name    = report_ret.NAME .. " " .. report_ret.TYPE
                    local content = report_ret.DATA
                    local msg     = report_ret.MSG

                    if (content and #content > 0) or msg then
                        local t = {}
                        if name then
                            table.insert(t, string.format('name:"%s"', name))
                        end

                        if #content > 0 then
                            table.insert(t, string.format('content:"%s"', msgpack.encode.auto_encode_to_b64(content)))
                        end

                        if msg then
                            table.insert(t, string.format('msg:"<pre>%s</pre>"', string.gsub(msg, "\n", "<br>")))
                        end

                        table.insert(content_table, string.format('%s:{%s}', report_name, table.concat(t, ",")))
                    end
                end
            end
        end

        return '{'..table.concat(content_table, ",")..'}'
    end

    local stats_content   = process_reports(stats_ret_vals)
    local analyze_content = process_reports(analyze_ret_vals)


    return '{"statsPanel":'..stats_content..', "analyzePanel":'..analyze_content..'}'
end


return reports