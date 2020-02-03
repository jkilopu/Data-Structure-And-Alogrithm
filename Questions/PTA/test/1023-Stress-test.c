/* 第一次压力测试 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
char *Method_1(char c1[], int a[]);
char *Method_2(char c2[], int b[]);
int main(void)
{
    int i, a[10], b[10];
    char c1[50] = {'\0'};
    char c2[50] = {'\0'};

    while(true)
    {
        for (i = 0; i < 10; i++)
        {
            a[i] = rand() % 6;
            b[i] = a[i];
        }
        if (strcmp(Method_1(c1, a), Method_2(c2, b)) != 0)
        {
            puts("Error!\n");
            break;
        }
    }

    return 0;
}
char *Method_1(char c1[], int a[])
{
    int i, j;
    bool is_none_zero_first = false;

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
    puts("##Method 1: ");
    for (i = 0; i < j; i++)
        putchar(c1[i]);
    putchar('\n');

    return c1;
}
char *Method_2(char c2[], int b[])
{
    int i, k = 1;

    //	for(i = 0; i < 10; i++)
    //		printf("%d ", a[i]);
    //检测第一个非零数
    for(i = 0; i < 10; i++)
		if(i != 0 && b[i] != 0)
			break;
    c2[0] = i + '0';
    b[i] = b[i] - 1;
    for (i = 0; i < 10; i++)
    {
        while(b[i] != 0){
            c2[k++] = i + '0';
            b[i]--;	
		}
	}
    puts("##Method 2: ");
    for (i = 0; i < k; i++)
        putchar(c2[i]);
    putchar('\n');

    return c2;
}
