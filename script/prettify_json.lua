-- Function to add indentation
local function add_indent(level)
    return string.rep("    ", level)
end

-- Function to prettify a JSON array of arrays
local function prettify_json(input_json)
    local result = ""
    local level = 0
    local in_quotes = false
    local escape_char = false

    for i = 1, #input_json do
        local char = input_json:sub(i, i)

        if char == '"' and not escape_char then
            in_quotes = not in_quotes
            result = result .. char
        elseif char == "\\" and in_quotes then
            escape_char = not escape_char
            result = result .. char
        elseif char == "{" or char == "[" then
            if not in_quotes then
                level = level + 1
                result = result .. char .. "\n" .. add_indent(level)
            else
                result = result .. char
            end
        elseif char == "}" or char == "]" then
            if not in_quotes then
                level = level - 1
                result = result .. "\n" .. add_indent(level) .. char
            else
                result = result .. char
            end
        elseif char == "," then
            if not in_quotes then
                result = result .. char .. "\n" .. add_indent(level)
            else
                result = result .. char
            end
        elseif char == ":" then
            if not in_quotes then
                result = result .. char .. " "
            else
                result = result .. char
            end
        else
            result = result .. char
            escape_char = false
        end
    end

    return result
end

-- Function to read the JSON string from a file
local function read_file(file_path)
    local file = io.open(file_path, "r") -- Open the file in read mode
    if not file then
        print("Could not open file: " .. file_path)
        return nil
    end
    local content = file:read("*a") -- Read the entire file content
    file:close() -- Close the file
    return content
end

-- Function to write the prettified JSON back to the file
local function write_file(file_path, content)
    local file = io.open(file_path, "w") -- Open the file in write mode
    if not file then
        print("Could not write to file: " .. file_path)
        return false
    end
    file:write(content) -- Write the prettified content back to the file
    file:close() -- Close the file
    return true
end

-- Main logic to read the JSON from a file, prettify it, and replace the original file
local file_path = arg[1] -- Get the file path passed as an argument

if not file_path then
    print("Please provide a file path as an argument.")
else
    local input_json = read_file(file_path)
    if input_json then
        local prettified_json = prettify_json(input_json)
        if write_file(file_path, prettified_json) then
            print("File has been prettified and saved: " .. file_path)
        end
    end
end
