#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main(void)
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    //一种创建链表的新奇方式?
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}
int FactorialSum( List L )
{
    int factory, i, sum = 0;
    PtrToNode p = L;
    while(p)
    {
        factory = p->Data, i = p->Data;
        //阶乘的奇妙实现
        if (i)
            while (--i)
                factory *= i;
        else
            factory = 1;
        
        sum += factory;
        p = p->Next;
    }
    return sum;
}