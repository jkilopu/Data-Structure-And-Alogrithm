#include "queue.h"
#include "fatal.h"
#include <string.h>

bool IsEmpty(const Queue Q)
{
    return Q->Size == 0;
}

bool IsFull(const Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(const int MaxElements, size_t elem_size)
{
    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        FatalError("Out of space!!!");

    CreateLocalQueue(Q, MaxElements, elem_size);

    return Q;
}

void CreateLocalQueue(struct QueueRecord *LQ, const int MaxElements, const size_t elem_size)
{
    if (MaxElements < MinQueueSize)
        Error("Queue len is too short");

    LQ->elem_size = elem_size;
    LQ->Capacity = MaxElements;
    LQ->Array = (void *)malloc(elem_size * MaxElements);
    if (LQ->Array == NULL)
        FatalError("Out of space!!!");
    MakeEmpty(LQ);
}

void DisposeQueue(Queue Q)
{
    DisposeLocalQueue(Q);
    free(Q);
}

void DisposeLocalQueue(struct QueueRecord *LQ)
{
    free(LQ->Array);
    LQ->Array = NULL;
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 0;
    Q->Rear = 0;
}

void Enqueue(const void *X, Queue Q)
{
    if (IsFull(Q))
        Error("Full queue.");
    else
    {
        Q->Size++;
        memcpy(((char *)Q->Array + Q->elem_size * Q->Rear), X, Q->elem_size);
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

void *Front(const Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue.");
    else
        return (void *)((char *)Q->Array + Q->elem_size * Q->Front);
}

void *FrontAndDequeue(Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue.");
    else
    {
        void *ret = (void *)((char *)Q->Array + Q->elem_size * Q->Front);
        Q->Size--;
        Q->Front = (Q->Front + 1) % Q->Capacity;
        return ret;
    }
}
