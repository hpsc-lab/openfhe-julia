# openfhe-julia
Julia wrapper for OpenFHE

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
