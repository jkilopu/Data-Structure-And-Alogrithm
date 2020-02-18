#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    char a[81];          /* 存放意图输出的字符串 */
    char b[81];          /* 存放因坏键而缺失的字符串 */
    char c[81] = {'\0'}; /* 存放坏键对应的字符*/
    int i, j, len_a, len_c;

    scanf("%s%s", a, b);
    for (i = 0, j = 0, len_a = strlen(a); i < len_a; i++)
    {
        if (strchr(b, a[i]) == NULL)
            if (strchr(c, toupper(a[i])) == NULL) /* 为了符合题目只输出大写的奇妙要求 */
                c[j++] = toupper(a[i]);
    }
    for (i = 0, len_c = strlen(c); i < len_c; i++)
        putchar(toupper(c[i]));
    putchar('\n');

    return 0;
}