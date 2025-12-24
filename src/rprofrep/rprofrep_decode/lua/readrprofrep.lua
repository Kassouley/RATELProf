local rprofrep = require("rprofrep_decoder_lua")

-- --------------------------
-- SECTION NAME → ENUM
-- --------------------------
local function lookup_section_id(name)
    local sections = {
        GLOBAL = 0,
        STRING = 1,
        LOCATION = 2,
        GPU_SPEC = 3,
        API_DATA = 4,
        KERNEL = 5,
        OFFSETS = 6,
        EVENTS = 7
    }
    return sections[name]
end

-- --------------------------
-- PRINT FUNCTIONS
-- --------------------------
local function print_section_title(section_id)
    local names = {
        [0] = "GLOBAL",
        [1] = "STRING",
        [2] = "LOCATION",
        [3] = "GPU_SPEC",
        [4] = "API_DATA",
        [5] = "KERNEL",
        [6] = "OFFSETS",
        [7] = "EVENTS"
    }
    print("\n==================== " .. names[section_id] .. " Section ====================")
end

local function print_section_end()
    print("\n====================================================\n")
end

local function print_global_section(ctx)
    print_section_title(0)
    print(string.format("Run Date: %s", ctx:get_run_date()))
    local exit_code = ctx:get_run_exit_code()
    print("Exit Code: " .. exit_code)
    local cmd = ctx:get_run_command_line()
    print("Command Line: " .. cmd)
    local version = ctx:get_report_version()
    print(string.format("Report Version: %d.%d.%d", version[1], version[2], version[3]))
    local rank = ctx:get_rank()
    print("Rank: " .. rank)
    print_section_end()
end

local function print_offsets_section(ctx)
    print_section_title(6)
    ctx:for_each_unit(function(pid, node)
        print("  - PID/GPU: " .. pid)
        ctx:for_each_sub_unit(node, function(tid, subnode)
            print("    - TID/QID/SDMA: " .. tid)
            -- Domains not implemented in Lua wrapper
        end)
    end)
    print_section_end()
end

local function print_events_section(ctx, requested_domains)
    print_section_title(7)
    local iterator = ctx:get_iterator(requested_domains)
    local count = 0
    while true do
        local event = iterator:next()
        if not event then break end
        print(string.format("Event: name=%s, rank=%d, domain=%d, pid=%d, tid=%d, phase=%d, id=%d, start=%d, dur=%d",
            event:name(), event:rank(), event:domain(), event:pid(), event:tid(), event:phase(), event:id(), event:start(), event:dur()))
        count = count + 1
        if count > 100 then break end -- limit for demo
    end
    print_section_end()
end

-- --------------------------
-- PRINT USAGE MESSAGE
-- --------------------------
local function print_usage()
    print("Usage:")
    print("  lua readrprofrep.lua -h <file>                                 Show rprofrep header")
    print("  lua readrprofrep.lua -s <SECTION> <file>                       Show a specific section")
    print("  lua readrprofrep.lua -s EVENTS -d <DOMAIN[,DOMAIN]> <file>     Show the events for specified domain (default: all domain)")
    print("Available sections:")
    print("  GLOBAL OFFSETS EVENTS")
end

-- --------------------------
-- MAIN
-- --------------------------
local function main()
    if #arg < 3 then
        print_usage()
        return
    end

    local filename
    local show_header = false
    local section_id = -1
    local requested_domains = {} -- table of domain ids

    if arg[1] == "-h" then
        if #arg ~= 3 then
            print_usage()
            return
        end
        show_header = true
        filename = arg[2]
    elseif arg[1] == "-s" then
        if #arg < 4 then
            print_usage()
            return
        end
        local secname = arg[2]
        section_id = lookup_section_id(secname)
        if section_id == nil then
            print("ERROR: Unknown section name: " .. secname)
            print_usage()
            return
        end
        filename = arg[3]
        if secname == "EVENTS" and arg[4] == "-d" then
            local domains_str = arg[5]
            for d in string.gmatch(domains_str, "[^,]+") do
                requested_domains[tonumber(d)] = true
            end
            filename = arg[6]
        end
    else
        print_usage()
        return
    end

    local ctx = rprofrep.new(filename)

    if show_header then
        print_global_section(ctx)
    end

    if section_id >= 0 then
        if section_id == 0 then
            print_global_section(ctx)
        elseif section_id == 6 then
            print_offsets_section(ctx)
        elseif section_id == 7 then
            print_events_section(ctx, requested_domains)
        else
            print("Section not implemented in Lua")
        end
    end
end

main()
