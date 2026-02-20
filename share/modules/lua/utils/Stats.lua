
-- Time Conversion Functions
local units = { ns = 1, us = 1e3, ms = 1e6, sec = 1e9, B = 1, KB = 1024, MB = 1024*1024, GB = 1024*1024*1024 }
local function convert(value, to_unit)
    if not to_unit then return value end
    return value / units[to_unit]
end


---
-- Entry Class
---
local Entry = {}
Entry.__index = Entry

-- Constructor
function Entry.new(key)
    local self = setmetatable({}, Entry)
    self.key = key
    self.metrics = {}
    self.is_sorted = true
    self.metrics_count = 0
    self.metrics_sum = 0
    self.sum_of_squares = 0
    -- self.min = math.huge
    -- self.max = 0

    self.subkey_min_val = math.huge
    self.subkey_max_val = 0
    self.subkey_min_key = nil
    self.subkey_max_key = nil
    self.per_subkey_total = {}
    return self
end

function Entry:compute_metric_count()
    return self.metrics_count
end

function Entry:compute_total_metric(to_unit)
    return convert(self.metrics_sum, to_unit)
end

function Entry:compute_max(to_unit)
    local metrics = self.metrics
    if not self.is_sorted then table.sort(metrics) end
    return convert(metrics[self.metrics_count], to_unit)
    -- return self.max
end

function Entry:compute_min(to_unit)
    local metrics = self.metrics
    if not self.is_sorted then table.sort(metrics) end
    return convert(metrics[1], to_unit)
    -- return self.min
end

function Entry:compute_med(to_unit)
    if not self.is_sorted then table.sort(self.metrics) end
    local count = self.metrics_count
    local mid_i = math.floor((count + 1) / 2)
    local med = -1
    if count % 2 == 0 then
        med = (self.metrics[mid_i] + self.metrics[mid_i + 1]) / 2
    else
        med = self.metrics[mid_i]
    end
    return convert(med, to_unit)
end

function Entry:compute_avg(to_unit)
    return convert(self.metrics_sum / self.metrics_count, to_unit)
end

function Entry:compute_stddev(to_unit)
    local mean = self:compute_avg()
    local variance = (self.sum_of_squares / self.metrics_count) - (mean * mean)
    local stdDev = math.sqrt(math.max(variance, 0))
    return convert(stdDev, to_unit)
end

function Entry:update(metric)
    local metrics = self.metrics
    local count = self.metrics_count + 1
    self.metrics_count = count

    self.metrics_sum    = self.metrics_sum + metric
    self.sum_of_squares = self.sum_of_squares + metric * metric

    -- self.max = metric > self.max and metric or self.max
    -- self.min = metric < self.min and metric or self.min

    if count > 1 and metrics[count - 1] > metric then
        self.is_sorted = false
    end

    metrics[count] = metric
end


function Entry:update_for_subkey(subkey, metric)
    self.per_subkey_total[subkey] = (self.per_subkey_total[subkey] or 0) + metric

    if metric < self.subkey_min_val then
        self.subkey_min_val = metric
        self.subkey_min_key = subkey
    end

    if metric > self.subkey_max_val then
        self.subkey_max_val = metric
        self.subkey_max_key = subkey
    end
end

function Entry:get_min_subkey()
    return self.subkey_min_key
end

function Entry:get_max_subkey()
    return self.subkey_max_key
end

function Entry:get_min_total_subkey()
    local _, k = table.min(self.per_subkey_total)
    return k
end

function Entry:get_max_total_subkey()
    local _, k = table.max(self.per_subkey_total)
    return k
end


---
-- Stats Class
---
local Stats = {}
Stats.__index = Stats

-- Constructor
function Stats.new()
    local self = setmetatable({}, Stats)
    self.entries = {}
    self.total_metric = 0
    return self
end

function Stats:compute_percentage(entry)
    return string.format("%.2f", (entry.metrics_sum / (self.total_metric or 1)) * 100)
end

-- Process a single trace and update entries
function Stats:add_entry(key, metric, subkey)
    local entry = self.entries[key.str]

    if not entry then
        entry = Entry.new(key.values)
        self.entries[key.str] = entry
    end

    entry:update(metric)
    self.total_metric = self.total_metric + metric

    if subkey then entry:update_for_subkey(subkey, metric) end

    return entry
end

function Stats:for_each_entry(callback)
    for key, entry in pairs(self.entries) do
        callback(key, entry)
    end
end


return Stats
