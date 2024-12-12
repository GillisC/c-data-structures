# Add the test executable
add_executable(test_program 
    test.c
    test_dynamic_array.c
    test_stack.c
)

find_library(CUNIT_LIBRARY NAMES cunit)
find_path(CUNIT_INCLUDE_DIR NAMES CUnit/CUnit.h)

# Include directories for the test program
target_include_directories(test_program PRIVATE 
    ${CUNIT_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/src  # This will allow the test to find dynamic_array.h
)

# Link the test executable with the shared library
target_link_libraries(test_program PRIVATE
    ${CUNIT_LIBRARY} 
    data_structures_lib  # Link the library containing dynamic_array.c
)
