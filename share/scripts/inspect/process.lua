module ("inspect.process", package.seeall)

require ("inspect.kernel_utils")

function inspect:process_inspecting(positional_args, options_values)
    inspect:inspect_kernels(positional_args[1], options_values)
end
