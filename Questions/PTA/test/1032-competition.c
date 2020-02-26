#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *a, i, j, n, tmp, max;

    scanf("%d", &n);
    a = (int *)calloc(n + 1, sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &j, &tmp);
        a[j] += tmp;
    }
    for (i = 1, max = 1; i <= n; i++)
        max = a[max] > a[i] ? max : i;
    printf("%d %d", max, a[max]);
    
    return 0;
}