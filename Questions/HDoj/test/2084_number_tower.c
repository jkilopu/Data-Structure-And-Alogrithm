/* 看看别人的简洁代码吧，在下面... 
 * 我的就像dfs...， 还要识别分支（甚至不知道怎么识别）
 * 1. 由小问题看大问题、反着分析或许会有好处
 * 2. 动态规划不一定要多开辟空间记录！！！在原表上记录也许方便很多！！！
 * 3. 运用了一些调试的方法（还是有收获的）
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int value;
    int status; /* 初始0，-1被向下探索过， -2被向右下探索过 */
} Node;
int down(Node **a, int *y, int *x, int border); // 能向下就向下，返回value；否则返回状态值-1
int right_down(Node **a, int *y, int *x, int border);
int up(Node **a, int *y, int *x, int border);
int left_up(Node **a, int *y, int *x, int border);
int main(void)
{
    int i, n, head, y, x, *sum; // sum用于记录n层中每一层的和（幻想中的动态规划）
    Node **a; // 储存节点及其信息（有大约一半是空的）

    /* input */
    scanf("%d%d", &n);
    a = (Node **)malloc(n * sizeof(Node *));
    sum = (int *)calloc(n, sizeof(int));
    for (y = 0; y < n; y++)
    {
        a[y] = (Node *)malloc(n * sizeof(Node));
        for (x = 0; x <= y; x++)
            scanf("%d", &a[y][x].value);
    }
    y = x = 0;
    i = 0;
    sum[0] = head = a[0][0].value;
    /* 开始... */
    while (1)
    {
        if ((head = down(a, &y, &x, n)) != -1 || (head = right_down(a, &y, &x, n)) != -2)
        {
            i++;
            /* 更新最大值（无法改变求和的分支！！！） */
            if (sum[i] == 0 || sum[i - 1] + head > sum[i])
                sum[i] = sum[i - 1] + head;
            /* 调试：显示此时总数 */
            // for (int j = 0; j < n; j++)
            //     printf("%d ", sum[j]);
            // putchar('\n');
            // putchar('\n');
        }
        else if (left_up(a, &y, &x, n) != -2 || up(a, &y, &x, n) != -1)
        {
            i--;
            /* 调试：测试每个节点状态或值 */
            // for (int j = 0; j < n; j++)
            // {
            //     for (int k = 0; k <= j; k++)
            //         printf("%d ", a[j][k].status);
            //     putchar('\n');
            // }
            // putchar('\n');
        }
        else
            break;
    }
    printf("%d\n", sum[n - 1]);

    return 0;
}
int down(Node **a, int *y, int *x, int border)
{
    if (*y >= border - 1 || a[*y + 1][*x].status == -1)
        return -1;
    if (a[*y + 1][*x].status == -2)
        return a[*y + 1][*x].status = -1;
    return a[++(*y)][*x].value;
}
int right_down(Node **a, int *y, int *x, int border)
{
    if (*y >= border - 1 || *x >= border - 1 || a[*y + 1][*x + 1].status == -2)
        return -2;
    return a[++(*y)][++(*x)].value;
}
int up(Node **a, int *y, int *x, int border)
{
    if (*y > 0 && *y > *x)
    {
        a[*y][*x].status = -1;
        return a[--(*y)][*x].value;
    }
    return -1;
}
int left_up(Node **a, int *y, int *x, int border)
{
    if (*y > 0 && *x > 0)
    {
        a[*y][*x].status = -2;
        return a[--(*y)][--(*x)].value;
    }
    return -2;
}
/* 不需要另找空间储存，直接在原表上修改 */
// #include <stdio.h>
// #define max(x, y) (x > y ? x : y)
// int main()
// {
//     int t;
//     scanf("%d", &t);
//     while (t--)
//     {
//         int a[101][101] = {0}, x, y, n;
//         scanf("%d", &n);
//         for (x = 1; x <= n; x++)
//             for (y = 1; y <= x; y++)
//                 scanf("%d", &a[x][y]);
//         for (x = n; x >= 2; x--) // 倒序计算（不从a[1][1]开始）
//             for (y = 1; y <= n - 1; y++)
//                 a[x - 1][y] += max(a[x][y], a[x][y + 1]);
//         printf("%d\n", a[1][1]);
//     }
// }