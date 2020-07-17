#include <stdio.h>
#include <stdlib.h>

#define MAX(__x, __y) ((__x > __y) ? (__x) : (__y))

const int DIRECTIONS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int **a, int **dp, int r, int c, int y, int x);

int main(void)
{
    int r, c;

    scanf("%d%d", &r, &c);
    int **map, **dp;
    map = (int **)malloc(sizeof(int *) * r );
    dp = (int **)malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++)
    {
        map[i] = (int *)malloc(sizeof(int) * c);
        dp[i] = (int *)calloc(c, sizeof(int));
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &map[i][j]);

    int maxLength = 1;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            int length = dfs(map, dp, r, c, i, j);
            maxLength = MAX(maxLength, length);
        }

    printf("%d\n", maxLength);

    for (int i = 0; i < r; i++)
    {
        free(map[i]);
        free(dp[i]); 
    }
    free(map);
    free(dp);
}

/* 思路混乱 */
int dfs(int **a, int **dp, int r, int c, int y, int x)
{
    if (dp[y][x] != 0)
        return dp[y][x];
    dp[y][x] = 1;
    for (int k = 0; k < 4; k++)
    {
        int nextY = y + DIRECTIONS[k][0], nextX = x + DIRECTIONS[k][1];
        if (nextY >= 0 && nextY < r && nextX >= 0 && nextX < c && a[nextY][nextX] > a[y][x])
        {
            dfs(a, dp, r, c, nextY, nextX);
            dp[y][x] = MAX(dp[y][x], dp[nextY][nextX] + 1);
        }
    }
    return dp[y][x];
}