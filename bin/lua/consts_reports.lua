local consts = ratelprof.consts

local opt_timeunit = {
    desc    = "\tSet basic unit of time.\n" ..
              "\tPossible values are: ns, us, ms, sec.",
    type    = "unit",
    allowed = { ns=true, us=true, ms=true, sec=true },
    default = "ns"
}

local opt_sizeunit = {
    desc    = "\tSet basic unit of size.\n" ..
              "\tPossible values are: B, KB, MB, GB.",
    type    = "unit",
    allowed = { B=true, KB=true, MB=true, GB=true },
    default = "KB"
}

local opt_mangled = {
    desc    = "\tIf true, do not demangle C++ symbol names in reports.",
    default = false
}

local opt_trunc = {
    desc    = "\tIf true, truncate long symbol names in reports.",
    default = true
}

consts.ANALYZE_REPORTS = {

  coalescable_kernels = {
    desc   = "This rule detects multiple small, back-to-back launches of the same kernel that may be combined into a single, larger launch.\n" ..
             "Frequent small kernel invocations can cause excessive launch overhead and underutilization of GPU resources.\n" ..
             "Combining them may reduce launch latency and improve overall throughput.",
    opt    = {
      th_dur   = { default = 1e6, desc = "\tMaximum duration (in ns) a kernel must have to be analyzed for coalescable optimization." },
      th_gap   = { default = 1e6, desc = "\tMaximum gaps duration (in ns) between two kernel calls." },
      min_seq  = { default = 3,   desc = "\tLength of the minimal sequence." },
      mangled  = opt_mangled,
      trunc    = opt_trunc,
      timeunit = opt_timeunit
    }
  },

  coalescable_transfers = {
    desc   = "This rule detects multiple small, back-to-back memory transfers that may be combined into a single, larger transfers.\n" ..
             "Frequent small transfers can cause excessive overhead and underutilization of GPU resources.\n" ..
             "Combining them may reduce latency and improve overall throughput.\n" ..
             "Note : These transfers are detected by SDMA engine and not by Stream ID. Some of the given advices might not be correct.",
    opt    = {
      th_dur   = { default = 1e6, desc = "\tMaximum duration (in ns) a transfers must have to be analyzed for coalescable optimization." },
      th_gap   = { default = 1e6, desc = "\tMaximum gaps duration (in ns) between two transfers." },
      min_seq  = { default = 3,   desc = "\tLength of the minimal sequence." },
      timeunit = opt_timeunit
    }
  },

  concurrency = {
    desc   = "This rule detects GPU kernels that execute concurrently with other kernels, based on time overlap.\n" ..
             "Each kernel's concurrency is measured as the percentage of its execution time that overlaps with other kernels.\n" ..
             "Kernels exceeding the configured concurrency threshold are highlighted in the report below.",
    opt    = {
      pct_th = { default = 20, desc = "\tMinimum concurrency pourcentage that a kernel must have to be reported." },
      mangled  = opt_mangled,
      trunc    = opt_trunc,
      timeunit = opt_timeunit
    }
  },

  gpu_idle = {
    desc   = "This rule identifies time regions where a GPU is idle for longer than a set threshold.\n" ..
             "For each GPU, gaps are found within the time range that starts with the beginning of the first GPU\n" ..
             "operation on that device and ends with the end of the last GPU operation on that device.",
    opt    = {
      th_gap = { default = 500, desc = "\tMinimum gap duration (in ms) that will be reported." },
      timeunit = opt_timeunit
    }
  },

  hidden_transfers = {
    desc   = "This rule identifies memory transfers (>threshold value in ns) whose latency is not fully hidden by concurrent kernel execution.\n" ..
             "For each memory transfer, the rule calculates how much of its duration does not overlap with any kernel activity for each GPU.\n" ..
             "Transfers that are not sufficiently overlapped may contribute to performance bottlenecks, as their latency is visible to the application.",
    opt    = {
      th_dur    = { default = 1e5, desc = "\tMinimum duration (in ns) a memory transfer must have to be analyzed for hidden latency." },
      th_hidden = { default = 50,  desc = "\tMaximum percentage of hidden time a memory transfer can have to be reported." },
      timeunit = opt_timeunit,
      sizeunit = opt_sizeunit
    }
  },

  hip_memcpy_async = {
    desc   = "This rule identifies asynchronous memory transfers that end up becoming synchronous if the memory is pageable or if the transfers is too short.",
    opt    = {
      timeunit = opt_timeunit,
      sizeunit = opt_sizeunit
    }
  },

  hip_memcpy_sync = {
    desc   = "This rule identifies memory transfers that are synchronous and block the host during GPU memory transfers.\n"..
             "It includes all hipMemcpy*() API functions.",
    opt    = {
      timeunit = opt_timeunit,
      sizeunit = opt_sizeunit
    }
  },
}

for name, data in pairs(consts.ANALYZE_REPORTS) do
  data.path = consts._MODULES_DIR .. "lua/rules/" ..  name .. ".lua"
  data.default = true
end


local REPORT_DESCRIPTION_SUM_FMT     = "Compute aggregated statistics about %s activities over all %s"
local REPORT_DESCRIPTION_PER_FMT     = "Compute Per-%s statistics about %s activities"
local REPORT_DESCRIPTION_TRACE_FMT   = "Show all trace of %s activities"

local kernel_options = {
    timeunit = opt_timeunit,
    mangled  = opt_mangled,
    trunc    = opt_trunc
}

local size_options = {
    sizeunit = opt_sizeunit
}

local time_options = {
    timeunit = opt_timeunit
}

consts.STATS_REPORTS = {
  gpu_sum              = { mode = "Aggregated-Mode", opt = kernel_options,  desc = string.format(REPORT_DESCRIPTION_SUM_FMT, "GPU", "GPU") },
  gpu_kern_sum         = { mode = "Aggregated-Mode", opt = kernel_options,  desc = string.format(REPORT_DESCRIPTION_SUM_FMT, "kernel", "GPU") },
  gpu_mem_time_sum     = { mode = "Aggregated-Mode", opt = time_options,    desc = string.format(REPORT_DESCRIPTION_SUM_FMT, "memory transfer (in Time)", "GPU") },
  gpu_mem_size_sum     = { mode = "Aggregated-Mode", opt = size_options,    desc = string.format(REPORT_DESCRIPTION_SUM_FMT, "memory transfer (in Size)", "GPU") },
  per_gpu_sum          = { mode = "Per-Mode",        opt = kernel_options,  desc = string.format(REPORT_DESCRIPTION_PER_FMT, "GPU", "GPU")},
  per_gpu_kern_sum     = { mode = "Per-Mode",        opt = kernel_options,  desc = string.format(REPORT_DESCRIPTION_PER_FMT, "GPU", "kernel")},
  per_gpu_mem_time_sum = { mode = "Per-Mode",        opt = time_options,    desc = string.format(REPORT_DESCRIPTION_PER_FMT, "GPU", "memory transfer (in Time)")},
  per_gpu_mem_size_sum = { mode = "Per-Mode",        opt = size_options,    desc = string.format(REPORT_DESCRIPTION_PER_FMT, "GPU", "memory transfer (in Size)")},
  -- gpu_trace = { desc = string.format(REPORT_DESCRIPTION_TRACE_FMT, "GPU")},
}

for name, data in pairs(consts.STATS_REPORTS) do
  data.path = consts._MODULES_DIR .. "lua/reports/" ..  name .. ".lua"
  data.default = data.mode == "Aggregated-Mode" and true or false
end

local API_REPORT_DEFINITION = {
    {key = "omp_region",  domain_id = consts.DOMAIN_OMPT_ID,        default = true },
    {key = "omp_target",  domain_id = consts.DOMAIN_OMP_TGT_RTL_ID, default = false },
    {key = "omp_routine", domain_id = consts.DOMAIN_OMP_TGT_ID,     default = true },
    {key = "hip",         domain_id = consts.DOMAIN_HIP_ID,         default = true },
    {key = "mpi",         domain_id = consts.DOMAIN_MPI_ID,         default = false },
    {key = "hsa",         domain_id = consts.DOMAIN_HSA_ID,         default = false },
    {key = "rocblas",     domain_id = consts.DOMAIN_ROCBLAS_ID,     default = false },
    {key = "rccl",        domain_id = consts.DOMAIN_RCCL_ID,        default = false },
}

consts.DOMAIN_FOR_REPORT = {}

-- Populate API reports
for _, r in ipairs(API_REPORT_DEFINITION) do
    local name = consts._TRACES[r.key:gsub("_", "-")].name
    local trace_report_name = r.key .. "_api_trace"
    local sum_report_name = r.key .. "_api_sum"
    local per_report_name = "per_pid_" .. sum_report_name
    local report_dir = consts._MODULES_DIR .. "lua/reports/"

    consts.STATS_REPORTS[trace_report_name] = {
      desc   = string.format(REPORT_DESCRIPTION_TRACE_FMT, name),
      path   = report_dir .. "generic_api_trace.lua",
      mode = "Trace-Mode",
      opt = time_options,
      default = false
    }

    consts.STATS_REPORTS[sum_report_name] = {
      desc   = string.format(REPORT_DESCRIPTION_SUM_FMT, name, "Process"),
      path   = report_dir .. "generic_api_sum.lua",
      mode = "Aggregated-Mode",
      opt = time_options,
      default = r.default
    }

    consts.STATS_REPORTS[per_report_name] = {
      desc   = string.format(REPORT_DESCRIPTION_PER_FMT, "Process", name),
      path   = report_dir .. "per_pid_generic_api_sum.lua",
      mode = "Per-Mode",
      opt = time_options,
      default = false
    }

    consts.DOMAIN_FOR_REPORT[sum_report_name]   = r.domain_id
    consts.DOMAIN_FOR_REPORT[per_report_name]   = r.domain_id
    consts.DOMAIN_FOR_REPORT[trace_report_name] = r.domain_id
end

consts.BREAKDOWN_REPORTS = {
  cpu_breakdown = {
    desc    = "Compute overview CPU API statistics of the application.",
    path    = consts._MODULES_DIR .. "lua/breakdown/" .. "cpu_breakdown.lua",
    opt = time_options,
    default = true
  },
  gpu_breakdown = {
    desc    = "Compute overview GPU statistics of the application.",
    path    = consts._MODULES_DIR .. "lua/breakdown/" .. "gpu_breakdown.lua",
    opt = time_options,
    default = true
  }
}