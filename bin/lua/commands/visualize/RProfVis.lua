local RProfVis_Histogram = require("commands.visualize.RProfVis_Histogram")
local RProfVis_Content   = require("commands.visualize.RProfVis_Content")

local mp = ratelprof.msgpack.encoder

local RProfVis = {}
RProfVis.__index = RProfVis

-- Constructor
function RProfVis:new(rprofrep, output, bucket_size, start, stop, pids, gpus)
    local instance = setmetatable({}, RProfVis)

    instance.rprofrep = rprofrep
    instance.curr_bucket_list = {}
    instance.bucket_count = 0
    instance.curr_group_list = {}
    instance.bucket_size = bucket_size
    instance.pids = pids
    instance.gpus = gpus
    instance.event_filter = ratelprof.utils.get_filter(start, stop)
    instance.filenames = {}

    instance.demangled_map = {}

    if not ratelprof.fs.is_dir(output) then
        error("Error: Output path '" .. output .. "' is not a directory")
    end
    instance.output = output

    instance.sections = {
        {name = "groups",      encode = "encode_groups"},
        {name = "buckets",     encode = "encode_buckets"},
        {name = "api_data",    encode = "copy_section", enum = rprofrep.RPROFREP_SECTION_API_DATA},
        {name = "kernel_data", encode = "copy_section", enum = rprofrep.RPROFREP_SECTION_KERNEL},
        {name = "locations",   encode = "copy_section", enum = rprofrep.RPROFREP_SECTION_LOCATION},
        {name = "strings",     encode = "string_to_js", enum = rprofrep.RPROFREP_SECTION_STRING},
    }

    return instance
end

function RProfVis:set_section_output(dirname)
    self.curr_dirname = dirname
    for _, section in ipairs(self.sections) do
        section.filename = dirname .. "/" .. section.name
    end
end


function RProfVis:init_bucket(bucket_id)
    local filename = string.format("%s/bucket_%d", self.curr_dirname, bucket_id)
    self.bucket_count = self.bucket_count + 1

    local metadata_file = ratelprof.fs.open_file(filename..".metadata", "w")
    metadata_file:write("window.metadata=[")


    RProfVis_Content.write_bucket_prefix(filename)
    return {
        track_setted = {},
        minStart = math.huge,
        maxStop = 0,
        nevents = 0,
        buffer = mp.new(65535, mp.OVERFLOW_APPEND_B64_TO_FILE, filename),
        filename = filename,
        metadata_file = metadata_file
    }
end

function RProfVis:get_bucket(event)
    local bucket_list = self.curr_bucket_list
    local bucket_id = math.floor((event:id() - 1) / self.bucket_size) -- event id is 1-based, bucket_id is 0-based
    local bucket = bucket_list[bucket_id] or self:init_bucket(bucket_id)
    bucket_list[bucket_id] = bucket
    bucket.minStart = math.min(bucket.minStart, event:start())
    bucket.maxStop  = math.max(bucket.maxStop, event:stop())
    bucket.nevents  = bucket.nevents + 1
    return bucket, bucket_id
end

local domain_mode_map = {
    [ratelprof.consts.DOMAIN_MEMORY_ID] = 0,
    [ratelprof.consts.DOMAIN_KERNEL_ID] = 1,
    [ratelprof.consts.DOMAIN_BARRIEROR_ID] = 3,
    [ratelprof.consts.DOMAIN_BARRIERAND_ID] = 3,
    [ratelprof.consts.DOMAIN_ROCTX_ID] = 4
}

function RProfVis:get_group(unit, domain, process_info)
    local domain_name = process_info.domain_name 
    local subunit_label = process_info.subunit_label
    local group_label = process_info.unit_label
    local key = unit .. "_" .. domain
    local group = self.curr_group_list[key]
    if not group then
        local mode = domain_mode_map[domain] or 2
        group = {
            id = self.group_count,
            unit = unit,
            group_label = group_label,
            domain = domain_name,
            domain_mode = mode,
            tracks_count = 0,
            tracks = {},
            histogram = RProfVis_Histogram:new(self.rprofrep:get_analyzed_interval_dur())
        }
        self.group_count = self.group_count + 1
        self.curr_group_list[key] = group
    end
    return group
end

function RProfVis:get_track_id(group, subunit, track_label)
    local tracks = group.tracks
    local track_id = group.tracks_count
    group.tracks_count = group.tracks_count + 1
    local track = {
        id = track_id,
        subunit = subunit,
        track_label = track_label,
        nsubtracks = 0
    }
    tracks[track_id] = track
    return track
end

function RProfVis:for_each_bucket(f)
    for bucket_id, bucket in pairs(self.curr_bucket_list) do
        f(bucket, bucket_id)
    end
end

function RProfVis:for_each_track(unit, subunit, domain, process_info)
    local group = self:get_group(unit, domain, process_info)
    local histogram = group.histogram
    local group_id = group.id
    local track = self:get_track_id(group, subunit, process_info.subunit_label)
    local track_id = track.id
    local subtrack_id = 1
    local last_event_start = {math.huge}

    local function get_subtrack_id(start, stop)
        while subtrack_id > 1 and stop <= last_event_start[subtrack_id] do
            subtrack_id = subtrack_id - 1
        end

        if stop > last_event_start[subtrack_id] then
            subtrack_id = subtrack_id + 1
        end
        last_event_start[subtrack_id] = start

        return subtrack_id
    end

    self.rprofrep:for_each_event({domain}, function (event)
        local bucket, _ = self:get_bucket(event)
        local buf = bucket.buffer
        local metadata_file = bucket.metadata_file

        if not bucket.track_setted[track] then
            buf:encode_uint(group_id)
            buf:encode_uint(track_id)
            bucket.track_setted[track] = true
        end

        local start = event:start()
        local dur = event:dur()
        local stop = start + dur
        local cid = event:cid()

       subtrack_id = get_subtrack_id(start, stop)

        if subtrack_id > 1 then
            buf:push_byte(0xc5)
            buf:encode_uint(subtrack_id - 1)
        else
            histogram:add_event(event)
        end

        buf:encode_uint(event:ufunid())
        buf:encode_uint(start)
        buf:encode_uint(dur)

        buf:encode_uint(event:id())

        if cid > 0 then
            buf:push_byte(0xc4)
            buf:encode_uint(cid)
        end


        if bucket.nevents > 1 then
            metadata_file:write(",")
        end
        self:encode_metadata(metadata_file, event, domain)



    end, self.event_filter, self:__get_process_str(process_info))

    for _, _ in pairs(last_event_start) do
        track.nsubtracks = track.nsubtracks + 1
    end

    self:for_each_bucket(function(bucket, _)
        local buf = bucket.buffer
        if bucket.track_setted[track] then
            buf:push_byte(0xc1)
        end
    end)
end


function RProfVis:encode_metadata(file, event, domain)
    local buf = mp.new(65535, mp.OVERFLOW_REALLOC)
    local rawargs, nargs = event:rawargs()
    local loc_id = event:loc_id()

    if domain == ratelprof.consts.DOMAIN_KERNEL_ID then
        buf:encode_uint(event:extra_id())
    elseif domain == ratelprof.consts.DOMAIN_MEMORY_ID then
        local _, memop = event:memop()
        buf:encode_uint(memop)
    elseif loc_id >= 0 then
        if domain ~= ratelprof.consts.DOMAIN_ROCTX_ID then
            buf:encode_uint(event:extra_id())
        end
        buf:encode_uint(loc_id)
    end

    buf:encode_uint(nargs)
    buf:push_bytes(rawargs)

    file:write('"', buf:to_b64(), '"')
    buf:free()
end


function RProfVis:__get_process_str(info)
    return string.format("Visualize %s events for %s %d and %s %d", 
        info.domain_name, 
        info.unit_label, info.unit_value,
        info.subunit_label, info.subunit_value)

end


function RProfVis:generate()
    local rprofrep = self.rprofrep
    rprofrep:for_each_rank(function(rank)
        self.curr_bucket_list = {}
        self.curr_group_list = {}
        self.curr_event_name_map = {}

        self:init_report(rank)
        self.group_count = 0

        local process_info = {
            domain_name = "",
            unit_label = "", unit_value = 0,
            subunit_label = "", subunit_value = 0
        }

        rprofrep:for_each_gpu(function (gpu_id)
            process_info.unit_label = "GPU"
            process_info.unit_value = gpu_id
            rprofrep:for_each_sdma(function (sdma)
                process_info.subunit_label = "SDMA"
                process_info.subunit_value = sdma
                rprofrep:for_each_domain(function (domain, domain_name, _)
                    process_info.domain_name = domain_name
                    self:for_each_track(gpu_id, sdma, domain, process_info)
                end)
            end)
            rprofrep:for_each_queue(function (queue)
                process_info.subunit_label = "Queue"
                process_info.subunit_value = queue
                rprofrep:for_each_domain(function (domain, domain_name, _)
                    process_info.domain_name = domain_name
                    self:for_each_track(gpu_id, queue, domain, process_info)
                end)
            end)
        end, self.gpus)

        rprofrep:for_each_pid(function (pid)
            process_info.unit_label = "PID"
            process_info.unit_value = pid
            rprofrep:for_each_tid(function (tid)
                process_info.subunit_label = "TID"
                process_info.subunit_value = tid
                rprofrep:for_each_domain(function (domain, domain_name, _)
                    process_info.domain_name = domain_name
                    self:for_each_track(pid, tid, domain, process_info)
                end)
            end)
        end, self.pids)

        self:for_each_bucket(function(bucket, _)
            local filename = bucket.filename
            local buf = bucket.buffer
            buf:write()
            buf:free()
            RProfVis_Content.write_bucket_suffix(bucket.filename, bucket.nevents)

            local metadata_file = bucket.metadata_file
            metadata_file:write("];")
            metadata_file:close()

            ratelprof.fs.zcat(filename, filename..".metadata")
            ratelprof.fs.mv(filename..".metadata", filename..".js")
            ratelprof.fs.rm(filename)

        end)

        self:encode_report()
    end)
end

function RProfVis:get_metadata_offset()
    return self.metadata_offset + self.metadata_buffer:size()
end

function RProfVis:init_report(rank)
    local basename = "rank_" .. rank
    local dirname = self.output .. "/" .. basename
    table.insert(self.filenames, {
        basename = basename,
        rank = rank,
    })
    ratelprof.fs.mkdir(dirname)

    self:set_section_output(dirname)

    self.curr_rankdir = dirname
end

function RProfVis:encode_report()
    for _, section in ipairs(self.sections) do
        if section.encode then
            self[section.encode](self, section)
        end
    end

    self.curr_rankdir = nil
end


function RProfVis:write_section(section)
    local filename = section.filename
    local name = section.name
    local jsfilename = filename..".js"

    local f = ratelprof.fs.open_file(jsfilename, "w")
    f:write("window.", name, "=\"")
    f:flush()
    ratelprof.fs.to_b64(filename, jsfilename, "a")
    f:seek("end")
    f:write("\"")
    f:close()
    ratelprof.fs.rm(filename)
end


function RProfVis:string_to_js(section)
    local name = section.name
    local filename = section.filename
    local jsfilename = filename..".js"
    local f = ratelprof.fs.open_file(jsfilename, "w")
    f:write("window.", name, "=")
    f:flush()
    f:close()
    self.rprofrep:string_section_to_json(jsfilename, "a", true)
end

function RProfVis:copy_section(section)
    local filename = section.filename
    self.rprofrep:export_section(section.enum, filename, 0)
    self:write_section(section)
end

function RProfVis:encode_buckets(section)
    local filename = section.filename..".js"
    local json = {
        mainTime = self.rprofrep:get_main_time(),
        maxTime = self.rprofrep:get_analyzed_interval_dur(),
        bucketList = {}
    }
    local bucketList = json.bucketList
    self:for_each_bucket(function(bucket, bucket_id)
        bucketList[tostring(bucket_id)] = {
            minStart = bucket.minStart,
            maxStop  = bucket.maxStop,
            count    = bucket.nevents
        }
    end)

    local f = ratelprof.fs.open_file(filename, "w")
    f:write("window.buckets=", JSON:encode(json))
    f:close()
end

function RProfVis:encode_groups(section)
    local filename = section.filename
    local name = section.name
    local jsfilename = filename..".js"

    local f = ratelprof.fs.open_file(jsfilename, "w")
    f:write("window.", name, "=\"")
    f:flush()

    local buf = mp.new(65535, mp.OVERFLOW_APPEND_B64_TO_FILE, jsfilename)
    buf:encode_uint(self.group_count)
    for _, group in pairs(self.curr_group_list) do
        buf:encode_uint(group.id)
        buf:encode_string(group.group_label)
        buf:encode_string(group.domain)
        buf:encode_uint(group.domain_mode)
        buf:encode_uint(group.unit)
        buf:encode_uint(group.tracks_count)
        for _, track in pairs(group.tracks) do
            buf:encode_uint(track.id)
            buf:encode_string(track.track_label)
            buf:encode_int(track.subunit)
            buf:encode_uint(track.nsubtracks)
        end
        group.histogram:encode(buf, group.tracks_count)
    end
    buf:write()
    buf:free()

    f:seek("end")
    f:write("\"")
    f:close()
end

function RProfVis:write_jsfile(fs)
    local __TIMELINE_DATA__ = { 
        FILENAMES = self.filenames,
        MAX_BUCKET_SIZE = self.bucket_size
    }
    fs.data.timeline:write("const __TIMELINE_DATA__=", JSON:encode(__TIMELINE_DATA__))
end

return RProfVis