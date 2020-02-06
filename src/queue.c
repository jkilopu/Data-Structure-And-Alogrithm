#include "queue.h"
#include "fatal.h"
struct QueueRecord
{
    unsigned int Capacity;
    unsigned int Front;
    unsigned int Rear;
    unsigned int Size;
    ElementType *Array;
};
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
    free(Q);
}
void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}
static int Succ(int Position, Queue Q)
{
    if (++Position == Q->Capacity)
        Position = 0;
    return Position;
}
void Enqueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
        Error("Full queue.");
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}
void Dequeue(Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue.");
    else
    {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
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
        Q->Front = Succ(Q->Front, Q);
        return ret;
    }
}
