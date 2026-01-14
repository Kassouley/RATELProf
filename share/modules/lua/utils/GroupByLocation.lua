local GroupByLocation = {}
GroupByLocation.__index = GroupByLocation

function GroupByLocation.new(rprofrep)
    local self = setmetatable({}, GroupByLocation)

    self.rprofrep = rprofrep
    self.groups = {}
    self.count = 0

    return self
end

function GroupByLocation:add(entry, name, metrics)
    local loc_str, loc_tbl = self.rprofrep:get_source_location(entry)

    local key = loc_tbl.address.."|"..name
    local group = self.groups[key]

    if not group then
        self.count = self.count + 1
        group = {}
        group.count = 0
        group.entry_name = entry:name()
        group.name = name
        group.location_str = loc_str
        self.groups[key] = group
    end
    group.count = group.count + 1

    for k, v in pairs(metrics) do
        group[k] = (group[k] or 0) + v
    end
end

return GroupByLocation
