local images_manager = require("images_manager")
local lfs = require ("lfs")

-- Module declaration
local merge_html = {}

-- Function: Minify HTML content
function merge_html.minify(html)
    html = html:gsub("<!%-%-(.-)%-%->", function(comment)
        if comment:match("^%[if") or comment:match("^<!") then
            return "<!--" .. comment .. "-->" -- Preserve conditional comments
        else
            return ""
        end
    end)
    html = html:gsub("^%s+", ""):gsub("%s+$", "") -- Trim whitespace
    html = html:gsub("%s%s+", " ")               -- Collapse multiple spaces
    html = html:gsub("\n", "")                   -- Remove line breaks
    html = html:gsub(">%s+<", "><")              -- Remove spaces between tags
    return html
end

-- Function: Replace images with Base64
local function replace_images_with_base64(html, absolute_path)
    local extensions = {"png", "jpeg", "gif"}
    for _, ext in ipairs(extensions) do
        local pattern = '["\']?([%w%-%_%.\\/]+%.'..ext..')["\']?'
        html = html:gsub(pattern, function(path)
            return '"' .. images_manager.img_to_src(absolute_path..path) .. '"'
        end)
    end
    return html
end

-- Function: Embed CSS and JS into HTML
function merge_html.embed_assets_into_html(html, vis_js_content, vis_css_content, absolute_path)
    html = html:gsub("%<vis%-handler%>", function()
        return "<style>" .. vis_css_content .. "</style><script>" .. vis_js_content .. "\n</script>"
    end)
    html = replace_images_with_base64(html, absolute_path)

    return html
end

return merge_html