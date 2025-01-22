-- stats.lua
-- Set up the script directory and package paths
local script_dir = debug.getinfo(1, "S").source:match("@(.*[\\/]?.*)") or ""
script_dir = script_dir:gsub('\\', '/'):match("(.*[\\/])") or ""
local paths = {
    '',
    '../',
    '../utils/',
    '../utils/json/',
}

for _, path in ipairs(paths) do
    package.path = package.path .. ';' .. script_dir .. path .. '?.lua'
end

require("string_ext")
local common = require("common")
local lfs = require("lfs")
local Script = require("Script")
local settings = common.load_json(lfs.get_script_path(1).."visualize_settings.json")
local merge_html = require("merge_html")
local merge_json = require("merge_json")
local merge_js = require("merge_js")
local merge_css = require("merge_css")

local INSTALL_DIR = os.getenv("RATELPROF_INSTALL_DIR")


local function process_visualizing(positional_args, options_values)
    local report_path = positional_args[1]
    local absolute_path = lfs.get_script_path(1).."../../visualize/"
    
    if not lfs.file_exists(report_path) then
        print("Error: Report file doesn't exist.")
        os.exit(1)
    end
    local output_file = lfs.remove_extension(report_path, "json")..'.html'

    local html_file = lfs.open_file(INSTALL_DIR.."/share/visualize/index.html", "r")
    local html_content = html_file:read("*all")
    html_file:close()

    local css_content
    css_content, html_content = merge_css.process(html_content, absolute_path)

    local js_content
    js_content, html_content = merge_js.process(html_content, absolute_path)

    local json_content = merge_json.get_json_data(report_path)

    html_content = merge_html.minify(html_content)

    html_content = merge_html.embed_assets_into_html(html_content, css_content, js_content, json_content, absolute_path)

    local output_file = io.open(output_file, "w")
    output_file:write(html_content)
    output_file:close()
end

-- Main script logic
local function main(arg)
        
    local attribute = {
        name = "ratelprof visualize",
        version = settings._VERSION,
        default_options_values = {}
    }
    local script = Script:new(attribute)

    script:set_desc("\n\tGenerate a HTML report view to see traces as a timeline.")

    script:set_execute_function(process_visualizing)

    script:add_argument("report", false, false, "\tThe JSON report path to visualize.")

    script:execute(arg)
end

-- Run the main function
main(arg)
