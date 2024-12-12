#include "test.h"
#include <stdio.h>

// Forward declare the register functions to help compiler
void register_test_dynamic_array(CU_pSuite suite);
void register_test_stack(CU_pSuite suite);


int main() 
{
    if (CUE_SUCCESS != CU_initialize_registry()) 
    {
        return CU_get_error();
    }

    // Add new suite
    CU_pSuite suite = CU_add_suite("GillisC's Data Structures Test Suite", NULL, NULL);
    if (suite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    // Register the tests
    register_test_dynamic_array(suite);
    register_test_stack(suite);

    // Run the tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Clean up
    CU_cleanup_registry();
    return CU_get_error();
}