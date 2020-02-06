/* 很有启发性的一道题 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LENS 5
#define MAXn 1000
int main(void)
{
    int N, i, j, k, N_search, last;
    int* n;
    char ***group, **search;
    bool *isHandsome;
    bool isnoHandsome = true;

    //读入数据
    scanf("%d", &N);
    n = (int *)malloc(N * sizeof(int));
    group = (char ***)malloc(N * sizeof(char**));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &n[i]);
        group[i] = (char **)malloc(n[i] * sizeof(char*));
        for (j = 0; j < n[i]; j++)
        {
            group[i][j] = (char*)malloc(LENS * sizeof(char));
            scanf("%s", group[i][j]);
        }
    }
    //读入被搜索数据
    scanf("%d", &N_search);
    search = (char **)malloc(N_search * sizeof(char*));
    for (i = 0; i < N_search; i++)
    {
        search[i] = (char *)malloc(LENS * sizeof(char));
        scanf("%s", search[i]);
    }
    //初始化
    isHandsome = (bool *)malloc(N_search * sizeof(bool));
    for (i = 0; i < N_search; i++)
        isHandsome[i] = true;
    //搜索
    for (k = 0; k < N_search; k++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < n[i];j++)
            {
                if((strcmp(search[k], group[i][j]) == 0) && n[i] != 1)
                {
                    isHandsome[k] = false;
                    break;
                }
            }
            if(isHandsome[k] == false)
                break;
        }
    }
    //输出格式处理
    for (i = 0; i < N_search; i++)
    {
        if(isHandsome[i])
            last = i;
        for (j = i + 1; j < N_search; j++)
        {
            if(strcmp(search[i],search[j]) == 0)
                isHandsome[j] = false;
        }
    }
    //输出
    for (i = 0; i < N_search; i++)
    {
        if(isHandsome[i])
        {
            if(i != last)
                printf("%s ", search[i]);
            else
                printf("%s", search[i]);
            isnoHandsome = false;
        }
    }
    if(isnoHandsome)
        printf("No one is handsome");

    return 0;
}
/*我的做法：
1.保存所有数据
2.将序号储存为字符串
3.在数据中搜索
4.时间复杂度：最大n^3，最小n^2
大佬的做法：
1.保存所有数据
2.将序号储存为整数，输出时利用printf的特性
3.在输入时确定属性：不帅的人一定出现在数据中！！！
4.时间复杂度：O(n),不包括输入*/

