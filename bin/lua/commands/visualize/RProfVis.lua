local RProfVis_Histogram = require("commands.visualize.RProfVis_Histogram")

local mp = ratelprof.msgpack.encoder

-- also we need to find a solution for the event content/name
-- Later we will need a new solution for concat everything (in RprofRep or RprofVis) to
-- avoid duplication in different report per rank

local DEFAULT_BUCKET_SIZE = 8192

local function write_header_section(rprof_vis, section, off, size)
    local f = rprof_vis.handle
    f:seek("set", section.hdr_pos)
    ratelprof.fs.write_pack(f, "LL", off, size)
    f:flush()
end

local function write_section(rprof_vis, section)
    local off = ratelprof.fs.size(rprof_vis.filename)
    write_header_section(rprof_vis, section, off, section.size)
    ratelprof.fs.zcat(section.filename, rprof_vis.filename)
    ratelprof.fs.rm(section.filename)
end

local function copy_section(rprof_vis, section, section_id, rprofrep)
    local off = ratelprof.fs.size(rprof_vis.filename)
    local copied_size = rprofrep:export_section(section_id, rprof_vis.filename, 1)
    write_header_section(rprof_vis, section, off, copied_size)
end

local function encode_buckets(rprof_vis, section, self)
    local filename = section.filename
    local buf = mp.new(65535, mp.OVERFLOW_WRITE_TO_FILE, filename)
    local offset = ratelprof.fs.size(rprof_vis.filename)

    buf:encode_uint(self.rprofrep:get_analyzed_interval_dur())
    buf:encode_uint(self.bucket_count)
    self:for_each_bucket(function(bucket, bucket_id)
        local size = bucket.size
        buf:encode_uint(bucket_id)
        buf:encode_uint(offset)
        buf:encode_uint(size)
        buf:encode_uint(bucket.minStart)
        buf:encode_uint(bucket.maxStop)
        buf:encode_uint(bucket.nevents)

        offset = offset + size
        ratelprof.fs.zcat(bucket.filename, rprof_vis.filename)
        ratelprof.fs.rm(bucket.filename)
    end)

    section.size = buf:size()

    buf:write()
    buf:free()

    write_section(rprof_vis, section)
end

local function encode_groups(rprof_vis, section, self)
    local buf = mp.new(65535, mp.OVERFLOW_WRITE_TO_FILE, section.filename)
    buf:encode_uint(self.group_count)
    for _, group in pairs(self.curr_group_list) do
        buf:encode_uint(group.id)
        buf:encode_string(group.group_label)
        buf:encode_string(group.domain)
        buf:encode_string(group.track_label)
        buf:encode_uint(group.unit)
        buf:encode_uint(group.tracks_count)
        for _, track in pairs(group.tracks) do
            buf:encode_uint(track.id)
            buf:encode_int(track.subunit)
            buf:encode_uint(track.nsubtracks)
        end
        group.histogram:encode(buf, group.tracks_count)
    end
    section.size = buf:size()
    buf:write()
    buf:free()
    write_section(rprof_vis, section)
end

local RProfVis = {}
RProfVis.__index = RProfVis

-- Constructor
function RProfVis:new(rprofrep, output, bucket_size)
    local instance = setmetatable({}, RProfVis)

    instance.rprofrep = rprofrep
    instance.curr_bucket_list = {}
    instance.bucket_count = 0
    instance.curr_group_list = {}
    instance.group_count = 0
    instance.bucket_size = bucket_size
    instance.filenames = {}

    if not ratelprof.fs.is_dir(output) then
        error("Error: Output path '" .. output .. "' is not a directory")
    end
    instance.output = output

    instance.sections = {
        {name = "groups",   encode = encode_groups, filename = output .. "/groups.mp"},
        {name = "buckets",  encode = encode_buckets, filename = output .. "/buckets.mp"},
        {name = "api_data", enum = rprofrep.RPROFREP_SECTION_API_DATA},
        {name = "kernel_data", enum = rprofrep.RPROFREP_SECTION_KERNEL},
        {name = "location", enum = rprofrep.RPROFREP_SECTION_LOCATION},
        {name = "string", enum = rprofrep.RPROFREP_SECTION_STRING},
    }

    return instance
end


function RProfVis:init_bucket(bucket_id)
    local filename = string.format("%s/bucket_%d.mp", self.output, bucket_id)
    self.bucket_count = self.bucket_count + 1
    return {
        track_setted = {},
        minStart = math.huge,
        maxStop = 0,
        nevents = 0,
        buffer = mp.new(65535, mp.OVERFLOW_WRITE_TO_FILE, filename),
        filename = filename
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

local function get_group_and_track_labels(domain)
    local consts = ratelprof.consts
    if domain == consts.DOMAIN_COPY_ID then
        return "GPU", "SDMA ID"
    elseif domain == consts.DOMAIN_KERNEL_ID
        or domain == consts.DOMAIN_BARRIEROR_ID
        or domain == consts.DOMAIN_BARRIERAND_ID then
        return "GPU", "Queue ID"
    end
    return "PID", "TID"
end

function RProfVis:get_group(unit, domain, domain_name)
    local key = unit .. "_" .. domain
    local group = self.curr_group_list[key]
    if not group then
        local group_label, track_label = get_group_and_track_labels(domain)
        group = {
            id = self.group_count,
            unit = unit,
            group_label = group_label,
            track_label = track_label,
            domain = domain_name,
            tracks_count = 0,
            tracks = {},
            histogram = RProfVis_Histogram:new(self.rprofrep:get_analyzed_interval_dur())
        }
        self.group_count = self.group_count + 1
        self.curr_group_list[key] = group
    end
    return group
end

function RProfVis:get_track_id(group, subunit)
    local tracks = group.tracks
    local track_id = group.tracks_count
    group.tracks_count = group.tracks_count + 1
    local track = {
        id = track_id,
        subunit = subunit,
        nsubtracks = 1
    }
    tracks[track_id] = track
    return track
end

function RProfVis:for_each_bucket(f)
    for bucket_id, bucket in pairs(self.curr_bucket_list) do
        f(bucket, bucket_id)
    end
end

function RProfVis:for_each_track(unit, subunit, domain, domain_name)
    local group = self:get_group(unit, domain, domain_name)
    local histogram = group.histogram
    local group_id = group.id
    local track = self:get_track_id(group, subunit)
    local track_id = track.id
    local subtrack_id = 1
    local last_event_stop = {0}

    local function get_subtrack_id(start, stop)
        while subtrack_id > 1 and start >= last_event_stop[subtrack_id] do
            subtrack_id = subtrack_id - 1
        end

        if start < last_event_stop[subtrack_id] then
            subtrack_id = subtrack_id + 1
        end

        last_event_stop[subtrack_id] = stop

        return subtrack_id
    end

    self.rprofrep:for_each_event({domain}, function (event)
        local bucket, _ = self:get_bucket(event)
        local buf = bucket.buffer
        if not bucket.track_setted[track] then
            buf:encode_uint(group_id)
            buf:encode_uint(track_id)
            bucket.track_setted[track] = true
        end

        local start = event:start()
        local dur = event:dur()
        local stop = start + dur
        local cid = self.rprofrep:get_correlated_id(event)

       subtrack_id = get_subtrack_id(start, stop)

        if subtrack_id > 1 then
            buf:push_byte(0xc4)
            buf:encode_uint(subtrack_id - 1)
        else
            histogram:add_event(event)
        end

        local meta_offset = self:get_metadata_offset()
        local rawargs, nargs = event:rawargs()
        local loc_id = event:loc_id()
        local old_size = self.metadata_buffer:size()

        if domain == ratelprof.consts.DOMAIN_KERNEL_ID then
            self.metadata_buffer:encode_bool(false)
            self.metadata_buffer:encode_uint(event:extra_id())
        elseif loc_id >= 0 then
            self.metadata_buffer:encode_bool(true)
            self.metadata_buffer:encode_uint(event:extra_id())
            self.metadata_buffer:encode_uint(loc_id)
        end

        self.metadata_buffer:encode_uint(event:id())
        if cid > 0 then
            self.metadata_buffer:push_byte(0xc4)
            self.metadata_buffer:encode_uint(cid)
        end
        self.metadata_buffer:encode_uint(nargs)
        self.metadata_buffer:push_bytes(rawargs)
        local new_size = self.metadata_buffer:size()
        local meta_size = new_size - old_size

        buf:encode_uint(event:ufunid())
        buf:encode_uint(start)
        buf:encode_uint(dur)
        buf:encode_uint(meta_offset)
        buf:encode_uint(meta_size)
    end)

    self:for_each_bucket(function(bucket, _)
        local buf = bucket.buffer
        if bucket.track_setted[track] then
            buf:push_byte(0xc1)
        end
    end)
end


-- MAIS il faut trouver une solution pour les noms de kernels qui sont mangled
-- soit je fais une section specialement pour juste dans rprofvis soit je le fais dans rep aussi
-- a voir

function RProfVis:generate()
    local rprofrep = self.rprofrep
    rprofrep:for_each_rank(function(rank)
        self.curr_bucket_list = {}
        self.curr_group_list = {}
        self.curr_event_name_map = {}

        self:init_report(rank)

        rprofrep:for_each_gpu(function (gpu_id)
            rprofrep:for_each_sdma(function (sdma)
                rprofrep:for_each_domain(function (domain, domain_name, _)
                    self:for_each_track(gpu_id, sdma, domain, domain_name)
                end)
            end)
            rprofrep:for_each_queue(function (queue)
                rprofrep:for_each_domain(function (domain, domain_name, _)
                    self:for_each_track(gpu_id, queue, domain, domain_name)
                end)
            end)
        end)

        rprofrep:for_each_pid(function (pid)
            rprofrep:for_each_tid(function (tid)
                rprofrep:for_each_domain(function (domain, domain_name, _)
                    self:for_each_track(pid, tid, domain, domain_name)
                end)
            end)
        end)

        self:for_each_bucket(function(bucket, _)
            local buf = bucket.buffer
            bucket.size = buf:size()
            buf:write()
            buf:free()
        end)

        self:encode_report()
    end)
end

function RProfVis:get_metadata_offset()
    return self.metadata_offset + self.metadata_buffer:size()
end

function RProfVis:init_report(rank)
    local basename = "rank_" .. rank .. ".rprof-vis"
    local filename = self.output .. "/" .. basename
    table.insert(self.filenames, basename)
    local f = ratelprof.fs.open_file(filename, "wb")

    for _, section in ipairs(self.sections) do
        section.hdr_pos = f:seek()

        -- write two u64 = offset + size (initialized to 0)
        ratelprof.fs.write_pack(f,"LL", 0, 0)
        f:flush()
    end

    local rprofvis = {filename = filename, handle = f}
    self.curr_rprofvis = rprofvis
    self.metadata_offset = ratelprof.fs.size(rprofvis.filename)
    self.metadata_buffer = mp.new(65535, mp.OVERFLOW_APPEND_TO_FILE, rprofvis.filename)

end

function RProfVis:encode_report()
    local rprofvis = self.curr_rprofvis
    local f = rprofvis.handle

    self.metadata_buffer:write()
    self.metadata_buffer:free()

    for _, section in ipairs(self.sections) do
        if section.encode then
            section.encode(rprofvis, section, self)
        end
        if section.enum then
            copy_section(rprofvis, section, section.enum, self.rprofrep)
        end
    end

    self.curr_rprofvis = nil
    self.metadata_buffer = nil
    self.metadata_offset = 0

    f:flush()
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