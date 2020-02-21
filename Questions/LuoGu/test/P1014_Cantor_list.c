/* 模拟 -- O(n) */
// 更优的做法是找通项公式
#include <stdio.h>
int main(void)
{
    int i, j, k, n;
    enum Turn
    {
        up = -1, // 右上
        no,
        down // 左下
    } turn;

    scanf("%d", &n);
    for (k = 1, i = 0, j = 0, turn = no; k < n; k++) /* 跳出循环时k = n*/
    {
        if (turn == no)
        {
            if (j == 0)
            {
                i++;
                turn = down;
            }
            else if (i == 0)
            {
                j++;
                turn = up;
            }
        }
        else if (turn == up)
        {
            i++;
            j--;
            if (j == 0)
                turn = no;
        }
        else if (turn == down)
        {
            j++;
            i--;
            if (i == 0)
                turn = no;
        }
    }
    printf("%d/%d", j + 1, i + 1);

    return 0;
}