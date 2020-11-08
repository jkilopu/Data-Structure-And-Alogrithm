#include "queue.h"
#include "unit_test.h"

static void queue_common_test(void);

int main(void)
{
    queue_common_test();
    test_passed("Queue");
}

static void queue_common_test(void)
{
    Queue q = CreateQueue(5, sizeof(char));
    char *seq = "012345678";

    Enqueue(seq, sizeof(char), q);
    Enqueue(seq + 1, sizeof(char), q);
    Enqueue(seq + 2, sizeof(char), q);
    Enqueue(seq + 3, sizeof(char), q);
    Enqueue(seq + 4, sizeof(char), q);
    assert_true("IsFull", IsFull(q));
    
    /* Enqueue, Dequeque and recorded size*/
    char actual_elem = (*(char *)FrontAndDequeue(sizeof(char), q));
    check_char("Element", '0', actual_elem);
    check_unsigned("Size", 4, q->Size);
    actual_elem = (*(char *)FrontAndDequeue(sizeof(char), q));
    check_char("Element", '1', actual_elem);
    Enqueue(seq + 5, sizeof(char), q);
    check_unsigned("Size", 4, q->Size);

    /* If the queue is circular */
    Dequeue(q);
    Dequeue(q);
    check_unsigned("Size", 2, q->Size);
    Dequeue(q);
    Dequeue(q);
    assert_true("IsEmpty", IsEmpty(q));
    Enqueue(seq + 6, sizeof(char), q);
    Enqueue(seq + 7, sizeof(char), q);
    check_unsigned("Size", 2, q->Size);
    actual_elem = *((char *)FrontAndDequeue(sizeof(char), q));
    check_char("Element", '6', actual_elem);
    actual_elem = *((char *)FrontAndDequeue(sizeof(char), q));
    check_char("Element", '7', actual_elem);
    assert_true("IsEmpty", IsEmpty(q));

    DisposeQueue(q);
}
