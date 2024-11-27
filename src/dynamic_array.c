#include "dynamic_array.h"

void append(lin_ds *array, int element) 
{
    if (array->size >= array->capacity) 
    {
        resize_lin_ds(array);
    }
    array->data[array->size] = element;
    array->size++;
}

int at(lin_ds *array, int index) 
{
    if (index < 0 || index >= array->size) 
    {
        fprintf(stderr, "index is out of bounds");
    } 
    return array->data[index];
}

int da_size(lin_ds *array) 
{
    return array->size;
}
