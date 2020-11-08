#ifndef _queue_h
#define _queue_h

#include <stdlib.h>
#include <stdbool.h>

#define MinQueueSize (5)

struct QueueRecord
{
    unsigned int Capacity;
    unsigned int Front;
    unsigned int Rear;
    unsigned int Size;
    void *Array;
};
typedef struct QueueRecord *Queue;

bool IsEmpty(Queue Q);
bool IsFull(Queue Q);
Queue CreateQueue(int MaxElements, size_t elem_size);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(void *X, size_t elem_size, Queue Q);
void *Front(size_t elem_size, Queue Q);
void Dequeue(Queue Q);
void *FrontAndDequeue(size_t elem_size, Queue Q);

#endif