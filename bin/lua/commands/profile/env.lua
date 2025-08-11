local kernel_helper = require ("commands.inspect.kernel_helper")

local env = {}

env.env_value = {}

-- Function to set environment variable
function env.set_env(var, value)
    if not var then return end
    table.insert(env.env_value, var.."="..value)
end

function env.get_env()
    return table.concat(env.env_value, " ")
end


function env.set_filter_env_var(filename, filter_type)
    local file = ratelprof.fs.open_file(filename, "r")
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
                for name in names:gmatch("[^%s*]+") do
                    table.insert(categories[current_category], name:trim())
                end
            end
        elseif current_category and line ~= "" then
            -- Add names to the current category if they are on separate lines
            for name in line:gmatch("[^%s*]+") do
                table.insert(categories[current_category], name:trim())
            end
        end
    end
    file:close()
    
    for category, names in pairs(categories) do
        local upper_category = string.upper(category)
        env.set_env(string.format(ratelprof.consts._ENV.FUNCTION_FILTERED, upper_category), table.concat(names,","))
        env.set_env(string.format(ratelprof.consts._ENV.FILTER_TYPE, upper_category), filter_type)
    end
end

function env.set_number_of_kernel_env_var(application)
    local n = kernel_helper.get_kernel_number(application)
    env.set_env(ratelprof.consts._ENV.NB_KERNEL_AV, n)
end


function env.set_number_of_queue_env_var()
    local num_queue = os.getenv("GPU_MAX_HW_QUEUES") or 4
    env.set_env(ratelprof.consts._ENV.NB_QUEUE_AV, tonumber(num_queue) + 1)
end

return env