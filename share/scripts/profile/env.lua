require ("utils.string_ext")
local utils    = require ("utils.utils")
local lfs      = require ("utils.lfs")
local settings = require ("settings")

local env = {}

env.env_value = {}

-- Function to set environment variable
function env.set_env(var, value)
    table.insert(env.env_value, var.."="..value)
end

function env.get_env()
    return table.concat(env.env_value, " ")
end


function env.set_filter_env_var(filename, filter_type)
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
        env.set_env(string.format(settings._ENV.FUNCTION_FILTERED, upper_category), table.concat(names,","))
        env.set_env(string.format(settings._ENV.FILTER_TYPE, upper_category), filter_type)
    end
end

function env.set_number_of_kernel_env_var(application)
    local num = tonumber(utils.execute_command(
        "nm --demangle --defined-only " .. application .. " | grep -iE \"__device_stub__|__omp_offloading\" | wc -l"
    ):match("%d+")) or 1
    local result = 32
    while result < num do
        result = result * 2
    end

    env.set_env(settings._ENV.NB_KERNEL_AV, result)
end


function env.set_number_of_queue_env_var()
    local output = utils.execute_command(settings._INSTALL_DIR.."/bin/ratelinfo --max-queue")
    env.set_env(settings._ENV.NB_QUEUE_AV, tonumber(output) + 1)
end

return env