#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define TIMES 4
void Swap(int *a, int *b);
void Method_1_test(double duration_1[]);
void Method_2_test(double duration_2[]);
void Method_3_test(double duration_3[]);
int main(void)
{
    int i;
    double duration_1[TIMES];
    double duration_2[TIMES];
    double duration_3[TIMES];

    srand(time(NULL));
    Method_1_test(duration_1);
    Method_2_test(duration_2);
    Method_3_test(duration_3);
    printf("Method 1:");
    for (i = 0; i < TIMES; i++)
        printf(" %lf", duration_1[i]);
    printf("\nMethod 2:");
    for (i = 0; i < TIMES; i++)
        printf(" %lf", duration_2[i]);
    printf("\nMethod 3:");
    for (i = 0; i < TIMES; i++)
        printf(" %lf", duration_3[i]);
    return 0;
}
void Method_1_test(double duration_1[])
{
    int i, j, k, tmp, *a;
    int n_test[TIMES] = {2000, 4000, 8000, 16000};
    bool isSame = false;
    clock_t start, stop;

    for (j = 0; j < TIMES; j++)
    {
        a = (int *)malloc(n_test[j] * sizeof(int));
        start = clock();
        for (i = 0; i < n_test[j]; )
        {
            tmp = rand() % n_test[j];
            for (k = 0; k < i; k++)
                if(tmp == a[k])
                {
                    isSame = true;
                    break;
                }
            if(!isSame)
            {
                a[i] = tmp;
                i++;
            }
            isSame = false;
        }
        stop = clock();
        free(a);
        duration_1[j] = ((double)stop - start) / CLK_TCK;
    }
}
void Method_2_test(double duration_2[])
{
    int i, j, tmp, *a;
    bool *Used_a;
    int n_test[TIMES] = {32000, 32000, 32000, 32000};
    clock_t start, stop;

    for (j = 0; j < TIMES; j++)
    {
        a = (int *)malloc(n_test[j] * sizeof(int));
        Used_a = (bool *)calloc(n_test[j], sizeof(bool));
        start = clock();
        for (i = 0; i < n_test[j]; )
        {
            tmp = rand() % n_test[j];    //rand() % n_test[j] + 1的话会越界
            if(!Used_a[tmp])
            {
                Used_a[tmp] = true;
                i++;
            }
        }
        stop = clock();
        free(Used_a);
        free(a);
        duration_2[j] = ((double)stop - start) / CLK_TCK;
    }
}
void Method_3_test(double duration_3[])
{
    int i, j, *a;
    int n_test[TIMES] = {640000, 1280000, 2560000, 5120000};
    clock_t start, stop;

    for (j = 0; j < TIMES; j++)
    {
        a = (int *)malloc(n_test[j] * sizeof(int));
        start = clock();
        for (i = 0; i < n_test[j]; i++)
            a[i] = i;
        for (i = 0; i < n_test[j]; i++)
            Swap(&a[i], &a[rand() % (i + 1)]);
        stop = clock();
        free(a);
        duration_3[j] = ((double)stop - start) / CLK_TCK;
    }
}
void Swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}