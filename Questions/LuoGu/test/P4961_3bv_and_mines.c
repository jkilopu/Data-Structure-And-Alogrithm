#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
const int dir[8][2] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // 用数组记录8个方向便于枚举
bool is_mine(int **m, int y, int x);
bool is_blank(int **m, int y, int x);
bool is_number(int **m, int y, int x);
void dfs(int **m, int y, int x);
bool check_kong(int **m, int y, int x);
int main(void)
{
    int m, n, i, j, k, cnt = 0;
    int **map;

    scanf("%d%d", &n, &m);
    /* create map map */
    map = (int **)malloc(sizeof(int *) * (n + 2));
    for (i = 0; i < n + 2; i++)
    {
        map[i] = (int *)malloc(sizeof(int) * (m + 2));
        memset(map[i], -1, sizeof(int) * (m + 2)); /* 必须这样memset*/
    }
    /* deel with the border */

    /* draw the map */
    for (i = 1; i < n + 1; i++)
        for (j = 1; j < m + 1; j++)
            scanf("%d", &map[i][j]);
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < m + 1; j++)
        {
            if (is_blank(map, i, j))
            {
                for (k = 0; k < 8; k++)
                {
                    if (is_mine(map, i + dir[k][0], j + dir[k][1]))
                    {
                        map[i][j] = 2;
                        break;
                    }
                }
            }
        }
    }
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < m + 1; j++)
        {
            if (is_blank(map, i, j))
            {
                dfs(map, i, j);
                cnt++;
            }
        }
    }
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < m + 1; j++)
        {
            if (is_number(map, i, j))
                if (check_kong(map, i, j) == false)
                    cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}
/* 总结：过程及其坎坷，但也很高兴
 * 1. 初读题概念绕了很久，感觉用不上dfs，而且感觉循环超多
 * 2. 开始有了暴力的思路，但被空搞蒙了
 * 3. 看了题解：空、墙、数字、未检测位都可以对应一个号码，这样区分记数最好
 * 4. 在墙的设置上弄了很久，要记住：四面八方都有墙，所以数组长宽都需+2;墙设为-1与其他东西分开
 *    在设置墙时使用了memset，memset可以直接设置二维数组、二维指针指向的一维数组。如果直接作用于二维指针，将作用于一维指针，而不是每一个“小室”。
 * 5. 还是在很多细节上犯错...要改啊！
 * 6. DFS（深度优先搜索）真是神奇，大概理解它的思想了！
 */
bool is_mine(int **m, int y, int x) // 传二维数组进函数的一种方法（不能用int m[][]，应该是int m[][常数]）
{
    return m[y][x] == 1; // 不管怎么样，a[i][j]不被允许。也是由编译器的寻址方式决定。（悬念...）
}
bool is_blank(int **m, int y, int x)
{
    return m[y][x] == 0;
}
bool is_number(int **m, int y, int x)
{
    return m[y][x] == 2;
}
bool is_kong(int **m, int y, int x)
{
    return m[y][x] == 3;
}
/* 原来二维数组传参有这么多细节 
 * https://www.jianshu.com/p/d7f2afe08f41
 */
void dfs(int **m, int y, int x)
{
    if (m[y][x] == -1) // 是墙直接返回
        return;
    m[y][x] = 3;
    int k;
    for (k = 0; k < 8; k++)
    {
        if (is_blank(m, y + dir[k][0], x + dir[k][1]))
            dfs(m, y + dir[k][0], x + dir[k][1]);
    }
}
bool check_kong(int **m, int y, int x)
{
    int k;
    bool ret = false;
    for (k = 0; k < 8; k++)
    {
        if (is_kong(m, y + dir[k][0], x + dir[k][1]))
        {
            ret = true;
            break;
        }
    }
    return ret;
}