#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int strCnt[2][6] = {'P', 'A', 'T', 'e', 's', 't'}; // strCnt[0]->需打印字符,strCnt[1]->对应字符数

    /* 流处理方式 */
    // int ch;
    // int pos = 0;
    // while((ch = getchar()) != '\n')
    // {
    //     for (int i = 0; i < 6; i++)
    //         if (ch == strCnt[0][i])
    //         {
    //             strCnt[1][i]++;
    //             break;
    //         }
        
    //     while (pos < 6 && strCnt[1][pos] > 0)
    //     {
    //         putchar(strCnt[0][pos]);
    //         strCnt[1][pos]--;
    //         pos++;
    //     }
    //     if (pos == 6)
    //         pos = 0;
    // }
    // /* 计算剩余字符数 */
    // int remain = 0;
    // for (int i = 0; i < 6; i++)
    //     remain += strCnt[1][i];

    /* 缓存后处理 */
    char str[10001];
    scanf("%s", str);
    int all = 0;
    for(int i = 0, len = strlen(str); i < len; i++)
        for (int j = 0; j < 6; j++)
            if (str[i] == strCnt[0][j])
            {
                strCnt[1][j]++;
                all++;
                break;
            }
    /* 输出 */
    for (int i = 0; all != 0; i++) // 流处理时i=0应改为i=pos;
    {
        if (i == 6)
            i = 0;
        if (strCnt[1][i] > 0)
        {
            putchar(strCnt[0][i]);
            strCnt[1][i]--;
            all--;
        }
    }
    putchar('\n');

    return 0;
}
