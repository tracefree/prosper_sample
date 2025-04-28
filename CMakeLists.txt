cmake_minimum_required(VERSION 3.21)
project(prosper_sample VERSION 0.1 LANGUAGES CXX C)

include(FetchContent)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_RPATH "./lib")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $<1:${CMAKE_SOURCE_DIR}/lib>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG $<1:${CMAKE_SOURCE_DIR}/lib>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE $<1:${CMAKE_SOURCE_DIR}/lib>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG $<1:${CMAKE_SOURCE_DIR}>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE $<1:${CMAKE_SOURCE_DIR}>)
set(CMAKE_CXX_FLAGS                " ${CMAKE_CXX_FLAGS_INIT} -std=c++20 -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG          " ${CMAKE_CXX_FLAGS_INIT} -std=c++20 -fPIC -g -DDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL     " ${CMAKE_CXX_FLAGS_INIT} -Os -DNDEBUG -s")
set(CMAKE_CXX_FLAGS_RELEASE        " ${CMAKE_CXX_FLAGS_INIT} -O2 -DNDEBUG -s -flto -fno-fat-lto-objects")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO " ${CMAKE_CXX_FLAGS_INIT} -O2 -g -DDEBUG")

# Prosper
set(PROSPER_PREFER_SYSTEM_LIBRARIES OFF)
FetchContent_Declare(
    prosper
    GIT_REPOSITORY https://github.com/tracefree/prosper
    GIT_TAG main
)
FetchContent_MakeAvailable(prosper)

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
