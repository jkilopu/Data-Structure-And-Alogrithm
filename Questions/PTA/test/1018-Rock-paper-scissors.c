/*亮点：
1.结构中的结构
2.判断最大值时遇到的相同问题*/
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int B;
    int C;
    int J;
    int sum;
} win;
typedef struct {
    win win;
    int draw, lose;
} player;
void Judge_and_Count(char aHand, char bHand, player *a, player *b);
void printMost(player *p);

int main(void)
{
    int N, i;
    char aHand, bHand;
    player *a, *b;

    a = (player *)malloc(sizeof(player));  //要记得malloc
    b = (player *)malloc(sizeof(player));
    //令人窒息的赋值（因为前面不能初始化！）
    a->win.B = 0, a->win.C = 0, a->win.J = 0, a->win.sum = 0;  
    b->win.B = 0, b->win.C = 0, b->win.J = 0, b->win.sum = 0;
    a->draw = 0, a->lose = 0;
    b->draw = 0, b->lose = 0;
    scanf("%d", &N);
    for (i = 0; i < N;i++)
    {
        scanf(" %c %c", &aHand, &bHand);
        Judge_and_Count(aHand, bHand, a, b);
    }
    printf("%d %d %d\n", a->win.sum, a->draw, a->lose);
    printf("%d %d %d\n", b->win.sum, b->draw, b->lose);
    printMost(a);
    putchar(' ');
    printMost(b);

    return 0;
}
void Judge_and_Count(char aHand, char bHand, player *a,player *b)
{
    if(aHand == bHand)
    {
        a->draw++;
        b->draw++;
    }
    else if(aHand == 'B' && bHand == 'C')
    {
        a->win.B++;
        b->lose++;
    }
    else if(aHand == 'C' && bHand == 'B')
    {
        b->win.B++;
        a->lose++;
    }
    else if(aHand == 'J' && bHand == 'B')
    {
        a->win.J++;
        b->lose++;
    }
    else if(aHand == 'B' && bHand == 'J')
    {
        b->win.J++;
        a->lose++;
    }
    else if(aHand == 'C' && bHand == 'J')
    {
        a->win.C++;
        b->lose++;
    }
    else if(aHand == 'J' && bHand == 'C')
    {
        b->win.C++;
        a->lose++;
    }
    a->win.sum = a->win.B + a->win.C + a->win.J;
    b->win.sum = b->win.B + b->win.C + b->win.J;
}
void printMost(player *p)
{
    char ch;
    //数目相同按字母序输出功能，可以利用if-else的先后实现！！！
    if((p->win.B >= p->win.C && p->win.C >= p->win.J) || (p->win.B >= p->win.J && p->win.J >= p->win.C))
        ch = 'B';
    else if((p->win.C >= p->win.B && p->win.B >= p->win.J) || (p->win.C >= p->win.J && p->win.J >= p->win.B))
        ch = 'C';
    else if((p->win.J >= p->win.B && p->win.B >= p->win.C) || (p->win.J >= p->win.C && p->win.C >= p->win.B))
        ch = 'J';
    printf("%c", ch);
}