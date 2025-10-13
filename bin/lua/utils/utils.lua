require("utils.json.json")

local utils = {}

utils.demangle = require ("demangle").demangle

function utils.compute_total_covered_duration(...)
    local intervals = {}
    local count = 0
    
    -- Step 1: Flatten all traces from each argument into intervals array
    local args = {...}
    for _, traces in ipairs(args) do
        for _, t in pairs(traces) do
            count = count + 1
            intervals[count] = {start = t.start, stop = t.start + t.dur}
        end
    end

    if count == 0 then return 0 end

    -- Step 2: Sort by start time
    table.sort(intervals, function(a, b)
        return a.start < b.start
    end)

    -- Step 3: Merge intervals and compute total
    local total = 0
    local cur_start = intervals[1].start
    local cur_stop = intervals[1].stop

    for i = 2, count do
        local s = intervals[i].start
        local e = intervals[i].stop

        if s <= cur_stop then
            if e > cur_stop then
                cur_stop = e
            end
        else
            total = total + (cur_stop - cur_start)
            cur_start = s
            cur_stop = e
        end
    end

    total = total + (cur_stop - cur_start)
    return total
end


-- Function to print memory usage in GB only if it changes (2 decimal digits)
function utils.print_mem_usage(suffix, old_value)

    -- Get memory in GB
    local memory_gb = collectgarbage("count") / (1024 * 1024)

    -- Round to 2 decimal places
    local memory_rounded = math.floor(memory_gb * 100 + 0.5) / 100

    -- Compare with old value
    if memory_rounded ~= old_value then
        io.write(string.format("\rMemory usage: %.2f GB%s", memory_rounded, suffix or ""))
        io.flush()  -- Ensure immediate print
        return memory_rounded
    else
        return old_value
    end
end


function utils.print_progress(current, total, prefix, suffix)
    prefix = prefix or ""
    suffix = suffix or ""
    local bar_length = 30
    local progress = math.floor((current / total) * bar_length)
    local bar = string.rep("=", progress) .. string.rep(" ", bar_length - progress)
    io.write(string.format("\r%-20s [%s] %d/%d %-30s", prefix, bar, current, total, suffix))
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


function utils.check_report_files(files, skip_on_check)
    local valid_files = {}

    local function error_and_handle(msg)
        if skip_on_check then
            Message:error(msg .. " (Skipping.)")
        else
            Message:error(msg)
            os.exit(1)
        end
    end

    for _, file in ipairs(files) do
        if not ratelprof.fs.exists(file) then
            error_and_handle("Report '" .. file .. "' doesn't exist.")
        elseif not ratelprof.fs.has_extension(file, ratelprof.consts._REPORT_EXT) then
            error_and_handle("Report '" .. file .. "' is not a ." .. ratelprof.consts._REPORT_EXT .. " file.")
        else
            table.insert(valid_files, file)
        end
    end

    if #valid_files == 0 then
        Message:error("No valid report files provided. Stopping...")
        os.exit(1)
    end

    return valid_files
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


local _MEM_KIND = {"Host", "Device"}

function utils.get_copy_name_from_kind(kind)
    return _MEM_KIND[kind+1]
end

local get_name = utils.get_copy_name_from_kind

function utils.get_copy_name(src, dst)
    return ("Copy%sTo%s"):format(get_name(src), get_name(dst))
end

function utils.get_copy_name_from_trace(trace)
    return utils.get_copy_name(trace.args.src_type, trace.args.dst_type)
end


function utils.get_gpu_id(trace, traces_data)
    local gpu_agent = trace.args.gpu_id
    if not gpu_agent then
        if trace.args.dst_type == 1 then gpu_agent = trace.args.dst_agent
        elseif trace.args.src_type == 1 then gpu_agent = trace.args.src_agent
        else error ("shouldn't reach, a gpu trace need to have a gpu agent")
        end
    end
    return traces_data:get_gpu_id(gpu_agent)
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

return utils