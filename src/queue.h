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
} queue;

queue *create_queue(size_t initial_capacity);
void stack_resize(queue *s);
void enqueue(queue *s, int);
int dequeue(queue *s);
int peek(queue *s);
int queue_size(queue *s);
bool queue_is_empty(queue *s);