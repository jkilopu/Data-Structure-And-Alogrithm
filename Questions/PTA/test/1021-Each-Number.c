#include <stdio.h>
int main(void)
{
    int a[10] = {0};
    int i = 0;
    char s[1001];

    scanf("%s", s);
    while(s[i] != '\0')
    {
        a[s[i] - '0']++;
        i++;
    }
    for (i = 0; i < 10; i++)
        if(a[i] != 0)
            printf("%d:%d\n", i, a[i]);

    return 0;
}