#include "stack.h"

stack *create_stack(size_t initial_capacity)
{
    stack *s = malloc(sizeof(stack));
    if (s == NULL) return NULL;

    s->data = malloc(initial_capacity * sizeof(int));
    if (s->data == NULL) return NULL;

    s->capacity = initial_capacity;
    s->size = 0;

    return s;
}

void stack_resize(stack *s)
{
    assert(s);

    s->capacity *= 2;
    int *new_data = realloc(s->data, s->capacity * sizeof(int));

    if (!new_data) 
    {
        fprintf(stderr, "Error occured when resizing stack\n");
    }
    s->data = new_data;
}

void push(stack *s, int element) 
{
    assert(s);

    if (s->size >= s->capacity) 
    {
        stack_resize(s);
    }
    s->data[s->size] = element;
    s->size++;
}


int pop(stack *s)
{
    assert(s);

    if (s->size <= 0)
    {
        return 0;
    }
    int result = s->data[s->size - 1];
    s->size--;
    return result;
}


int head(stack *s)
{
    assert(!stack_is_empty(s));
    return s->data[s->size - 1];
}


int stack_size(stack *s)
{
    assert(s);
    return s->size;
}


bool stack_is_empty(stack *s)
{
    assert(s);
    return ((stack_size(s)) == 0);
}
