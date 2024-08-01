package.path = package.path .. ';./script/?.lua'
package.path = package.path .. ';./script/json/?.lua'
local csv = require("csv")
local common = require("common")
local data_parser = require("BeTAProf_output_parser")
local statistics = require("statistics")

local function hex_to_mb(hex_string)
    local hex_value = hex_string:sub(3)
    local bytes = tonumber(hex_value, 16)
    local mb = bytes / (1024 * 1024)
    return mb
end


local function metric_function(trace)
    return hex_to_mb(trace.args.bytes)
end

common.check_arg(arg)

local input_file = arg[1]
local output_file = arg[2]

local input_data = data_parser.load_data_from(input_file)
local gpu_mem_data = data_parser.get_gpu_mem_data_from(input_data)

local headers = {
    "\"Total (%)\"", 
    "\"Total (MB)\"", 
    "\"Count\"", 
    "\"Avg (MB)\"", 
    "\"Med (MB)\"", 
    "\"Min (MB)\"", 
    "\"Max (MB)\"", 
    "\"StdDev (MB)\"",
    "\"Operation\"" 
}

local output_data = statistics.get_output_summary(gpu_mem_data, {"name"}, metric_function)

table.sort(output_data, function(a, b)
    return common.sortByColumn(a, b, 2, ">", "int")
end)
table.insert(output_data, 1, headers)

csv.write(output_file, output_data)

