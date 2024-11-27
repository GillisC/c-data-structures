#include <stdio.h>

#include "stack.h"

#include "test.h"

void test_stack_001() 
{
    printf("Running test_stack_001 (stack creation)\n");
    stack *s = create_stack(1);
    ASSERT_NOTNULL(s);

    ASSERT(stack_is_empty(s));
    push(s, 1);
    ASSERT_EQUALS(stack_size(s), 1);
    ASSERT_EQUALS(head(s), 1);
    ASSERT_EQUALS(pop(s), 1);
    ASSERT_EQUALS(stack_size(s), 0);    
}

void test_stack_002()
{
    printf("Running test_stack_002 (stack push & pop)\n");

    stack *s = create_stack(1);
    ASSERT_NOTNULL(s);

    // push 10 elements
    for (int i=0; i<10; i++)
    {
        push(s, i);
    }

    // pop 10 elements 
    for (int i=9; i>=0; i--)
    {
        int num = pop(s);
        ASSERT_EQUALS(num, i);
    }
    // after popping all elements from the stack it should be empty
    ASSERT(stack_size(s) == 0);
}



void test_stack()
{   
    printf("Testing stack...\n");
    test_stack_001();
    test_stack_002();
    printf("All tests passed!\n\n");

}