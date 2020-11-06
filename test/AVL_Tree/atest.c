#include "avl-tree.h"
#define SIZE 10
int main(void)
{
    ATree atree = NULL;
    int i;

    for (i = 0; i < SIZE; i++)
        atree = AInsert(i, atree);
    ATraversal(atree);
    
    AMakeEmpty(atree);
    return 0;
}