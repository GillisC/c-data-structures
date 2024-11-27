#include "queue.h"



queue *create_queue(int initial_capacity)
{
    queue *q = malloc(sizeof(queue));
    if (!q)
    {
        return NULL;
    }
    q->data = malloc(initial_capacity * sizeof(int));

    if (!q->data) 
    {
        fprintf(stderr, "memory allocation failed\n");
        return NULL;
    }

    q->capacity = initial_capacity;
    q->size = 0;
    q->front = -1;
    q->back = -1;
    
    return q;
}


void resize_queue(queue *q)
{
    // Creates a new array and copies the current array to it starting from the head and looping around if neccassary
    int new_capacity = q->capacity * 2;

    int *new_data = malloc(new_capacity * sizeof(int)); // Allocate the space for the new queue contents

    for (int i = 0; i < q->size; i++)
    {
        new_data[i] = q->data[(q->front + i) % q->capacity];
    }
    free(q->data);
    q->data = new_data;
    q->capacity = new_capacity;
    q->front = 0;
    q->back = q->size;
}


void enqueue(queue *q, int element)
{
    assert(q);

    if (q->front == -1 && q->back == -1)
    {
        // The queue is empty 
        q->front = 0;
        q->back = 0;

    }
    else if (q->front == q->back)
    {
        resize_queue(q);
    }

    q->data[q->back] = element;
    q->back++;
    q->size++;
}


int dequeue(queue *q)
{
    if (queue_is_empty(q))
    {
        fprintf(stderr, "Queue is empty can't dequeue.\n");
        exit(EXIT_FAILURE);
    }

    int result = q->data[q->front];
    q->front++;
    q->size--;

    if (q->front == q->back)
    {
        q->front = -1;
        q->back = -1;
    }

    return result; 
}


int peek(queue *q)
{
    assert(q);

    if (queue_is_empty(q))
    {
        fprintf(stderr, "Can't peek, queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    return q->data[q->front];
}


int queue_size(queue *q)
{
    assert(q);

    return q->size;
}


bool queue_is_empty(queue *q)
{
    return (q->front -1 && q->back == -1);
}