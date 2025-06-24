local common_data = {}


function common_data.get_domain_table_as_js_string(data)
    local domains = data:get_domain_traced()
    local domain_table = {}
    for _, domain in ipairs(domains) do
        local name = ratelprof.consts._DOMAIN_NAME[domain]
        local desc = ratelprof.consts._DOMAIN_DESC[domain]
        local isGPU = ratelprof.consts._GPU_DOMAIN[domain] or false
        domain_table[domain] = {name = name, desc = desc, isGPU = isGPU}
    end
    return JSON:encode(domain_table)
end


function common_data.get_lifecycle_table_as_js_string(data)
    local lifecycle_table = {
        init_start = data:get_constructor_start(),
        main_start = data:get_main_start(),
        main_stop  = data:get_main_stop(),
        fini_stop  = data:get_destructor_stop()
    }
    return JSON:encode(lifecycle_table)
end

return common_data
