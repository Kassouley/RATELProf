package.path = package.path .. ';./script/?.lua'
package.path = package.path .. ';./script/json/?.lua'
local csv = require("csv")
local common = require("common")
local data_parser = require("BeTAProf_output_parser")

local function get_copy_dst_from_kind(memCpyKind)
    if memCpyKind == 1 then
        return "Device"
    elseif memCpyKind == 2 then
        return "Host"
    else
        return "Unknown"
    end
end

local function get_copy_src_from_kind(memCpyKind)
    if memCpyKind == 1 then
        return "Host"
    elseif memCpyKind == 2 then
        return "Device"
    else
        return "Unknown"
    end
end

local function get_output_data(correlated_data)
    local output_data = {}

    for _, data in ipairs(correlated_data) do
        local gpu_data = data.gpu_data
        local api_data = data.api_data
        local entry = {
            tostring(gpu_data.beginNs),
            tostring(gpu_data.endNs - gpu_data.beginNs),
            tostring(gpu_data.corr_id),
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            tostring(gpu_data.device_id),
            tostring(gpu_data.queue_id),
            tostring(api_data.args.stream),
            tostring(gpu_data.name)
        }

        if gpu_data.domain == 0 then
            entry[4] = tostring(api_data.args.grd[1])
            entry[5] = tostring(api_data.args.grd[2])
            entry[6] = tostring(api_data.args.grd[3])
            entry[7] = tostring(api_data.args.blk[1])
            entry[8] = tostring(api_data.args.blk[2])
            entry[9] = tostring(api_data.args.blk[3])
            entry[10] = tostring(api_data.args.shrdMem)
        elseif gpu_data.domain == 1 then
            entry[11] = tostring(gpu_data.args.bytes / 1024 / 1024)
            entry[12] = tostring(entry[11] / (entry[2] / 1e-9))
            entry[13] = get_copy_src_from_kind(api_data.args.memCpyKind)
            entry[14] = get_copy_dst_from_kind(api_data.args.memCpyKind)
        end

        table.insert(output_data, entry)
    end
    return output_data
end

common.check_arg(arg)

local input_file = arg[1]
local output_file = arg[2]

local input_data = data_parser.load_data_from(input_file)
local api_data = data_parser.get_api_all_data_from(input_data)
local gpu_data = data_parser.get_gpu_all_data_from(input_data)
local correlated_traces = data_parser.get_correlated_data_from(gpu_data, api_data)

local headers = {
    "\"Start (ns)\"", -- 1
    "\"Duration (ns)\"", -- 2
    "\"CorrId\"", -- 3
    "\"GrdX\"", -- 4
    "\"GrdY\"", -- 5
    "\"GrdZ\"", -- 6
    "\"BlkX\"", -- 7
    "\"BlkY\"", -- 8
    "\"BlkZ\"", -- 9
    "\"SharedMem (MB)\"", -- 10
    "\"Bytes (MB)\"", -- 11
    "\"Throughput (MBps)\"", -- 12
    "\"SrcMemKd\"", -- 13
    "\"DstMemKd\"", -- 14
    "\"Device\"", -- 15
    "\"Queue\"", -- 16
    "\"Strm\"", -- 17
    "\"Name\"" -- 18
}
local output_data = get_output_data(correlated_traces)

table.sort(output_data, function(a, b)
    return common.sortByColumn(a, b, 3, "<", "int")
end)

table.insert(output_data, 1, headers)

csv.write(output_file, output_data)
