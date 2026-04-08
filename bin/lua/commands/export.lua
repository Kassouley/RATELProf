local RProfRep = require ("utils.Classes.RProfRep")
local options_helper = require ("options_helper")

local export = {}

local function to_json(rprofrep, output)
    local write = output.write
    local DOMAIN_KERNEL_ID = ratelprof.consts.DOMAIN_KERNEL_ID

    local indent_level = 0
    local indent_cache = { [0] = "" }

    local function indent()
        local s = indent_cache[indent_level]
        if not s then
            s = ("\t"):rep(indent_level)
            indent_cache[indent_level] = s
        end
        return s
    end

    local function inc() indent_level = indent_level + 1 end
    local function dec() indent_level = indent_level - 1 end

    local function write_line(s)
        write(output, indent() .. s)
    end

    write_line("{\n")
    inc()
    write_line('"events": {\n')
    inc()
    write_line('"ranks": {\n')
    inc()

    local first_rank = true
    rprofrep:for_each_rank(function(rank)
        if not first_rank then write(output, ",\n") end
        first_rank = false

        write_line('"' .. rank .. '": {\n')
        inc()

        -- GPUs
        write_line('"gpus": {\n')
        inc()

        local first_gpu = true
        rprofrep:for_each_gpu(function(gpu_id)
            if not first_gpu then write(output, ",\n") end
            first_gpu = false

            write_line('"' .. gpu_id .. '": [\n')
            inc()

            local first_event = true
            rprofrep:for_each_event("all", function(event)
                if not first_event then write(output, ",\n") end
                first_event = false

                local e = {
                    name = event:name(),
                    domain = event:domain(),
                    id = event:id(),
                    cid = rprofrep:get_correlated_id(event),
                    start = event:start(),
                    dur = event:dur(),
                    args = event:args(),
                }

                if e.domain ~= DOMAIN_KERNEL_ID then
                    e.sdma = event:sdma_id()
                else
                    if e.domain == DOMAIN_KERNEL_ID then
                        e.kernel_metadata = event:kernel_metadata()
                    end
                    e.qid = event:queue_id()
                end

                write_line(JSON:encode(e))
            end)

            write(output, "\n")
            dec()
            write_line("]")
        end)

        write(output, "\n")
        dec()
        write_line("},\n")

        -- PIDs
        write_line('"pids": {\n')
        inc()

        local first_pid = true
        rprofrep:for_each_pid(function(pid)
            if not first_pid then write(output, ",\n") end
            first_pid = false

            write_line('"' .. pid .. '": [\n')
            inc()

            local first_event = true
            rprofrep:for_each_event("all", function(event)
                if not first_event then write(output, ",\n") end
                first_event = false

                local e = {
                    name = event:name(),
                    domain = event:domain(),
                    id = event:id(),
                    cid = rprofrep:get_correlated_id(event),
                    start = event:start(),
                    dur = event:dur(),
                    args = event:args(),
                    tid = event:tid(),
                    loc = rprofrep:get_source_location(event)
                }

                write_line(JSON:encode(e))
            end)

            write(output, "\n")
            dec()
            write_line("]")
        end)

        write(output, "\n")
        dec()
        write_line("}")

        dec()
        write_line("}")
    end)

    write(output, "\n")
    dec()
    write_line("}")
    dec()
    write_line("}")
    dec()
    write_line("}")

    output:close()
end


local function format_value(name, value)
    if type(value) == "table" then
        local sub_parts = {}
        for _, field in ipairs(value) do
            table.insert(sub_parts, field)
        end
        return string.format("%s{%s}", name or "", table.concat(sub_parts, ", "))
    else
        return string.format("%s%s", name and name..":" or "", value)
    end
end

local function format_call(e)
    local arg_parts = {}
    local retval_value = "void"

    for name, value in pairs(e:args()) do
        if name == "retval" then
            retval_value = format_value(nil, value)
        else
            table.insert(arg_parts, format_value(name, value))
        end
    end

    local args_str = table.concat(arg_parts, ", ")
    return string.format("%s(%s):%s", e:name(), args_str, retval_value)
end


local function to_arg_info(rprofrep, output)
    local write = output.write

    rprofrep:for_each_rank(function(rank)
        rprofrep:for_each_gpu(function(gpu_id)
            rprofrep:for_each_event("all", function(e)
                local domain_name = ratelprof.consts._DOMAIN_NAME[e:domain()]
                write(output, string.format("%-24s |%s id:%8s | %s\n", 
                    domain_name, rank == -1 and "" or " RANK "..rank.." |", e:id(), format_call(e)))
            end)
        end)
        rprofrep:for_each_pid(function(pid)
            rprofrep:for_each_event("all", function(e)
                local domain_name = ratelprof.consts._DOMAIN_NAME[e:domain()]
                write(output, string.format("%-24s |%s id:%8s | %s\n", 
                    domain_name, rank == -1 and "" or " RANK "..rank.." |", e:id(), format_call(e)))
            end)
        end)
    end)
    output:close()
end


local function open_file(default, opt, ext)
    local output, filename = options_helper.parse_file_option(opt, "output", ext)
    if not output then
        filename = default .. "." .. ext
        output = ratelprof.fs.open_file(filename, "w", ext)
    end
    return output, filename
end

function export.process(positional_args, opt)
    local type = ratelprof.get_opt_val(opt, "type")

    if not type then
        Message:error("Export type is required.")
        os.exit(1)
    end

    local rprofrep = RProfRep:new(positional_args)

    local handlers = {
        ["json"]     = to_json,
        ["arg-info"] = to_arg_info
    }
    local fn = handlers[type]
    if not fn then
        Message:error("Unknown export type: "..type)
        os.exit(1)
    end

    local output, filename = open_file(rprofrep.basename, opt, type)
    fn(rprofrep, output)
    Message:print("RPROF: Export written to '" .. filename.."'")
end

return export
