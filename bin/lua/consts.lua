local consts = {}

consts._LUA_PATH     = os.getenv("LUA_PATH") or "."
consts._INSTALL_DIR  = os.getenv("INSTALL_DIR") or "."
consts._LIBS_DIR     = consts._INSTALL_DIR.."/lib/"
consts._MODULES_DIR  = consts._INSTALL_DIR.."/share/modules/"


local major, minor, patch = 1, 1, 0
consts._VERSION_MAJOR = major
consts._VERSION_MINOR = minor
consts._VERSION_PATCH = patch
consts._VERSION = string.format("%d.%d.%d", major, minor, patch)

consts._REPORT_EXT = "rprof-rep"

consts._LIBS_NAME = {
      RATELPROF       = "libratelprof.so",
      WRAPPERS        = "libratelprof_wrapper.so",
      PLUGIN_STDOUT   = 'libplugin_stdout.so',
      PLUGIN_MSGPACK  = 'libplugin_msgpack.so',
      PLUGIN_JSON     = 'libplugin_json.so',
      PLUGIN_JSON_DYN = 'libplugin_json_dyn.so',
}

consts._LIBS = {
      RATELPROF       = consts._LIBS_DIR..consts._LIBS_NAME.RATELPROF,
      WRAPPERS        = consts._LIBS_DIR..consts._LIBS_NAME.WRAPPERS,
      PLUGIN_STDOUT   = consts._LIBS_DIR..consts._LIBS_NAME.PLUGIN_STDOUT,
      PLUGIN_MSGPACK  = consts._LIBS_DIR..consts._LIBS_NAME.PLUGIN_MSGPACK,
      PLUGIN_JSON     = consts._LIBS_DIR..consts._LIBS_NAME.PLUGIN_JSON,
      PLUGIN_JSON_DYN = consts._LIBS_DIR..consts._LIBS_NAME.PLUGIN_JSON_DYN,
}

consts._PRELOADED_LIBS = {
  {name = consts._LIBS_NAME.WRAPPERS,  path = consts._LIBS.WRAPPERS},
  {name = consts._LIBS_NAME.RATELPROF, path = consts._LIBS.RATELPROF},
}

consts._DEFAULT_PLUGIN = consts._LIBS.PLUGIN_MSGPACK

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
    }

consts._DOMAIN_NAME = {
  [consts._ENV.DOMAIN_HIP]          = "HIP API",
  [consts._ENV.DOMAIN_HSA]          = "HSA API",
  [consts._ENV.DOMAIN_OMP_TGT]      = "OpenMP Target Routine",
  [consts._ENV.DOMAIN_OMP_TGT_RTL]  = "OpenMP Target RTL",
  [consts._ENV.DOMAIN_BARRIEROR]    = "Barrier OR Dispatch",
  [consts._ENV.DOMAIN_BARRIERAND]   = "Barrier AND Dispatch",
  [consts._ENV.DOMAIN_KERNEL]       = "Kernel Dispatch",
  [consts._ENV.DOMAIN_COPY]         = "Memory Transfer",
  [consts._ENV.DOMAIN_PROFILING]    = "HSA for RATELProf",
  [consts._ENV.DOMAIN_OMPT]         = "OpenMP Target Region",
  [consts._ENV.DOMAIN_ROCTX]        = "ROCtx"
}

consts._GPU_DOMAIN = {
  [consts._ENV.DOMAIN_BARRIEROR]    = true,
  [consts._ENV.DOMAIN_BARRIERAND]   = true,
  [consts._ENV.DOMAIN_KERNEL]       = true,
  [consts._ENV.DOMAIN_COPY]         = true,
}

consts._DOMAIN_DESC = {
  [consts._ENV.DOMAIN_HIP]          = "HIP is a programming framework used to launch GPU operations such as kernel dispatch or memory transfer. This domain is useful for anyone looking to understand and optimize the interactions between the CPU and GPU in programming.",
  [consts._ENV.DOMAIN_HSA]          = "HSA is an AMD low-level library that operates behind the scenes of HIP and OpenMP, enabling communication between CPUs and GPUs for parallel processing. This domain will be only useful for expert or debugging.",
  [consts._ENV.DOMAIN_OMP_TGT]      = "OpenMP Target is a runtime library that provides routines for managing data movement, memory mapping, etc.",
  [consts._ENV.DOMAIN_OMP_TGT_RTL]  = "Refers to the target runtime library in the OpenMP programming model, working behind the scenes to execute '#pragma omp target' directives by managing data transfers and kernel execution on GPUs.",
  [consts._ENV.DOMAIN_BARRIEROR]    = "The Barrier OR is a less restrictive synchronization mechanism that allows subsequent operations to proceed as soon as any one of the specified preceding operations has completed.",
  [consts._ENV.DOMAIN_BARRIERAND]   = "The Barrier AND is a synchronization primitive that ensures all preceding operations in the command queue have completed before subsequent operations can begin.",
  [consts._ENV.DOMAIN_KERNEL]       = "The kernel dispatch operation is the process of launching a computational kernel on the GPU.",
  [consts._ENV.DOMAIN_COPY]         = "The copy operation in GPU programming is responsible for transferring data between memory locations (between host and device memory or between different regions of GPU memory).",
  [consts._ENV.DOMAIN_PROFILING]    = "The profiling domain correspond to all HSA function used by RATELProf for GPU Profiling",
  [consts._ENV.DOMAIN_OMPT]         = "OpenMP Target region traces given by the OMPT API",
  [consts._ENV.DOMAIN_ROCTX]        = "ROCtx Support for RATELProf"
}


consts._TRACES = {
  ['hip'] =           {var=consts._ENV.DOMAIN_HIP,          name="HIP API"}, 
  ['hsa'] =           {var=consts._ENV.DOMAIN_HSA,          name="HSA API"},
  ['omp-routine'] =   {var=consts._ENV.DOMAIN_OMP_TGT,      name="OpenMP Target Routine"},
  ['omp-region'] =    {var=consts._ENV.DOMAIN_OMPT,         name="OpenMP Target Region"},
  ['omp-tgt-rtl'] =   {var=consts._ENV.DOMAIN_OMP_TGT_RTL,  name="OpenMP Target RTL"},
  ['hsa-for-rprof'] = {var=consts._ENV.DOMAIN_PROFILING,    name="HSA for RATELProf"},
  ['kernel'] =        {var=consts._ENV.DOMAIN_KERNEL,       name="Kernel Dispatch"},
  ['memory'] =        {var=consts._ENV.DOMAIN_COPY,         name="Memory Transfer"},
  ['roctx'] =         {var=consts._ENV.DOMAIN_ROCTX,        name="ROCtx"},
  ['barrier'] =       {var={
                          consts._ENV.DOMAIN_BARRIEROR,
                          consts._ENV.DOMAIN_BARRIERAND},  name="Barrier AND/OR Dispatch"},
  ['cpu'] =           {var={
                          consts._ENV.DOMAIN_OMP_TGT,
                          consts._ENV.DOMAIN_OMP_TGT_RTL,
                          consts._ENV.DOMAIN_OMPT,
                          consts._ENV.DOMAIN_HSA,
                          consts._ENV.DOMAIN_HIP},         name="CPU API"},
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
}


consts._ALL_RULES_REPORT = {
    __default_report_path = consts._MODULES_DIR.."lua/rules/",

    hip_memcpy_async = {
      desc   = [[
This rule identifies asynchronous memory transfers that end up becoming synchronous if the memory is pageable or if the transfers is too short.
]],
      default = true
    },
    hip_memcpy_sync = {
      desc   = [[
This rule identifies memory transfers that are synchronous and block the host during GPU memory transfers. 
It includes all hipMemcpy*() API functions.
]],
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
      default = true
    },
}


consts._ALL_STATS_REPORT = {
      __default_report_path = consts._MODULES_DIR.."lua/reports/",

      omp_region_api_trace = {
        desc    = "Show all trace about OpenMP Target Region",
        default = false
      },
      omp_region_api_sum = {
        desc    = "Compute statistics about OpenMP Target Region traces",
        default = true
      },
      omp_api_trace = {
        desc    = "Show all trace about OpenMP Target API",
        default = false
      },
      omp_api_sum = {
        desc    = "Compute statistics about OpenMP Target API traces",
        default = true
      },
      omp_target_api_trace = {
        desc    = "Show all trace about OpenMP Target RTL API",
        default = false
      },
      omp_target_api_sum = {
        desc    = "Compute statistics about OpenMP Target RTL API traces",
        default = true
      },
      hip_api_trace = {
        desc    = "Show all trace about HIP API",
        default = false
      },
      hip_api_sum = {
        desc    = "Compute statistics about HIP API traces",
        default = true
      },
      hsa_api_trace = {
        desc    = "Show all trace about HSA API",
        default = false
      },
      hsa_api_sum = {
        desc    = "Compute statistics about HSA API traces",
        default = true
      },
      gpu_trace = {
        desc    = "Show all trace about GPU activity",
        default = false
      },
      gpu_mem_trace = {
        desc    = "Show all trace about memory transfer activity",
        default = false
      },
      gpu_sum = {
        desc    = "Compute statistics about GPU traces",
        default = true
      },
      gpu_kern_sum = {
        desc    = "Compute statistics about kernel traces",
        default = true
      },
      gpu_mem_time_sum = {
        desc    = "Compute statistics about memory transfer traces (in Time)",
        default = true
      },
      gpu_mem_size_sum = {
        desc    = "Compute statistics about memory transfer traces (in Size)",
        default = false
      }
    }

consts._IDX_CONSTRUCTOR_STOP = 1
consts._IDX_MAIN_START = 1
consts._IDX_MAIN_STOP = 2
consts._IDX_DESTRUCTOR_START = 2
consts._IDX_DESTRUCTOR_STOP = 3

return consts