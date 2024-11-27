#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

typedef struct
{
    int *data;
    int capacity;
    int size;
    int front;
    int back;
} queue;

queue *create_queue(int initial_capacity);
void resize_queue(queue *q);
void enqueue(queue *q, int);
int dequeue(queue *q);
int peek(queue *q);
int queue_size(queue *q);
bool queue_is_empty(queue *q);