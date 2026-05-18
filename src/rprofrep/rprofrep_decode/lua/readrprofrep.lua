local rprofrep = require("rprofrep_decoder_lua")

-- --------------------------
-- UTILITY FUNCTIONS
-- --------------------------
local function head(str, len)
    if #str <= len then
        return str
    else
        return string.sub(str, 1, len - 3) .. "..."
    end
end

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
local function print_section_title(name)
    local names = {
        [0] = "Global",
        [1] = "String",
        [2] = "Location",
        [3] = "GPU Specification",
        [4] = "API's Data",
        [5] = "Kernels",
        [6] = "Offsets Tree",
        [7] = "Events"
    }
    print("\n==================== " .. names[lookup_section_id(name)] .. " Section ====================")
end

local function print_section_end()
    print("\n====================================================\n")
end

local function print_global_section(ctx)
    print_section_title("GLOBAL")
    print(string.format("Run Date: %s", ctx:get_run_date()))
    local exit_code = ctx:get_run_exit_code()
    print("Exit Code: " .. exit_code)
    local cmd = ctx:get_run_command_line()
    print("Command Line: " .. cmd)
    local version = ctx:get_report_version()
    print(string.format("Report Version: %d.%d.%d", version.major, version.minor, version.patch))
    local rank = ctx:get_rank()
    print("Rank: " .. rank)
    print_section_end()
end

local function print_offsets_section(ctx)
    print_section_title("OFFSETS")
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
    print_section_title("EVENTS")

    print(string.rep("-", 134))
    print(string.format("%-6s | %-10s | %-12s | %-32s | %-6s | %-6s | %-6s | %-16s | %-16s",
        "Domain", "PID/GPU", "TID/QID/SDMA", "Name", "ID", "CID", "Start", "Duration"))
    print(string.rep("-", 134))

    ctx:for_each_unit(function(_, unit_node)
        ctx:for_each_sub_unit(unit_node, function(_, node)
            local iterator = ctx:get_iterator(node, requested_domains)
            if not iterator then return end
            for _ = 1, 128 do
                local event = iterator:next()
                if not event then break end
                print(string.format("%6d | %10d | %12d | %-32s | %6d | %6d | %16d | %16d",
                    event:domain(), event:unit(), event:sub_unit(), head(event:name(), 32), event:id(), 0, event:start(), event:dur()))
            end
        end)
    end)

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
    if #arg < 2 then
        print_usage()
        return
    end

    local filename
    local show_header = false
    local section_id = -1
    local requested_domains = {} -- table of domain ids

    if arg[1] == "-h" then
        show_header = true
        filename = arg[2]
    elseif arg[1] == "-s" then
        if #arg < 3 then
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
        if secname == "EVENTS" and arg[3] == "-d" then
            local domains_str = arg[4]
            for d in string.gmatch(domains_str, "[^,]+") do
                table.insert(requested_domains, tonumber(d))
            end
            filename = arg[5]
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
