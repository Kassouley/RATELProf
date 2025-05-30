-- visualize.lua
local lfs = require("lfs")
local merge_html = require("merge_html")
local merge_js = require("merge_js")
local merge_css = require("merge_css")

local function main(arg)
    local output_dir = arg[1] or "."
    local absolute_path = lfs.get_script_path(1).."../"
    local file = nil

    file = lfs.open_file(absolute_path.."index.min.html", "r")
    local html_content = file:read("*all")
    file:close()
    
    file = lfs.open_file(absolute_path.."vis/vis-timeline-graph2d.min.js", "r")
    local vis_js_content = file:read("*all")
    file:close()

    file = lfs.open_file(absolute_path.."vis/vis-timeline-graph2d.min.css", "r")
    local vis_css_content = file:read("*all")
    file:close()


    html_content = merge_html.minify(html_content)
    html_content = merge_css.process(html_content, absolute_path)
    html_content = merge_js.process(html_content, absolute_path)


    html_content = merge_html.embed_assets_into_html(html_content, vis_js_content, vis_css_content, absolute_path)

    local output_file = io.open(output_dir.."/index.min.html", "w")
    output_file:write(html_content)
    output_file:close()

end

-- Run the main function
main(arg)
