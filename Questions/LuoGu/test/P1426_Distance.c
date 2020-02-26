#include <stdio.h>
#define RATIO 0.98
int main(void)
{
    float v = 7.0, s, x, d = 0;

    scanf("%f%f", &s, &x);
    while (d < s - x)
    {
        d += v;
        v *= RATIO;
    }
    if (v * RATIO <= s - d + x)
        putchar('y');
    else
        putchar('n');

    return 0;
}