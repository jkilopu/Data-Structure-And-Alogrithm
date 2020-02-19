/* DFS第一题 
 * 我觉得这道题的解法被称作DFS是因为每一次都将结果穷尽
//  * 1. 一开始硬算（枚举） （DFS）
 * 2. 后面利用排列组合的知识（组合数怎么算都忘了）
 * 3. 超时，后面看题解，C(n,2)就是n(n-1)/2...完全没想到
 * ps:此公式也等于高斯求和的公式，有的题解是这样找规律的...
 */
#include <stdio.h>
#include <stdlib.h>
int combination_2(int n);
int main(void)
{
    int n, i, j, num_c_col, num_c_row, cnt = 0, tmp;
    char **map;

    scanf("%d", &n);
    map = (char **)malloc(sizeof(char *) * n);
    for (i = 0; i < n; i++)
    {
        map[i] = (char *)malloc(sizeof(char) * n);
        scanf("%s", map[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0, num_c_col = 0, num_c_row = 0; j < n; j++)
        {
            /* 行 */
            if (map[i][j] == 'C')
                num_c_col++;
            /* 列 */
            if (map[j][i] == 'C')
                num_c_row++;
        }
        cnt += combination_2(num_c_col);
        cnt += combination_2(num_c_row);
    }
    printf("%d", cnt);

    return 0;
}
/* 使用排列组合的知识:C(n,2) */
int combination_2(int n)
{
    return n * (n - 1) / 2;
}