/* 字符串比较可以用高效的KMP算法（不过目前我不会） */
#include <stdio.h>
#include <string.h>

char *reverse_str(char target[], char dest[]);

int main(void)
{
    char cloth[1001], fragment[1001], reverse_fragment[1001];
    int len_fragment, len_cloth;

    while (scanf("%s", cloth) && strcmp(cloth, "#"))
    {
        scanf("%s", fragment);
        len_cloth = strlen(cloth);
        len_fragment = strlen(fragment);

        int sum = 0;
        char *k = cloth;
        /* 反转便于比较 */
        reverse_str(fragment, reverse_fragment);
        /* 不进行重复计数 */

        /* 开始比较 */
        while (k - cloth <= len_cloth)
        {
            // 正向
            if (strncmp(k, fragment, len_fragment) == 0)
            {
                sum++;
                k += len_fragment;
            }
            else if (strncmp(k, reverse_fragment, len_fragment) == 0) // 正向不行再反向
            {
                sum++;
                k += len_fragment;
            }
            else
                k += 1;
        }
        printf("%d\n", sum);
    }

    return 0;
}
/* 反转字符串 */
char *reverse_str(char target[], char dest[])
{
    int len_target = strlen(target);
    int i, j;

    for (i = 0, j = len_target - 1; j >= 0; i++, j--)
        dest[i] = target[j];
    dest[i] = '\0';

    return dest;
}