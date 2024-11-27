#include "dynamic_array.h"

dynamic_array *create_dynamic_array(size_t initial_capacity) 
{
    dynamic_array *array = malloc(sizeof(dynamic_array));
    
    if (array == NULL) return NULL;
    
    array->data = malloc(initial_capacity * sizeof(int));
    if (!array->data) 
    {
        free(array);
        fprintf(stderr, "memory allocation failed\n");
        return NULL;
    }

    array->size = 0;
    array->capacity = initial_capacity;

    return array;
}

void resize(dynamic_array *array) 
{
    array->capacity *= 2;
    array->data = realloc(&array->data, array->capacity);
    if (!array->data) 
    {
        fprintf(stderr, "memory reallocation failed\n");
    }
}


void append(dynamic_array *array, int element) 
{
    if (array->size >= array->capacity) 
    {
        resize(array);
    }
    array->data[array->size] = element;
    array->size++;
}

int at(dynamic_array *array, int index) 
{
    if (index < 0 || index >= array->size) 
    {
        fprintf(stderr, "index is out of bounds");
    } 
    return array->data[index];
}

int size(dynamic_array *array) 
{
    return array->size;
}
