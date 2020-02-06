/* 约瑟夫环模拟的做法 */
#include <stdio.h>
#include "circular-singly-list.h"
#include <time.h>
#include <unistd.h>
int main(void)
{
    CList people = CreateCList();
    CNode *p, *front;
    int M = 1, N = 5, i;
    double duration;
    clock_t start, stop;

    for (i = 0; i < N; i++)
        CAdd(people, i);
    // 测试CDelete_n
    // CDelete_n(people, 0);
    // CPrint(people);

    start = clock();
    //Josephus Problem
    M %= N; //使烫手山芋不会绕一圈
    for (p = people->head; p->next != p; p = front->next)
    {
        for (i = 0; i < M; i++)
        {
            front = p;
            p = p->next;
        }
        front->next = p->next;
        if (p == people->head)
            people->head = p->next;
        if (p == people->tail)
            people->tail = front;
        free(p);
        // CPrint(people); /* 仅测试时使用 */
    }
    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    CPrint(people), printf("Time spent: %lf", duration);
    CClear(people);

    return 0;
}
/* 改进:
 * 1. M模N，使 M > N 时烫手山芋不会绕一圈
 * 2. M > N / 2 时，改变传递方向（要用到双向链表）
 * 3. 使用一些数学知识（递归的想法：解决N，就要先解决N - 1）（未完成）
*/