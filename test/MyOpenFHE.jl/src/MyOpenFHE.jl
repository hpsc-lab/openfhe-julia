module MyOpenFHE

using CxxWrap
using Preferences: @load_preference

const libopenfhe_julia_path = @load_preference("libopenfhe_julia")
@wrapmodule(() -> libopenfhe_julia_path)

function __init__()
    @initcxx
end

end # module MyOpenFHE
