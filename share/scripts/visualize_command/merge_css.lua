local lfs = require("lfs")
local merge_css = {}

local function concat_css_files(css_files)
        local css_contents = {}
        for _, css_file in ipairs(css_files) do
                local file = lfs.open_file(css_file, "r")
                local content = file:read("*all")
                file:close()
                table.insert(css_contents, content)
        end
        return table.concat(css_contents, "\n")
end


local function extract_css_paths(html, absolute_path)
    local paths = {}

    -- Pattern to match <link rel="stylesheet" href=PATH>
    html = html:gsub('<link%s+rel="stylesheet"%s+href="([^"]+)">', function(path)
        if lfs.file_exists(absolute_path..path) then
                table.insert(paths, absolute_path..path)
                return ""
        end
    end)

    return paths, html
end

local function minify(css_content)
    -- Remove comments
    local minified = css_content:gsub("/%*.-%*/", "")

    -- Remove newlines and excessive whitespace
    minified = minified:gsub("%s+", " ")

    -- Remove spaces around braces, colons, semicolons, and commas
    minified = minified:gsub("%s*{%s*", "{")
    minified = minified:gsub("%s*}%s*", "}")
    minified = minified:gsub("%s*;%s*", ";")
    minified = minified:gsub("%s*:%s*", ":")
    minified = minified:gsub("%s*,%s*", ",")

    -- Remove trailing semicolon in a block
    minified = minified:gsub(";}", "}")

    return minified
end


-- Function: Process CSS
function merge_css.process(html, absolute_path)
    local css_files, updated_html = extract_css_paths(html, absolute_path)
    local css_content = concat_css_files(css_files)
    css_content = minify(css_content)
    return css_content, updated_html
end


return merge_css