#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct {
    int *data;
    size_t capacity; 
    size_t size;
} dynamic_array;

dynamic_array *create_dynamic_array(size_t initial_capacity);
void resize(dynamic_array *array);
void append(dynamic_array *array, int element);
int at(dynamic_array *array, int index);
int size(dynamic_array *array);

void sort(dynamic_array *array);

