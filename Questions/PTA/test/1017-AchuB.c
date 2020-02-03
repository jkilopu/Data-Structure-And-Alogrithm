#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int CHtoNUM(char x) //可以写成类函数宏
{
    return (x - '0');
}
char NUMtoCH(int x)
{
    return (x + '0');
}
int main(void)
{
    //A为被除数、Q为商、R为余数
    char A[1001], Q[1001];
    int B, R = 0, i = 0, j = 0, Position_0, divided;
    
    scanf("%s %d", A, &B);
    Position_0 = strlen(A);
    //处理A只有个位的情况（因为接下来的算法无法处理这种情况）
    if(Position_0 == 1)
    {
        Q[0] = NUMtoCH(CHtoNUM(A[0]) / B);
        R = CHtoNUM(A[0]) % B;
    }
    else for (i = 0, j = 0; i < Position_0 - 1;i++)
    {
        //被除后该位有余数时，不向下进行检测；否则检测该位和下一位（这时两位数一定可以被整除）
        if(CHtoNUM(A[i]) / B)
        {
            divided = CHtoNUM(A[i]);
            Q[j] = NUMtoCH(divided / B);
            A[i] = NUMtoCH(divided % B);
            i--;    //不向下进行检测
        }
        else if(CHtoNUM(A[i]) || CHtoNUM(A[i + 1])) 
        {
            divided = CHtoNUM(A[i]) * 10 + CHtoNUM(A[i + 1]);
            Q[j] = NUMtoCH(divided / B);
            A[i + 1] = NUMtoCH(divided % B);
        }
        else Q[j] = '0';    //两位数为0时，商的该位写'0'
        if(i == Position_0 - 2)
            R = divided % B;
        j++;    //使用j录入是因为i可能停下
    }
    Q[j + 1] = '\0';  //末尾加'\0'以便输出
    printf("%s %d", Q, R);

    return 0;
}
/*
总结：
1.要敢于重写自己的代码
2.当感觉要分很多类（用很多if-else）时，思考一下有什么更简便的判断方法
3.写语句时一定要注意是否正确啊！（类型、变量名）
*/