# Works with 3.12 and tested through 3.19
cmake_minimum_required(VERSION 3.12...3.19)

# Project name and a few useful settings. Other commands can pick up the results
project(
    PimplExample
    VERSION 1.0.0
    DESCRIPTION "Pointer-To-Implementation (Pimpl) Example"
    LANGUAGES CXX)

message(${PROJECT_NAME} " version " ${PROJECT_VERSION})

# Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


if (NOT CMAKE_CXX_FLAGS MATCHES "std")
    if (CMAKE_BUILD_TYPE MATCHES Debug)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O0 -Wall -Wuninitialized")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3 -Wall -Wuninitialized")
    endif()
endif()

include(include/CMakeLists.txt)
include(src/CMakeLists.txt)

add_executable(RunSample
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${HEADERS}
    ${SOURCEFILES}
    )

target_include_directories( RunSample PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    )