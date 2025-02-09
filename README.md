# RATELProf

RATELProf is a powerful and lightweight profiler designed specifically for AMD GPU applications. It enables detailed profiling by tracing GPU activities, and runtime API calls from HSA, HIP, and OpenMP. This tool is ideal for developers and researchers aiming to optimize GPU-accelerated applications.

##  Table of Contents

- [Features](#-features)
- [Getting Started](#-getting-started)
  - [Prerequisites](#-prerequisites)
  - [Installation](#-installation)
- [Project Structure](#-project-structure)

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
   - Profiles the application and generates a detailed JSON report.  
   - This command captures kernel execution, memory transfers, and runtime API details.

2. **`stats`**  
   - Computes statistical summaries from a JSON report created by the `profile` command.  
   - Output includes detailed metrics similar to the `stat` command from NVIDIA's Nsight Systems.

3. **`visualize`**  
   - Generates an interactive HTML timeline report for the JSON profile report created by the profile command.  
   - Perfect for visualizing application details.

4. **`inspect`**  
   - Inspects the application and outputs a CSV report containing detailed kernel information.  
   - Use this command to analyze kernel properties and optimize your code further.

---

## **Getting Started**

Installing RATELProf is simple and requires running the provided `install.sh` script.

### Prerequisites

Ensure you have the following installed on your system before proceeding:
- **CMake** (version 3.10 or later)
- **AMD ROCm Toolkit** (download from [ROCm's official site](https://github.com/ROCm/ROCm))

### Installation

1. Clone the repository:

```bash
git clone https://github.com/Kassouley/RATELProf
cd RATELProf
```

2. Run the installation script:

```bash
./install.sh
```
By default, the tool will be installed to $HOME/.local. If you want to install it to a custom directory, specify it as an argument:

```bash
./install.sh /custom/install/path
```

##  Project Structure

```sh
└── RATELProf/
    ├── CMakeLists.txt
    ├── install.sh
    ├── README.md
    ├── bin
    │   ├── ratelprof.sh
    ├── share
    │   ├── ratelinfo
    │   ├── scripts
    │   ├── visualize
    └── src
        ├── tools
        ├── core
        ├── ext
        ├── wrappers
        └── plugins
```
