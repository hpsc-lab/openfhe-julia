# OpenFHE-julia

[![Build Status](https://github.com/hpsc-lab/openfhe-julia/actions/workflows/ci.yml/badge.svg)](https://github.com/hpsc-lab/openfhe-julia/actions?query=workflow%3ACI)
[![License: BSD 2-Clause](https://img.shields.io/badge/License-BSD_2--Clause-success.svg)](https://opensource.org/license/bsd-2-clause/)
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.10456858.svg)](https://doi.org/10.5281/zenodo.10456858)

Julia bindings for the homomorphic encryption library
[OpenFHE](https://github.com/openfheorg/openfhe-development) based on
[CxxWrap.jl](https://github.com/JuliaInterop/CxxWrap.jl). This repository is mainly
interesting for those who want to extend the set of OpenFHE features that are available in
Julia. If you just want to use OpenFHE in Julia, please have a look at
[OpenFHE.jl](https://github.com/hpsc-lab/OpenFHE.jl).


## Installation
1. Locally build and install [OpenFHE](https://github.com/openfheorg/openfhe-development).
   For example on Linux:
   ```shell
   git clone git@github.com:openfheorg/openfhe-development.git
   cd openfhe-development
   mkdir build && cd build
   cmake .. -DCMAKE_INSTALL_PREFIX=../install \
       -DBUILD_BENCHMARKS=OFF -DBUILD_UNITTESTS=OFF \
       -DLIBINSTALL="$(dirname $(pwd))/install/lib"
   make -j 4
   make install
   ```
   Sometimes it might be necessary to explicitly enable the `BE2` and `BE4`
   backends by providing `-DWITH_BE2=ON -DWITH_BE4=ON` to CMake. In case you would like to
   include the benchmarks and/or unit tests, you can enable them again by removing the
   respective flag that disables them.

   Note: The argument `-DLIBINSTALL=...` may be removed once
   [this issue](https://openfhe.discourse.group/t/bug-in-rpath-runpath-specification-in-cmakelists-txt/1071)
   has been resolved upstream.
2. Locally build and install
   [`libcxxwrap-julia`](https://github.com/JuliaInterop/libcxxwrap-julia). For example on
   Linux:
   ```shell
   git clone git@github.com:JuliaInterop/libcxxwrap-julia.git
   cd libcxxwrap-julia
   git checkout v0.11.2
   mkdir build && cd build
   cmake .. -DCMAKE_INSTALL_PREFIX=../install
   make -j 4
   make install
   ```
   The version tag in the line  `git checkout <version>` should be updated to the latest
   `libcxxwrap-julia` version that is compatible with the current release of CxxWrap.jl
   release (see
   [here](https://github.com/JuliaInterop/libcxxwrap-julia#using-libcxxwrap-julia-as-a-dependency-for-downstream-packages)
   for further information).
3. Clone this repository:
   ```shell
   git clone git@github.com:hpsc-lab/openfhe-julia.git
   ```
4. Create a build directory and switch to it. Then call CMake with the `CMAKE_PREFIX_PATH`
   set to a colon-separated list of install prefixes for the dependencies, e.g.:
   ```shell
   cd openfhe-julia
   mkdir build && cd build
   prefix_path="$(pwd)/../../libcxxwrap-julia/install/;$(pwd)/../../openfhe-development/install/"
   cmake .. -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_PREFIX_PATH="$prefix_path"
   make -j 4
   make install
   ```


## Development
Unfortunately, there is not much documentation for developers available at the moment. The
little we have can be found in [`development.md`](development.md).


## Referencing
If you use OpenFHE-julia in your own research, please cite this repository as follows:
```bibtex
@misc{schlottkelakemper2024openfhejulia,
  title={{O}pen{FHE}-julia: {J}ulia bindings for the homomorphic encryption library {O}pen{FHE}},
  author={Schlottke-Lakemper, Michael},
  year={2024},
  howpublished={\url{https://github.com/hpsc-lab/openfhe-julia}},
  doi={10.5281/zenodo.10456858}
}
```
Note that if you only use OpenFHE-julia as part of OpenFHE.jl, it is sufficient to cite
OpenFHE.jl.


## Authors
OpenFHE-julia was initiated by [Michael Schlottke-Lakemper](https://www.uni-augsburg.de/fakultaet/mntf/math/prof/hpsc)
(University of Augsburg, Germany), who is also its principal maintainer.

Further contributions to OpenFHE-julia have been made by the following people:
* [Arseniy Kholod](https://www.github.com/ArseniyKholod) (RWTH Aachen University, Germany)
* [Max Grübmeyer](https://www.github.com/MaxGruebmeyer) (University of Augsburg, Germany)


## License and contributing
OpenFHE-julia is available under the BSD 2-Clause license (see [LICENSE.md](LICENSE.md)).
[OpenFHE](https://github.com/openfheorg/openfhe-development) itself is also available under
the BSD 2-Clause license.

Contributions by the community are very welcome! A good start would be to compare the
`examples` folder in OpenFHE.jl
([link](https://github.com/hpsc-lab/OpenFHE.jl/tree/main/examples))
and in OpenFHE
([link](https://github.com/openfheorg/openfhe-development/tree/main/src/pke/examples)) and to
port a missing example file to OpenFHE.jl. In case some OpenFHE functionality is not yet
exposed by [OpenFHE-julia](https://github.com/hpsc-lab/openfhe-julia), it would have to be
added there first.
