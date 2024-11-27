#include <stdio.h>

#include "dynamic_array.h"

#include "test.h"

void test_dynamic_array_001() 
{
    printf("Running test_dynamic_array_001 (dynamic_array creation)");
    dynamic_array *arr = create_dynamic_array(1);
    ASSERT_NOTNULL(arr);
    append(arr, 1);
    ASSERT_EQUALS(at(arr, 0), 1);
    ASSERT_EQUALS(size(arr), 1);
}

void test_dynamic_array()
{
    test_dynamic_array_001();
}