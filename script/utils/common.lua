local common = {}

local json = require("json")

function common.load_json(__input_path__)
    if __input_path__ == nil then
        error ("Missing JSON input file")
        return nil
    end
    local infile = io.open (__input_path__, "r")
    if infile == nil then
        error ("JSON input file "..__input_path__.." can't be opened")
        return nil
    end
    local data = infile:read ("*a")
    infile:close ()
    return JSON:decode(data)
end

return common