#!/usr/bin/env lua
local json = require("bin.lua.utils.json.json")

local function usage()
    print([[
Usage: set_install.lua <sett.config>

Arguments:
  sett.config       JSON file containing build options
]])
    os.exit(1)
end


local function resolve_env_var(path)
    -- Replace $VAR or ${VAR} with the environment variable value
    path = path:gsub("%${(.-)}", function(var) return os.getenv(var) or "" end)
    path = path:gsub("%$(%w+)", function(var) return os.getenv(var) or "" end)
    return path
end


-- Read command-line argument
local config_file = arg[1] or "./sett.config"

-- Load JSON file
local function load_json(file)
    local f = io.open(file, "r")

    if f then
        local content = f:read("*a")
        f:close()
        return JSON:decode(content)
    else
        print("Error: JSON config file '" .. file .. "' not found.")
        usage()
    end
end

local config = load_json(config_file)

-- Helper: get nested value up to 3 levels
local function get_json_value(...)
    local keys = {...}
    local v = config

    for _, key in ipairs(keys) do
        if type(v) ~= "table" or v[key] == nil then
            print("sett error: get_json_value: key '" .. key .. "' does not exist in JSON")
            os.exit(1)
        end
        v = v[key]
    end

    return v
end


local cmake_options = {}
local function add_cmake_option(option, value)
    if value and value ~= "AUTO" then
        table.insert(cmake_options, "-D"..option.."="..value)
    end
end

-- Feature parsing
local function parse_feature(feature, key, option)
    local build = get_json_value("features", feature, "build")
    local feature_macro = feature:upper()
    local build_opt_name = "BUILD_" .. feature_macro

    if build == true then
        local value = get_json_value("features", feature, key)
        add_cmake_option(option,  value)
    end
    add_cmake_option(build_opt_name,  build  and "ON" or "OFF")
end

-- Read top-level options
local install_dir = get_json_value("options", "install_dir") or (os.getenv("HOME") .. "/.local")
install_dir = resolve_env_var(install_dir:gsub("/$", "") .. "/ratelprof")

local build_dir = "build"
add_cmake_option("CMAKE_INSTALL_PREFIX", install_dir)

-- Toolchain
local cc_compiler       = get_json_value("toolchain", "CC")
local cxx_compiler      = get_json_value("toolchain", "CXX")
local hipcc_compiler    = get_json_value("toolchain", "HIPCC")

add_cmake_option("CMAKE_C_COMPILER",   cc_compiler)
add_cmake_option("CMAKE_CXX_COMPILER", cxx_compiler)
add_cmake_option("HIPCC_COMPILER",     hipcc_compiler)

-- Plugins
local build_plugin_stdout    = get_json_value("plugins", "stdout")
local build_plugin_msgpack   = get_json_value("plugins", "msgpack")
add_cmake_option("BUILD_PLUGIN_STDOUT",  build_plugin_stdout  and "ON" or "OFF")
add_cmake_option("BUILD_PLUGIN_MSGPACK", build_plugin_msgpack and "ON" or "OFF")

-- Options
local check_symbol_quiet = get_json_value("options", "check_symbol_quiet")
add_cmake_option("CHECK_SYMBOL_QUIET",  check_symbol_quiet  and "ON" or "OFF")

-- Features
parse_feature("hip_tracing",          "include_dir", "HIP_INCLUDE_DIR")
parse_feature("hsa_tracing",          "include_dir", "HSA_INCLUDE_DIR")
parse_feature("omp_routine_tracing",  "include_dir", "OMP_ROUTINE_INCLUDE_DIR")
parse_feature("mpi_tracing",          "include_dir", "MPI_INCLUDE_DIR")
parse_feature("omp_tgt_rtl_tracing",  "library",     "OMP_TGT_RTL_LIB")
-- parse_feature("ompt_tracing",         "include_dir", "OMPT_INCLUDE_DIR")

-- Run CMake
os.execute("cmake -B " .. build_dir .. " " .. table.concat(cmake_options, " "))
os.execute("cmake --build " .. build_dir)
os.execute("cmake --install " .. build_dir)

print("Installed to " .. install_dir)

-- Check and optionally add bin dir to PATH
local bin_dir = install_dir.."/bin"
local path = os.getenv("PATH") or ""

if not path:find(bin_dir, 1, true) then
    print(bin_dir .. " is not in your PATH.")
    io.write("Do you want to add it to your PATH permanently? (y/n): ")
    local answer = io.read()
    if answer:lower() == "y" then
        local shell = os.getenv("SHELL") or ""
        local shell_config = nil

        if     shell:find("bash")   then shell_config = os.getenv("HOME") .. "/.bashrc"
        elseif shell:find("zsh")    then shell_config = os.getenv("HOME") .. "/.zshrc"
        elseif shell:find("fish")   then shell_config = os.getenv("HOME") .. "/.config/fish/config.fish" end

        if shell_config then
            local f = io.open(shell_config, "a")
            if f then
                f:write('export PATH="' .. bin_dir .. ':$PATH"\n')
                f:close()
                print(bin_dir .. " has been added to your PATH permanently in " .. shell_config)
            else
                print("sett error: " .. shell_config .. " doesn't exist.")
            end
        else
            print("Could not determine shell config. Add " .. bin_dir .. " to PATH manually.")
        end
    else
        print("To use the installed binaries, run: export PATH=\"" .. bin_dir .. ":$PATH\"")
    end
else
    print(bin_dir .. " is already in your PATH.")
end
