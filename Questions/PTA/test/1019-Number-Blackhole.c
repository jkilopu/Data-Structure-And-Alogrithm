//数学类？
#include <stdio.h>
#include <stdbool.h>
#define BlackholeNumber 6174
bool sortDecrease(int N, int a[]);

int main(void)
{
    int N, IncreaseN, DecreaseN;
    int a[4];

    scanf("%d", &N);
    do{                            //用do-while的原因是要先做运算后判断（黑洞数字必须出现在差值位置）
        if(sortDecrease(N, a)){    //判断是否所有位数相同
            printf("%.4d - %.4d = %.4d\n", N, N, N - N);    //%.4d代表数的前面补0，直到4位
            break;
        }
        else{                      //计算递增数和递减数
            IncreaseN = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
            DecreaseN = a[0] + a[1] * 10 + a[2] * 100 + a[3] * 1000;
            N = IncreaseN - DecreaseN;
            printf("%.4d - %.4d = %.4d\n", IncreaseN, DecreaseN, N);
        }
    }while(N != BlackholeNumber);

    return 0;
}
bool sortDecrease(int N, int a[])   
{
    int i, j, temp;
    bool equalNumber = false;
    bool isSorted = true;
    for (i = 0; i < 4; i++)       //提取出每一位数
    {
        a[i] = N % 10;
        N /= 10;
    }
    for (i = 0; i < 4 - 1; i++)   //冒泡排序
    {
        for (j = 0; j < 4 - 1 - i; j++)
        {
            if(a[j] < a[j+1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = false;
            }
        }
        if(isSorted)
            break;
    }
    if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3])
        equalNumber = true;
    return equalNumber;
}
/*总结
1.冒泡排序的变量和条件还是搞得不是很清楚
2.断点突然不可用，新建一个.c就好了（为什么会无效呢？）
3.N的值被输入函数，外部N的值不会改变*/