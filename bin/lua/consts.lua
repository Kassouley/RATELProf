local consts = {}

consts._LUA_PATH     = os.getenv("LUA_PATH") or "."
consts._INSTALL_DIR  = os.getenv("INSTALL_DIR") or "."
consts._LIBS_DIR     = consts._INSTALL_DIR.."/lib/"
consts._MODULES_DIR  = consts._INSTALL_DIR.."/share/modules/"


local major, minor, patch = 1, 1, 0
consts._VERSION_MAJOR = major
consts._VERSION_MINOR = minor
consts._VERSION_PATCH = patch
consts._VERSION       = string.format("%d.%d.%d", major, minor, patch)

consts._REPORT_EXT = "rprof-rep"

consts._LIBS_NAME = {
      RATELPROF       = "libratelprof.so",
      WRAPPERS        = "libratelprof_wrapper.so",
      PLUGIN_STDOUT   = 'libplugin_stdout.so',
      PLUGIN_MSGPACK  = 'libplugin_msgpack.so',
      PLUGIN_RPROFREP = 'libplugin_rprofrep.so',
}

consts._LIBS = {
      RATELPROF       = consts._LIBS_DIR..consts._LIBS_NAME.RATELPROF,
      WRAPPERS        = consts._LIBS_DIR..consts._LIBS_NAME.WRAPPERS,
      PLUGIN_STDOUT   = consts._LIBS_DIR..consts._LIBS_NAME.PLUGIN_STDOUT,
      PLUGIN_MSGPACK  = consts._LIBS_DIR..consts._LIBS_NAME.PLUGIN_MSGPACK,
      PLUGIN_RPROFREP = consts._LIBS_DIR..consts._LIBS_NAME.PLUGIN_RPROFREP,
}

consts._PRELOADED_LIBS = {
  {name = consts._LIBS_NAME.WRAPPERS,  path = consts._LIBS.WRAPPERS},
  {name = consts._LIBS_NAME.RATELPROF, path = consts._LIBS.RATELPROF},
}

consts._DEFAULT_PLUGIN = consts._LIBS.PLUGIN_RPROFREP

consts._HTML_REPORT_PATH   = consts._MODULES_DIR.."/html/index.min.html"
consts._DATA_SET_TEST_PATH = consts._MODULES_DIR.."/html/data_handler.js"

consts._ENV = {
      FUNCTION_FILTERED =   "RATELPROF_DOMAIN_%s_FUNCTIONS_FILTERED",
      FILTER_TYPE =         "RATELPROF_DOMAIN_%s_FILTER_TYPE",
      PLUGIN_PATH =         "RATELPROF_PLUGIN_PATH",
      OUTPUT_FILE =         "RATELPROF_OUTPUT_FILE",
      NB_KERNEL_AV =        "RATELPROF_NB_KERNEL_AVAILABLE",
      NB_QUEUE_AV =         "RATELPROF_MAX_QUEUE_AVAILABLE",
      LOG_LEVEL =           "RATELPROF_LOG_LEVEL",

      DOMAIN_HSA =          "RATELPROF_DOMAIN_HSA",
      DOMAIN_HIP =          "RATELPROF_DOMAIN_HIP",
      DOMAIN_OMP_TGT =      "RATELPROF_DOMAIN_OMP_ROUTINE",
      DOMAIN_OMP_TGT_RTL =  "RATELPROF_DOMAIN_OMP_TGT_RTL",
      DOMAIN_BARRIEROR =    "RATELPROF_DOMAIN_BARRIEROR",
      DOMAIN_BARRIERAND =   "RATELPROF_DOMAIN_BARRIERAND",
      DOMAIN_KERNEL =       "RATELPROF_DOMAIN_KERNEL",
      DOMAIN_COPY =         "RATELPROF_DOMAIN_COPY",
      DOMAIN_PROFILING =    "RATELPROF_DOMAIN_PROFILING",
      DOMAIN_OMPT =         "RATELPROF_DOMAIN_OMP_REGION",
      DOMAIN_ROCTX =        "RATELPROF_DOMAIN_ROCTX",
      DOMAIN_MPI =          "RATELPROF_DOMAIN_MPI",
    }

consts.DOMAIN_HSA_ID          = 0
consts.DOMAIN_OMP_TGT_RTL_ID  = 1
consts.DOMAIN_OMP_TGT_ID      = 2
consts.DOMAIN_HIP_ID          = 3
consts.DOMAIN_MPI_ID          = 4
consts.DOMAIN_OMPT_ID         = 5
consts.DOMAIN_ROCTX_ID        = 6
consts.DOMAIN_PROFILING_ID    = 7
consts.DOMAIN_COPY_ID         = 8
consts.DOMAIN_KERNEL_ID       = 9
consts.DOMAIN_BARRIERAND_ID   = 10
consts.DOMAIN_BARRIEROR_ID    = 11


consts._DOMAIN_NAME = {
  [consts.DOMAIN_HIP_ID]          = "HIP API",
  [consts.DOMAIN_HSA_ID]          = "HSA API",
  [consts.DOMAIN_OMP_TGT_ID]      = "OpenMP Target Routine",
  [consts.DOMAIN_OMP_TGT_RTL_ID]  = "OpenMP Target RTL",
  [consts.DOMAIN_BARRIEROR_ID]    = "Barrier OR Dispatch",
  [consts.DOMAIN_BARRIERAND_ID]   = "Barrier AND Dispatch",
  [consts.DOMAIN_KERNEL_ID]       = "Kernel Dispatch",
  [consts.DOMAIN_COPY_ID]         = "Memory Transfer",
  [consts.DOMAIN_PROFILING_ID]    = "HSA for RATELProf",
  [consts.DOMAIN_OMPT_ID]         = "OpenMP Target Region",
  [consts.DOMAIN_ROCTX_ID]        = "ROCtx",
  [consts.DOMAIN_MPI_ID]          = "MPI API",
}

consts._GPU_DOMAIN = {
  [consts.DOMAIN_BARRIEROR_ID]    = true,
  [consts.DOMAIN_BARRIERAND_ID]   = true,
  [consts.DOMAIN_KERNEL_ID]       = true,
  [consts.DOMAIN_COPY_ID]         = true,
}

consts._DOMAIN_DESC = {
  [consts.DOMAIN_HIP_ID]          = "HIP is a programming framework used to launch GPU operations such as kernel dispatch or memory transfer. This domain is useful for anyone looking to understand and optimize the interactions between the CPU and GPU in programming.",
  [consts.DOMAIN_HSA_ID]          = "HSA is an AMD low-level library that operates behind the scenes of HIP and OpenMP, enabling communication between CPUs and GPUs for parallel processing. This domain will be only useful for expert or debugging.",
  [consts.DOMAIN_OMP_TGT_ID]      = "OpenMP Target is a runtime library that provides routines for managing data movement, memory mapping, etc.",
  [consts.DOMAIN_OMP_TGT_RTL_ID]  = "Refers to the target runtime library in the OpenMP programming model, working behind the scenes to execute '#pragma omp target' directives by managing data transfers and kernel execution on GPUs.",
  [consts.DOMAIN_BARRIEROR_ID]    = "The Barrier OR is a less restrictive synchronization mechanism that allows subsequent operations to proceed as soon as any one of the specified preceding operations has completed.",
  [consts.DOMAIN_BARRIERAND_ID]   = "The Barrier AND is a synchronization primitive that ensures all preceding operations in the command queue have completed before subsequent operations can begin.",
  [consts.DOMAIN_KERNEL_ID]       = "The kernel dispatch operation is the process of launching a computational kernel on the GPU.",
  [consts.DOMAIN_COPY_ID]         = "The copy operation in GPU programming is responsible for transferring data between memory locations (between host and device memory or between different regions of GPU memory).",
  [consts.DOMAIN_PROFILING_ID]    = "The profiling domain correspond to all HSA function used by RATELProf for GPU Profiling.",
  [consts.DOMAIN_OMPT_ID]         = "OpenMP Target region traces given by the OMPT API.",
  [consts.DOMAIN_ROCTX_ID]        = "ROCtx Support for RATELProf.",
  [consts.DOMAIN_MPI_ID]          = "MPI is a standardized library for parallel programming that enables processes to communicate by passing messages, supporting distributed-memory architectures.",
}


consts._TRACES = {
  ['hip'] =           {var=consts._ENV.DOMAIN_HIP,          name="HIP API"}, 
  ['hsa'] =           {var=consts._ENV.DOMAIN_HSA,          name="HSA API"},
  ['omp-routine'] =   {var=consts._ENV.DOMAIN_OMP_TGT,      name="OpenMP Target Routine"},
  ['omp-region'] =    {var=consts._ENV.DOMAIN_OMPT,         name="OpenMP Target Region"},
  ['omp-target'] =    {var=consts._ENV.DOMAIN_OMP_TGT_RTL,  name="OpenMP Target RTL"},
  ['hsa-for-rprof'] = {var=consts._ENV.DOMAIN_PROFILING,    name="HSA for RATELProf"},
  ['kernel'] =        {var=consts._ENV.DOMAIN_KERNEL,       name="Kernel Dispatch"},
  ['memory'] =        {var=consts._ENV.DOMAIN_COPY,         name="Memory Transfer"},
  ['roctx'] =         {var=consts._ENV.DOMAIN_ROCTX,        name="ROCtx"},
  ['mpi'] =           {var=consts._ENV.DOMAIN_MPI,          name="MPI API"},
  ['barrier'] =       {var={
                          consts._ENV.DOMAIN_BARRIEROR,
                          consts._ENV.DOMAIN_BARRIERAND},  name="Barrier AND/OR Dispatch"},
  ['cpu'] =           {var={
                          consts._ENV.DOMAIN_MPI,
                          consts._ENV.DOMAIN_OMP_TGT,
                          consts._ENV.DOMAIN_OMP_TGT_RTL,
                          consts._ENV.DOMAIN_OMPT,
                          consts._ENV.DOMAIN_HSA,
                          consts._ENV.DOMAIN_HIP},         name="CPU Activity"},
  ['gpu'] =           {var={
                          consts._ENV.DOMAIN_KERNEL,
                          consts._ENV.DOMAIN_COPY,
                          consts._ENV.DOMAIN_BARRIEROR,
                          consts._ENV.DOMAIN_BARRIERAND},  name="GPU Activity"},
  ['omp'] =           {var={
                          consts._ENV.DOMAIN_OMP_TGT,
                          consts._ENV.DOMAIN_OMP_TGT_RTL,
                          consts._ENV.DOMAIN_OMPT},        name="OpenMP API"},
  ['all'] =           {var={
                          consts._ENV.DOMAIN_MPI,
                          consts._ENV.DOMAIN_ROCTX,
                          consts._ENV.DOMAIN_OMP_TGT,
                          consts._ENV.DOMAIN_OMP_TGT_RTL,
                          consts._ENV.DOMAIN_OMPT,
                          consts._ENV.DOMAIN_HSA,
                          consts._ENV.DOMAIN_HIP,
                          consts._ENV.DOMAIN_KERNEL,
                          consts._ENV.DOMAIN_COPY,
                          consts._ENV.DOMAIN_BARRIEROR,
                          consts._ENV.DOMAIN_BARRIERAND},  name="All Activity"},
  ['none'] =          {var = nil,                          name="No Traces"},
}


local rules_dir = consts._MODULES_DIR.."lua/rules/"

consts.ALL_ANALYZE_REPORT = {
    hip_memcpy_async = {
      desc   = [[
This rule identifies asynchronous memory transfers that end up becoming synchronous if the memory is pageable or if the transfers is too short.
]],
      path = rules_dir .. "hip_memcpy_async.lua",
      default = true
    },
    hip_memcpy_sync = {
      desc   = [[
This rule identifies memory transfers that are synchronous and block the host during GPU memory transfers. 
It includes all hipMemcpy*() API functions.
]],
      path = rules_dir .. "hip_memcpy_sync.lua",
      default = true
    },
    gpu_idle = {
      desc    = [[
This rule identifies time regions where a GPU is idle for longer than a set threshold. 
For each GPU, gaps are found within the time range that starts with the beginning of the first GPU
operation on that device and ends with the end of the last GPU operation on that device.
]],
      opt = {
        th_gap = {
          default = 500,
          desc    = "Minimum gap duration (in ms) that will be reported."
        }
      },
      path = rules_dir .. "gpu_idle.lua",
      default = true
    },
    hidden_transfers = {
      desc    = [[
This rule identifies memory transfers (>threshold value in ns) whose latency is not fully hidden by concurrent kernel execution.
For each memory transfer, the rule calculates how much of its duration does not overlap with any kernel activity for each GPU.
Transfers that are not sufficiently overlapped may contribute to performance bottlenecks, as their latency is visible to the application.
]],
      opt = {
        th_dur = {
          default = 1e5,
          desc    = "Minimum duration (in ns) a memory transfer must have to be analyzed for hidden latency."
        },
        th_hidden = {
          default = 50,
          desc    = "Maximum percentage of hidden time a memory transfer can have to be reported."
        }
      },
      path = rules_dir .. "hidden_transfers.lua",
      default = true
    },
    coalescable_kernels = {
      desc    = [[
This rule detects multiple small, back-to-back launches of the same kernel that may be combined into a single, larger launch.
Frequent small kernel invocations can cause excessive launch overhead and underutilization of GPU resources.
Combining them may reduce launch latency and improve overall throughput.
]],
      opt = {
        th_dur = {
          default = 1e6,
          desc    = "Maximum duration (in ns) a kernel must have to be analyzed for coalescable optimization."
        },
        th_gap = {
          default = 1e6,
          desc    = "Maximum gaps duration (in ns) between two kernel calls."
        },
        min_seq = {
          default = 3,
          desc    = "Length of the minimal sequence."
        }
      },
      path = rules_dir .. "coalescable_kernels.lua",
      default = true
    },
    coalescable_transfers = {
      desc    = [[
This rule detects multiple small, back-to-back memory transfers that may be combined into a single, larger transfers.
Frequent small transfers can cause excessive overhead and underutilization of GPU resources.
Combining them may reduce latency and improve overall throughput.
Note : These transfers are detected by SDMA engine and not by Stream ID. Some of the given advices might not be correct. 
]],
      opt = {
        th_dur = {
          default = 1e6,
          desc    = "Maximum duration (in ns) a transfers must have to be analyzed for coalescable optimization."
        },
        th_gap = {
          default = 1e6,
          desc    = "Maximum gaps duration (in ns) between two transfers."
        },
        min_seq = {
          default = 3,
          desc    = "Length of the minimal sequence."
        }
      },
      path = rules_dir .. "coalescable_transfers.lua",
      default = true
    },
    concurrency = {
      desc    = [[
This rule detects GPU kernels that execute concurrently with other kernels, based on time overlap.
Each kernel's concurrency is measured as the percentage of its execution time that overlaps with other kernels.
Kernels exceeding the configured concurrency threshold are highlighted in the report below.
]],
      opt = {
        pct_th = {
          default = 20,
          desc    = "Minimum concurrency pourcentage that a kernel must have to be reported."
        },
      },
      path = rules_dir .. "concurrency.lua",
      default = true
    },
}



consts.ALL_STATS_REPORT = {}

local REPORT_DIRECTORY               = consts._MODULES_DIR.."lua/reports/"
local REPORT_DESCRIPTION_SUM_FMT     = "Compute aggregated statistics about %s activities over all GPU"
local REPORT_DESCRIPTION_PER_FMT     = "Compute Per-GPU statistics about %s activities"
local REPORT_DESCRIPTION_TRACE_FMT   = "Show all trace of %s activities"

local GPU_REPORT_DEFINITIONS = {
  -- { key = "gpu_trace",                  name = "GPU",                       mode="Trace-Mode",   default=false },
  -- { key = "gpu_mem_trace",              name = "memory transfer",           mode="Trace-Mode",   default=false },
  { key = "gpu_sum",                    name = "GPU",                       mode="Aggregated-Mode", default=true },
  { key = "gpu_kern_sum",               name = "kernel",                    mode="Aggregated-Mode", default=true },
  { key = "gpu_mem_time_sum",           name = "memory transfer",           mode="Aggregated-Mode", default=true },
  { key = "gpu_mem_size_sum",           name = "memory transfer",           mode="Aggregated-Mode", default=false },
  { key = "per_gpu_sum",                name = "GPU",                       mode="Per-Mode", default=false },
  { key = "per_gpu_mem_time_sum",       name = "memory transfer (in Time)", mode="Per-Mode", default=false },
  { key = "per_gpu_mem_size_sum",       name = "memory transfer (in Size)", mode="Per-Mode", default=false },
  { key = "per_gpu_kern_sum",           name = "kernel",                    mode="Per-Mode", default=false },
}

local function make_desc(r)
  if r.mode == "Trace-Mode" then
    return string.format(REPORT_DESCRIPTION_TRACE_FMT, r.name)
  elseif r.mode == "Aggregated-Mode" then
    return string.format(REPORT_DESCRIPTION_SUM_FMT, r.name)
  else
    return string.format(REPORT_DESCRIPTION_PER_FMT, r.name)
  end
end

for _, r in ipairs(GPU_REPORT_DEFINITIONS) do
  consts.ALL_STATS_REPORT[r.key] = {
    desc    = make_desc(r),
    mode    = r.mode,
    path    = REPORT_DIRECTORY .. r.key .. ".lua",
    default = r.default
  }
end

local API_REPORT_DEFINITION = {
    {key = "omp_region",  domain_id = consts.DOMAIN_OMPT_ID,        default = true },
    {key = "omp_target",  domain_id = consts.DOMAIN_OMP_TGT_ID,     default = true },
    {key = "omp_routine", domain_id = consts.DOMAIN_OMP_TGT_RTL_ID, default = true },
    {key = "hip",         domain_id = consts.DOMAIN_HIP_ID,         default = true },
    {key = "mpi",         domain_id = consts.DOMAIN_MPI_ID,         default = true },
    {key = "hsa",         domain_id = consts.DOMAIN_HSA_ID,         default = false },
}

consts.DOMAIN_FOR_REPORT = {}

-- Populate API reports
for _, r in ipairs(API_REPORT_DEFINITION) do
    local name = consts._TRACES[r.key:gsub("_", "-")].name
    -- Trace report
    local trace_name = r.key .. "_api_trace"
    consts.ALL_STATS_REPORT[trace_name] = {
        desc    = "Show all trace of " .. name .. " activities",
        mode = "Trace-Mode",
        path    = REPORT_DIRECTORY .. "generic_api_trace.lua",
        default = false
    }
    -- Sum report
    local sum_name = r.key .. "_api_sum"
    consts.ALL_STATS_REPORT[sum_name] = {
        desc    = "Compute aggregated statistics about " .. name .. " activities over all Proccesses",
        mode = "Aggregated-Mode",
        path    = REPORT_DIRECTORY .. "generic_api_sum.lua",
        default = r.default
    }

    -- Per Sum report
    local per_name = "per_pid_" .. sum_name
    consts.ALL_STATS_REPORT[per_name] = {
        desc    = "Compute Per-Process statistics about " .. name .. " activities",
        mode = "Per-Mode",
        path    = REPORT_DIRECTORY .. "per_pid_generic_api_sum.lua",
        default = false
    }

    consts.DOMAIN_FOR_REPORT[trace_name] = r.domain_id
    consts.DOMAIN_FOR_REPORT[sum_name]   = r.domain_id
    consts.DOMAIN_FOR_REPORT[per_name]   = r.domain_id
end


-- consts._IDX_CONSTRUCTOR_STOP = 1
-- consts._IDX_MAIN_START = 1
-- consts._IDX_MAIN_STOP = 2
-- consts._IDX_DESTRUCTOR_START = 2
-- consts._IDX_DESTRUCTOR_STOP = 3

return consts