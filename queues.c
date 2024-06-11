// QUEUES!!!
// a queue is a data structure very similar to a stack
// in a stack, insertion and deletion happen at the same end of the list
// a queue on the other hand is first in first out
// this means that insertion and deletion happen on opposite ends of the loop

// array implementation
// here the front is gonna be the fron of the array (lower index)

#include <stdio.h>

#define QUEUE_SIZE 10

// create the queue and define top and rear
int queue[QUEUE_SIZE];
int top, rear = -1;

// returns 1 if the queue is empty, 0 if it has elements in it
int isEmpty()
{
    if (top == -1 && rear == -1)
    {
        return 1;
    }

    return 0;
}

// returns 1 if the queue is full, 0 if it there is free space
int isFull()
{
    if (rear == QUEUE_SIZE - 1)
    {
        return 1;
    }

    return 0;
}

void enqueue(int value)
{
}