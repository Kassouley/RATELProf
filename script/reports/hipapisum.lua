package.path = package.path .. ';./script/?.lua'
package.path = package.path .. ';./script/json/?.lua'
local csv = require("csv")
local common = require("common")
local data_parser = require("BeTAProf_output_parser")
local statistics = require("statistics")

local function metric_function(trace)
    return trace.endNs - trace.beginNs
end

common.check_arg(arg)

local input_file = arg[1]
local output_file = arg[2]

local input_data = data_parser.load_data_from(input_file)
local api_data = data_parser.get_api_hip_data_from(input_data)

local headers = {
    "\"Time (%)\"", -- 1
    "\"Total Time (ns)\"", -- 2 
    "\"Num Calls\"", -- 3
    "\"Avg (ns)\"", -- 4
    "\"Med (ns)\"", -- 5
    "\"Min (ns)\"", -- 6
    "\"Max (ns)\"", -- 7
    "\"StdDev (ns)\"", -- 8
    "\"Name\"" -- 9
}

local output_data = statistics.get_output_summary(api_data, {"name"}, metric_function)

table.sort(output_data, function(a, b)
    return common.sortByColumn(a, b, 2, ">", "int")
end)
table.insert(output_data, 1, headers)

csv.write(output_file, output_data)

