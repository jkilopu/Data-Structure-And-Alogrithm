#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int ToIndex(char ch);

int main(void)
{
    int *info, cnt = 0, less = 0;
    char ch;

    info = (int *)calloc(10 + 26 + 26, sizeof(int));
    while((ch = getchar()) != '\n')
    {
        int index = ToIndex(ch);
        info[index]++;
        cnt++;
    }
    while((ch = getchar()) != '\n')
    {
        int index = ToIndex(ch);
        if (info[index] > 0)
            cnt--;
        else
            less++;
        info[index]--;
    }

    if(!less)
        printf("Yes %d\n", cnt);
    else
        printf("No %d\n", less);
    
    free(info);
    return 0;
}

int ToIndex(char ch)
{
    int ret;
    if(isdigit(ch))
        ret = ch - '0';
    else if (islower(ch))
        ret = ch - 'a' + 10;
    else if (isupper(ch))
        ret = ch - 'A' + 26 + 10;
    return ret;
}