#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue
{
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
    int size;
}Queue;

void queue_init(Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    memset(queue->data, 0, MAX_QUEUE_SIZE);
}

bool queue_isFull(Queue* queue)
{
    return (queue->size == MAX_QUEUE_SIZE);
}

bool queue_isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

bool queue_enqueue(Queue* queue, int x)
{
    if (queue_isFull(queue))
    {
        printf("Queue is full\n");
        return false;
    }

    queue->data[queue->rear] = x;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->size++;
    return true;
}

bool queue_dequeue(Queue* queue, int* value)
{
    if (queue_isEmpty(queue))
    {
        printf("Queue is empty\n");
        return false;
    }

    *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    return true;
}

bool queue_peek(Queue* queue, int* value)
{
    if (queue_isEmpty(queue))
    {
        printf("Queue is empty\n");
        return false;
    }
    *value = queue->data[queue->front];
    return true;
}

void queue_print(Queue* queue)
{
    for (int iter = queue->front; iter <= queue->size; ++iter)
    {
        printf("Queu: %d\n", queue->data[iter]);
    }
    printf("\n");
}

int main()
{
    Queue queue;
    int value = 0;
    queue_init(&queue);
    queue_enqueue(&queue, 1);
    queue_enqueue(&queue, 2);
    queue_enqueue(&queue, 3);

    queue_print(&queue);

    queue_peek(&queue, &value);
    printf("Peek Value: %d\n", value);
    queue_dequeue(&queue, &value);
    printf("Value dequeued: %d\n", value);

    queue_print(&queue);



    return 0;
}





