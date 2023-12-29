# openfhe-julia
Julia wrapper for [OpenFHE](https://github.com/openfheorg/openfhe-development) based on
[CxxWrap.jl](https://github.com/JuliaInterop/CxxWrap.jl). This repository is mainly
interested for those who want to extend the set of OpenFHE features that are available in
Julia. If you just want to use OpenFHE in Julia, please have a look at
[OpenFHE.jl](https://github.com/sloede/OpenFHE.jl).

**Note: While already usable, this wrapper is in an early state and only exposes a very
limited subset of OpenFHE to Julia. Community contributions welcome!**


## Installation
1. Locally build (and optionally install) `openfhe-development`. For example on Linux:
   ```shell
   git clone git@github.com:openfheorg/openfhe-development.git
   cd openfhe-development
   mkdir build && cd build
   cmake ..
   make -j 4
   ```
2. Locally build [`libcxxwrap-julia`](https://github.com/JuliaInterop/libcxxwrap-julia).
   Do *not* remove the build directory, since it contains CMake files needed later. For
   example on Linux:
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
4. Create a build directory and switch to it. Then call CMake with `JlCxx_DIR` set to the
   `libcxxwrap-julia` build directory and `OpenFHE_DIR` set to the OpenFHE build or install
   directory, e.g.:
   ```shell
   cd openfhe-julia
   mkdir build && cd build
   cmake .. \
     -DJlCxx_DIR=$(pwd)/../../libcxxwrap-julia/build/
     -DOpenFHE_DIR=$(pwd)/../../openfhe-development/build/
   make -j 4
   ```


## Development
Unfortunately, there is not much documentation available at the moment. To wrap additional
C++ functions or types from OpenFHE, proceed roughly as follows:
1. Check the sources of OpenFHE for the type/function you want to make available in Julia.
2. Open [`src/openfhe_julia.cpp`](src/openfhe_julia.cpp) and check the file structure to
   figure out where your addition might fit.
3. If it is not clear how to properly wrap your new addition, consult the `README.md` for
   [CxxWrap.jl](https://github.com/JuliaInterop/CxxWrap.jl).


## Authors
OpenFHE-julia was initiated by [Michael Schlottke-Lakemper](https://lakemper.eu) (RWTH
Aachen University/High-Performance Computing Center Stuttgart (HLRS), Germany), who is also
its principal maintainer.


## License
OpenFHE-julia is available under the BSD 2-Clause license (see [LICENSE.md](LICENSE.md)).
[OpenFHE](https://github.com/openfheorg/openfhe-development) itself is also available under
the BSD 2-Clause license.
