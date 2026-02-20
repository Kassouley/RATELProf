-- Progress.lua

local Progress = {}
Progress.__index = Progress

function Progress:new(opts)
    opts = opts or {}

    local total = opts.total

    local obj = {
        width        = opts.width or 40,
        filled_char  = opts.filled_char or "=",
        empty_char   = opts.empty_char or " ",
        prefix       = opts.prefix or "",
        suffix       = opts.suffix or "",
        show_percent = opts.show_percent ~= false,
        show_eta     = opts.show_eta or false,
        show_count   = opts.show_count or false,

        print_every  = opts.print_every or 1,
        percent_step = opts.percent_step,
    }

    setmetatable(obj, self)
    self:reset(total)
    return obj
end


function Progress:reset(total)
    self.total        = total or 100
    self.current      = 0
    self.last_print_i = 0
    self.last_percent = -1
    self.start_time   = os.time()
    self.finished     = false
    self.last_line_len = 0
    self.message      = nil
end

local function format_time(seconds)
    if seconds < 0 then return "--:--" end
    local m = math.floor(seconds / 60)
    local s = seconds % 60
    return string.format("%02d:%02d", m, s)
end

function Progress:update(value, message)
    if self.finished then return end
    value = value or self.current + 1
    self.current = math.min(value, self.total)
    self.message = message or self.message

    local percent = math.floor((self.current / self.total) * 100)
    local should_print = false

    if self.percent_step then
        if percent - self.last_percent >= self.percent_step then
            should_print = true
            self.last_percent = percent
        end
    else
        if self.current - self.last_print_i >= self.print_every then
            should_print = true
            self.last_print_i = self.current
        end
    end

    if should_print or self.current == self.total then
        self:render(percent)
    end
end

function Progress:render(percent)
    local filled = math.floor((percent / 100) * self.width)
    local empty  = self.width - filled

    local bar = string.rep(self.filled_char, filled) ..
                string.rep(self.empty_char, empty)

    local parts = {}

    if self.prefix ~= "" then table.insert(parts, self.prefix) end
    table.insert(parts, "[" .. bar .. "]")
    if self.show_percent then
        table.insert(parts, string.format("%3d%%", percent))
    end
    
    if self.show_count then
        table.insert(parts, string.format("%d/%d", self.current, self.total))
    end

    if self.show_eta then
        local elapsed = os.time() - self.start_time
        local remaining = (percent > 0)
            and math.floor(elapsed * (100 - percent) / percent)
            or -1
        table.insert(parts, "ETA " .. format_time(remaining))
    end
    if self.message then table.insert(parts, self.message) end
    if self.suffix ~= "" then table.insert(parts, self.suffix) end

    local line = table.concat(parts, " ")
    
    self:clear()
    self.last_line_len = #line

    io.write("\r" .. line)
    io.flush()
end

-- Erase the progress bar line
function Progress:clear()
    if self.last_line_len > 0 then
        io.write("\r" .. string.rep(" ", self.last_line_len) .. "\r")
        io.flush()
    end
end

-- Finish and optionally erase
function Progress:finish(erase)
    if self.finished then return end
    self.finished = true

    if erase then
        self:clear()
    else
        io.write("\n")
    end
end


return Progress