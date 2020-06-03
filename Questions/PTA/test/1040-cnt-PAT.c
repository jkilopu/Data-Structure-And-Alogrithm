/*
 * 常规思路超时了...
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100001];
    char *p, *a, *t;
    int cnt = 0;

    scanf("%s", str);
    for(p = strchr(str, 'P'); p != NULL; p = strchr(p + 1, 'P'))
        for(a = strchr(p, 'A'); a != NULL; a = strchr(a + 1, 'A'))
            for(t = strchr(a, 'T'); t != NULL; t = strchr(t + 1, 'T'))
            {
                cnt++;
                if(cnt >= 1000000007)
                    cnt %= 1000000007;
            }

    printf("%d\n", cnt);
}