#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int i, j, a[10];
    char c1[50];
    bool is_none_zero_first = false;

    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for (i = 1, j = 0; i < 10; i++)
    {
        if (is_none_zero_first)
        {
            if (a[0] > 0)
                while (a[0]--)
                {
                    c1[j] = 0 + '0';
                    j++;
                }
        }
        else
        {
            if(a[i])
            {
                c1[j] = i + '0';
                j++;
                a[i]--;
                i--;
                is_none_zero_first = true;
                continue;
            }
        }
        while(a[i]--)
        {
            c1[j] = i + '0';
            j++;
        }
    }
    for (i = 0; i < j; i++)
        putchar(c1[i]);

    return 0;
}
/*总结:
1.if-else的关系很重要啊!弄清先判断什么，再判断什么
2.压力测试虽然难以涉及特殊情况，但仍起到了一定的作用
3.我调试时没有从头开始思考问题，这样应该会节省许多时间
4.别人的方法仍然更简洁
*/