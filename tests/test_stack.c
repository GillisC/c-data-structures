#include <stdio.h>

#include "stack.h"

#include "test.h"

void test_stack_001() 
{
    printf("Running test_stack_001 (stack creation)\n");
    lin_ds *stack = create_lin_ds(1);
    ASSERT_NOTNULL(stack);

    ASSERT(is_empty(stack));
    push(stack, 1);
    ASSERT_EQUALS(size(stack), 1);
    ASSERT_EQUALS(head(stack), 1);
    ASSERT_EQUALS(pop(stack), 1);
    ASSERT_EQUALS(size(stack), 0);    
}

void test_stack_002()
{
    printf("Running test_stack_002 (stack push & pop)\n");

    lin_ds *stack = create_lin_ds(1);
    ASSERT_NOTNULL(stack);

    // push 10 elements
    for (int i=0; i<10; i++)
    {
        push(stack, i);
    }

    // pop 10 elements 
    for (int i=9; i>=0; i--)
    {
        int num = pop(stack);
        ASSERT_EQUALS(num, i);
    }
    // after popping all elements from the stack it should be empty
    ASSERT(size(stack) == 0);
}



void test_stack()
{   
    printf("Testing stack...\n");
    test_stack_001();
    test_stack_002();
    printf("All tests passed!\n\n");

}