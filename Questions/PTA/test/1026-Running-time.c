#include <stdio.h>
#include <math.h>
#define CLK_TCK 100
int main(void)
{
    int s, h, d;
    double a, b;

    scanf("%lf %lf", &a, &b);
    s = round((b - a) / CLK_TCK);
    h = s / 60;
    s = s % 60;
    d = h / 60;
    h = h % 60;
    printf("%.2d:%.2d:%.2d", d, h, s);

    return 0;
}