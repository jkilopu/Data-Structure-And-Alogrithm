#include "queue.h"
#include "fatal.h"
#include <string.h>

bool IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

bool IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements, size_t elem_size)
{
    Queue Q;
    if (MaxElements < MinQueueSize)
        Error("Queue len is too short");

    Q = (Queue)malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        FatalError("Out of space!!!");

    Q->Array = (void *)malloc(elem_size * MaxElements);
    if (Q->Array == NULL)
        FatalError("Out of space!!!");
    Q->Capacity = MaxElements;
    MakeEmpty(Q);

    return Q;
}

void DisposeQueue(Queue Q)
{
    free(Q->Array);
    Q->Array = NULL;
    free(Q);
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 0;
    Q->Rear = 0;
}

void Enqueue(void *X, size_t elem_size, Queue Q)
{
    if (IsFull(Q))
        Error("Full queue.");
    else
    {
        Q->Size++;
        memcpy(((char *)Q->Array + elem_size * Q->Rear), X, elem_size);
        Q->Rear = (Q->Rear + 1) % Q->Capacity;
    }
}

void Dequeue(Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue.");
    else
    {
        Q->Size--;
        Q->Front = (Q->Front + 1) % Q->Capacity; 
    }
}

void *Front(size_t elem_size, Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue.");
    else
        return (void *)((char *)Q->Array + elem_size * Q->Front);
}

void *FrontAndDequeue(size_t elem_size, Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue.");
    else
    {
        void *ret = (void *)((char *)Q->Array + elem_size * Q->Front);
        Q->Size--;
        Q->Front = (Q->Front + 1) % Q->Capacity;
        return ret;
    }
}