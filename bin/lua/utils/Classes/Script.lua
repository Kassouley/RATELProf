-- Define the Script class
local Script = {}
Script.__index = Script

-- Constructor
function Script:new(attribute)
    local instance = setmetatable({}, Script)
    instance.type = "Script"
    instance.name = attribute.name
    instance.version = attribute.version
    instance.usage = nil
    instance.desc = "No description provided"
    instance.options = {{
            long_name = "help",
            short_name = "h",
            arg = nil,
            description = "Show this help message and exit",
            default = nil
        },
        {
            long_name = "version",
            short_name = nil,
            arg = nil,
            description = "Show the version of this command",
            default = nil
        }
    }
    instance.options_values = attribute.default_options_values or {}
    instance.arguments = {}
    instance.arguments_values = {}
    instance.min_arguments = 0
    instance.max_arguments = 0
    instance.execute_function = nil
    instance.commands = {} -- Table to store sub-commands
    instance.nb_commands = 0
    return instance
end

function Script:execute(args)
    self:check_args(args)
    if not self.execute_function then error("No execute function set") end
    return self.execute_function(self.arguments_values, self.options_values)
end

function Script:set_execute_function(execute_function)
    self.execute_function = execute_function
end

-- Method to add a sub-command
function Script:add_command(name, command)
    if command.type ~= "Script" then
        error("Command '" .. name .. "' is not a Script object.")
    end
    if self.commands[name] then
        error("Command '" .. name .. "' already exists.")
    end
    self.commands[name] = command
    self.nb_commands = self.nb_commands + 1
end

-- Method to add an argument
function Script:add_argument(name, is_optional, is_list, description)
    local last_arg = self.arguments[#self.arguments]
    if last_arg and (last_arg.is_list or last_arg.is_optional) then
        error("Cannot add a new argument after a list/optional argument")
    end
    if not is_optional then 
        self.min_arguments = self.min_arguments + 1
        self.max_arguments = self.max_arguments + 1
    elseif is_optional then 
        self.max_arguments = self.max_arguments + 1
    end
    if is_list then 
        self.max_arguments = nil 
    end
    table.insert(self.arguments, {
        name = name,
        is_optional = is_optional,
        is_list = is_list,
        description = description or "No description",
    })
end

-- Method to add an option
function Script:add_option(long_name, short_name, arg, description, need_arg, default_val)
    table.insert(self.options, {
        long_name = long_name,
        short_name = short_name,
        arg = arg,
        description = description or "No description",
        need_arg = need_arg,
        default_val = default_val
    })
end

function Script:set_usage(usage)
    self.usage = usage
end

function Script:get_usage()
    local function concat_args(args)
        local str = ""
        for _, arg in ipairs(args) do
            if arg.is_optional then
                str = str.." [<"..arg.name..">]"
            else
                str = str.." <"..arg.name..">"
            end
        end
        return str
    end
    return self.usage or self.name.." [<options>]"..concat_args(self.arguments)
end

function Script:set_desc(desc)
    self.desc = desc
end

-- Method to display script information
function Script:show_help()
    print("Usage: " .. self:get_usage())
    print("")
    print("Description: " .. self.desc)
    print("")
    if self.nb_commands > 0 then
        print("Commands: ")
        for cmd_name, cmd in pairs(self.commands) do
            print("\t"..cmd.name.."\t"..cmd.desc.." (More info with '"..self.name.." "..cmd_name.." --help').\n")
        end
    end
    if #self.arguments > 0 then
        print("Arguments: ")
        for _, arg in ipairs(self.arguments) do
            print("\t"..arg.name.."\t"..arg.description.."\n")
        end
    end
    print("Options:")
    for _, option in ipairs(self.options) do
        local content = "\t"
        if option.short_name then content = content .. "-" .. option.short_name end
        if option.long_name then
            content = content .. (option.short_name and ", " or "") .. "--" .. option.long_name
        end
        if option.arg then content = content .. " " .. option.arg end
        content = content .. "\t" .. option.description
        if option.default then content = content .. " " .. "(Default: " .. option.default .. ")" end
        print(content.."\n")
    end
    os.exit(0)
end

function Script:show_version()
    print(self.name.." version "..self.version)
    os.exit(0)
end

function Script:check_args(args)
    local i = 1
    while i <= #args do
        local arg = args[i]
        local value = true
        local matched_option = false
        
        if arg:sub(1, 1) == "-" then
            if arg == "--" then
                for i=i+1, #args do
                    local arg = args[i]
                    table.insert(self.arguments_values, arg)
                end
                break
            end
            for _, option in ipairs(self.options) do
                if (option.short_name and arg == "-" .. option.short_name) 
                    or (option.long_name and arg:match("^%-%-" .. option.long_name:gsub("-", "%%-") .. "=?")) then
                    matched_option = true
                    option.has_been_processed = true
                    if option.arg and option.need_arg then
                        if option.long_name and arg:match("=(.+)") then
                            value = arg:match("^%-%-" .. option.long_name .. "=(.+)")
                        else
                            i = i + 1
                            value = args[i]

                            if value and (value:sub(1, 1) == '"' or value:sub(1, 1) == "'") then
                                local quote_char = value:sub(1, 1)
                                local quoted_value = value
                                while i + 1 <= #args and not value:match(quote_char .. "$") do
                                    i = i + 1
                                    quoted_value = quoted_value .. " " .. args[i]
                                end
                                value = quoted_value:match("^" .. quote_char .. "(.-)" .. quote_char .. "$") or quoted_value
                            end

                            if not value or value:sub(1, 1) == "-" then
                                print("Error: " .. arg .. " need an argument.\n")
                                self:show_help()
                            end
                        end
                    elseif option.arg and not option.need_arg then
                        if option.long_name and arg:match("=(.+)") then
                            value = arg:match("^%-%-" .. option.long_name .. "=(.*)")
                        else
                            i = i + 1
                            value = args[i]
                            if not value or value:sub(1, 1) == "-" then
                                value = ""
                                i = i - 1
                            end
                        end
                    end
                    self.options_values[option.long_name] = value 
                    break
                end
            end
            if not matched_option then
                print("Unknown option: " .. arg)
                self:show_help()
            end
        else
            if self.nb_commands > 0 then
                local command_name = arg
                local new_args = {}
                for j = i + 1, #args do
                    table.insert(new_args, args[j])
                end
                local command = self.commands[command_name]
                if command then
                    command:execute(new_args)
                    os.exit(0)
                else
                    print("Error: Command '"..command_name.."' doesn't exists\n")
                    self:show_help()
                end
            end
            table.insert(self.arguments_values, arg)
        end

        i = i + 1
    end

    if self.options_values["help"] then
        self:show_help()
    elseif self.options_values["version"] then
        self:show_version()
    end

    
    for _, option in ipairs(self.options) do
        if not option.has_been_processed and option.default_val then
            self.options_values[option.long_name] = option.default_val 
        end
    end

    if self.nb_commands > 0 then
        print("Error: Need a command\n")
        self:show_help()
    end
    if #self.arguments_values < self.min_arguments 
        or (self.max_arguments and  #self.arguments_values > self.max_arguments) then
        local msg = "Error: Incorrect number of arguments; expected %s but received '".. #self.arguments_values .."'.\n"
        local fmt = ""
        if self.min_arguments == self.max_arguments then
            fmt = "'"..self.min_arguments.."'"
        elseif not self.max_arguments then
            fmt = "at least '"..self.min_arguments.."'"
        else
            fmt = "between '"..self.min_arguments.."' and '"..self.max_arguments.."'"
        end
        print(string.format(msg, fmt))
        self:show_help()
    end
end

return Script