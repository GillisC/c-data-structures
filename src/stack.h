#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct 
{
    int *data;
    int capacity;
    int size;
} stack;

stack *create_stack(size_t*);
void resize(stack*);
void push(stack*, int);
int pop(stack*);
int head(stack*);
bool isEmpty(stack*);
int size(stack*);


