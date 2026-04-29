-- rfs.lua
local rfs = require("fileutils")

--- Opens a file with the specified mode after normalizing its path.
-- @param filename The name of the file to open as a string.
-- @param mode The mode in which to open the file (e.g., "r" for read, "w" for write).
-- @param ext Optional, check if the filename has the correct extension.
-- @return A file handle if the file is opened successfully, otherwise raises an error.
function rfs.open_file(filename, mode, ext)
    if filename == nil or type(filename) ~= "string" then
        error ("Error: Missing input file")
    end
    if ext and not rfs.has_extension (filename, ext) then
        error ("Error: The input file is not a '"..ext.."' file")
    end
    
    local dirname = rfs.dirname(filename)
    if dirname and dirname ~= "" and not rfs.exists(dirname) then
        rfs.mkdir(dirname)
    end

    local file = io.open(filename, mode)
    if not file then
        error ("Error: Unable to open file " .. filename)
    end
    return file
end

return rfs