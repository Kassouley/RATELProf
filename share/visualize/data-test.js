gpuLabels = ["Name", "Marketing Name", "Node", "Device Type", "Uuid", "Feature", "Nearest CPU", "Compute Unit", "SIMDs per CU", "Shader Engines", "Shader Arrs. per Eng.", "Wavefront Size", "Max Waves Per CU", "Max Queue Number", "Queue Min Size", "Queue Max Size", "Queue Type", "Cache Info", "       L1", "       L2", "       L3", "Chip ID", "Cacheline Size", "Max Clock Freq. (MHz)", "Driver UID", "Internal Node ID", "Max Work-item Per CU", "Workgroup Max Size per Dimension", "       x", "       y", "       z", "Grid Max Size", "Grid Max Size per Dimension", "       x", "       y", "       z", "Max fbarriers/Workgrp"], 
gpuDatasets = [
    {
        'Node 1': ["gfx1030", "AMD Radeon PRO W6800", "1", "GPU", "GPU-33ae733b627e51d1", "KERNEL DISPATCH", "0", "60", "2", "4", "2", "32(0x20)", "32(0x20)", "128(0x80)", "64(0x40)", "131072(0x20000)", "MULTI", "", "16384(0x4000) KB", "4194304(0x400000) KB", "134217728(0x8000000) KB", "29603(0x73A3)", "64(0x40)", "2555", "35549", "1", "1024(0x400)", "", "1024(0x400)", "1024(0x400)", "1024(0x400)", "4294967295(0xFFFFFFFF)", "", "4294967295(0xFFFFFFFF)", "4294967295(0xFFFFFFFF)", "4294967295(0xFFFFFFFF)", "32"]
    },
], reportData = {
    profilingSummary: {
        title: 'Profiling Summary',
        rows: [{
            label: 'App Time (s)',
            value: '336532473',
            tooltip: 'Application total time'
        }, {
            label: 'GPU Active Time (s)',
            value: '70842',
            tooltip: 'Total GPU time including all kernels and copies'
        }, {
            label: 'GPU Compute Time (s)',
            value: '21681',
            tooltip: 'Total time spent in all kernels'
        }, {
            label: 'GPU Copy Time (s)',
            value: '49161',
            tooltip: 'Total time spent in all memory transfers'
        }, {
            label: 'Hidden Copy Score ()',
            value: 'nan',
            tooltip: 'Percentage of copy hidden by kernel computation. Higher is better.'
        }, {
            label: 'Longest GPU Activity',
            value: 'CopyHostToDeviceCopyHostToDeviceCopyHostToDeviceCopyHostToDeviceCopyHostToDeviceCopyHostToDeviceCopyHostToDeviceCopyHostToDeviceCopyHostToDeviceCopyHostToDeviceCopyHostToDeviceCopyHostToDevice',
            tooltip: 'Longest GPU activity. Can be a kernel or copy operation.'
        }, {
            label: 'Total bytes transfered',
            value: '120000',
            tooltip: 'Total bytes transferred from/to GPU by memory transfers.'
        }]
    },
    potentialSpeedUp: {
        title: 'Potential Speed Up',
        rows: [{
            label: 'Perfect Async Copy',
            value: '12.826380270243',
            tooltip: 'Speed up if all copies were 100 asynchronous'
        }, {
            label: 'Perfect Hidden Copy',
            value: '1',
            tooltip: 'Speed up if all copies were hidden by kernels'
        }, {
            label: 'Kernel Coalescing',
            value: '1',
            tooltip: 'Speed up if all coalescable kernels were coalesced'
        }]
    },
    experimentInfo: {
        title: 'Experiment Info',
        rows: [{
            label: 'Application',
            value: '../../random/hip-test/a.out (ret: 0)'
        }, {
            label: 'Date',
            value: 'N/A'
        }, {
            label: 'Tool Version',
            value: '1.0.0'
        }, {
            label: 'Report File',
            value: 'test.rprof-rep'
        }]
    }
}, domain_table = {
    "RATELPROF_DOMAIN_HSA": {
        "name": "HSA API",
        "desc": "HSA is an AMD low-level library that operates behind the scenes of HIP and OpenMP, enabling communication between CPUs and GPUs for parallel processing. This domain will be only useful for expert or debugging."
    },
    "RATELPROF_DOMAIN_BARRIEROR": {
        "name": "Barrier OR Dispatch",
        "desc": "The Barrier OR is a less restrictive synchronization mechanism that allows subsequent operations to proceed as soon as any one of the specified preceding operations has completed."
    },
    "RATELPROF_DOMAIN_KERNEL": {
        "name": "Kernel Dispatch",
        "desc": "The kernel dispatch operation is the process of launching a computational kernel on the GPU."
    },
    "RATELPROF_DOMAIN_BARRIERAND": {
        "name": "Barrier AND Dispatch",
        "desc": "The Barrier AND is a synchronization primitive that ensures all preceding operations in the command queue have completed before subsequent operations can begin."
    },
    "RATELPROF_DOMAIN_OMP_ROUTINE": {
        "name": "OpenMP Target Routine",
        "desc": "OpenMP Target is a runtime library that provides routines for managing data movement, memory mapping, etc."
    },
    "RATELPROF_DOMAIN_OMP_TGT_RTL": {
        "name": "OpenMP Target RTL",
        "desc": "Refers to the target runtime library in the OpenMP programming model, working behind the scenes to execute '#pragma omp target' directives by managing data transfers and kernel execution on GPUs."
    },
    "RATELPROF_DOMAIN_COPY": {
        "name": "Memory Transfer",
        "desc": "The copy operation in GPU programming is responsible for transferring data between memory locations (between host and device memory or between different regions of GPU memory)."
    },
    "RATELPROF_DOMAIN_HIP": {
        "name": "HIP API",
        "desc": "HIP is a programming framework used to launch GPU operations such as kernel dispatch or memory transfer. This domain is useful for anyone looking to understand and optimize the interactions between the CPU and GPU in programming."
    },
    "RATELPROF_DOMAIN_PROFILING": {
        "name": "HSA for RATELProf",
        "desc": "The profiling domain correspond to all HSA function used by RATELProf for GPU Profiling"
    },
    "RATELPROF_DOMAIN_OMP_REGION": {
        "name": "OpenMP Target Region",
        "desc": "OpenMP Target region traces given by the OMPT API"
    }
}, lifecycle_table = {
    "fini_stop": 352915985,
    "main_start": 16457451,
    "main_stop": 343331587,
    "init_start": 16383512
}, csvDataPerTab = {
    "stats": {
        "hip_api_sum": {
            content: ['App Time (%),API Time (%),Total Time (ns),Num Calls,Avg (ns),Med (ns),Min (ns),Max (ns),StdDev (ns),Name', '92.22,95.05,3.103e+08,3.000e+00,1.034e+08,1.254e+06,5.449e+04,3.090e+08,1.454e+08,hipMemcpy', '4.66,4.80,1.569e+07,3.000e+00,5.229e+06,3.808e+03,1.322e+03,1.568e+07,7.391e+06,hipMalloc', '0.13,0.13,4.328e+05,1.000e+00,4.328e+05,4.328e+05,4.328e+05,4.328e+05,0.000e+00,hipLaunchKernel', '0.01,0.01,2.269e+04,3.000e+00,7.564e+03,2.454e+03,1.964e+03,1.827e+04,7.576e+03,hipFree', '0.00,0.00,7.420e+02,1.000e+00,7.420e+02,7.420e+02,7.420e+02,7.420e+02,0.000e+00,__hipPopCallConfiguration', '0.00,0.00,1.322e+03,1.000e+00,1.322e+03,1.322e+03,1.322e+03,1.322e+03,0.000e+00,__hipPushCallConfiguration', '0.00,0.00,9.920e+02,1.000e+00,9.920e+02,9.920e+02,9.920e+02,9.920e+02,0.000e+00,hipDeviceSynchronize']
        },
        "gpu_sum": {
            content: ['App Time (%),API Time (%),Total Time (ns),Instances,Avg (ns),Med (ns),Min (ns),Max (ns),StdDev (ns),Category,Operation', '0.01,57.59,4.080e+04,2.000e+00,2.040e+04,2.040e+04,1.908e+04,2.172e+04,1.320e+03,MemoryOperation,CopyHostToDevice', '0.01,30.60,2.168e+04,1.000e+00,2.168e+04,2.168e+04,2.168e+04,2.168e+04,0.000e+00,KernelDispatch,"kernel_gpuXmm_aux(unsigned int, unsigned int, unsigned int, float const*, float const*, float*) [clone .kd]"', '0.00,11.80,8.360e+03,1.000e+00,8.360e+03,8.360e+03,8.360e+03,8.360e+03,0.000e+00,MemoryOperation,CopyDeviceToHost']
        },
        "gpu_kern_sum": {
            content: ['App Time (%),API Time (%),Total Time (ns),Instances,Avg (ns),Med (ns),Min (ns),Max (ns),StdDev (ns),Total QTime (ns),QAvg (ns),QMed (ns),QMin (ns),QMax (ns),QStdDev (ns),GridX,GridY,GridZ,BlockX,BlockY,BlockZ,Name', '0.01,100.00,2.168e+04,1.000e+00,2.168e+04,2.168e+04,2.168e+04,2.168e+04,0.000e+00,1.461e+04,1.461e+04,1.461e+04,1.461e+04,1.461e+04,0.000e+00,1.280e+02,1.280e+02,1.000e+00,3.200e+01,3.200e+01,1.000e+00,"kernel_gpuXmm_aux(unsigned int, unsigned int, unsigned int, float const*, float const*, float*) [clone .kd]"']
        },
        "gpu_mem_time_sum": {
            content: ['App Time (%),API Time (%),Total Time (ns),Count,Avg (ns),Med (ns),Min (ns),Max (ns),StdDev (ns),Operation', '0.01,82.99,4.080e+04,2.000e+00,2.040e+04,2.040e+04,1.908e+04,2.172e+04,1.320e+03,CopyHostToDevice', '0.00,17.01,8.360e+03,1.000e+00,8.360e+03,8.360e+03,8.360e+03,8.360e+03,0.000e+00,CopyDeviceToHost']
        },
        "gpu_mem_size_sum": {
            content: ['App Time (%),API Time (%),Total (B),Count,Avg (B),Med (B),Min (B),Max (B),StdDev (B),Operation', '0.02,66.67,8.000e+04,2.000e+00,4.000e+04,4.000e+04,4.000e+04,4.000e+04,0.000e+00,CopyHostToDevice', '0.01,33.33,4.000e+04,1.000e+00,4.000e+04,4.000e+04,4.000e+04,4.000e+04,0.000e+00,CopyDeviceToHost']
        }
    },
    "analyze": {
        "hip_memcpy_sync": {
            content: ['Copy ID,API ID,API Name,PID,TID,Operation,Size (MB),CPU Duration (ns),GPU Duration (ns)', '7,6,hipMemcpy,3432400,3432400,CopyHostToDevice,0,5.449e+04,1.908e+04', '13,12,hipMemcpy,3432400,3432400,CopyDeviceToHost,0,1.254e+06,8.360e+03', '5,4,hipMemcpy,3432400,3432400,CopyHostToDevice,0,3.090e+08,2.172e+04']
        }
    }
}, extension_string_array = ["content", "CopyHostToDevice", "id", "start", "subgroup", "dur", "cid", "args", "size", "sig", "engine_id", "dst", "Device Node ID. 1 (971483728)", "src", "Host Node ID. 0 (971459584)", "CopyDeviceToHost", "RATELPROF_DOMAIN_COPY", "hipMalloc", "ptr", "type", "void **", "value", "size_t", "retval", "hipError_t", "pid", "tid", "hipMemcpy", "kind", "hipMemcpyKind", "sizeBytes", "const void *", "void *", "__hipPushCallConfiguration", "sharedMem", "gridDim", "struct dim3", "y", "uint32_t", "x", "z", "blockDim", "stream", "hipStream_t", "__hipPopCallConfiguration", "size_t *", "dim3 *", "hipStream_t *", "hipLaunchKernel", "dimBlocks", "numBlocks", "function_address", "sharedMemBytes", "hipFree", "hipDeviceSynchronize", "RATELPROF_DOMAIN_HIP", "\"kernel_gpuXmm_aux(unsigned int, unsigned int, unsigned int, float const*, float const*, float*) [clone .kd]\"", "private_segment_size", "kernel_object", "group_segment_size", "grd", "wrg", "queue_id", "gpu_id", "1 (971483728)", "kernarg_address", "dispatch_time", "RATELPROF_DOMAIN_KERNEL"]
