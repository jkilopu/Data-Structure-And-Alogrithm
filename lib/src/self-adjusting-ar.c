#include "self-adjusting-ar.h"
Saar CreateSaar(int MaxArraySize)
{
    if (MaxArraySize < MINARRAYSIZE)
        Error("The size of array is too small");
    Saar sa = (Saar)malloc(sizeof(ElementType *));
    if (sa == NULL)
        FatalError("Out of space!");
    sa->ar = (ElementType *)malloc(MaxArraySize * sizeof(ElementType));
    if (sa->ar == NULL)
        FatalError("Out of space!");
    sa->capacity = MaxArraySize;
    SAMakeEmpty(sa);
    return sa;
}
Saar SAAdd(Saar sa, ElementType value)
{
    if (SAIsFull(sa))
        Error("The sa is full!");
    else
        sa->ar[++sa->top] = value;
}
Saar SAFind(Saar sa, ElementType value)
{
    int i, j;
    ElementType temp;
    //查找 由于有最高访问量的数据靠近表头，所以从前面开始找
    for (i = sa->top; i >= 0; i--)
        if (sa->ar[i] == value)
            break;
    //将i与top之间的数据向后移一位
    if (i != EMPTYTOP)
    {
        temp = sa->ar[i];
        for (j = i + 1; j <= sa->top; j++)
            sa->ar[j - 1] = sa->ar[j];
        sa->ar[sa->top] = temp;
    }
    return sa;
}
Saar SADispose(Saar sa)
{
    if (sa != NULL)
    {
        free(sa->ar);
        free(sa);
    }
}
void SAPrint(Saar sa)
{
    int i;
    for (i = 0; i <= sa->top; i++)
        printf("%d ", sa->ar[i]);
    putchar('\n');
}
void SAMakeEmpty(Saar sa)
{
    sa->top = EMPTYTOP;
}
bool SAIsEmpty(Saar sa)
{
    return (sa->top == EMPTYTOP);
}
bool SAIsFull(Saar sa)
{
    return sa->top == sa->capacity - 1;
}