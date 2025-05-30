-- Message.lua
local Message = {}
Message.__index = Message

-- Constructor
function Message:new()
    local self = setmetatable({}, Message)
    return self
end

-- Internal method to format and print messages
function Message:log(level, msg)
    local formatted = string.format("[%s] %s", level, msg)
    print(formatted)
end

-- Public methods
function Message:print(msg)
    print(msg)
end

function Message:warn(msg)
    self:log("WARNING", msg)
end

function Message:error(msg)
    self:log("ERROR", msg)
end

function Message:info(msg)
    self:log("INFO", msg)
end

return Message
