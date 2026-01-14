---
-- Entry Class
---
local Entry = {}
Entry.__index = Entry

-- Constructor
function Entry.new(key, start, stop)
    local self = setmetatable({}, Entry)
    self.key = key
    self.curr_start = start
    self.curr_stop = stop
    self.active_time = 0
    return self
end

function Entry:update(start, stop)
    if start <= self.curr_stop then
        if stop > self.curr_stop then
            self.curr_stop = stop
        end
    else
        self.active_time = self.active_time + (self.curr_stop - self.curr_start)
        self.curr_start = start
        self.curr_stop = stop
    end
end


function Entry:compute_active_time()
    self.active_time = self.active_time + (self.curr_stop - self.curr_start)
    self.curr_start = 0
    self.curr_stop = 0
    return self.active_time
end

function Entry:compute_active_percentage(total_analyzed_time)
    return string.format("%.2f", (self:compute_active_time() / total_analyzed_time) * 100)
end


---
-- Timewise Class
---
local Timewise = {}
Timewise.__index = Timewise

-- Constructor
function Timewise.new()
    local self = setmetatable({}, Timewise)
    self.entries = {}
    self.active_time = 0
    self.curr_start = nil
    self.curr_stop  = nil
    return self
end

-- Process a single trace and update entries
function Timewise:add_entry(keys, start, stop)
    local entry = self.entries[keys.str]

    if not entry then
        entry = Entry.new(keys.values, start, stop)
        self.entries[keys.str] = entry
    end

    entry:update(start, stop)
    self:update(start, stop)

end

function Timewise:update(start, stop)
    if not self.curr_start or not self.curr_stop then
        self.curr_start = start
        self.curr_stop = stop
    elseif start <= self.curr_stop then
        if stop > self.curr_stop then
            self.curr_stop = stop
        end
    else
        self.active_time = self.active_time + (self.curr_stop - self.curr_start)
        self.curr_start = start
        self.curr_stop = stop
    end
end

function Timewise:compute_active_time()
    self.active_time = self.active_time + (self.curr_stop - self.curr_start)
    self.curr_start = 0
    self.curr_stop = 0
    return self.active_time
end

function Timewise:for_each_entry(callback)
    for key, entry in pairs(self.entries) do
        callback(key, entry)
    end
end

return Timewise
