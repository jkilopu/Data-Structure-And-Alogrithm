#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LENS 18
bool isRight(int *a);
int main(void)
{
    int i, j, n;
    int check_code;
    const int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};  /* 权重 */
    const char board[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};/* 校验 */
    char tmp[LENS]; /* 在还不能判断是否输出时暂时存放数组 */
    bool allpass;

    scanf("%d", &n);
    for (i = 0, allpass = true; i < n; i++)
    {
        getchar(); /* for '\n' */
        for (j = 0, check_code = 0; j < LENS - 1; j++)
        {
            tmp[j] = getchar();
            check_code += ((tmp[j] - '0') * weight[j]);
        }
        tmp[j] = getchar();
        tmp[j + 1] = '\0';
        check_code %= 11;
        if (tmp[j] != board[check_code])
        {
            puts(tmp);
            allpass = false;
        }
    }
    if (allpass)
        puts("All passed");

    return 0;
}
bool isRight(int *a)
{
}