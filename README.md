# RATELProf

RATELProf is a powerful and lightweight profiler designed specifically for AMD GPU applications. It enables detailed profiling by tracing GPU activities, and runtime API calls from HSA, HIP, and OpenMP. This tool is ideal for developers and researchers aiming to optimize GPU-accelerated applications.

##  Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Comparison with ROCprof v3](#comparison-with-rocprof-v3)
- [Future Work and Improvement](#future-work-and-improvement)
- [Contribution](#contribution)

---

##  Features

RATELProf provides a comprehensive suite of tools to profile, analyze, and optimize AMD GPU applications. Key features include:

#### **GPU Activity Profiling**
- Monitor kernel dispatches, barriers and memory transfers to identify bottlenecks and optimize GPU performance.

#### **Runtime API Tracing**
- Trace calls from HSA, HIP, and OpenMP runtimes, offering deep insights into application behavior.

#### **Commands**
RATELProf includes four core commands to streamline your profiling workflow:

1. **`profile`**  
   - Profiles the application and generates a detailed .rprof-rep report.  
   - This command captures kernel execution, memory transfers, and runtime API details.

2. **`stats`**  
   - Computes statistical summaries from a .rprof-rep report created by the `profile` command.  
   - Output includes detailed metrics similar to the `stat` command from NVIDIA's Nsight Systems.

3. **`analyze`**  
   - Analyze profiling results from a .rprof-rep report created by the `profile` command.  
   - Output advices to optimize your CPU/GPU code.

4. **`breakdown`**  
   - Give time breakdown information for each PID or GPU.  

5. **`summarize`**  
   - Run `stats`, `analyze` and `breakdown` command to give in terminal view a summary of your profiling report.  

6. **`visualize`**  
   - Generates an interactive HTML timeline report for the .rprof-rep profile report created by the `profile` command.  
   - Perfect for visualizing application details.

7. **`inspect`**  
   - Inspects the application binary and outputs a CSV/JSON report containing detailed kernel information.  
   - Use this command to analyze static kernel properties.

8. **`export`**  
   - Export the .rprof-rep report to another type of report (json, arg-info, ...).

---

## **Getting Started**

Installing RATELProf is simple and requires running the provided `install.sh` script.

### Prerequisites

Ensure you have the following installed on your system before proceeding:
- **CMake** (version 3.10 or later)
- **Lua** (version 5.1)
- **LuaJIT** (optional)
- **AMD ROCm** (download from [ROCm's official site](https://github.com/ROCm/ROCm))

### Installation

1. Clone the repository:

```bash
git clone --recurse-submodules https://github.com/Kassouley/RATELProf.git
cd RATELProf
```

2. Run the installation script:

```bash
lua sett_install.lua
```
By default, the installation script will use the sett.config config file.
Modify this file to custom your installation.

```bash
lua set_install.lua <sett.config>
```

3. Set ENV

If needed, set up your environment variable:
```bash
export PATH=<path/to/ratelprof/bin>:$PATH
export PATH=<path/to/lua5.1/bin>:$PATH
export LD_LIBRARY_PATH=<path/to/hsa/lib/dir>:$LD_LIBRARY_PATH
export LIBRARY_PATH=<path/to/hsa/lib/dir>:$LIBRARY_PATH
```

##  Comparison with ROCprof v3

| Attribute                         | ROCprof v3                                      | RATELProf                                    |
|-----------------------------------|-------------------------------------------------|----------------------------------------------|
| **GPU Architecture Support**      | AMD RDNA, CDNA (ROCm-compatible GPUs)           | AMD RDNA, CDNA (ROCm-compatible GPUs)        |
| **HIP Tracing**                   | ✅                                             | ✅                                           |
| **HSA Tracing**                   | ✅                                             | ✅                                           |
| **rocBLAS Tracing**               | ❌                                             | ❌ But can be easily implemented with GILDA  |
| **RCCL Tracing**                  | ✅                                             | ❌ But can be easily implemented with GILDA  |
| **Marker Tracing**                | ✅ (ROCTx)                                     | ✅ (ROCTx)                                   |
| **OpenMP Routine Tracing**        | ❌                                             | ✅                                           |
| **OpenMP Target RTL Tracing**     | ❌                                             | ✅                                           |
| **OMPT Integration**              | ✅                                             | ✅                                           |
| **Scratch Memory Tracing**        | ✅                                             | ❌                                           |
| **Memory transfers Profiling**    | ✅                                             | ✅                                           |
| **Kernel dispatch Profiling**     | ✅                                             | ✅                                           |
| **Barrier dispatch Profiling**    | ❌                                             | ✅                                           |
| **Trace filtering**               | ❌                                             | ✅                                           |
| **PC Sampling**                   | ✅ (Beta)                                      | ❌                                           |
| **HW Counter**                    | ✅                                             | ❌ (WIP)                                     |
| **Statistical post processing**   | ✅ but really simple post processing           | ✅                                           |
| **Post processing analysis**      | ❌                                             | ✅                                           |
| **Output Formats**                | CSV, JSON                                       | Binary (rprof-rep), CSV, TSV, JSON, TXT      |
| **Output Size**                   | Large                                           | Small (binary format)                        |
| **Visualization Tools**           | External (Perfetto)                             | Integrated                                   |
| **Ease of Use**                   | Medium (requires scripting for deeper analysis) | Easy, run and play                           |
| **Overhead**                      | Low to Medium (depends on config)               | Low                                          |


##  Future Work and Improvement

While the current version provides a functional profiling workflow, there are several areas identified for future enhancement:

- **Hardware Counter Support**: Support for hardware performance counters is a work in progress. These metrics are crucial for low-level performance analysis and are planned to be implemented in the next major release.

- **Barrier Dispatch Reliability**: Certain applications may encounter issues with barrier dispatch tracking. Investigating edge cases is on the roadmap.

- **Documentation**: A full and detailed documentation is work in progress.

Community feedback and contributions are welcome to help guide and accelerate these improvements.

##  Contribution

Contributions to RATELProf are welcome and appreciated! Whether you're fixing bugs, improving documentation, adding new features, or optimizing performance, your input helps make this tool better for everyone.

### Guidelines

- Follow existing code style and structure.
- Keep changes focused and well-documented.
- For major changes, open an issue to discuss first.

Thanks for contributing!
