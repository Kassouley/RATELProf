require("utils.json.json")

local utils = {}


function utils.print_progress(prefix, current, total)
    local bar_length = 30
    local progress = math.floor((current / total) * bar_length)
    local bar = string.rep("=", progress) .. string.rep(" ", bar_length - progress)
    io.write(string.format("\r%-20s [%s] %d/%d", prefix, bar, current, total))
    if current == total then io.write("\n") end
    io.flush()
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

-- function utils.merge_tab(t1, ...)
--     for _, t in ipairs({...}) do
--         for _, value in pairs(t) do
--             table.insert(t1, value)
--         end
--     end
--     return t1
-- end

function utils.is_integer(n)
  return n == math.floor(n)
end

function utils.check_report_file(report_file)
    if not ratelprof.fs.exists(report_file) then
        Message:error("Report '"..report_file.."' doesn't exists.")
        os.exit(1)
    end
    if not ratelprof.fs.has_extension(report_file, ratelprof.consts._REPORT_EXT) then
        Message:error("Report '"..report_file.."' is not a "..ratelprof.consts._REPORT_EXT.." file.")
        os.exit(1)
    end
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

function utils.get_kernel_name(name, is_trunc, is_mangled)
    local mangled_name, line = name:match(omp_pattern)
    local ret = name
    if not is_mangled then
        if mangled_name then
            name = mangled_name
        end
        if is_trunc then
            ret = utils.execute_command("c++filt --no-params ".. name)
        else
            ret = utils.execute_command("c++filt ".. name)
        end
        if line then
            ret = ret .. " (l." .. line .. ")"
        end
    end
    return '"'..ret..'"'
end


local _MEM_KIND = {"Host", "Device"}

function utils.get_copy_name_from_kind(kind)
    return _MEM_KIND[kind+1]
end

local get_name = utils.get_copy_name_from_kind

function utils.get_copy_name(src, dst)
    return ("Copy%sTo%s"):format(get_name(src), get_name(dst))
end

local function generate_json(value, indent)
    indent = indent or 0
    local indentation = string.rep(" ", indent)
    local json_parts = {}

    if type(value) ~= "table" then
        if type(value) == "string" then
            return string.format("%q", value) -- Escape strings for JSON
        else
            return string.format("%.0f", value)
        end
    end

    -- Check if the table is an array (has sequential numeric indices)
    local is_array = true
    local count = 0
    for k, _ in pairs(value) do
        count = count + 1
        if type(k) ~= "number" or k ~= count then
            is_array = false
            break
        end
    end

    if is_array then
        -- Handle JSON list (array)
        table.insert(json_parts, "[\n")
        for i, v in ipairs(value) do
            if i > 1 then
                table.insert(json_parts, ",\n")
            end
            table.insert(json_parts, indentation .. "  " .. generate_json(v, indent + 2))
        end
        table.insert(json_parts, "\n" .. indentation .. "]")
    else
        -- Handle JSON object
        table.insert(json_parts, "{\n")
        local first = true
        for k, v in pairs(value) do
            if not first then
                table.insert(json_parts, ",\n")
            end
            first = false

            local key = tostring(k)
            if type(k) == "string" then
                key = string.format("%q", k) -- Escape string keys
            end

            table.insert(json_parts, indentation .. "  " .. key .. ": " .. generate_json(v, indent + 2))
        end
        table.insert(json_parts, "\n" .. indentation .. "}")
    end

    return table.concat(json_parts)
end

utils.generate_json = generate_json

return utils