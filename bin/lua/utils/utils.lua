require("utils.json.json")

local utils = {}

local convert = require ("utils.convert") 

utils.demangle = require ("demangle").demangle

utils.Progress = require ("utils.Classes.Progress")


-- Function to print memory usage in GB only if it changes (2 decimal digits)
function utils.print_mem_usage(suffix, old_value)

    -- Get memory in GB
    local memory_gb = collectgarbage("count") / (1024 * 1024)

    -- Round to 2 decimal places
    local memory_rounded = math.floor(memory_gb * 100 + 0.5) / 100

    -- Compare with old value
    if memory_rounded ~= old_value then
        io.write(string.format("\rMemory usage: %.2f GB %s", memory_rounded, suffix or ""))
        io.flush()  -- Ensure immediate print
        return memory_rounded
    else
        return old_value
    end
end


function utils.load_json (__input_path__)
    local infile = ratelprof.fs.open_file (__input_path__, "r", "json")
    local data = infile:read ("*a")
    infile:close ()
    return JSON:decode(data)
end


function utils.store_json (data, __input_path__)
    local infile = ratelprof.fs.open_file (__input_path__, "w", "json")
    infile:write (JSON:encode(data))
    infile:close ()
end


function utils.is_integer(n)
    return n == math.floor(n)
end

function utils.is_array(tbl)
    if type(tbl) ~= "table" then
    return false
    end

    local i = 0
    for k, _ in pairs(tbl) do
        i = i + 1
        if type(k) ~= "number" or k ~= i then
            return false
        end
    end

    return true
end


function utils.execute_command(cmd)
    local handle = io.popen(cmd)
    if not handle then
        error ("cannot execute command, handle is nil")
    end
    local result = handle:read("*a")
    handle:close()
    return string.gsub(result, "\n$", "")
end

local omp_pattern = "^__omp_offloading_[%da-f]+_[%da-f]+_(.-)_l(%d+).*"

local name_cache = {}
function utils.get_kernel_name(name, is_trunc, is_mangled)
    local cached_name = name_cache[name]
    if cached_name then return cached_name end

    local mangled_name, line = name:match(omp_pattern)
    local ret = name
    if not is_mangled then
        if mangled_name then
            name = mangled_name
        end
        if is_trunc then
            ret = utils.demangle(name, true)
        else
            ret = utils.demangle(name)
        end
        if line then
            ret = ret .. " (l." .. line .. ")"
        end
    end
    cached_name = '"'..ret..'"'
    name_cache[name] = cached_name
    return cached_name
end


local function generate_json(value, indent)
    indent = indent or 0
    local indentation = string.rep(" ", indent)
    local json_parts = {}

    local function escape_string(str)
        return string.format("%q", str):gsub("\\\n", "\\n") -- Clean up newline
    end

    if type(value) == "string" then
        return escape_string(value)
    elseif type(value) == "number" then
        return tostring(value)
    elseif type(value) == "boolean" then
        return tostring(value)
    elseif type(value) == "nil" then
        return "null"
    elseif type(value) ~= "table" then
        error("Unsupported type: " .. type(value))
    end

    if utils.is_array(value) then
        table.insert(json_parts, "[\n")
        for i, v in ipairs(value) do
            if i > 1 then table.insert(json_parts, ",\n") end
            table.insert(json_parts, indentation .. "  " .. generate_json(v, indent + 2))
        end
        table.insert(json_parts, "\n" .. indentation .. "]")
    else
        table.insert(json_parts, "{\n")
        local first = true
        for k, v in pairs(value) do
            if not first then table.insert(json_parts, ",\n") end
            first = false
            local key = escape_string(tostring(k))
            table.insert(json_parts, indentation .. "  " .. key .. ": " .. generate_json(v, indent + 2))
        end
        table.insert(json_parts, "\n" .. indentation .. "}")
    end

    return table.concat(json_parts)
end


utils.generate_json = generate_json


function utils.get_duration(dur, timeunit)
    if timeunit and timeunit ~= "ns" then
        return convert.time(dur, "ns", timeunit)
    end
    return dur
end

function utils.get_size(size, sizeunit)
    if sizeunit ~= "B" then
        return convert.bytes(size, "B", sizeunit)
    end
    return size
end

function utils.is_gpu_domain(domain)
    return ratelprof.consts._GPU_DOMAIN[domain]
end

function utils.label_unit_with_rank(key, with_unit_label)
    local rank = key.rank or -1

    local unit, label
    if key.gpu_id then
        unit = key.gpu_id
        label = with_unit_label and "GPU " or ""
    elseif key.pid then
        unit = key.pid
        label = with_unit_label and "PID " or ""
    else
        unit = "??"
        label = with_unit_label and "??" or ""
    end

    if rank == -1 then
        return label .. tostring(unit)
    end

    return string.format("%s%s ( rank %d )", label, unit, rank)
end



function utils.json_to_js(filename, varname, output)
    -- read JSON
    local f = ratelprof.fs.open_file(filename, "r")
    local content = f:read("*all")
    f:close()

    -- write prefixed JS
    output = output or ratelprof.fs.remove_extension(filename)..'.js'
    local f2 = ratelprof.fs.open_file(output, "w")
    f2:write(varname, "=", content, ";\n")
    f2:close()

    ratelprof.fs.rm(filename)

    return output
end

return utils