local lfs   = require ("utils.lfs")
local utils = require ("utils.utils")

local settings = {}

settings._INSTALL_DIR = utils.execute_command("realpath "..lfs.get_script_path(1).."../../")

settings._VERSION = "1.0"

settings._TRACES = {
      {var="RATELPROF_DOMAIN_HSA",            name="HSA",                 option="hsa-trace"},
      {var="RATELPROF_DOMAIN_HIP",            name="HIP",                 option="hip-trace"},
      {var="RATELPROF_DOMAIN_OMP_TGT",        name="OpenMP Target",       option="omp-tgt-trace"},
      {var="RATELPROF_DOMAIN_OMP_TGT_RTL",    name="OpenMP Target RTL",   option="omp-tgt-rtl-trace"}
    }

settings._ENV = {
      FUNCTION_FILTERED =   "RATELPROF_DOMAIN_%s_FUNCTIONS_FILTERED",
      FILTER_TYPE =         "RATELPROF_DOMAIN_%s_FILTER_TYPE",
      PLUGIN_PATH =         "RATELPROF_PLUGIN_PATH",
      OUTPUT_FILE =         "RATELPROF_OUTPUT_FILE",
      NB_KERNEL_AV =        "RATELPROF_NB_KERNEL_AVAILABLE",
      NB_QUEUE_AV =         "RATELPROF_MAX_QUEUE_AVAILABLE",
      DOMAIN_PROFILING =    "RATELPROF_DOMAIN_PROFILING"
    }

settings._REPORT_PATH = {
  omp_api_trace         = "reports/omp_api_trace.lua",
  omp_api_sum           = "reports/omp_api_sum.lua",
  omp_target_api_trace  = "reports/omp_target_api_trace.lua",
  omp_target_api_sum    = "reports/omp_target_api_sum.lua",
  hip_api_trace         = "reports/hip_api_trace.lua",
  hip_api_sum           = "reports/hip_api_sum.lua",
  hsa_api_trace         = "reports/hsa_api_trace.lua",
  hsa_api_sum           = "reports/hsa_api_sum.lua",
  gpu_trace             = "reports/gpu_trace.lua",
  gpu_sum               = "reports/gpu_sum.lua",
  gpu_kern_sum          = "reports/gpu_kern_sum.lua",
  gpu_mem_time_sum      = "reports/gpu_mem_time_sum.lua",
  gpu_mem_size_sum      = "reports/gpu_mem_size_sum.lua"
}

settings._ALL_REPORT = {
      {
        name    = "omp_api_trace",
        desc    = "Show all trace about OpenMP Target API",
        default = false
      },
      {
        name    = "omp_api_sum",
        desc    = "Compute statistics about OpenMP Target API traces",
        default = true
      },
      {
        name    = "omp_target_api_trace",
        desc    = "Show all trace about OpenMP Target RTL API",
        default = false
      },
      {
        name    = "omp_target_api_sum",
        desc    = "Compute statistics about OpenMP Target RTL API traces",
        default = true
      },
      {
        name    = "hip_api_trace",
        desc    = "Show all trace about HIP API",
        default = false
      },
      {
        name    = "hip_api_sum",
        desc    = "Compute statistics about HIP API traces",
        default = true
      },
      {
        name    = "hsa_api_trace",
        desc    = "Show all trace about HSA API",
        default = false
      },
      {
        name    = "hsa_api_sum",
        desc    = "Compute statistics about HSA API traces",
        default = true
      },
      {
        name    = "gpu_trace",
        desc    = "Show all trace about GPU activity",
        default = false
      },
      {
        name    = "gpu_sum",
        desc    = "Compute statistics about GPU traces",
        default = true
      },
      {
        name    = "gpu_kern_sum",
        desc    = "Compute statistics about kernel traces",
        default = true
      },
      {
        name    = "gpu_mem_time_sum",
        desc    = "Compute statistics about memory transfer traces (in Time)",
        default = true
      },
      {
        name    = "gpu_mem_size_sum",
        desc    = "Compute statistics about memory transfer traces (in Size)",
        default = false
      }
    }

settings._MEM_KIND = {"Host", "Device"}

return settings