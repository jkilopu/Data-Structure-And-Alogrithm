/* 包含找到数组中所有不重复数的方法 
 * 正确题解看这里https://www.liuchuo.net/archives/2480
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) ((x > y) ? (x) : (y))

int cmp(const void *a, const void *b);
int nextRight(int right, int a[], int N);

int main(void)
{
    int N, *a;
    
    scanf("%d", &N);
    a = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    
    qsort(a, N, sizeof(int), cmp);
    
    int E = 0;
    int right = 0; // 左闭右开区间
    while (right < N)
    {
        int largerN = N - right;
        if (largerN < a[right])
            E = MAX(E, largerN);
        right = nextRight(right, a, N);
    }
    
    printf("%d\n", E);
    
    free(a);
    return 0;
}

int cmp (const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int nextRight(int right, int a[], int N)
{
    int present = a[right];
    while (right < N && a[right] == present)
        right++;
    return right;
}