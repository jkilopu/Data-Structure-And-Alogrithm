#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int cmp(const void *a, const void *b);
void swap(int *a, int *b);

int main(void)
{
    int N, *arr;
    
    /* 读入 */
    scanf("%d", &N);
    arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    
    /* 排序 */
    qsort(arr, N, sizeof(int), cmp);

    /* 计算m、n */
    int m = (int) sqrt((double) N);
    while (N % m != 0)
        m++;
    int n = N / m;
    if (m < n)
        swap(&m, &n);
    // printf("m = %d, n = %d\n", m, n);
    
    /* 给矩阵分配空间 */
    int **matrix = (int **)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++)
        matrix[i] = (int *)malloc(sizeof(int) * n);
    
    /* 开始赋值 */
    bool xChanging = true;
    for (int i = 0, j = 0, k = 0, right = n, left = -1, bottom = m, top = -1, xDirection = 1, yDirection = 1; k < N; k++)
    {
        matrix[i][j] = arr[k];
        if (xChanging)
        {
            j += xDirection;
            if (j == right || j == left)
            {
                xDirection *= -1;
                xChanging = false;
                if (j == right)
                {
                    j = right - 1;
                    i++;
                    top++;
                }
                else
                {
                    j = left + 1;
                    i--;
                    bottom--;
                }
            }
        }
        else
        {
            i += yDirection;
            if (i == top || i == bottom)
            {
                yDirection *= -1;
                xChanging = true;
                if (i == bottom)
                {
                    i = bottom - 1;
                    j--;
                    right--;
                }
                else
                {
                    i = top + 1;
                    j++;
                    left++;
                }
            }
        }
    }

    /* 输出 */
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", matrix[i][j]);
            if (j != n - 1)
                putchar(' ');
        }
        putchar('\n');
    }

    /* 释放空间 */
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
    free(arr);
    return 0;
}

int cmp(const void *a, const void *b)
{
    return *((int *) b) - *((int *) a);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}