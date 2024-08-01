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
local gpu_all_data = data_parser.get_gpu_all_data_from(input_data)

local headers = {
    "\"Time (%)\"", 
    "\"Total Time (ns)\"", 
    "\"Instances\"", 
    "\"Avg (ns)\"", 
    "\"Med (ns)\"", 
    "\"Min (ns)\"", 
    "\"Max (ns)\"", 
    "\"StdDev (ns)\"",
    "\"Category\"",
    "\"Operation\"" 
}

local key_tab = {
    "domain",
    "name"
}

local output_data = statistics.get_output_summary(gpu_all_data, key_tab, metric_function)

table.sort(output_data, function(a, b)
    return common.sortByColumn(a, b, 2, ">", "int")
end)
table.insert(output_data, 1, headers)

csv.write(output_file, output_data)