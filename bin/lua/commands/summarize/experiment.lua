-- summarize_experiment.lua
local summarize_experiment = {}

local experiment_info = {
    {key = "app",     label = "Application"},
    {key = "date",    label = "Date"},
    {key = "version", label = "Tool Version"},
    {key = "file",    label = "Report File"},
    {key = "domain",  label = "Domain Traced"},
}

function summarize_experiment.get_experiment_info(rprofrep)
    local domains = {}
    for id, name in pairs(ratelprof.consts._DOMAIN_NAME) do
        if rprofrep:is_domain_traced(id) then
            domains[#domains + 1] = name
        end
    end

    -- Precompute values once
    local values = {
        app     = rprofrep:get_run_command_line()
                  .. " (exit code: " .. rprofrep:get_run_exit_code() .. ")",
        date    = rprofrep:get_run_date(),
        version = rprofrep:get_tool_version(),
        file    = rprofrep:get_reports_filename_str(nil, 0),
        domain  = table.concat(domains, ", "),
    }

    -- Fill experiment_info
    for _, entry in ipairs(experiment_info) do
        entry.value = values[entry.key]
    end
    return experiment_info
end


return summarize_experiment