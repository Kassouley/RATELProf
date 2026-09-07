local consts = {}
ratelprof.consts = consts

-- consts._LUA_PATH     = os.getenv("LUA_PATH") or "."
consts._INSTALL_DIR  = os.getenv("INSTALL_DIR") or "."
consts._LIBS_DIR     = consts._INSTALL_DIR.."/lib/"
consts._MODULES_DIR  = consts._INSTALL_DIR.."/share/modules/"
consts._HTML_DIR     = consts._INSTALL_DIR.."/share/visualize/"


local major, minor, patch = 1, 4, 0
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
  -- {name = consts._LIBS_NAME.WRAPPERS,  path = consts._LIBS.WRAPPERS},
  {name = consts._LIBS_NAME.RATELPROF, path = consts._LIBS.RATELPROF},
}

consts._DEFAULT_PLUGIN = consts._LIBS.PLUGIN_RPROFREP

consts._HTML_REPORT_PATH   = consts._MODULES_DIR.."/html/index.min.html"

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
      DOMAIN_MEMORY =       "RATELPROF_DOMAIN_MEMORY",
      DOMAIN_PROFILING =    "RATELPROF_DOMAIN_PROFILING",
      DOMAIN_OMPT =         "RATELPROF_DOMAIN_OMP_REGION",
      DOMAIN_ROCTX =        "RATELPROF_DOMAIN_ROCTX",
      DOMAIN_MPI =          "RATELPROF_DOMAIN_MPI",
      DOMAIN_RCCL =         "RATELPROF_DOMAIN_RCCL",
      DOMAIN_ROCBLAS =      "RATELPROF_DOMAIN_ROCBLAS",
    }

consts.DOMAIN_HSA_ID          = 0
consts.DOMAIN_OMP_TGT_RTL_ID  = 1
consts.DOMAIN_ROCBLAS_ID      = 2
consts.DOMAIN_OMP_TGT_ID      = 3
consts.DOMAIN_HIP_ID          = 4
consts.DOMAIN_RCCL_ID         = 5
consts.DOMAIN_MPI_ID          = 6
consts.DOMAIN_OMPT_ID         = 7
consts.DOMAIN_ROCTX_ID        = 8
consts.DOMAIN_PROFILING_ID    = 9
consts.DOMAIN_MEMORY_ID       = 10
consts.DOMAIN_KERNEL_ID       = 11
consts.DOMAIN_BARRIERAND_ID   = 12
consts.DOMAIN_BARRIEROR_ID    = 13


consts._DOMAIN_NAME = {
  [consts.DOMAIN_HIP_ID]          = "HIP API",
  [consts.DOMAIN_HSA_ID]          = "HSA API",
  [consts.DOMAIN_OMP_TGT_ID]      = "OpenMP Target Routine",
  [consts.DOMAIN_OMP_TGT_RTL_ID]  = "OpenMP Target RTL",
  [consts.DOMAIN_BARRIEROR_ID]    = "Barrier OR Dispatch",
  [consts.DOMAIN_BARRIERAND_ID]   = "Barrier AND Dispatch",
  [consts.DOMAIN_KERNEL_ID]       = "Kernel Dispatch",
  [consts.DOMAIN_MEMORY_ID]       = "Memory Operations",
  [consts.DOMAIN_PROFILING_ID]    = "HSA for RATELProf",
  [consts.DOMAIN_OMPT_ID]         = "OpenMP Target Region",
  [consts.DOMAIN_ROCTX_ID]        = "ROCtx",
  [consts.DOMAIN_MPI_ID]          = "MPI API",
  [consts.DOMAIN_RCCL_ID]         = "RCCL",
  [consts.DOMAIN_ROCBLAS_ID]      = "rocBLAS",
}

consts._GPU_DOMAIN = {
  [consts.DOMAIN_BARRIEROR_ID]    = true,
  [consts.DOMAIN_BARRIERAND_ID]   = true,
  [consts.DOMAIN_KERNEL_ID]       = true,
  [consts.DOMAIN_MEMORY_ID]       = true,
}

consts._CPU_DOMAIN = {}
for id, _ in pairs(consts._DOMAIN_NAME) do
  if not consts._GPU_DOMAIN[id] then
    consts._CPU_DOMAIN[id] = true
  end
end

consts._TRACED_LIB_PATH = {
  ["omp-routine"]   = false,
  ["omp-target"]   = "$ROCM_PATH/llvm/lib/libomptarget.rtl.amdgpu.so",
  ["hsa"]           = false,
  ["hip"]           = false,
  ["rccl"]          = false,
  ["rocblas"]       = false,
  ["mpi"]           = false,
}


consts._TRACES = {
  ['hip'] =           {var=consts._ENV.DOMAIN_HIP,          name="HIP API"}, 
  ['hsa'] =           {var=consts._ENV.DOMAIN_HSA,          name="HSA API"},
  ['omp-routine'] =   {var=consts._ENV.DOMAIN_OMP_TGT,      name="OpenMP Target Routine"},
  ['omp-region'] =    {var=consts._ENV.DOMAIN_OMPT,         name="OpenMP Target Region"},
  ['omp-target'] =    {var=consts._ENV.DOMAIN_OMP_TGT_RTL,  name="OpenMP Target RTL"},
  ['hsa-for-rprof'] = {var=consts._ENV.DOMAIN_PROFILING,    name="HSA for RATELProf"},
  ['kernel'] =        {var=consts._ENV.DOMAIN_KERNEL,       name="Kernel Dispatch"},
  ['memory'] =        {var=consts._ENV.DOMAIN_MEMORY,       name="Memory Operations"},
  ['roctx'] =         {var=consts._ENV.DOMAIN_ROCTX,        name="ROCtx"},
  ['rccl'] =          {var=consts._ENV.DOMAIN_RCCL,         name="RCCL"},
  ['rocblas'] =       {var=consts._ENV.DOMAIN_ROCBLAS,      name="rocBLAS"},
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
                          consts._ENV.DOMAIN_ROCBLAS,
                          consts._ENV.DOMAIN_RCCL,
                          consts._ENV.DOMAIN_HIP},         name="CPU Activity"},
  ['gpu'] =           {var={
                          consts._ENV.DOMAIN_KERNEL,
                          consts._ENV.DOMAIN_MEMORY,
                          consts._ENV.DOMAIN_BARRIEROR,
                          consts._ENV.DOMAIN_BARRIERAND},  name="GPU Activity"},
  ['omp'] =           {var={
                          consts._ENV.DOMAIN_OMP_TGT,
                          consts._ENV.DOMAIN_OMP_TGT_RTL,
                          consts._ENV.DOMAIN_OMPT},        name="OpenMP API"},
  ['runtime'] =       {var={
                          consts._ENV.DOMAIN_ROCBLAS,
                          consts._ENV.DOMAIN_RCCL,
                          consts._ENV.DOMAIN_MPI,
                          consts._ENV.DOMAIN_ROCTX,
                          consts._ENV.DOMAIN_OMP_TGT,
                          consts._ENV.DOMAIN_OMPT,
                          consts._ENV.DOMAIN_HIP,
                          consts._ENV.DOMAIN_KERNEL,
                          consts._ENV.DOMAIN_MEMORY},  name="Runtime Activity"},
  ['all'] =           {var={
                          consts._ENV.DOMAIN_ROCBLAS,
                          consts._ENV.DOMAIN_RCCL,
                          consts._ENV.DOMAIN_MPI,
                          consts._ENV.DOMAIN_ROCTX,
                          consts._ENV.DOMAIN_OMP_TGT,
                          consts._ENV.DOMAIN_OMP_TGT_RTL,
                          consts._ENV.DOMAIN_OMPT,
                          consts._ENV.DOMAIN_HSA,
                          consts._ENV.DOMAIN_HIP,
                          consts._ENV.DOMAIN_KERNEL,
                          consts._ENV.DOMAIN_MEMORY,
                          consts._ENV.DOMAIN_BARRIEROR,
                          consts._ENV.DOMAIN_BARRIERAND},  name="All Activity"},
  ['none'] =          {var = nil,                          name="No Traces"},
}