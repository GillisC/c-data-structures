#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef struct {
    int *data;
    size_t capacity; 
    size_t size;
} dynamic_array;

dynamic_array *create_dynamic_array(size_t initial_capacity);
void da_resize(dynamic_array *array);
void append(dynamic_array *array, int element);
int at(dynamic_array *array, int index);
int da_size(dynamic_array *array);
void sort(dynamic_array *array);

