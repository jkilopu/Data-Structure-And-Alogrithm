#include "binary-search-tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int main(void)
{
    STree stree = NULL;

    srand(time(NULL));
    int i, a[SIZE];
    for (i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 10;
        printf("%d ", a[i]);
        stree = SInsert(a[i], stree);
    }
    putchar('\n');
    PTraversal(stree);
    printf("\nMax: %d, Min: %d\n", SFindMax(stree)->value, SFindMin(stree)->value);

    return 0;
}