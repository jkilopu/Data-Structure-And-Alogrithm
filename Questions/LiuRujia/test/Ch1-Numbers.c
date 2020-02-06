#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
bool isNumber(double x);
bool isFiniteNumber(double x);
int main(void)
{
    printf("%d %d\n", sqrt(-10), 8.0 / 5.0);
    printf("%d %d\n", isNumber(0.0 / 0.0), sizeof(bool));
    printf("%f %d\n", 1.0 / 0.0, isFiniteNumber(1.0 / 0.0));
    printf("%f\n", sin(2.0));
    printf("%d %d\n", 1 || 1 && 0, (1 || 1) && 0);    //&&和||优先级及其理解
    printf("%%d\n");       //百分号要用百分号去释义
    return 0;
}
bool isNumber(double x)   
{
    return (x == x);       //判断NaN居然能这样弄
}
bool isFiniteNumber(double x)
{
    return (x <= DBL_MAX && x >= -DBL_MAX);   //判断浮点数是否有限
}