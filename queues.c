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
    // cant add more if the queue is full
    if (isFull())
    {
        printf("yo g, cant't enqueue because the queue is full! maybe dequeue?\n");
    }
    else if (isEmpty())
    {
        // set both top and rear to 0 cos there is only one element
        top, rear = 0;
        queue[rear] = value;
    }
    else
    {
        // insert at rear
        rear++;
        queue[rear] = value;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        printf("yo g cant dequeue cos there is nothing to dequeue!!\n");
    }
    else
    {
        int temp = queue[top];

        // shift everything by one towards top
        for (int i = top; i < rear + 1; i++)
        {
            queue[i] = queue[i + 1];
        }

        rear--;
        return temp;
    }
}

void printQueue()
{
    for (int i = top; i < rear + 1; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    dequeue();
    enqueue(11);

    printQueue();

    return 1;
}