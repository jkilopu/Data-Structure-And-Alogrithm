/* 没搞懂返回值 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a, b) a < b ? a : b
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dfs(int **m, int y, int x, int life);
int main(void)
{
    int **map;
    int n, m, i, j, cnt = 0;

    scanf("%d%d", &n, &m);
    /* create map map */
    map = (int **)malloc(sizeof(int *) * (n + 2));
    for (i = 0; i < n + 2; i++)
    {
        map[i] = (int *)malloc(sizeof(int) * (m + 2));
        memset(map[i], 0, sizeof(int) * (m + 2)); /* 必须这样memset*/
    }
    /* draw the map */
    for (i = 1; i < n + 1; i++)
        for (j = 1; j < m + 1; j++)
            scanf("%d", &map[i][j]);
    for (i = 1; i < n + 1, cnt == 0; i++)
        for (j = 1; j < m + 1, cnt == 0; j++)
            if (map[i][j] == 2)
            {
                cnt = dfs(map, i, j, 6);
                break;
            }

    if (cnt >= 9999)
        printf("%d", -1);
    else
        printf("%d", cnt);

    return 0;
}
int dfs(int **m, int y, int x, int life)
{
    int ans = 99999999;
    if (life == 0 || m[y][x] == 0 || m[y][x] == 5)
        return 9999;
    if (m[y][x] == 1 || m[y][x] == 2)
    {
        m[y][x] = 5; /* 已走过 */
        for (int k = 0; k < 4; k++)
            ans = MIN(dfs(m, y + dir[k][0], x + dir[k][1], life - 1) + 1, ans);
        return ans;
    }
    if (m[y][x] == 3)
        return 0;
    if (m[y][x] == 4)
        life = 6;
}