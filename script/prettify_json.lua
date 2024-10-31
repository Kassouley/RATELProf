-- prettify_json.lua

local function get_traces(__input_path__)
    local file, err = io.open(__input_path__, "r")
    if not file then
        error("Could not open file: " .. err)
    end

    local traces = {
        hsaTraces = {},
        hipTraces = {},
        memoryTraces = {},
        kernelTraces = {}
    }

    for line in file:lines() do
        local key, modifiedLine
        if line:find('"d":0,') then
            key, modifiedLine = "hsaTraces", "\t\t\t" .. line:gsub('"d":0,', '')
        elseif line:find('"d":1,') then
            key, modifiedLine = "hipTraces", "\t\t\t" .. line:gsub('"d":1,', '')
        elseif line:find('"d":16,') then
            key, modifiedLine = "memoryTraces", "\t\t\t" .. line:gsub('"d":16,', '')
        elseif line:find('"d":17,') then
            key, modifiedLine = "kernelTraces", "\t\t\t" .. line:gsub('"d":17,', '')
        end

        if key then
            table.insert(traces[key], modifiedLine)
        end
    end
    file:close()

    for k, v in pairs(traces) do
        traces[k] = table.concat(v, ",\n")
    end

    return traces
end

-- Main script logic
local function main()
    local __input_path__ = arg[1]
    if not __input_path__ then
        error("Input file path not specified. Usage: lua " .. arg[0] .. " <input_file_path>")
    end

    local traces = get_traces(__input_path__)
    local traceEvents = {}

    for k, v in pairs(traces) do
        if v == "" then
            table.insert(traceEvents, '\t\t"' .. k .. '": []')
        else
            table.insert(traceEvents, '\t\t"' .. k .. '": [\n' .. v .. '\n\t\t]')
        end
    end

    local json = "{\n\t\"traceEvents\": {\n" .. table.concat(traceEvents, ",\n") .. "\n\t}\n}"
    
    local output_path = "output.json" 
    local outputFile, err = io.open(output_path, "w")
    if not outputFile then
        error("Could not open output file: " .. err)
    end
    outputFile:write(json)
    outputFile:close()
end

-- Run the main function
main()
