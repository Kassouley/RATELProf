local FileStructure = {}

function FileStructure:__tostring()
    return self._root .. (self._prefix or "")
end

FileStructure.__index = function(self, key)
    if FileStructure[key] then
        return FileStructure[key]
    end

    local value = self._structure[key]
    if not value then return nil end

    if type(value) == "table" then
        -- directory node
        return setmetatable({
            _root = self._root,
            _structure = value,
            _prefix = (self._prefix and self._prefix .. "/" .. key) or key
        }, FileStructure)
    elseif type(value) == "string" then
        -- file node
        return setmetatable({
            _root = self._root,
            _structure = nil,  -- indicates a file
            _prefix = (self._prefix and self._prefix .. "/" .. value) or value
        }, FileStructure)
    end
end

-- constructor
function FileStructure.new(root, structure)
    return setmetatable({
        _root = root,
        _structure = structure,
        _prefix = ""
    }, FileStructure)
end

function FileStructure:path()
    return self:__tostring()
end

-- generate directories/files
function FileStructure:generate()
    local function walk(tbl, prefix)
        for k, v in pairs(tbl) do
            if type(v) == "table" then
                local dir_path = self._root .. "/" .. ((prefix and prefix .. "/" .. k) or k)
                ratelprof.fs.mkdir(dir_path)
                walk(v, (prefix and prefix .. "/" .. k) or k)
            elseif type(v) == "string" then
                local full_path = self._root .. "/" .. ((prefix and prefix .. "/" .. v) or v)
                local dir = full_path:match("(.+)/[^/]+$")
                if dir then ratelprof.fs.mkdir(dir) end
                local f = ratelprof.fs.open_file(full_path, "w")
                if f then f:close() end
            end
        end
    end
    ratelprof.fs.mkdir(self._root)
    walk(rawget(self, "_structure"), "")
end

-- write method for file nodes
function FileStructure:write(...)
    if rawget(self, "_structure") then
        error("Cannot write to a directory node")
    end

    local path = self._root .. "/" .. (self._prefix or "")
    local dir = path:match("(.+)/[^/]+$")
    if dir then ratelprof.fs.mkdir(dir) end

    local f = ratelprof.fs.open_file(path, "w")
    f:write(...)
    f:close()
    return true
end

return FileStructure