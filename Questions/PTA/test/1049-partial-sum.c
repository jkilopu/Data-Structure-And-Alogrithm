#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    double *a;

    /* 读入 */
    scanf("%d", &N);
    a = (double *)malloc(sizeof(double) * N);
    for (int i = 0; i < N; i++)
        scanf("%lf", a + i);
    
    /* 计算 */
    double sum = 0.0;
    for (int i = 0; i < N; i++)
        sum += (double) (i + 1) * (double) (N - i) * a[i];

    /* 输出 */
    printf("%.2lf", sum);

    free(a);
    return 0;
}