#include "test.h"
#include "dynamic_array.h"

void test_dynamic_array_001() 
{   
    lin_ds *arr = create_lin_ds(1);
    CU_ASSERT_PTR_NOT_NULL(arr);
    
    append(arr, 1);
    CU_ASSERT_EQUAL(at(arr, 0), 1);
    CU_ASSERT_EQUAL(size(arr), 1);
}

void test_dynamic_array_002() 
{
    lin_ds *arr = create_lin_ds(1);
    CU_ASSERT_PTR_NOT_NULL(arr);

    for (int i=0; i<10; i++)
    {
        append(arr, i);
    }
    CU_ASSERT(arr->capacity > 10);

    for (int i=0; i<10; i++)
    {
        CU_ASSERT(at(arr, i) == i);
    }
}

void test_dynamic_array_003()
{
    lin_ds *arr = create_lin_ds(1);
    CU_ASSERT_PTR_NOT_NULL(arr);

    for (int i = 0; i < 1000000; i++) {
        append(arr, i);
    }

    CU_ASSERT(arr->data[999999] == 999999);
}


void register_test_dynamic_array(CU_pSuite suite)
{
    CU_add_test(suite, "Test append and at", test_dynamic_array_001);
    CU_add_test(suite, "Test append and at more", test_dynamic_array_002);
    CU_add_test(suite, "Test append on large array", test_dynamic_array_003);
}