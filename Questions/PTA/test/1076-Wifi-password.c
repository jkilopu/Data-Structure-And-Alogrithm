#include <stdio.h>

int main(void)
{
    int num = 0;
    scanf("%d", &num);
    num *= 4; // 每个选择题四个选项
    while(num--)
    {
        char option, ans;
        scanf(" %c-%c", &option, &ans);
        if (ans == 'T')
            putchar(option - 'A' + '1'); // 不是putchar(option - 'A' + 1);!
    }
    putchar('\n');

    return 0;
}