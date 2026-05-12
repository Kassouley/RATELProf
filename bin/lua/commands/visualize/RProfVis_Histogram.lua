local RProfVis_Histogram = {}
RProfVis_Histogram.__index = RProfVis_Histogram

-- Constructor
function RProfVis_Histogram:new(total_dur, nbars)
    local instance = setmetatable({}, RProfVis_Histogram)
    instance.histogram_bars = {}
    instance.nbars = nbars or 1000
    instance.total_dur = total_dur
    instance.bar_interval = math.ceil(total_dur / instance.nbars)

    for i = 1, instance.nbars do
        instance.histogram_bars[i] = {
            segments = {},
            nsegments = 0
        }
    end

    return instance
end

function RProfVis_Histogram:add_event(event)
    local start  = event:start()
    local stop   = event:stop()
    local ufunid = event:ufunid()
    local first_bar = math.floor(start / self.bar_interval) + 1
    local last_bar = math.floor(stop / self.bar_interval) + 1
    for i = first_bar, last_bar do
        local local_dur = math.min(stop, i * self.bar_interval) - math.max(start, (i - 1) * self.bar_interval)
        local bar = self.histogram_bars[i]
        local segment = bar.segments[ufunid]
        if not segment then
            segment = {
                ufunid = ufunid,
                sum = 0
            }
            bar.nsegments = bar.nsegments + 1
            bar.segments[ufunid] = segment
        end
        segment.sum = segment.sum + local_dur
    end
end

function RProfVis_Histogram:encode(buf, ntracks)
    local nbars_util = 0
    for _, bar in ipairs(self.histogram_bars) do
        if bar.nsegments > 0 then
            nbars_util = nbars_util + 1
        end
    end

    buf:encode_uint(nbars_util)
    for i, bar in ipairs(self.histogram_bars) do
        if bar.nsegments > 0 then
            buf:encode_uint(i)
            buf:encode_uint(bar.nsegments)
            for _, segment in pairs(bar.segments) do
                local seg_name = segment.ufunid
                local seg_cov = segment.sum / (self.bar_interval * ntracks)
                buf:encode_string(seg_name)
                buf:encode_float(seg_cov)
            end
        end
    end
end

return RProfVis_Histogram