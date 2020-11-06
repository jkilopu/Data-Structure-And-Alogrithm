#include "queue.h"
#include "fatal.h"

bool IsEmpty(Queue Q)
{
    return Q->Size == 0;
}
bool IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}
Queue CreateQueue(int MaxElements)
{
    Queue Q;
    if (MaxElements < MinQueueSize)
        Error("Queue size is too small");

    Q = (Queue)malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        FatalError("Out of space!!!");

    Q->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
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
void Enqueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
        Error("Full queue.");
    else
    {
        Q->Size++;
        Q->Array[Q->Rear] = X;
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
ElementType Front(Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue.");
    else
        return Q->Array[Q->Front];
}
ElementType FrontAndDequeue(Queue Q)
{
    int ret;
    if (IsEmpty(Q))
        Error("Empty queue.");
    else
    {
        Q->Size--;
        ret = Q->Array[Q->Front];
        Q->Front = (Q->Front + 1) % Q->Capacity;
        return ret;
    }
}