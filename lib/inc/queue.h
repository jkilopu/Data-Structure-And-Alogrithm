#ifndef _queue_h
#define _queue_h

#include <stdlib.h>
#include <stdbool.h>

#define MinQueueSize (5)

typedef char ElementType;
struct QueueRecord;
typedef struct QueueRecord *Queue;

bool IsEmpty(Queue Q);
bool IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
static int Succ(int Position, Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif