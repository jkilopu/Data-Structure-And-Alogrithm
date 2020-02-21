#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b);
int main(void)
{
    int t, i, j, n, m, *a;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        a = (int *)malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        qsort(a, n, sizeof(int), cmp);
    }
}
int cmp(const void *a, const void *b)
{
    return (*(int *)a) > (*(int *)b);
}