package.path = package.path .. ';./script/?.lua'
package.path = package.path .. ';./script/json/?.lua'
local csv = require("csv")
local common = require("common")
local data_parser = require("BeTAProf_output_parser")
local statistics = require("statistics")

local function metric_function(trace)
    return trace.gpu_data.endNs - trace.gpu_data.beginNs
end

common.check_arg(arg)

local input_file = arg[1]
local output_file = arg[2]

local input_data = data_parser.load_data_from(input_file)
local gpu_kern_data = data_parser.get_gpu_kern_data_from(input_data)
local all_api_data = data_parser.get_api_all_data_from(input_data)
local correlated_traces = data_parser.get_correlated_data_from(gpu_kern_data, all_api_data)

local headers = {
    "\"Time (%)\"", 
    "\"Total Time (ns)\"", 
    "\"Instances\"", 
    "\"Avg (ns)\"", 
    "\"Med (ns)\"", 
    "\"Min (ns)\"", 
    "\"Max (ns)\"", 
    "\"StdDev (ns)\"",
    "\"GridX\"", 
    "\"GridY\"", 
    "\"GridZ\"", 
    "\"BlockX\"", 
    "\"BlockY\"", 
    "\"BlockZ\"", 
    "\"Name\"" 
}

local key_tab = {
    "api_data.args.grd[1]",
    "api_data.args.grd[2]",
    "api_data.args.grd[3]",
    "api_data.args.blk[1]",
    "api_data.args.blk[2]",
    "api_data.args.blk[3]",
    "gpu_data.name"
}

local output_data = statistics.get_output_summary(correlated_traces, key_tab, metric_function)

table.sort(output_data, function(a, b)
    return common.sortByColumn(a, b, 2, ">", "int")
end)
table.insert(output_data, 1, headers)

csv.write(output_file, output_data)
