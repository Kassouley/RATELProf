local kernel_utils = require ("inspect.kernel_utils")

local inspect = {}

function inspect.process_inspecting(positional_args, options_values)
    kernel_utils.inspect_kernels(positional_args[1], options_values)
end

return inspect
