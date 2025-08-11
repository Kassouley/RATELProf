-- BinaryReport.lua

local BinaryReport = {}
BinaryReport.__index = BinaryReport

local function decode_rprof(rprof_rep)

    local data = ratelprof.msgpack.decode(rprof_rep)
    local report_version = data.version

    if report_version then
        local rvmajor = report_version[1]
        local rvminor = report_version[2]
        local rvpatch = report_version[3]

        if  rvmajor ~= ratelprof.consts._VERSION_MAJOR or
            rvminor ~= ratelprof.consts._VERSION_MINOR or
            rvpatch ~= ratelprof.consts._VERSION_PATCH then

            Message:error(string.format(
                "Incompatible report file version: expected %d.%d.%d but got %d.%d.%d.\n" ..
                "Please regenerate the report using the current version of RATELProf.",
                ratelprof.consts._VERSION_MAJOR,
                ratelprof.consts._VERSION_MINOR,
                ratelprof.consts._VERSION_PATCH,
                rvmajor or 0, rvminor or 0, rvpatch or 0
            ))
            os.exit(1)
        end
    else
        Message:error("Missing or malformed report version information in the report file.")
        os.exit(1)
    end

    return data
end

function BinaryReport:new(rprof_rep_files, opt)
    local self = setmetatable({}, BinaryReport)

    if type(rprof_rep_files) ~= "table" or #rprof_rep_files == 0 then
        error("Invalid report file(s) provided. Expected a table with at least one file path.")
    end

    local opt = opt or {}
    self.only_main = opt.only_main
    self.start = opt.start
    self.stop  = opt.stop

    self.version = nil
    self.main_data = nil
    self.experiment_start_epoch = nil

    self.rprof_rep_files = {}

    self.trace_events = {}
    self.lifecycle = {}

    self.locations = {}
    self.gpu_props = {}
    self.node_id = {}

    self.rank_count = #rprof_rep_files

    for i, rprof_rep_file in ipairs(rprof_rep_files) do
        ratelprof.utils.check_report_file(rprof_rep_file)
        local data = decode_rprof(rprof_rep_file)

        local mpi_rank = data.mpi_rank or -1

        if i == 0 then
            self.version   = data.version
            self.main_data = data.main_data
            self.experiment_start_epoch = data.experiment_start_epoch
        end


        if self.rprof_rep_files[mpi_rank] then
            error(string.format("Duplicate MPI rank found in report file %s and %s: RANK %s", rprof_rep_file, self.rprof_rep_files[mpi_rank], mpi_rank))
        end
        self.rprof_rep_files[mpi_rank]  = rprof_rep_file
        self.trace_events[mpi_rank]     = data.trace_events or error("Missing trace events in report file: " .. rprof_rep_file)
        self.lifecycle[mpi_rank]        = data.lifecycle    or error("Missing lifecycle data in report file: " .. rprof_rep_file)

        self.locations = table.merge_map(self.locations, data.locations)
        self.gpu_props = table.merge_map(self.gpu_props, data.gpu_props)
        self.node_id   = table.merge_map(self.node_id,   data.node_id)
    end


    self.__cached_trace = {}
    return self
end

function BinaryReport:to_json()
    return {
        version = self.version,
        main_data = self.main_data,
        experiment_start_epoch = self.experiment_start_epoch,
        trace_events = self.trace_events,
        lifecycle = self.lifecycle,
        locations = self.locations,
        node_id = self.node_id,
        gpu_props = self.gpu_props,
    }
end


function BinaryReport:get_rprof_rep_files()
    local files = {}
    for _, rprof_rep_file in pairs(self.rprof_rep_files) do
        table.insert(files, rprof_rep_file)
    end
    return files
end

    -------- TODO TO AVOID APP TIME (%) > 100% , need to compute_total_covered_duration / non overlapping duration for each API
    --- Then i will be able to create graph to show camembert of time spent in each API

function BinaryReport:get_domain_traced()
    local domains = {}
    for _, trace_events in pairs(self.trace_events) do
        for domain_name, _ in pairs(trace_events) do
            table.insert(domains, domain_name)
        end
        break -- Only need to check one rank
    end
    return domains
end

function BinaryReport:get_app_name()
    local main_data = self.main_data
    local ret = main_data[1]

    local parts = {}
    for i = 2, #main_data do
        table.insert(parts, main_data[i])
    end
    return table.concat(parts, " ") .. " (ret: " .. ret .. ")"
end

function BinaryReport:get_app_date()
    return os.date("%Y-%m-%d %H:%M:%S", self.experiment_start_epoch / 1e9)
end

function BinaryReport:get_tool_version()
    local v = self.version
    return string.format("%d.%d.%d", v[1], v[2], v[3])
end

function BinaryReport:for_each_traces(func)
    for mpi_rank, traces_per_rank in pairs(self.trace_events) do
        for domain_name, traces_per_domain in pairs(traces_per_rank) do
            for trace_id, trace in pairs(traces_per_domain) do
                func(mpi_rank, domain_name, trace_id, trace)
            end
        end
    end
end

function BinaryReport:for_each_rank(func)
    self.__in_for_each_rank = true
    for mpi_rank, _ in pairs(self.trace_events) do
        self._current_rank = mpi_rank
        func(mpi_rank, self.rprof_rep_files[mpi_rank])
    end
    self._current_rank = nil
    self.__in_for_each_rank = false
end

function BinaryReport:for_each_gpu(func)
    self.__in_for_each_gpu = true
    for _, gpu_props in ipairs(self.gpu_props) do
        local gpu_node_id = gpu_props[3]
        self.__current_gpu = gpu_node_id
        func(gpu_node_id, gpu_props)
    end
    self.__current_gpu = nil
    self.__in_for_each_gpu = false
end


function BinaryReport:__get(ret, trace_events, mpi_rank, cond_func)
    if not cond_func then 
        cond_func = function (self, trace)
            return true
        end
    end

    local is_only_main =  self.only_main
    local opt_start = self.start
    local opt_stop = self.stop
    ret = ret or {}
    if not trace_events then
        return ret
    end
    for id, trace in pairs(trace_events) do
        if (not is_only_main or trace.phase == "MAIN_PHASE") and cond_func(self, trace) then
            local start = trace.start
            local stop  = trace.start + trace.dur
            local within_start = not opt_start or start >= opt_start
            local within_stop  = not opt_stop  or stop  <= opt_stop
            if within_start and within_stop then
                trace.mpi_rank = mpi_rank
                trace.id = id
                trace.stop = stop
                ret[#ret + 1] = trace
            end
        end
    end
    return ret
end

function BinaryReport:__get_for_gpu(domain)
    local ret = {}

    local cond_func = nil

    if domain == ratelprof.consts._ENV.DOMAIN_KERNEL then
        cond_func = function(obj, trace)
            return obj:get_gpu_id(trace.args.gpu_id) == obj.__current_gpu
        end
    elseif domain == ratelprof.consts._ENV.DOMAIN_COPY then
        cond_func = function(obj, trace)
            if trace.args.src_type == 1 then
                return obj:get_gpu_id(trace.args.src_agent) == obj.__current_gpu
            elseif trace.args.dst_type == 1 then
                return obj:get_gpu_id(trace.args.dst_agent) == obj.__current_gpu
            end
        end
    else
        error("Using get(domain) method inside for_each_gpu() is only available for GPU domain")
    end

    for mpi_rank, traces_per_rank in pairs(self.trace_events) do
        self:__get(ret, traces_per_rank[domain], mpi_rank, cond_func)
    end
    return ret
end


function BinaryReport:get(domain_name)
    self.__cached_trace = self.__cached_trace or {}

    local cache_key
    if self.__in_for_each_rank then
        cache_key = domain_name .. "::rank::" .. tostring(self._current_rank)
    elseif self.__in_for_each_gpu then
        cache_key = domain_name .. "::gpu::" .. tostring(self.__current_gpu)
    else
        cache_key = domain_name .. "::all"
    end

    if self.__cached_trace[cache_key] then
        return self.__cached_trace[cache_key]
    end

    local ret = {}

    if self.__in_for_each_rank then
        ret = self:__get(ret, self.trace_events[self._current_rank][domain_name], self._current_rank)
    elseif self.__in_for_each_gpu then
        ret = self:__get_for_gpu(domain_name)
    else
        for mpi_rank, trace_events in pairs(self.trace_events) do
            ret = self:__get(ret, trace_events[domain_name], mpi_rank)
        end
    end

    table.sort(ret, function(a, b) return a.start < b.start end)
    self.__cached_trace[cache_key] = ret
    return ret
end


function BinaryReport:get_location(trace)
    return self.locations[trace.return_address] 
            or {sfun = "<unknown>", sfile = "<unknown>", sline = 0}
end


function BinaryReport:get_location_str(trace)
    local loc = self:get_location(trace)
    if not loc then return "Unknown Location" end
    return string.format("%s in %s:%d", loc.sfun, loc.sfile, loc.sline)
end

function BinaryReport:find_parent_trace(trace, mpi_rank)
    mpi_rank = mpi_rank or trace.mpi_rank
    if not mpi_rank then
        error("A trace need to have an MPI rank attribute, even if it's -1.")
    end
    local parent_trace = nil
    local parent_domain = nil
    for domain, per_domain_traces in pairs(self.trace_events[mpi_rank]) do
        parent_trace = per_domain_traces[trace.corr_id]
        if parent_trace then
            parent_domain = domain
            break
        end
    end
    return parent_trace, parent_domain
end

function BinaryReport:find_entry_point(trace)
    local entry_point = trace
    local entry_point_domain = nil
    local mpi_rank = trace.mpi_rank
    if not mpi_rank then
        error("A trace need to have an MPI rank attribute, even if it's -1.")
    end
    local parent_trace, parent_domain = self:find_parent_trace(entry_point, mpi_rank)

    while parent_trace do
        entry_point = parent_trace
        entry_point_domain = parent_domain
        parent_trace, parent_domain = self:find_parent_trace(entry_point, mpi_rank)
    end

    return entry_point, entry_point_domain
end

function BinaryReport:get_gpu_id(handle)
    return self.node_id[handle] or string.format('Unknown (%lu)', handle)
end


function BinaryReport:__get_lifecycle_data(rank)
    rank = rank or self._current_rank
    if not rank then
        error("Rank must be specified when not in per-rank mode")
    end
    if not self.lifecycle[rank] then
        error("Lifecycle data for rank " .. rank .. " is not available")
    end
    return self.lifecycle[rank]
end

function BinaryReport:get_constructor_start(rank)
    return 0
end

function BinaryReport:get_main_start(rank)
    return self:__get_lifecycle_data(rank)[ratelprof.consts._IDX_MAIN_START]
end

function BinaryReport:get_main_stop(rank)
    return self:__get_lifecycle_data(rank)[ratelprof.consts._IDX_MAIN_STOP]
end

function BinaryReport:get_destructor_stop(rank)
    return self:__get_lifecycle_data(rank)[ratelprof.consts._IDX_DESTRUCTOR_STOP]
end

function BinaryReport:get_analyzed_interval_dur()
    local start = math.max(self.start or 0, 0)
    local stop  = math.min(self.stop or math.huge, self:get_app_dur())
    return stop - start
end

function BinaryReport:get_app_dur(rank)
    rank = rank or self._current_rank
    local time = 0
    if not rank then
        for mpi_rank, _ in pairs(self.trace_events) do
            time = math.max(time, self:get_destructor_stop(mpi_rank))
        end
    else
        time = self:get_destructor_stop(rank)
    end
    return time
end

function BinaryReport:get_active_compute_time()
    if self.cached_active_compute_time then return self.cached_active_compute_time end
    self.cached_active_compute_time = self:compute_total_covered_duration(ratelprof.consts._ENV.DOMAIN_KERNEL)
    return self.cached_active_compute_time
end


function BinaryReport:get_active_copy_time()
    if self.cached_active_copy_time then return self.cached_active_copy_time end
    self.cached_active_copy_time = self:compute_total_covered_duration(ratelprof.consts._ENV.DOMAIN_COPY)
    return self.cached_active_copy_time
end

function BinaryReport:get_active_gpu_time()
    if self.cached_active_gpu_time then return self.cached_active_gpu_time end
    self.cached_active_gpu_time = self:compute_total_covered_duration(ratelprof.consts._ENV.DOMAIN_KERNEL, ratelprof.consts._ENV.DOMAIN_COPY)
    return self.cached_active_gpu_time
end

function BinaryReport:get_not_hidden_active_copy_time()
    local active_gpu_time = self:get_active_gpu_time()
    local active_compute_time = self:get_active_compute_time()
    return active_gpu_time - active_compute_time
end

function BinaryReport:compute_total_covered_duration_of(...)
    local intervals = {}
    local count = 0

    local args = {...}
    if #args > 1 then
        for _, domain in ipairs(args) do
            local traces = self:get(domain)
            for _, t in pairs(traces) do
                count = count + 1
                intervals[count] = t
            end
        end
        table.sort(intervals, function(a, b) return a.start < b.start end)
    else
        intervals = self:get(args[1])
        count = #intervals
    end

    -- Merge intervals and compute total
    local total = 0
    local cur_start = intervals[1].start
    local cur_stop = intervals[1].stop

    for i = 2, count do
        local s = intervals[i].start
        local e = intervals[i].stop

        if s <= cur_stop then
            if e > cur_stop then
                cur_stop = e
            end
        else
            total = total + (cur_stop - cur_start)
            cur_start = s
            cur_stop = e
        end
    end

    total = total + (cur_stop - cur_start)
    return total
end


return BinaryReport