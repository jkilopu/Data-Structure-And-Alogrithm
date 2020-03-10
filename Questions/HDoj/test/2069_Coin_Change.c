/* 别人的最简单的版本...
 * 还可以用动态规划做...
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int v[5] = {1, 5, 10, 25, 50};
int n;
int res;
void dfs(int sum, int ans, int s, int num)
{
    // sum表示当前组成的面值,ans代表n值,s代表搜索深度（0,4）,num代表硬币数
    if (num > 100)
        return;
    if (sum == ans)
    {
        res++;
        return;
    }
    if (sum > ans)
        return;
    for (int i = s; i < 5; i++)
    {
        if (sum + v[i] > ans)
            return;
        dfs(v[i] + sum, ans, i, num + 1);
    }
}
int main(void)
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            printf("1\n");
            continue;
        }
        res = 0;
        for (int i = 0; i < 5; i++)
        {
            dfs(v[i], n, i, 1);
        }
        printf("%d\n", res);
    }
}