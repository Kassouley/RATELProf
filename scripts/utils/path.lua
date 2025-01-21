-- path.lua

local path = {}
path.__index = path

-- Substitutes environment variables in a string
local function sub_env_var(p)
    return p:gsub("%$([%w_]+)", function(env_var)
        return os.getenv(env_var) or ""
    end)
end
-- Utility function to normalize path separators
local function normalize_path_separator(p)
    return p:gsub("\\", "/")
end

local function get_path(p)
    p = sub_env_var(p)
    p = normalize_path_separator(p)
    return p
end


function path.require_from_path(file_path)
    local file_path = sub_env_var(file_path)
    return assert(loadfile(file_path))()
end


-- Concatenates multiple path segments into a single path
-- @param ... Variable number of path segments
-- @return The concatenated path
function path.concat(...)
    local segments = {...}
    local result = {}
    
    for _, segment in ipairs(segments) do
        segment = get_path(segment)
        -- Remove trailing slash from each segment except the last one
        if #result > 0 and segment:sub(-1) == "/" then
            segment = segment:sub(1, -2)
        end
        table.insert(result, segment)
    end

    -- Join all segments with a single slash
    return table.concat(result, "/")
end

-- Gets the base name (file name) from a path
-- @param p The path
-- @return The base name
function path.basename(p)
    p = get_path(p)
    return p:match("([^/]+)$") or ""
end


-- Removes the specified file extension from a path
-- @param p The path
-- @param ext The file extension to remove (including the dot, e.g., ".txt"). Optional.
-- @return The path without the specified extension
function path.remove_extension(p, ext)
    p = get_path(p)
    if ext then
        if not ext:match("^%.") then
            ext = "." .. ext
        end
        if p:sub(-#ext) == ext then
            return p:sub(1, -#ext - 1)
        end
    else
        -- Remove the extension if no specific one is given
        local base_name = p:match("^(.-)%.[^.]*$")
        if base_name then
            return base_name
        end
    end
    return p
end

-- Gets the directory name from a path
-- @param p The path
-- @return The directory name
function path.dirname(p)
    p = get_path(p)
    return p:match("^(.-)[/\\][^/\\]*$") or ""
end

-- Joins a base path with a relative path
-- @param base The base path
-- @param relative The relative path
-- @return The joined path
function path.join(base, relative)
    base = get_path(base)
    relative = get_path(relative)
    
    if relative:sub(1, 1) == "/" then
        return relative
    end
    
    return path.concat(base, relative)
end

-- Returns whether a given path is absolute
-- @param p The path
-- @return true if the path is absolute, false otherwise
function path.is_absolute(p)
    p = get_path(p)
    return p:sub(1, 1) == "/" or p:match("^[A-Za-z]:\\")
end


-- Creates a directory, including any necessary parent directories
function path.mkdir(p)
    local dirname = get_path(p)
    os.execute("mkdir -p \"" .. dirname .. "\"")
end

-- Checks if a file exists
function path.file_exists(p)
    local file = get_path(p)
    if type(file) ~= "string" then return false end
    return os.rename(file, file) and true or false
end

-- Scans a directory and returns a list of files
function path.scanfile(p)
    local dir = get_path(p)
    local files = {}
    local command = "find \"" .. dir .. "\" -maxdepth 1 -type f"
    for line in io.popen(command):lines() do
        if line ~= dir then
            table.insert(files, line:match("[^/]+$"))
        end
    end
    return files
end

function path.get_script_dir(level)
    level = (level or 0) + 1  -- Default to 1 level up, adding 1 for this function itself
    local info = debug.getinfo(level, "S")
    local path = info and info.source:match("@(.*)$")  -- Extract file path if info exists
    return path and path:match("(.*/)") or "./"       -- Extract directory from path or return "./" as default
end


-- Example usage
-- local p = path.concat("folder", "subfolder", "file.txt")
-- print(p) -- Outputs: folder/subfolder/file.txt
-- print(path.basename(p)) -- Outputs: file.txt
-- print(path.remove_extension(p)) -- Outputs: folder/subfolder/file
-- print(path.dirname(p)) -- Outputs: folder/subfolder
-- print(path.join("folder", "file.txt")) -- Outputs: folder/file.txt
-- print(path.is_absolute("/folder/file.txt")) -- Outputs: true
-- print(path.is_absolute("folder/file.txt")) -- Outputs: false

return path
