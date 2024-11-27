#include "linear_data_structure.h"

lin_ds *create_lin_ds(size_t initial_capacity)
{
    lin_ds *lds = malloc(sizeof(lin_ds));
    
    if (lds == NULL) return NULL;
    
    lds->data = malloc(initial_capacity * sizeof(int));
    if (!lds->data) 
    {
        free(lds);
        fprintf(stderr, "memory allocation failed\n");
        return NULL;
    }

    lds->size = 0;
    lds->capacity = initial_capacity;

    return lds;
}

void resize_lin_ds(lin_ds *lds)
{
    assert(lds);

    lds->capacity *= 2;

    int *new_data = realloc(lds->data, lds->capacity * sizeof(int));
    if (!new_data) 
    {
        fprintf(stderr, "Error occurred when resizing linear data structure\n");
    }

    lds->data = new_data;
}

int size(lin_ds *lds) 
{   
    assert(lds);
    return lds->size;
}

bool is_empty(lin_ds *lds)
{
    assert(lds);
    return lds->size == 0;
}
