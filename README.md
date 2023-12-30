# openfhe-julia

[![Build Status](https://github.com/sloede/openfhe-julia/workflows/CI/badge.svg)](https://github.com/sloede/openfhe-julia/actions?query=workflow%3ACI)
[![License: BSD 2-Clause](https://img.shields.io/badge/License-BSD_2--Clause-success.svg)](https://opensource.org/license/bsd-2-clause/)

Julia wrapper for [OpenFHE](https://github.com/openfheorg/openfhe-development) based on
[CxxWrap.jl](https://github.com/JuliaInterop/CxxWrap.jl). This repository is mainly
interested for those who want to extend the set of OpenFHE features that are available in
Julia. If you just want to use OpenFHE in Julia, please have a look at
[OpenFHE.jl](https://github.com/sloede/OpenFHE.jl).

**Note: While already usable, this wrapper is in an early state and only exposes a very
limited subset of OpenFHE to Julia. Community contributions welcome!**


## Installation
1. Locally build and install `openfhe-development`. For example on Linux:
   ```shell
   git clone git@github.com:openfheorg/openfhe-development.git
   cd openfhe-development
   mkdir build && cd build
   cmake .. -DCMAKE_INSTALL_PREFIX=../install
   make -j 4
   make install
   ```
   Note that sometimes it might be necessary to explicitly enable the `BE2` and `BE4`
   backends by providing `-DWITH_BE2=ON -DWITH_BE4=ON` to CMake. In case you experience
   problems with building the benchmarks and/or unit tests but do not actually need them,
   you can disable them by adding `-DBUILD_BENCHMARKS=OFF -DBUILD_UNITTESTS=OFF`.
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
   `libcxxwrap-julia` build directory and `OpenFHE_DIR` set to the OpenFHE install
   directory, e.g.:
   ```shell
   cd openfhe-julia
   mkdir build && cd build
   cmake .. \
     -DJlCxx_DIR=$(pwd)/../../libcxxwrap-julia/build/
     -DOpenFHE_DIR=$(pwd)/../../openfhe-development/install/
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


## License and contributing
OpenFHE-julia is available under the BSD 2-Clause license (see [LICENSE.md](LICENSE.md)).
[OpenFHE](https://github.com/openfheorg/openfhe-development) itself is also available under
the BSD 2-Clause license.

Contributions by the community are very welcome! A good start would be to compare the
`examples` folder in OpenFHE.jl
([link](https://github.com/sloede/OpenFHE.jl/tree/main/examples))
and in OpenFHE
([link](https://github.com/openfheorg/openfhe-development/tree/main/src/pke/examples)) and to
port a missing example file to OpenFHE.jl. In case some OpenFHE functionality is not yet
exposed by [openfhe-julia](https://github.com/sloede/openfhe-julia), it would have to be
added there first.
