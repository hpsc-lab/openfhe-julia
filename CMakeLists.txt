cmake_minimum_required (VERSION 3.5.1)

# Get project version from `VERSION` file
file(READ "${CMAKE_SOURCE_DIR}/VERSION" version_file)
# Parse string
if (${version_file} MATCHES "(([0-9]+)\\.([0-9]+)\\.([0-9]+)([+-]([A-Za-z0-9_-]+))?)")
  set(OPENFHE_JULIA_VERSION ${CMAKE_MATCH_1})
  set(OPENFHE_JULIA_VERSION_MAJOR ${CMAKE_MATCH_2})
  set(OPENFHE_JULIA_VERSION_MINOR ${CMAKE_MATCH_3})
  set(OPENFHE_JULIA_VERSION_PATCH ${CMAKE_MATCH_4})
  set(OPENFHE_JULIA_VERSION_PRERELEASE ${CMAKE_MATCH_6})
else()
  message(FATAL_ERROR "Unable to parse version from `VERSION` file")
endif()

project(openfhe_julia
        VERSION ${OPENFHE_JULIA_VERSION_MAJOR}.${OPENFHE_JULIA_VERSION_MINOR}.${OPENFHE_JULIA_VERSION_PATCH}
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
option( BUILD_STATIC "Set to ON to include static versions of the library" OFF)

# Dependency: OpenFHE
find_package(OpenFHE CONFIG REQUIRED)
if (OpenFHE_FOUND)
    message(STATUS "FOUND PACKAGE OpenFHE")
    message(STATUS "OpenFHE Version: ${BASE_OPENFHE_VERSION}")
    message(STATUS "OpenFHE installed as shared libraries: ${OpenFHE_SHARED}")
    message(STATUS "OpenFHE include files location: ${OpenFHE_INCLUDE}")
    message(STATUS "OpenFHE lib files location: ${OpenFHE_LIBDIR}")
    message(STATUS "OpenFHE shared libraries: ${OpenFHE_SHARED_LIBRARIES}")
    message(STATUS "OpenFHE static libraries: ${OpenFHE_STATIC_LIBRARIES}")
    message(STATUS "OpenFHE Native Backend size: ${OpenFHE_NATIVE_SIZE}")
else()
    message(FATAL_ERROR "PACKAGE OpenFHE NOT FOUND")
endif ()

set( CMAKE_CXX_FLAGS ${OpenFHE_CXX_FLAGS} )

# Set OpenMP configuration manually for macOS
if (APPLE)
    if (USE_MACPORTS)
        # Macports-based installation
        message( STATUS "Using Macports setup")
        set(OPENMP_LIBRARIES "/opt/local/lib/libomp")
        set(OPENMP_INCLUDES "/opt/local/include/libomp")
        if(CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_C_COMPILER_ID MATCHES "AppleClang")
            set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp -lomp -Wno-unused-command-line-argument")
            set(OpenMP_C_LIB_NAMES "omp")
            set(OpenMP_omp_LIBRARY ${OpenMP_C_LIB_NAMES})
        endif()
        if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "AppleClang")
            set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -lomp -Wno-unused-command-line-argument")
            set(OpenMP_CXX_LIB_NAMES "omp")
            set(OpenMP_omp_LIBRARY ${OpenMP_CXX_LIB_NAMES})
        endif()
    else (USE_MACPORTS)
        # Homebrew-based installation
        # Check for Apple M1 Processor
        if (${ARCHITECTURE} MATCHES "arm64")
            message( STATUS "Apple M1 detected")
            set(OPENMP_LIBRARIES "/opt/homebrew/opt/libomp/lib")
            set(OPENMP_INCLUDES "/opt/homebrew/opt/libomp/include")
        else() # Apple Intel Processor
            message( STATUS "Apple Intel detected")
            set(OPENMP_LIBRARIES "/usr/local/opt/libomp/lib")
            set(OPENMP_INCLUDES "/usr/local/opt/libomp/include")
        endif()

        if(CMAKE_C_COMPILER_ID MATCHES "Clang")
            set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp -lomp -Wno-unused-command-line-argument")
            set(OpenMP_C_LIB_NAMES "libomp")
            set(OpenMP_libomp_LIBRARY ${OpenMP_C_LIB_NAMES})
        endif()
        if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
            set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -lomp -Wno-unused-command-line-argument")
            set(OpenMP_CXX_LIB_NAMES "libomp")
            set(OpenMP_libomp_LIBRARY ${OpenMP_CXX_LIB_NAMES})
        endif()
    endif (USE_MACPORTS)

    include_directories("${OPENMP_INCLUDES}")
    link_directories("${OPENMP_LIBRARIES}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")

    message( STATUS "OPENMP_LIBRARIES: " ${OPENMP_LIBRARIES})
    message( STATUS "OPENMP_INCLUDES: " ${OPENMP_INCLUDES})
    message( STATUS "OpenMP_CXX_FLAGS: " ${OpenMP_CXX_FLAGS})
    message( STATUS "OpenMP_CXX_LIB_NAMES: " ${OpenMP_CXX_LIB_NAMES})
endif()

find_package (OpenMP)
# OpenMP_CXX_FOUND was added in cmake 3.9.x so we are also checking the OpenMP_FOUND flag
if (OpenMP_CXX_FOUND OR OpenMP_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
else()
    message(SEND_ERROR "** ERROR ** OpenMP is not installed. If using macOS/clang, please run 'cmake ..' again.")
endif()

if (OpenMP_C_FOUND OR OpenMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
endif()

include_directories( ${OPENMP_INCLUDES} )
include_directories( ${OpenFHE_INCLUDE} )
include_directories( ${OpenFHE_INCLUDE}/third-party/include )
include_directories( ${OpenFHE_INCLUDE}/core )
include_directories( ${OpenFHE_INCLUDE}/pke )
include_directories( ${OpenFHE_INCLUDE}/binfhe )
### add directories for other OpenFHE modules as needed for your project

link_directories( ${OpenFHE_LIBDIR} )
link_directories( ${OPENMP_LIBRARIES} )
if(BUILD_STATIC)
    set( CMAKE_EXE_LINKER_FLAGS "${OpenFHE_EXE_LINKER_FLAGS} -static")
    link_libraries( ${OpenFHE_STATIC_LIBRARIES} )
else()
    set( CMAKE_EXE_LINKER_FLAGS ${OpenFHE_EXE_LINKER_FLAGS} )
    link_libraries( ${OpenFHE_SHARED_LIBRARIES} )
endif()


### Dependency: libcxxwrap-julia
find_package(JlCxx)
get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)

message(STATUS "Found JlCxx at ${JlCxx_location}")

# openfhe-julia
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib;${JlCxx_location};${OpenFHE_LIBDIR}")

add_library(openfhe_julia SHARED
  ${CMAKE_SOURCE_DIR}/src/openfhe_julia.cpp
  ${CMAKE_SOURCE_DIR}/src/enums.cpp
  ${CMAKE_SOURCE_DIR}/src/nativeinteger.cpp
  ${CMAKE_SOURCE_DIR}/src/ubint.cpp
  ${CMAKE_SOURCE_DIR}/src/cryptocontextbfvrns.cpp
  ${CMAKE_SOURCE_DIR}/src/cryptocontextbgvrns.cpp
  ${CMAKE_SOURCE_DIR}/src/cryptocontextckksrns.cpp
  ${CMAKE_SOURCE_DIR}/src/fheckksrns.cpp
  ${CMAKE_SOURCE_DIR}/src/params.cpp
  ${CMAKE_SOURCE_DIR}/src/ccparams.cpp
  ${CMAKE_SOURCE_DIR}/src/serializable.cpp
  ${CMAKE_SOURCE_DIR}/src/dcrtpoly.cpp
  ${CMAKE_SOURCE_DIR}/src/privatekeyimpl.cpp
  ${CMAKE_SOURCE_DIR}/src/publickeyimpl.cpp
  ${CMAKE_SOURCE_DIR}/src/keypair.cpp
  ${CMAKE_SOURCE_DIR}/src/plaintextimpl.cpp
  ${CMAKE_SOURCE_DIR}/src/cryptoobject.cpp
  ${CMAKE_SOURCE_DIR}/src/ciphertextimpl.cpp
  ${CMAKE_SOURCE_DIR}/src/decryptresult.cpp
  ${CMAKE_SOURCE_DIR}/src/ildcrtparams.cpp
  ${CMAKE_SOURCE_DIR}/src/cryptocontextimpl.cpp
  ${CMAKE_SOURCE_DIR}/src/encodingparamsimpl.cpp
  ${CMAKE_SOURCE_DIR}/src/auxiliary.cpp
)
target_link_libraries(openfhe_julia JlCxx::cxxwrap_julia)
target_include_directories(openfhe_julia PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION
                      ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})

install(TARGETS ${PROJECT_NAME})
