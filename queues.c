// QUEUES!!!
// a queue is a data structure very similar to a stack
// in a stack, insertion and deletion happen at the same end of the list
// a queue on the other hand is first in first out
// this means that insertion and deletion happen on opposite ends of the loop

// array implementation
// now you might be thinking, this guy is so silly he will run out of space in his array
// little did you know... CIRCULAR ARRAY!!!

#include <stdio.h>

#define QUEUE_SIZE 10

// create the queue and define front and rear
int queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

// returns 1 if the queue is empty, 0 if it has elements in it
int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        printf("yeah mate, pretty empty\n");
        return 1;
    }

    return 0;
}

// returns 1 if the queue is full, 0 if it there is free space
int isFull()
{
    if ((rear + 1) % QUEUE_SIZE == front)
    {
        return 1;
    }

    return 0;
}

void enqueue(int value)
{
    printf("front: %d, rear: %d\n", front, rear);

    // cant add more if the queue is full
    if (isFull())
    {
        printf("yo g, cant't enqueue because the queue is full! maybe dequeue?\n");
    }
    else if (isEmpty())
    {
        // set both front and rear to 0 cos there is only one element
        front = 0;
        rear = 0;
        queue[rear] = value;
    }
    else
    {
        // insert at rear
        rear = (rear + 1) % QUEUE_SIZE;
        queue[rear] = value;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        printf("yo g cant dequeue cos there is nothing to dequeue!!\n");
    }
    else if (front == rear)
    {
        // only one element so dequeue will make the queue empty
        front = -1;
        rear = -1;
    }
    else
    {
        int temp = queue[front];
        front = (front + 1) % QUEUE_SIZE;
        return temp;
    }
}

void printQueue()
{
    for (int i = 0; i < QUEUE_SIZE; i++)
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
    printf("dequeued value: %d\n", dequeue());
    enqueue(11);
    printf("dequeued value: %d\n", dequeue());
    enqueue(12);

    printQueue();

    return 1;
}