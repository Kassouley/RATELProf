local Overlapping = {}
Overlapping.__index = Overlapping

function Overlapping.new(rprofrep, domains)
    local self = setmetatable({}, Overlapping)
    -- Active events where stop >= current looking start
    self.active_events = {}

    self.it = rprofrep:get_iterator(domains)
    if not self.it then return end
    self.curr_event = self.it:next()
    return self
end

function Overlapping:update_active_events(event_start, event_stop)
    local active = self.active_events
    local curr = self.curr_event
    local it = self.it

    if not it then return end

    -- 1. Add events that overlap the window.
    -- Events are ordered by STOP descending.
    while curr and curr:stop() > event_start do
        if curr:start() < event_stop then
            active[#active + 1] = curr
        end
        curr = it:next()
    end
    self.curr_event = curr

    -- 2. Remove expired active events
    local write = 1
    for read = 1, #active do
        local ev = active[read]
        if ev:start() < event_stop then
            active[write] = ev
            write = write + 1
        end
    end

    -- Trim
    for i = write, #active do
        active[i] = nil
    end
end


function Overlapping:compute_overlap(event)
    local event_start = event:start()
    local event_stop  = event:stop()
    local event_id    = event:id()

    self:update_active_events(event_start, event_stop)

    local covered = 0
    local current_cover_end = event_start

    for _, active_event in ipairs(self.active_events) do
        if event_id ~= active_event:id() then
            local overlap_start = math.max(active_event:start(), event_start)
            local overlap_end   = math.min(active_event:stop(),  event_stop)

            if overlap_end > overlap_start then
                if overlap_start > current_cover_end then
                    covered = covered + (overlap_end - overlap_start)
                    current_cover_end = overlap_end
                elseif overlap_end > current_cover_end then
                    covered = covered + (overlap_end - current_cover_end)
                    current_cover_end = overlap_end
                end
            end
        end
    end

    return covered
end

return Overlapping