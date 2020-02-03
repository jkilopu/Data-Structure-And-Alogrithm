#include <stdio.h>
#include <time.h>
int main(void)
{
    int sum = 0, i, j, k, n = 200;
    clock_t start, stop;
    double duration;

    start = clock();
    for (i = 0; i < n; i++)
        for (j = 0; j < i * i; j++)
            if(j % i==0)
                for (k = 0; k < j; k++)
                    sum++;
    stop = clock();
    duration = ((double)stop - start) / CLK_TCK;
    printf("Time_1: %lf", duration);

    return 0;
}