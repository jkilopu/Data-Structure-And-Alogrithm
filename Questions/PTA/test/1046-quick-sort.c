#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b);

int main(void)
{
    int N, *a, *sorted;
    bool *isMains;

    scanf("%d", &N);
    a = (int *)malloc(sizeof(int) * N);
    sorted = (int *)malloc(sizeof(int) * N);
    isMains = (bool *)calloc(N, sizeof(bool));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", a + i);
        sorted[i] = a[i];
    }
    
    qsort(sorted, N, sizeof(int), cmp);

    int max = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (sorted[i] == a[i] && sorted[i] == max)
        {
            isMains[i] = true;
            n++;
        }
    }

    printf("%d\n", n);
    if (n == 0)
        putchar('\n');
    for (int i = 0, cnt = 0; i < N; i++)
    {
        if (isMains[i])
        {
            cnt++;
            if (cnt == n)
                printf("%d\n", a[i]);
            else
                printf("%d ", a[i]);
        }
    }

    free(a);
    free(isMains);
    free(sorted);
    return 0;
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}