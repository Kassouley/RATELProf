local consts = {}

consts._LUA_PATH     = os.getenv("LUA_PATH") or "."
consts._INSTALL_DIR  = os.getenv("INSTALL_DIR") or "."
consts._LIBS_DIR     = consts._INSTALL_DIR.."/lib/"
consts._MODULES_DIR  = consts._INSTALL_DIR.."/share/modules/"

consts._VERSION = "1.0"

package.cpath = consts._LIBS_DIR.."lua/?.so;" .. package.cpath
package.path  = consts._MODULES_DIR.."lua/?.lua;" .. package.path

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
  {name = consts._LIBS_NAME.RATELPROF, path = consts._LIBS.RATELPROF},
  {name = consts._LIBS_NAME.WRAPPERS,  path = consts._LIBS.WRAPPERS}
}

consts._DEFAULT_PLUGIN = consts._LIBS.PLUGIN_MSGPACK    

consts._HTML_REPORT_PATH = consts._MODULES_DIR.."/html/index.min.html"

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
  [consts._ENV.DOMAIN_OMPT]         = "OpenMP Target Region"
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
}


consts._ALL_RULES_REPORT = {
    __default_report_path = consts._MODULES_DIR.."lua/rules/",

    hip_memcpy_async = {
      desc    = "Show HIP API synchronous memory copy that should be async",
      default = true
    },
    hip_memcpy_sync = {
      desc    = "Show HIP API synchronous memory copy that block the CPU",
      default = true
    },
    gpu_idle = {
      desc    = "Compute GPU time where no kernel is running",
      default = true
    },
    hidden_transfers = {
      desc    = "TODO",
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

return consts