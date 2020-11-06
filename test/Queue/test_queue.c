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
    Queue q = CreateQueue(5);
    Enqueue('1', q);
    Enqueue('2', q);
    Enqueue('3', q);
    Enqueue('4', q);
    Enqueue('5', q);
    assert_true("IsFull", IsFull(q));
    
    /* Enqueue, Dequeque and recorded size*/
    char actual_elem = FrontAndDequeue(q);
    check_char("Element", '1', actual_elem);
    check_unsigned("Size", 4, q->Size);
    actual_elem = FrontAndDequeue(q);
    check_char("Element", '2', actual_elem);
    Enqueue('6', q);
    check_unsigned("Size", 4, q->Size);

    /* If the queue is circular */
    Dequeue(q);
    Dequeue(q);
    check_unsigned("Size", 2, q->Size);
    Dequeue(q);
    Dequeue(q);
    assert_true("IsEmpty", IsEmpty(q));
    Enqueue('7', q);
    Enqueue('8', q);
    check_unsigned("Size", 2, q->Size);
    actual_elem = FrontAndDequeue(q);
    check_char("Element", '7', actual_elem);
    actual_elem = FrontAndDequeue(q);
    check_char("Element", '8', actual_elem);
    assert_true("IsEmpty", IsEmpty(q));

    DisposeQueue(q);
}
