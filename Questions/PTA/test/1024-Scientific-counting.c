#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    char c[10000];
    int i = 0, e = 0, j, k;
    bool is_e_negative;

    scanf("%s", c);
    //计算e
    while(c[i])
    {
        i++;
        if(c[i] == 'E')
        {
            c[i] = '\0';
            break;
        }
    }
    if(c[i + 1] == '+')
        is_e_negative = false;
    else
        is_e_negative = true;
    for (j = i; c[j + 1] != '\0'; j++)
            ;
    for (k = 1; j != i + 1; k *= 10, j--)
        e += (c[j] - '0') * k;
    if(is_e_negative)
        e = -e;
    //输出
    if(c[0] == '-')
        putchar('-');    
    if(e < 0){
        putchar('0');
        putchar('.');
        e++;
        for (i = 0; i > e; i--)
            putchar('0');
        for (i = 1; c[i] != '\0'; i++)
            if(c[i] != '.')
                putchar(c[i]);
    }
    else{
        for (i = 3, j = 0; c[i] != '\0'; i++, j++)
            ;
        for (i = 1; c[i] != '\0'; i++)
        {
            if(e < j)
                if(i - 3 == e)
                    putchar('.');
                if(c[i] != '.')
                    putchar(c[i]);
        }
        while(e > j)
        {
            putchar('0');
            j++;
        }
    }
    // printf("%d\n", e);

    return 0;
}