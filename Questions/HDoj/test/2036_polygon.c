/* 求多边形面积（已知坐标） —— 叉乘法*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _point
{
    int x, y;
} * Point;

int main(void)
{
    int n;
    float area;
    Point polygon;
    Point vector;

    while (scanf("%d", &n) && n != 0)
    {
        area = 0.0;
        polygon = (Point)malloc(sizeof(struct _point) * n);
        vector = (Point)malloc(sizeof(struct _point) * (n - 1));
        for (int i = 0; i < n; i++)
            scanf("%d%d", &polygon[i].x, &polygon[i].y);
        /* 向量 */
        for (int i = 0; i < n - 1; i++)
        {
            vector[i].x = polygon[i + 1].x - polygon[0].x;
            vector[i].y = polygon[i + 1].y - polygon[0].y;
        }
        /* 叉乘 */
        for (int i = 0; i < n - 2; i++)
            area += (float)(vector[i].x * vector[i + 1].y - vector[i + 1].x * vector[i].y) / 2.0;
        /* 先求和后取绝对值（为了处理凹多边形的特殊情况） */
        area = fabs(area);
        printf("%.1f\n", area);

        free(vector);
        free(polygon);
    }

    return 0;
}