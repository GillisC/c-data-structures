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

void da_resize(dynamic_array *array) 
{
    array->capacity *= 2;
    int *new_data = realloc(array->data, array->capacity);
    if (!new_data) 
    {
        fprintf(stderr, "memory reallocation failed\n");
    }
    array->data = new_data;
}


void append(dynamic_array *array, int element) 
{
    if (array->size >= array->capacity) 
    {
        da_resize(array);
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

int da_size(dynamic_array *array) 
{
    return array->size;
}
