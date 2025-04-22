cmake_minimum_required(VERSION 3.31)
project(prosper_sample VERSION 0.1 LANGUAGES CXX C)

include(FetchContent)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(BUILD_SHARED_LIBS ON)
set(CMAKE_CXX_FLAGS                " ${CMAKE_CXX_FLAGS_INIT} -std=c++20 -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG          " ${CMAKE_CXX_FLAGS_INIT} -std=c++20 -fPIC -g -DDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL     " ${CMAKE_CXX_FLAGS_INIT} -Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE        " ${CMAKE_CXX_FLAGS_INIT} -O2 -DNDEBUG -flto -fno-fat-lto-objects")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO " ${CMAKE_CXX_FLAGS_INIT} -O2 -g -DDEBUG")

# Prosper
FetchContent_Declare(
    prosper
    GIT_REPOSITORY https://github.com/tracefree/prosper
    GIT_TAG main
)
FetchContent_MakeAvailable(prosper)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG $<1:${CMAKE_SOURCE_DIR}>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE $<1:${CMAKE_SOURCE_DIR}>)

add_executable(prosper_sample
    src/main.cpp
    src/components/rotate.cpp
)

set_property(
    TARGET prosper_sample
    PROPERTY LINKER MOLD
)

target_precompile_headers(prosper_sample PRIVATE <optional> <vector> <string> <unordered_map> <print> <memory>)

target_link_libraries(prosper_sample PRIVATE prosper)
