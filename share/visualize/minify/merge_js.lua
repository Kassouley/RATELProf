local lfs = require ("lfs")

local merge_js = {}

-- Function to get the directory of a given file path
-- local function get_file_directory(file_path)
--     return file_path:match("(.*/)")
-- end

-- local function concat_js_files(js_files, visited_files)
--     local script_contents = {}
--     visited_files = visited_files or {}
--     for _, js_file in ipairs(js_files) do
--         -- Avoid processing the same file multiple times.
--         if not visited_files[js_file] then
--             visited_files[js_file] = true

--             -- Get the directory of the current file
--             local js_file_directory = get_file_directory(js_file)

--             -- Open the current JS file and read its content.
--             local file = io.open(js_file, "r")
--             if file then
--                 local content = file:read("*all")
--                 file:close()

--                 local imported_js_list = {}
--                 -- Find and remove 'import' statements, and process the imported files recursively.
--                 content = content:gsub("import%s+[^;]*from%s+[\'\"](.-)[\'\"];", function(import_file)
--                         -- Resolve the relative path of the imported file.
--                         local full_import_path = (js_file_directory .. import_file):gsub("/./", "/")
--                         table.insert(imported_js_list, full_import_path)
--                         return ""  -- Remove the 'import' statement
--                 end)

--                 -- Recursively merge the content of the imported file.
--                 local imported_content = concat_js_files(imported_js_list, visited_files)
--                 table.insert(script_contents, imported_content)
--                 -- Replace 'export function' with just 'function'.
--                 content = content:gsub("export%s+function", "function")
--                 -- Add the modified content to the list.
--                 table.insert(script_contents, content)
--             end
--         end
--     end
--     return table.concat(script_contents, "\n")
-- end


local function minify(js_content)
    -- Function to escape strings
    local function preserve_strings(content)
        local preserved_content = {}
        local idx = 1

        -- Function to replace strings with placeholders
        local function string_replacer(quote, inner)
                local placeholder = string.format("'##STRING_%d##'", idx)
                preserved_content[placeholder] = quote .. inner .. quote -- Preserve the full string
                idx = idx + 1
                return placeholder
        end

        -- Match strings starting and ending with the same quote, allowing for escaped quotes inside
        content = content:gsub(
                "(['\"`])" .. -- Match opening quote
                "(.-)" ..     -- Match everything until...
                "%1",         -- ...the same closing quote
                function(quote, inner)
                        -- Ensure we skip escaped closing quotes within the inner string
                        local valid_inner = inner:gsub("\\.", "") -- Remove escaped characters
                        if not valid_inner:find(quote) then -- If there's no unescaped closing quote
                        return string_replacer(quote, inner)
                end
                return quote .. inner .. quote -- Return the string unchanged if unescaped
        end)

        return content, preserved_content
    end

    js_content, preserved_content = preserve_strings(js_content)

    -- Remove single-line comments
    js_content = js_content:gsub("//[^\n]*", "")
    -- Remove multi-line comments
    js_content = js_content:gsub("/%*.-%*/", "")

    -- Remove extra whitespace and newlines
    js_content = js_content:gsub("%s+", " ") -- Replace multiple spaces with a single space
    js_content = js_content:gsub("%s*([{};,%[%]()=:+-*/<>!&|?])%s*", "%1") -- Trim spaces around symbols
    js_content = js_content:gsub(";%s*", ";") -- Remove space after semicolons

    -- Trim leading and trailing whitespace
    js_content = js_content:match("^%s*(.-)%s*$")

    -- Restore string literals by replacing placeholders with the original content
    for placeholder, str in pairs(preserved_content) do
        js_content = js_content:gsub(placeholder, function() return string.format("%s", str) end) 
    end

    return js_content
end


-- Function: Process JS
function merge_js.process(html, absolute_path)
    html = html:gsub('<script[^>]*src="([^"]+)"[^>]*></script>', function(path)
        path = absolute_path..path
        if lfs.file_exists(path) then
                local file = lfs.open_file(path, "r")
                local content = minify(file:read("*all"))
                file:close()
                return "<script>" .. content .. "</script>"
        end
    end)
    html = html:gsub('</script><script>', function() return "" end)

    return html
end

return merge_js