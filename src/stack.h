#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef struct 
{
    int *data;
    int capacity;
    int size;
} stack;

stack *create_stack(size_t initial_capacity);
void stack_resize(stack *s);
void push(stack *s, int);
int pop(stack *s);
int head(stack *s);
int stack_size(stack *s);
bool stack_is_empty(stack *s);