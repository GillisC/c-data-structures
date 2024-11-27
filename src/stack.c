#include "stack.h"

stack *create_stack(int initial_capacity)
{
    stack *stack = malloc(stack);
    if (stack == NULL) return NULL;

    stack->data = malloc(initial_capacity * sizeof(int));
    if (stack->data == NULL) return NULL;

    stack->capacity = initial_capacity;
    stack->size = 0;

    return stack;
}

void resize(stack *s)
{
    s->capacity *= 2;
    stack *new_stack = create_stack(s->capacity);
    new_stack->data = realloc(s, s->capacity * sizeof(int));

    if (new_stack->data) 
    {
        free(s->data);
        *s = *new_stack;
        free(new_stack->data);
        free(new_stack);
    }
    else
    {
        return NULL;
    }
}

void push(stack* s, int element) 
{
    if (s->size >= s->capacity) 
    {
        resize(s);
    }
    s->data[s->size] = element;
    s->size++;
}

// TODO
int pop(stack*);
