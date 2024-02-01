if !isdir("MyOpenFHE.jl")
    error("wrong working directory (must be invoked from the `test/` directory)")
end

if length(ARGS) < 1
    error("missing command line argument: LIBOPENFHE_JULIA_PATH")
end
libopenfhe_julia_path = ARGS[1]

@info "Creating LocalPreferences.toml..." libopenfhe_julia_path
contents = read("LocalPreferences.toml.tmpl", String)
modified = replace(contents, "{libopenfhe_julia_path}" => libopenfhe_julia_path)
write("LocalPreferences.toml", modified)

@info "Dev'ing MyOpenFHE..."
using Pkg
Pkg.activate(".")
Pkg.develop(path="MyOpenFHE.jl")
Pkg.instantiate()
