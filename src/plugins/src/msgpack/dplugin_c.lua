local ContentManager = require("ContentManager")
local Content = require("Content")
local common = require("common")

dplugin_msgpack_c = setmetatable({}, ContentManager)
dplugin_msgpack_c.__index = dplugin_msgpack_c

function dplugin_msgpack_c:new(options, template_path, output_path)
    local do_not_gen = false
    if options.plugin_gen == false then
        do_not_gen = true
    elseif options.plugin_gen and not (options.plugin_gen["msgpack"] or options.plugin_gen["all"]) then
        do_not_gen = false
    end
    local attribute = {
        file_name = S:STRING("DPLG_SRC"),
        do_not_gen = do_not_gen,
        subcontents = {
            ["case_block"] = Content:new()
        } 
    }
    local instance = ContentManager:new(attribute, template_path, output_path)
    setmetatable(instance, dplugin_msgpack_c)
    return instance
end

function dplugin_msgpack_c:generate_content()
    return [[
/** ]]..S:STRING("WARNING_MSG")..[[ 
 */
 
#include <]]..S:STRING("INTERCEPTOR_HDR")..[[>
#include <ratelprof_ext.h>
#include "]]..S:STRING("DPLG_HDR")..[["
#include "msgpack.h"

]]..S:STRING("PLG_OE_CALLBACK_FUNC_DECL")..[[
{
    ]]..S:STRING("I_API_DATA_T")..[[* activity = (]]..S:STRING("I_API_DATA_T")..[[*)user_activity;
    ]]..S:STRING("IDS_GET_CID_FUNC")..[[(&activity->corr_id);
    ]]..S:STRING("IDS_PUSH_ID_FUNC")..[[(&activity->id);
    activity->phase = ]]..S:STRING("LC_GET_PHASE_FUNC")..[[();
    activity->domain = domain;
    activity->funid = id;
    activity->pid = get_pid();
    activity->tid = get_tid();
}

]]..S:STRING("PLG_OX_CALLBACK_FUNC_DECL")..[[
{
	(void)domain;
	(void)id;
	(void)user_activity;
    ]]..S:STRING("IDS_POP_ID_FUNC")..[[();
}

]]..S:STRING("PLG_PROCESS_FUNC_DECL")..[[ 
{
    msgpack_buffer_t* buf = (msgpack_buffer_t*)user_args;
    switch(funid) {
]]..self.subcontents.case_block..[[ 
        default : break;
    }
}

]]
end


local function get_plugin_block_for(cvar_list, fname, depth, comment_content, macro_content, parent_vname)
    local depth = depth or 0
    local parent_vname = parent_vname or ""
    local comment_content = comment_content or Content:new(3)
    local macro_content = macro_content or Content:new(3)
    local print_indent = string.rep("\\t", depth + 1)
    local comment_indent = string.rep("\t", depth + 1)

    for index, cvar in ipairs(cvar_list) do
        local vname = "args->"..fname.."."..cvar.name
        if parent_vname ~= "" then
            vname = parent_vname .. "." .. cvar.name
        end
        if cvar:is_array() and not cvar:is_string() then
            for _, _ in ipairs(cvar.dimensions) do
                vname=vname.."[0]"
            end
        end

        if cvar:is_unknown() then
            comment_content:addfLine(
                "//%s%s %s (unknown);", 
                comment_indent, cvar.vtype, cvar.name)
            macro_content:addfLine(
                'msgpack_encode_string_ext(buf, "%s");\n'..
                '\t\t\tmsgpack_encode_map(buf, 2);\n'..
                '\t\t\tmsgpack_encode_string_ext(buf, "type");\n'..
                '\t\t\tmsgpack_encode_string_ext(buf, "%s");\n'..
                '\t\t\tmsgpack_encode_string_ext(buf, "value");\n'..
                '\t\t\tmsgpack_encode_string_ext(buf, "N/A");\n',
                cvar.name, cvar.vtype)
        else
            if (cvar:is_pointer() and depth == 0) or cvar:is_opaque() or cvar:is_function() then
                comment_content:addfLine(
                    "//%s%s %s (%s);", 
                    comment_indent, cvar.vtype, cvar.name, cvar.ctype)
                macro_content:addfLine(
                    'msgpack_encode_string_ext(buf, "%s");\n'..
                    '\t\t\tmsgpack_encode_map(buf, 2);\n'..
                    '\t\t\tmsgpack_encode_string_ext(buf, "type");\n'..
                    '\t\t\tmsgpack_encode_string_ext(buf, "%s");\n'..
                    '\t\t\tmsgpack_encode_string_ext(buf, "value");\n'..
                    '\t\t\tmsgpack_encode_uint(buf, (uintptr_t)%s);\n',
                    cvar.name, cvar.vtype, vname)
                
            elseif not cvar:is_pointer() then
                if cvar:is_struct() or cvar:is_union() then 
                    comment_content:addfLine(
                        "//%s%s %s ({", 
                        comment_indent, cvar.vtype, cvar.name)
                    macro_content:addfLine(
                        'msgpack_encode_string_ext(buf, "%s");\n'..
                        '\t\t\tmsgpack_encode_map(buf, 2);\n'..
                        '\t\t\tmsgpack_encode_string_ext(buf, "type");\n'..
                        '\t\t\tmsgpack_encode_string_ext(buf, "%s");\n'..
                        '\t\t\tmsgpack_encode_string_ext(buf, "value");\n'..
                        '\t\t\tmsgpack_encode_map(buf, %s);\n',
                        cvar.name, "struct "..cvar.vtype, #cvar.struct_fields
                    )
                    get_plugin_block_for(
                        cvar.struct_fields,
                        fname,
                        depth+1, 
                        comment_content, 
                        macro_content, 
                        ("*"):rep(cvar.dyn_ref_cnt)..vname)

                    comment_content:addfLine("//%s});", comment_indent)

                elseif not cvar:is_void() then
                    comment_content:addfLine("//%s%s %s (%s);", comment_indent, cvar.vtype, cvar.name, cvar.ctype)
                    local encoding_type = "int"
                    if cvar:is_string() then
                        encoding_type = "string"
                    elseif string.find(cvar.ctype, "double", 1, true) ~= nil then
                        encoding_type = "double"
                    elseif string.find(cvar.ctype, "float", 1, true) ~= nil then
                        encoding_type = "float"
                    end
                    macro_content:addfLine(
                        'msgpack_encode_string_ext(buf, "%s");\n'..
                        '\t\t\tmsgpack_encode_map(buf, 2);\n'..
                        '\t\t\tmsgpack_encode_string_ext(buf, "type");\n'..
                        '\t\t\tmsgpack_encode_string_ext(buf, "%s");\n'..
                        '\t\t\tmsgpack_encode_string_ext(buf, "value");\n'..
                        '\t\t\tmsgpack_encode_%s(buf, %s);\n',
                        cvar.name, cvar.vtype, encoding_type, vname
                    )
                else
                    comment_content:addfLine("//%s%s %s (%s);", comment_indent, cvar.vtype, cvar.name, cvar.ctype)
                end
            end
        end
    end
    return macro_content:getContent(), comment_content:getContent()
end

function dplugin_msgpack_c:generate_subcontents(f)
    local signature = common.get_function_signature(f)
    local macro_blk, comment_blk = get_plugin_block_for(signature, f.fname)
    self.subcontents["case_block"]:addfLine("\t\tcase %s%s :", S:STRING("IF_API_ID_PREFIX"), f.fname) 
    self.subcontents["case_block"]:addfLine("%s", comment_blk) 
    self.subcontents["case_block"]:addfLine("\t\t\tmsgpack_encode_map(buf, %s);", #signature) 
    self.subcontents["case_block"]:addfLine("%s", macro_blk == "" and "\\" or macro_blk) 
    self.subcontents["case_block"]:addLine("\t\t\tbreak;\n")
end

return dplugin_msgpack_c, "DOMAIN"
