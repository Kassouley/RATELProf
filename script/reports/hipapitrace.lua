package.path = package.path .. ';./script/?.lua'
package.path = package.path .. ';./script/json/?.lua'
local csv = require("csv")
local common = require("common")
local data_parser = require("BeTAProf_output_parser")

local function get_output_data(data)
    local output_data = {}

    for _, data in ipairs(data) do
        local entry = {
            tostring(data.beginNs),
            tostring(data.endNs - data.beginNs),
            tostring(data.name),
            tostring(data.corr_id),
            tostring(data.pid),
            tostring(data.tid)
        }
        local args = "\""
        for k, v in pairs(data.args) do
            if type(v) == "table" then
                args = args .. k .. "=[" .. table.concat(v, ", ") .. "]; "
            else
                args = args .. k .. "=" .. tostring(v).."; "
            end
        end

        args = args.."\""
        table.insert(entry, args)
        table.insert(output_data, entry)
    end
    return output_data
end

common.check_arg(arg)

local input_file = arg[1]
local output_file = arg[2]

local input_data = data_parser.load_data_from(input_file)
local api_hip_data = data_parser.get_api_hip_data_from(input_data)

local headers = {
    "\"Start (ns)\"", -- 1
    "\"Duration (ns)\"", -- 2
    "\"Name\"", -- 4
    "\"CorrId\"", -- 4
    "\"Pid\"", -- 5
    "\"Tid\"", -- 6
    "\"Args\"" -- 7
}

local output_data = get_output_data(api_hip_data)

table.sort(output_data, function(a, b)
    return common.sortByColumn(a, b, 4, "<", "int")
end)

table.insert(output_data, 1, headers)

csv.write(output_file, output_data)
