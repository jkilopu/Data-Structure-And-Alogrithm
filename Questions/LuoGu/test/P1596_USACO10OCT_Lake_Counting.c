#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
const int dir[8][2] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool is_water(char **m, int y, int x);
bool is_land(char **m, int y, int x);
void dfs(char **m, int y, int x);
int main(void)
{
    int i, j, n, m, cnt = 0;
    char **map;

    scanf("%d%d", &n, &m);
    map = (char **)malloc((n + 2) * sizeof(char *));
    for (i = 0; i < n + 2; i++)
    {
        map[i] = (char *)malloc((m + 2) * sizeof(char));
        // Deal with the border
        memset(map[i], '.', m + 2);
    }
    /* Init map */
    for (i = 1; i < n + 1; i++)
        for (j = 1; j < m + 1; j++)
            scanf(" %c", &map[i][j]);
    for (i = 1; i < n + 1; i++)
        for (j = 1; j < m + 1; j++)
        {
            if (is_water(map, i, j))
            {
                dfs(map, i, j);
                cnt++;
            }
        }
    printf("%d", cnt);

    return 0;
}
void dfs(char **m, int y, int x)
{
    if (is_land(m, y, x))
        return;
    /* else is W*/
    m[y][x] = '.';
    for (int k = 0; k < 8; k++)
        dfs(m, y + dir[k][0], x + dir[k][1]);
}
bool is_water(char **m, int y, int x)
{
    return m[y][x] == 'W';
}
bool is_land(char **m, int y, int x)
{
    return m[y][x] == '.';
}