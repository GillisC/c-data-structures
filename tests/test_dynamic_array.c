#include <stdio.h>

#include "dynamic_array.h"

#include "test.h"

void test_dynamic_array_001() 
{
    printf("Running test_dynamic_array_001 (dynamic_array creation)\n");
    lin_ds *arr = create_lin_ds(1);
    ASSERT_NOTNULL(arr);
    append(arr, 1);
    ASSERT_EQUALS(at(arr, 0), 1);
    ASSERT_EQUALS(size(arr), 1);
}

void test_dynamic_array_002() 
{
    printf("Running test_dynamic_array_002 (dynamic_array memory allocation)\n");
    lin_ds *arr = create_lin_ds(1);
    ASSERT_NOTNULL(arr);

    for (int i=0; i<10; i++)
    {
        append(arr, i);
    }
    ASSERT(arr->capacity > 10);

    for (int i=0; i<10; i++)
    {
        ASSERT(at(arr, i) == i);
    }
}

void test_dynamic_array_003()
{
    printf("Running test_dynamic_array_003 (dynamic_array append)\n");
    lin_ds *arr = create_lin_ds(1);
    ASSERT_NOTNULL(arr);

    for (int i = 0; i < 1000000; i++) {
        append(arr, i);
    }

    ASSERT(arr->data[999999] == 999999);
}


void test_dynamic_array()
{
    printf("Testing dynamic array...\n");
    test_dynamic_array_001();
    test_dynamic_array_002();
    test_dynamic_array_003();
    printf("All tests passed!\n\n");
}