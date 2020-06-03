/*
 * *****
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    int a[100], b[100];
    memset(a, 0, 100 * sizeof(int));
    memset(b, 0, 100 * sizeof(int));

    /* 读入 */
    char ch;
    int aN, bN;
    for (aN = 0; (ch = getchar()) != ' '; aN++)
        a[aN] = ch - '0';
    for (bN = 0; (ch = getchar()) != '\n'; bN++)
        b[bN] = ch - '0';

    /* 加密 */
    int max = (aN > bN) ? aN : bN;
    int *p = (aN > bN) ? a + aN - 1 : b + bN - 1;
    for (int i = 1; i <= max; i++)
    {
        int aBit = 0, bBit = 0;
        if (aN - i >= 0)
            aBit = a[aN - i];
        if (bN - i >= 0)
            bBit = b[bN - i];
        if (i & 1 == 1)
            *p-- = (bBit + aBit) % 13;
        else
        {
            int tmp = bBit - aBit;
            *p-- = tmp < 0 ? tmp + 10 : tmp; 
        }
    }

    /* 输出 */
    int *q = (aN > bN) ? a : b;
    for (int i = 0; i < max; i++)
    {
        if (*q < 10)
            printf("%d", *q++);
        else
        {
            char ch;
            switch (*q++)
            {
            case 10:
                ch = 'J';
                break;
            case 11:
                ch = 'Q';
                break;
            case 12:
                ch = 'K';
                break;
            }
            putchar(ch);
        }
    }
    putchar('\n');

    return 0;
}