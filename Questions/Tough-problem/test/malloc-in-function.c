//两种在函数中malloc()的方式（为什么不可靠？）
#include <stdio.h>
#include <stdlib.h>
int *f(void);
int* g(int **);
int main(void)
{
    int *p, *q;
    p = (int *)malloc(10 * sizeof(int));
    printf("Method 1: %p\n", p);
    printf("Method 2: %p\n", f());
    printf("Method 3: %p\n", g(&q));

    //f()分配的空间释放很不方便，必须要用另一个变量记录
    free(p);
    free(q);

    return 0;
}
int* f(void)
{
    int *tmp;
    tmp = (int *)malloc(10 * sizeof(int));
    return tmp;
}
int* g(int **q)
{
    *q = (int *)malloc(10 * sizeof(int));
    return *q;
}