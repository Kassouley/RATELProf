# RATELProf

RATELProf is a powerful and lightweight profiler designed specifically for AMD GPU applications. It enables detailed profiling by tracing GPU activities, and runtime API calls from HSA, HIP, and OpenMP. This tool is ideal for developers and researchers aiming to optimize GPU-accelerated applications.

##  Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Comparison with ROCprof v3](#comparison-with-rocprof-v3)
- [Future Work and Improvement](#future-work-and-improvement)
- [Project Structure](#project-structure)
- [Contribution](#contribution)

---

##  Features

RATELProf provides a comprehensive suite of tools to profile, analyze, and optimize AMD GPU applications. Key features include:

#### **GPU Activity Profiling**
- Monitor kernel dispatches, barriers and memory transfers to identify bottlenecks and optimize GPU performance.

#### **Runtime API Tracing**
- Trace calls from HSA, HIP, MPI, and OpenMP runtimes, offering deep insights into application behavior.

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

4. **`summarize`** 
   - Output global metrics and plot to get insight of your application.

5. **`visualize`**  
   - Generates an interactive HTML timeline report for the .rprof-rep profile report created by the `profile` command.  
   - Perfect for visualizing application details.

6. **`inspect`**  
   - Inspects the application binary and outputs a CSV/JSON report containing detailed kernel information.  
   - Use this command to analyze static kernel properties.

7. **`export`**  
   - Export the .rprof-rep report to another type of report (json, arg-info, ...).

---

## **Getting Started**

Installing RATELProf is simple and requires running the provided `set_install.lua` script.

### Prerequisites

Ensure you have the following installed on your system before proceeding:
- **CMake** (version 3.10 or later)
- **Lua** (version 5.1)
- **AMD ROCm** (download from [ROCm's official site](https://github.com/ROCm/ROCm))

### Installation

1. Clone the repository:

```bash
git clone https://github.com/Kassouley/RATELProf
cd RATELProf
```

2. Run the installation script:

```bash
./sett_install.lua
```
By default, the tool will be installed to $HOME/.local. If you want to install it to a custom directory, specify it in the `sett.config` file:

```bash
./sett_install.lua /path/to/sett.config
```

##  Comparison with ROCprof v3

| Attribute                         | ROCprof v3                                      | RATELProf                                    |
|-----------------------------------|-------------------------------------------------|----------------------------------------------|
| **GPU Architecture Support**      | AMD RDNA, CDNA (ROCm-compatible GPUs)           | AMD RDNA, CDNA (ROCm-compatible GPUs)        |
| **HIP Tracing**                   | ✅                                              | ✅                                           |
| **HSA Tracing**                   | ✅                                              | ✅                                           |
| **rocBLAS Tracing**               | ❌                                              | ❌ But can be easily implemented with GILDA  |
| **RCCL Tracing**                  | ✅                                              | ❌ But can be easily implemented with GILDA  |
| **Marker Tracing**                | ✅ (ROCTx)                                      | ✅ (ROCTx)                                   |
| **OpenMP Routine Tracing**        | ❌                                              | ✅                                           |
| **OpenMP Target RTL Tracing**     | ❌                                              | ✅                                           |
| **OMPT Integration**              | ✅                                              | ✅                                           |
| **MPI Tracing**                   | ❌                                              | ✅                                           |
| **Scratch Memory Tracing**        | ✅                                              | ❌                                           |
| **Memory transfers Profiling**    | ✅                                              | ✅                                           |
| **Kernel dispatch Profiling**     | ✅                                              | ✅                                           |
| **Barrier dispatch Profiling**    | ❌                                              | ✅                                           |
| **Trace filtering**               | ❌                                              | ✅                                           |
| **PC Sampling**                   | ✅ (Beta)                                       | ❌                                           |
| **HW Counter**                    | ✅                                              | ❌ (WIP)                                     |
| **Statistical post processing**   | ✅ but really simple post processing            | ✅                                           |
| **Post processing analysis**      | ❌                                              | ✅                                           |
| **Output Formats**                | CSV, JSON                                       | Binary (rprof-rep), CSV, TSV, JSON, TXT      |
| **Output Size**                   | Large                                           | Small (msgpack binary format)                |
| **Visualization Tools**           | External (Perfetto)                             | Integrated                                   |
| **Ease of Use**                   | Medium (requires scripting for deeper analysis) | Easy, run and play                           |


##  Future Work and Improvement

While the current version provides a functional profiling workflow, there are several areas identified for future enhancement:

- **Hardware Counter Support**: Support for hardware performance counters. These metrics are crucial for low-level performance analysis and are planned to be implemented.

- **Barrier Dispatch Reliability**: Certain applications may encounter issues with barrier dispatch tracking. Investigating edge cases is on the roadmap.

- **Documentation**: A full and detailed documentation is work in progress.

Community feedback and contributions are welcome to help guide and accelerate these improvements.


##  Project Structure

```sh
└── RATELProf/
    ├── CMakeLists.txt
    ├── install.sh
    ├── README.md
    ├── bin/
    │   ├── lua/
    │   ├── ratelprof.sh
    ├── share/
    │   ├── modules/
    │   │      ├── lua/
    │   │      ├── html/
    │   ├── visualize/
    └── src/
        ├── lua/
        ├── tools/
        ├── core/
        ├── ext/
        ├── wrappers/
        ├── common/
        └── plugins/
```

- **`bin/`**  
  Contains executable scripts and lua command scripts:
  - **`lua/`**: Lua scripts used for tooling.
  - **`ratelprof.sh`**: Main shell script to launch RATELProf.

- **`share/`**  
  Contains shared assets used by the tool:
  - **`modules/`**: Modular components of the tool.
    - **`lua/`**: Built-in and user Lua modules for Analyze and Stats scripts.
    - **`html/`**: Minified and unified HTML report from visualize directory.
  - **`visualize/`**: HTML code used for the visualizing report.

- **`src/`**  
  Core source code of RATELProf:
  - **`lua/`**: C Stub for Lua modules.
  - **`tools/`**: Main tool src file.
  - **`core/`**: Core logic of the tool (auto generated by GILDA).
  - **`ext/`**: Extension logic of the tool (source of GPU profiling logic).
  - **`wrappers/`**: API wrappers for hooking into applications or libraries (e.g., HIP, HSA, ...).
  - **`plugins/`**: Built-in plugins for callbacks definition.
  - **`common/`**: Common source code to lua stub libraries and RATELProf

##  Contribution

Contributions to RATELProf are welcome and appreciated! Whether you're fixing bugs, improving documentation, adding new features, or optimizing performance, your input helps make this tool better for everyone.

### Guidelines

- Follow existing code style and structure.
- Keep changes focused and well-documented.
- For major changes, open an issue to discuss first.

Thanks for contributing!
