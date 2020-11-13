#ifndef _queue_h
#define _queue_h

#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MinQueueSize (5)

struct QueueRecord
{
    unsigned int Capacity;
    unsigned int Front;
    unsigned int Rear;
    unsigned int Size;
    void *Array;
    size_t elem_size;
};
typedef struct QueueRecord *Queue;

bool IsEmpty(const Queue Q);
bool IsFull(const Queue Q);
Queue CreateQueue(const int MaxElements, const size_t elem_size);
void CreateLocalQueue(struct QueueRecord *LQ, const int MaxElements, const size_t elem_size);
void DisposeQueue(Queue Q);
void DisposeLocalQueue(struct QueueRecord *LQ);
void MakeEmpty(Queue Q);
void Enqueue(const void *X, Queue Q);
void *Front(const Queue Q);
void Dequeue(Queue Q);
void *FrontAndDequeue(Queue Q);

#endif
