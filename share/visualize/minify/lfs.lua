-- lfs.lua
local lfs = {}

--- Substitutes environment variables in a string.
-- Replaces occurrences of `$VAR` in the string with the corresponding environment variable.
-- @param str The string containing environment variables.
-- @return The string with environment variables substituted.
local function sub_env_var(p)
    return p:gsub("%$([%w_]+)", function(env_var)
        return os.getenv(env_var) or ""
    end)
end

--- Normalizes the path separators in a file path to use forward slashes.
-- Converts all backslashes (`\`) in the provided path to forward slashes (`/`).
-- @param p The file path as a string.
-- @return The normalized file path with forward slashes.
local function normalize_path_separator(p)
    return p:gsub("\\", "/")
end

--- Processes a file path by substituting environment variables and normalizing separators.
-- This function expands any environment variables in the path and converts backslashes to forward slashes.
-- @param p The file path as a string.
-- @return The processed and normalized file path.
local function get_path(p)
    p = sub_env_var(p)
    p = normalize_path_separator(p)
    return p
end

--- Cleans and normalizes a file path for consistent usage.
-- This function is a public interface for `get_path`.
-- @param p The file path as a string.
-- @return The cleaned and normalized file path.
function lfs.get_cleaned_path(p)
    return get_path(p)
end

--- Opens a file with the specified mode after normalizing its path.
-- This function ensures the provided file path is cleaned before attempting to open the file.
-- @param filename The name of the file to open as a string.
-- @param mode The mode in which to open the file (e.g., "r" for read, "w" for write).
-- @return A file handle if the file is opened successfully, otherwise raises an error.
function lfs.open_file(filename, mode)
    if filename == nil then
        error("Missing input file")
        return nil
    end
    filename = get_path(filename)
    local file = io.open(filename, mode)
    if not file then
        error("Error: Unable to open file " .. filename)
        return nil
    end
    return file
end

--- Requires a Lua module from a specific file lfs.
-- Loads and executes a Lua file from the given path, allowing dynamic module loading.
-- @param p The file path of the Lua module to load.
-- @return The result of the module execution.
function lfs.require_from_path(p)
    p = get_path(p)
    return assert(loadfile(p))()
end


-- Concatenates multiple path segments into a single path
-- @param ... Variable number of path segments
-- @return The concatenated path
function lfs.concat_path(...)
    local segments = {...}
    local result = {}
    
    for _, segment in ipairs(segments) do
        segment = get_path(segment)
        -- Remove trailing slash from each segment except the last one
        if segment:sub(-1) == "/" then
            segment = segment:sub(1, -2)
        end
        if #result > 0 and segment:sub(1, 1) == "/" then
            segment = segment:sub(2)
        end
        table.insert(result, segment)
    end

    -- Join all segments with a single slash
    return table.concat(result, "/")
end

--- Copies a file from source to destination using the cp command.
-- @param src The source file path.
-- @param dest The destination file path.
-- @return True if the file was copied successfully, false otherwise.
function lfs.copy_file(src, dest)
    local command = string.format('cp "%s" "%s"', src, dest)
    local success = os.execute(command)
    return success == 0
end

-- Gets the base name (file name) from a path
-- @param p The path
-- @return The base name
function lfs.basename(p)
    p = get_path(p)
    return p:match("([^/]+)$") or nil
end

--- Splits a file path into its directory and filename components.
-- @param filepath The file path to split.
-- @return The directory part and the filename part of the file lfs.
function lfs.split_path(p)
    p = get_path(p)
    local dir, file = string.match(p, "(.-)([^\\/]-%.?[^%.\\/]*)$")
    return dir, file
end

--- Checks if a filename has a specific extension.
-- @param filename The filename to check.
-- @param ext The extension to check for.
-- @return `true` if the filename has the specified extension, `false` otherwise.
function lfs.has_extension(p, ext)
    p = get_path(p)
    return p:sub(-#ext) == ext
end

-- Removes the specified file extension from a path
-- @param p The path
-- @param ext The file extension to remove (including the dot, e.g., ".txt"). Optional.
-- @return The path without the specified extension
function lfs.remove_extension(p, ext)
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
function lfs.dirname(p)
    p = get_path(p)
    return p:match("^(.-)[/\\][^/\\]*$") or ""
end

-- Joins a base path with a relative path
-- @param base The base path
-- @param relative The relative path
-- @return The joined path
function lfs.join(base, relative)
    base = get_path(base)
    relative = get_path(relative)
    
    if relative:sub(1, 1) == "/" then
        return relative
    end
    
    return lfs.concat_path(base, relative)
end

-- Returns whether a given path is absolute
-- @param p The path
-- @return true if the path is absolute, false otherwise
function lfs.is_absolute(p)
    p = get_path(p)
    return p:sub(1, 1) == "/" or p:match("^[A-Za-z]:\\")
end

--- Checks if a given path is a directory using system commands.
-- @param p The path to check.
-- @return True if the path is a directory, false otherwise.
function lfs.is_dir(p)
    p = get_path(p)
    local command = 'test -d "' .. p .. '"'
    return os.execute(command)
end


--- Checks if a given path is a file using system commands.
-- @param p The path to check.
-- @return True if the path is a file, false otherwise.
function lfs.is_file(p)
    p = get_path(p)
    local command = 'test -f "' .. p .. '"'
    return os.execute(command)
end
--- Creates a directory, including any necessary parent directories.
-- @param dirname The name of the directory to create.
function lfs.mkdir(p)
    p = get_path(p)
    local dirname = get_path(p)
    os.execute("mkdir -p \"" .. dirname .. "\"")
end

--- Checks if a file exists.
-- @param name The name of the file to check.
-- @return `true` if the file exists, `false` otherwise.
function lfs.file_exists(p)
    p = get_path(p)
    local file = get_path(p)
    if type(file) ~= "string" then return false end
    return os.rename(file, file) and true or false
end


--- Scans a directory and returns a list of files.
-- @param p The directory to scan.
-- @param type_flag File type flag for find command (nothing for any file types, f for files, d for directories).
-- @return A table containing the names of files or directories based on type_flag.
function lfs.scanfile(p, type_flag, maxdepth)
    maxdepth = maxdepth and "-maxdepth "..tostring(maxdepth) or ""
    type_flag = type_flag and '-type "'..type_flag..'"' or ""
    local dir = get_path(p)
    local result = {}
    local command = string.format('find "%s" %s %s', dir, maxdepth, type_flag)
    for line in io.popen(command):lines() do
        if line ~= dir then
            table.insert(result, line)
        end
    end
    
    return result
end

--- Retrieves the file path of the Lua script at the specified stack level.
-- This function uses the debug library to determine the source file of the caller.
-- It is commonly used to get the directory or file path of the current script.
-- @param level (optional) The stack level to inspect. Defaults to 1 level up from this function's own call.
-- @return The file path of the script at the specified stack level, or nil if not found.

function lfs.get_script_path(level)
    level = (level or 0) + 1  -- Default to 1 level up, adding 1 for this function itself
    local info = debug.getinfo(level, "S")
    local path = info and info.source:match("@(.*)$")  -- Extract file path if info exists
    return path and path:match("(.*/)") or "./"  -- Extract directory from path
end

return lfs

-- Example usage
-- local p = lfs.concat_path("folder", "subfolder", "file.txt")
-- print(p) -- Outputs: folder/subfolder/file.txt
-- print(lfs.basename(p)) -- Outputs: file.txt
-- print(lfs.remove_extension(p)) -- Outputs: folder/subfolder/file
-- print(lfs.dirname(p)) -- Outputs: folder/subfolder
-- print(lfs.join("folder", "file.txt")) -- Outputs: folder/file.txt
-- print(lfs.is_absolute("/folder/file.txt")) -- Outputs: true
-- print(lfs.is_absolute("folder/file.txt")) -- Outputs: false