module("profile.env", package.seeall)

require ("utils.common")
require ("utils.string_ext")
require ("utils.lfs")

local env = {}

-- Function to set environment variable
function profile:set_env(var, value)
    table.insert(env, var.."="..value)
end

function profile:get_env()
    return table.concat(env, " ")
end


function profile:set_filter_env_var(filename, filter_type, settings)
    local file = lfs.open_file(filename, "r")
    local categories = {}
    local current_category = nil

    for line in file:lines() do
        line = line:trim()

        if line:find(":") then
            -- Found a new category
            local category, names = line:match("^(.-):%s*(.*)$")
            current_category = category:trim()
            categories[current_category] = {}

            if names and names ~= "" then
                -- Add any names that are on the same line as the category
                for name in names:gmatch("[^,]+") do
                    table.insert(categories[current_category], name:trim())
                end
            end
        elseif current_category and line ~= "" then
            -- Add names to the current category if they are on separate lines
            for name in line:gmatch("[^,]+") do
                table.insert(categories[current_category], name:trim())
            end
        end
    end
    file:close()
    
    for category, names in pairs(categories) do
        local upper_category = string.upper(category)
        profile:set_env(string.format(settings.settings._ENV.FUNCTION_FILTERED, upper_category), table.concat(names,","))
        profile:set_env(string.format(settings.settings._ENV.FILTER_TYPE, upper_category), filter_type)
    end
end

function profile:set_number_of_kernel_env_var(application)
    local num = tonumber(common.execute_command(
        "nm --demangle --defined-only " .. application .. " | grep -iE \"__device_stub__|__omp_offloading\" | wc -l"
    ):match("%d+")) or 1
    local result = 32
    while result < num do
        result = result * 2
    end

    profile:set_env(settings.settings._ENV.NB_KERNEL_AV, result)
end


function profile:set_number_of_queue_env_var()
    local output = common.execute_command(settings.settings._INSTALL_DIR.."/bin/ratelinfo --max-queue")
    profile:set_env(settings.settings._ENV.NB_QUEUE_AV, tonumber(output) + 1)
end