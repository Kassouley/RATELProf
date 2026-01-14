-- RProfRep.lua

local rprofrep = require("rprofrep_decoder_lua")

local RProfRep = {}
RProfRep.__index = RProfRep


local function check_report_file(report_file, skip_on_check)
    local function error_and_handle(msg)
        if skip_on_check then
            Message:error(msg .. " (Skipping.)")
            return true
        else
            Message:error(msg)
            os.exit(1)
        end
    end

    if not ratelprof.fs.exists(report_file) then
        return error_and_handle("Report '" .. report_file .. "' doesn't exist.")
    end

    if not ratelprof.fs.has_extension(report_file, ratelprof.consts._REPORT_EXT) then
        return error_and_handle("Report '" .. report_file .. "' is not a ." .. ratelprof.consts._REPORT_EXT .. " file.")
    end
end


function RProfRep:new(rprofrep_files, opt)
    local instance = setmetatable({}, RProfRep)

    if type(rprofrep_files) ~= "table" or #rprofrep_files == 0 then
        error("Invalid report file(s) provided. Expected a table with at least one file path.")
    end

    opt = opt or {}

    instance.basename = #rprofrep_files == 1 and ratelprof.fs.remove_extension(rprofrep_files[1]) or "aggregated_report"

    instance.rank_count = #rprofrep_files
    instance.reports_rprofrep = {}
    instance.reports_filename = {}

    for _, filename in ipairs(rprofrep_files) do
        check_report_file(filename)

        local rprofrep_obj = rprofrep.new(filename)

        local rank = rprofrep_obj:get_rank()

        if instance.reports_filename[rank] then
            error(string.format("Duplicate MPI rank found in report file %s and %s: RANK %s", filename, instance.reports_filename[rank], rank))
        end
        instance.reports_rprofrep[rank] = rprofrep_obj
        instance.reports_filename[rank] = filename
    end


    return instance
end


function RProfRep:get_run_exit_code()
    return self.reports_rprofrep[1]:get_run_exit_code()
end


function RProfRep:get_run_command_line()
    return self.reports_rprofrep[1]:get_run_command_line()
end


function RProfRep:get_run_date()
    return self.reports_rprofrep[1]:get_run_date()
end


function RProfRep:get_tool_version()
    local v = self.reports_rprofrep[1]:get_tool_version()
    return string.format("%d.%d.%d", v.major, v.minor, v.patch)
end


function RProfRep:for_each_rank(callback)
    self.__in_for_each_rank = true
    for rank, ctx in pairs(self.reports_rprofrep) do
        self.__current_rprofrep = ctx
        callback(rank, ctx)
    end
    self.__current_rprofrep = nil
    self.__in_for_each_rank = false
end


function RProfRep:__for_each_unit(callback)
    if self.__in_for_each_rank then
        self.__current_rprofrep:for_each_unit(callback)
    else
        self:for_each_rank(function(_, ctx)
            ctx:for_each_unit(callback)
        end)
    end
end

function RProfRep:for_each_pid(callback)
    self.__in_for_each_pid = true
    self:__for_each_unit(function (pid, node)
        self.__current_node = node
        callback(pid)
        self.__current_node = nil
    end)
    self.__in_for_each_pid = false
end


function RProfRep:for_each_tid(callback)
    if not self.__in_for_each_pid then
        error("The method for_each_tid must be call in a for_each_pid callback.")
    end

    local node = self.__current_node

    self.__current_rprofrep:for_each_sub_unit(node, function (tid, sub_node)
        self.__current_node = sub_node
        callback(tid)
        self.__current_node = node
    end)
end




function RProfRep:for_each_gpu(callback)
    self.__in_for_each_gpu = true
    self:__for_each_unit(function (gpu_id, node)
        self.__current_node = node
        callback(gpu_id)
        self.__current_node = nil
    end)
    self.__in_for_each_gpu = false
end


function RProfRep:for_each_qid(callback)
    if not self.__in_for_each_gpu then
        error("The method for_each_qid must be call in a for_each_gpu callback.")
    end

    local node = self.__current_node

    self.__current_rprofrep:for_each_sub_unit(node, function (qid, sub_node)
        self.__current_node = sub_node
        callback(qid)
        self.__current_node = node
    end)
end


function RProfRep:for_each_sdma(callback)
    if not self.__in_for_each_gpu then
        error("The method for_each_sdma must be call in a for_each_gpu callback.")
    end

    local node = self.__current_node

    self.__current_rprofrep:for_each_sub_unit(node, function (sdma, sub_node)
        self.__current_node = sub_node
        callback(sdma)
        self.__current_node = node
    end)
end


function RProfRep:next_event()
    if self.__current_it then
        return self.__current_it:next()
    end
    return nil
end

function RProfRep:get_iterator(domains)
    return self.__current_rprofrep:get_iterator(self.__current_node, domains, self.filter)
end

function RProfRep:for_each_event(domains, callback)
    if not self.__current_node then
        error("for_each_event must be called at least inside a for_each_pid/gpu method.")
    end

    self.__current_it = self:get_iterator(domains)
    if not self.__current_it then return end
    local curr_event = self.__current_it:next()
    while curr_event do
       if callback(curr_event) then break end
       curr_event = self.__current_it:next()
    end
    self.__current_it = nil
end

function RProfRep:get_source_location(event)
    if not event then return "<unknown>", {} end
    local loc = self.__current_rprofrep:get_location(event)
    if not loc then return "<unknown>", {} end
    return string.format("%s in %s:%d", loc.func, loc.filename, loc.line), loc
end


function RProfRep:get_object_location(event)
    if not event then return "<unknown>", {} end
    local loc = self.__current_rprofrep:get_location(event)
    if not loc then return "<unknown>", {} end
    return string.format("in %s at 0x%X", loc.objfile, loc.address), loc
end

function RProfRep:get_correlated_event(event)
    return self.__current_rprofrep:get_correlated_event(event)
end

function RProfRep:find_entry_point(event)
    return self.__current_rprofrep:find_entry_point_event(event)
end

function RProfRep:get_entry_point_location(event)
    local entry_point_event = self:find_entry_point(event)
    return self:get_source_location(entry_point_event)
end

function RProfRep:get_gpu_id(handle)
    return self.__current_rprofrep:get_gpu_id_from_agent(handle)
end

function RProfRep:node_is_gpu(node_id)
    for _, ctx in pairs(self.reports_rprofrep) do
        local is_gpu = ctx:node_is_gpu(node_id)
        if is_gpu then
            return true
        end
    end
    return false
end


function RProfRep:get_max_application_time()
    local max_time = 0
    for _, ctx in pairs(self.reports_rprofrep) do
        local time = ctx:get_application_time()
        if time > max_time then
            max_time = time
        end
    end
    return max_time
end

function RProfRep:get_application_time(rank)
    rank = rank or self._current_rank
    if not rank then
        return self:get_max_application_time()
    end
    return self.reports_rprofrep[rank]:get_application_time()
end


function RProfRep:to_json(filename)
    print("TO IMPLEMENT")
end


function RProfRep:get_analyzed_interval_dur()
    local start = math.max(self.start or 0, 0)
    local stop  = math.min(self.stop or math.huge, self:get_application_time())
    return stop - start
end


function RProfRep:is_domain_traced(d)
    return self.__current_rprofrep:is_domain_traced(d)
end

function RProfRep:get_reports_filename(rank)
    rank = rank or self._current_rank
    if not rank then
        return self.reports_filename
    end
    return { self.reports_filename[rank] }
end

function RProfRep:get_current_rank()
    return self._current_rank or -1
end

return RProfRep