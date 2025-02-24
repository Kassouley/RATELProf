local lfs = require("utils.lfs")

local merge_json = {}

local function minify(json_content)
    return json_content:gsub("%s+", " ")
end

function merge_json.get_json_data(json_path)
    local content = nil
    local file = lfs.open_file(json_path, "r")
    content = file:read("*all")
    file:close()
    return minify(content)
end

return merge_json