#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX(_X, _Y) ((_X > _Y) ? _X : _Y)

typedef struct _node
{
    int8_t left;
    int8_t right;
    int8_t height;
} Node;

typedef struct _queue
{
    int8_t *arr;
    int8_t front;
    int8_t rear;
    int8_t size;
} Queue;

int8_t cnt_height(Node *a, int8_t i);
Queue *create_queue(int8_t size);
void destroy_queue(Queue **queue);
bool empty_queue(Queue *q);
void enqueue(Queue *q, int8_t elem);
int8_t dequeue(Queue *q);

void level_traverse(Node *a, int8_t size, int8_t head);

int main(void)
{
    int8_t N;
    Node *arr;

    scanf("%hhd", &N);
    arr = malloc(N * sizeof(Node));

    /* -1代表指向"空" */
    memset(arr, -1, N * sizeof(Node));

    char l, r;
    for (int8_t i = 0; i < N; i++)
    {
        /* 如果用%hhd遇到'-'会赋0 */
        scanf(" %c %c", &l, &r);
        if (l != '-')
            arr[i].left = l - '0';
        if (r != '-')
            arr[i].right = r - '0';
    }
    /* 高度只能在这个时候算... */
    int8_t head, max_height = 0;
    for (int8_t i = 0; i < N; i++)
    {
        arr[i].height = cnt_height(arr, i);
        if (arr[i].height > max_height)
        {
            max_height = arr[i].height;
            head = i;
        }
    }

    level_traverse(arr, N, head);

    free(arr);
    arr = NULL;
    return 0;
}

int8_t cnt_height(Node *a, int8_t i) // 可以改写为set_height为所有节点设置高度
{
    if (i == -1)
        return 0;
    return MAX(cnt_height(a, a[i].left), cnt_height(a, a[i].right)) + 1;
}

/* 使用队列的层次遍历 */
void level_traverse(Node *a, int8_t size, int8_t head)
{
    int8_t p;
    Queue *q = create_queue(size + 1); // 队列的大小必须比元素个数多1，可以不创建在堆上
    
    enqueue(q, head);
    do
    {
        p = dequeue(q);
        if (a[p].left == -1 && a[p].right == -1) // 只输出叶子
            printf("%hhd", p);
        if (a[p].left != -1)
            enqueue(q, a[p].left);
        if (a[p].right != -1)
            enqueue(q, a[p].right);
        if (a[p].left == -1 && a[p].right == -1 && !empty_queue(q)) // 格式要求。。。
            putchar(' ');
    } while (!empty_queue(q));

    destroy_queue(&q);
}

Queue *create_queue(int8_t size)
{
    Queue *queue;
    queue = malloc(sizeof(Queue));
    queue->arr = malloc(size * sizeof(int8_t));
    queue->size = size + 1;
    queue->front = queue->rear = 0;
    return queue;
}

void destroy_queue(Queue **queue)
{
    free((*queue)->arr);
    (*queue)->arr = NULL;
    free(*queue);
    (*queue) = NULL;
}

bool empty_queue(Queue *q)
{
    return q->front == q->rear;
}

void enqueue(Queue *q, int8_t elem)
{
    if (((q->rear + 1) % q->size) == q->front)
    {
        fprintf(stderr, "%s\n", "Full queue!");
        exit(1);
    }
    q->arr[q->rear] = elem;
    q->rear = (q->rear + 1) % q->size;
}

int8_t dequeue(Queue *q)
{
    if (empty_queue(q))
    {
        fprintf(stderr, "%s\n", "Empty Queue!");
        return -1;
    }
    int8_t ret = q->arr[q->front];
    q->front = (q->front + 1) % q->size;
    return ret;
}