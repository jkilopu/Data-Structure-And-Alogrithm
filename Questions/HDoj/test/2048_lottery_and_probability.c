#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, j, N;
    long n;
    long double *probability;

    scanf("%d", &N);
    probability = (long double *)malloc(N * sizeof(long double));
    for (j = 0; j < N; j++)
    {
        scanf("%ld", &n);
        int tmp = n;
        if (n == 1)
            probability[j] = 0.0;
        else
        {
            for (i = 2, n = 1; i <= tmp; i++)
                n = n * i;
            probability[j] = 100 / (long double)n;
        }
    }
    for (j = 0; j < N; j++)
        printf("%Lf\n", probability[j]);

    return 0;
}