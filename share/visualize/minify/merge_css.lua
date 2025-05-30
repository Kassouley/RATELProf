local lfs = require ("lfs")

local merge_css = {}

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
    html = html:gsub('<link%s+rel="stylesheet"%s+href="([^"]+)">', function(path)
        path = absolute_path..path
        if lfs.file_exists(path) then
                local file = lfs.open_file(path, "r")
                local content = minify(file:read("*all"))
                file:close()
                return "<style>"..content.."</style>"
        end
    end)
    html = html:gsub('</style><style>', function() return "" end)
    return html
end


return merge_css