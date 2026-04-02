
local BUCKET_SIZE = 10000

local bucket_list = {}

local function get_bucket(event_id, bucket_size)
    local bucket_id = math.floor(event_id / bucket_size)
    local bucket = bucket_list[bucket_id] or init_bucket()
    bucket_list[bucket_id] = bucket
    return bucket, bucket_id
end




local function for_each_track(rprofrep, domain, mpbuf)

    rprofrep:for_each_event(domain, function (event, event_count)
        
    end)
end

local function process_report(rprofrep)
    rprofrep:for_each_rank(function(rank)
        rprofrep:for_each_gpu(function (gpu_id)
            rprofrep:for_each_sdma(function (sdma)
                for_each_track(rprofrep, ratelprof.consts.DOMAIN_COPY_ID, mpbuf)
            end)
            rprofrep:for_each_queue(function (queue)
                for_each_track(rprofrep, ratelprof.consts.DOMAIN_KERNEL_ID, mpbuf)
            end)
        end)

        rprofrep:for_each_pid(function (pid)
            rprofrep:for_each_tid(function (tid)
                for id, _ in pairs(ratelprof.consts._CPU_DOMAIN) do
                    for_each_track(rprofrep, id, mpbuf)
                end
            end)
        end)
    end)


end