#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
/* 大佬的记忆宏*/
// #define W_MEM(x,y,z) (w_mem[x][y][z] ? w_mem[x][y][z] : w_mem[x][y][z] = w(x, y, z))
#define MIN(a, b) a < b ? a : b

/* 记忆 */
long memory[30][30][30]; // 开大一点、全局变量自动赋0值

long w(long, long, long);
long w2(long a, long b, long c);
long mypow(long a, int x);
int main(void)
{
    long a, b, c;
    while (scanf("%ld%ld%ld", &a, &b, &c) && (a != -1 || b != -1 || c != -1))
        printf("w(%ld, %ld, %ld) = %ld\n", a, b, c, w2(a, b, c));
    /* 压力测试 */
    // srand(time(NULL));
    // do
    // {
    //     a = rand() % 11, b = rand() % 11, c = rand() % 11;
    //     printf("w(%ld, %ld, %ld) = %ld\n", a, b, c, w(a, b, c));
    //     printf("w2(%ld, %ld, %ld) = %ld\n", a, b, c, w2(a, b, c));
    // } while (w(a, b, c) == w2(a, b, c));

    return 0;
}
long w(long a, long b, long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    else if (memory[a][b][c] != 0) /* 放在这！防负数和大整数！ */
        return memory[a][b][c];
    else if (a < b && b < c)
        return memory[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        return memory[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
/* 投机取巧的w2 */
long w2(long a, long b, long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return mypow(2, 20);
    else if (a > b)
        return w(a, b, c);
    else
        return mypow(2, a); /* 发现的规律 */
}
long mypow(long a, int x)
{
    int res = 1;
    while (x != 0)
    {
        if (x % 2 == 1)
            res = res * a;
        a = a * a;
        x /= 2;
    }
    return res;
}
/* 注：百度“记忆化搜索”
 * 记忆化搜索：算法上依然是搜索的流程，但是搜索到的一些解用动态规划的那种思想和模式作一些保存。
 * 一般说来，动态规划总要遍历所有的状态，而搜索可以排除一些无效状态。
 * 更重要的是搜索还可以剪枝，可能剪去大量不必要的状态，因此在空间开销上往往比动态规划要低很多。
 * 记忆化算法在求解的时候还是按着自顶向下的顺序，但是每求解一个状态，就将它的解保存下来，
 * 以后再次遇到这个状态的时候，就不必重新求解了。
 */