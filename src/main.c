// Standard library includes
#include <stdio.h>


// Others
#include "dynamic_array.h"
#include "stack.h"



// This project is made to learn c more deeply, 
// refresh knowledge and implementation details of common data structures
// refresh memory on sorting algorithms
// learn how to setup project with make, cmake and allow basic testing capabilities

// Data structures to implement:
//   dynamic_array, stack, queue, dequeue, linked list
//   trees, binary-trees, red-black trees, min- and max-heap
//   graphs with nodes and edges able to use search algorithms
//   hash table, hash set, hash map

int main(void) {
    
    stack *s = create_stack(1);
    push(s, 1);
    printf("stack empty? : %d\n", stack_is_empty(s));
    
    return 0;
}