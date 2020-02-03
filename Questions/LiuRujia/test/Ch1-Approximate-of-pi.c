#include <stdio.h>
int main(void)
{
    double pi = 0.0;
    int i = 1, t = 1;

    do  //注意题目需求啊,do-while要好用些
    {
        pi += 1 / (double)i * t;
        t = -t;
        i += 2;
    } while ((1 / (double)i) >= 10e-10);
    pi *= 4;
    printf("%.20lf\n", pi);

    return 0;
}