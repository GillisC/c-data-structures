# Add the test executable
add_executable(test_program 
    main.c
    test_dynamic_array.c
    test_stack.c
)

# Include directories for the test program
target_include_directories(test_program PRIVATE 
    ${CMAKE_SOURCE_DIR}/src  # This will allow the test to find dynamic_array.h
)

# Link the test executable with the shared library
target_link_libraries(test_program PRIVATE 
    data_structures_lib  # Link the library containing dynamic_array.c
)
