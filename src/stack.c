#include "stack.h"

void push(lin_ds *s, int element) 
{
    assert(s);

    if (s->size >= s->capacity) 
    {
        resize_lin_ds(s);
    }
    s->data[s->size] = element;
    s->size++;
}


int pop(lin_ds *s)
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


int head(lin_ds *s)
{
    assert(!is_empty(s));
    return s->data[s->size - 1];
}
