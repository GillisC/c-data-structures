#include "test.h"
#include "stack.h"


void test_stack_001() 
{
    lin_ds *stack = create_lin_ds(1);
    CU_ASSERT_PTR_NOT_NULL(stack);
    CU_ASSERT(is_empty(stack));
    
    push(stack, 1);
    CU_ASSERT_EQUAL(size(stack), 1);
    CU_ASSERT_EQUAL(head(stack), 1);
    CU_ASSERT_EQUAL(pop(stack), 1);
    CU_ASSERT_EQUAL(size(stack), 0);    
}


void test_stack_002()
{
    lin_ds *stack = create_lin_ds(1);
    CU_ASSERT_PTR_NOT_NULL(stack);

    // push 10 elements
    for (int i=0; i<10; i++)
    {
        push(stack, i);
    }

    // pop 10 elements 
    for (int i=9; i>=0; i--)
    {
        int num = pop(stack);
        CU_ASSERT_EQUAL(num, i);
    }
    // after popping all elements from the stack it should be empty
    CU_ASSERT(size(stack) == 0);
}


void register_test_stack(CU_pSuite suite)
{   
    CU_add_test(suite, "Initialization", test_stack_001);
    CU_add_test(suite, "Push and Pop", test_stack_002);
}