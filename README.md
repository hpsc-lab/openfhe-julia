# openfhe-julia
Julia wrapper for [OpenFHE](https://github.com/openfheorg/openfhe-development) based on
[CxxWrap.jl](https://github.com/JuliaInterop/CxxWrap.jl). This repository is mainly
interested for those who want to extend the set of OpenFHE features that are available in
Julia. If you just want to use OpenFHE in Julia, please have a look at
[OpenFHE.jl](https://github.com/sloede/OpenFHE.jl).

## Installation

1. Locally build and install `openfhe-development`.
2. Locally build [`libcxxwrap-julia`](https://github.com/JuliaInterop/libcxxwrap-julia).
   Do *not* remove the build directory, since it contains CMake files needed later. For
   example
   ```shell
   git clone git@github.com:JuliaInterop/libcxxwrap-julia.git
   cd libcxxwrap-julia
   mkdir build && cd build
   cmake ..
   make -j 4
   ```
3. Clone this repository:
   ```shell
   git clone git@github.com:sloede/openfhe-julia.git
   ```
4. Create a build directory and switch to it. Then call CMake with `JlCxx_DIR` set to the `libcxxwrap-julia` build directory:
   ```shell
   mkdir openfhe-julia/build
   cd openfhe-julia/build
   cmake .. -DJlCxx_DIR=$(pwd)/../../libcxxwrap-julia/build/
   make -j 4
   ```


## Authors
OpenFHE-julia was initiated by [Michael Schlottke-Lakemper](https://lakemper.eu) (RWTH
Aachen University/High-Performance Computing Center Stuttgart (HLRS), Germany), who is also
its principal maintainer.

## License
OpenFHE-julia is available under the BSD 2-Clause license (see [LICENSE.md](LICENSE.md)).
[OpenFHE](https://github.com/openfheorg/openfhe-development) itself is also available under
the BSD 2-Clause license.
