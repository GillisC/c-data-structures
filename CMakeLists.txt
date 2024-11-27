cmake_minimum_required(VERSION 3.10)
project(DataStructures)

# Set C flags
set(CMAKE_C_FLAGS "-Wall -g")

# Specify the source files
set(SOURCE_FILES
    src/main.c
    src/dynamic_array.c
)

# Create a library for shared code
add_library(data_structures_lib
    src/dynamic_array.c
)

target_include_directories(data_structures_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/src
)

# Main program
add_executable(main_program src/main.c)
target_link_libraries(main_program PRIVATE data_structures_lib)

# Add tests subdirectory
add_subdirectory(tests)
