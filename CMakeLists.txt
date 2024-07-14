cmake_minimum_required(VERSION 3.4...3.18)
project(mockturtle_wrapper)

add_subdirectory(pybind11)
add_subdirectory(mockturtle)
pybind11_add_module(mockturtle_wrapper src/wrapper.cpp)

target_link_libraries(mockturtle_wrapper PRIVATE mockturtle)

target_include_directories(mockturtle_wrapper PRIVATE .)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(mockturtle_wrapper
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

add_executable(main src/main.cpp)
target_include_directories(main PRIVATE .)
target_link_libraries(main PRIVATE mockturtle)
