#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int t, sum, i, j, temp, *max, *n, *s, **a;

    scanf("%d", &t);
    n = (int *)malloc(t * sizeof(int));
    s = (int *)malloc(t * sizeof(int));
    max = (int *)malloc(t * sizeof(int));
    a = (int **)malloc(t * sizeof(int*));
    for (i = 0; i < t;i++)
    {
        scanf("%d %d", &n[i], &s[i]);
        a[i] = (int *)malloc(n[i] * sizeof(int));
        for (j = 0; j < n[i];j++)
            scanf("%d", &a[i][j]);
        max[i] = 0;
    }
    for (i = 0, sum = 0; i < t;i++)
    {
        sum = 0, j = 0, temp = 0;
        while(j < n[i])
        {
            if(a[i][j] > a[i][temp])
                max[i] = j;
            temp = max[i];
            sum += a[i][j];
            j++;
            if(sum > s[i])
                break;
        }
        if(j == n[i])
            max[i] = -1;
        else 
        {
            sum -= a[i][temp];
            if(sum + a[i][j] > s[i])
                max[i] = -1;
        }
    }
    for (i = 0; i < t;i++)
        printf("%d\n", max[i] + 1);
    free(n);
    free(s);
    free(max);
    free(a);

    return 0;
}