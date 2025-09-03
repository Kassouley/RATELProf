-- summarize_experiment.lua
local summarize_experiment = {}

local experiment_info = {
    {key = "app",       label = "Application"},
    {key = "date",      label = "Date"},
    {key = "version",   label = "Tool Version"},
    {key = "file",      label = "Report File"},
    {key = "domain",    label = "Domain Traced"},
    -- {key = "filtered", label = "Domain Filtered"},
    -- {key = "nkernel", label = "Kernels Number"},
}


function summarize_experiment.get_experiment_info(data)
    local domain_traced = data:get_domain_traced()
    local domain_traced_name = {}
    for _, domain in ipairs(domain_traced) do
        table.insert(domain_traced_name, ratelprof.consts._DOMAIN_NAME[domain])
    end

    for _, entry in ipairs(experiment_info) do
        if entry.key == "app" then
            entry.value = data:get_app_name()
        elseif entry.key == "date" then
            entry.value = data:get_app_date()
        elseif entry.key == "version" then
            entry.value = data:get_tool_version()
        elseif entry.key == "file" then
            entry.value = table.concat(data:get_rprof_rep_files(), ", ")
        elseif entry.key == "domain" then
            entry.value = table.concat(domain_traced_name, ", ")
        end
    end

    return experiment_info
end

return summarize_experiment