#include <stdio.h>
#include "fatal.h"
#include "stackar.h"
#include <ctype.h>
#include <stdbool.h>
#define MAXSIZE 50
#define TON(CH) (CH - '0')
int Caculate(int a, int b, char ch);
bool IsRightParenthesis(char ch);
bool IsLeftParenthesis(char ch);
int GetPriority(char ch);
int main(void)
{
    char test[] = "94*5";
    Stack postfix;
    Stack operator;
    int i, j, m, n, a, b;
    char ch;

    postfix = CreateStack(MAXSIZE);
    operator = CreateStack(MAXSIZE);
    for (i = 0; test[i] != '\0'; i++)
    {
        if(isdigit(test[i])){
            j = 1, a = 0;
            while(isdigit(test[i]))
                a = a * 10 + TON(test[i++]);  //WOW!逐个读入并计算多位数最简便的方法!
            Push(a, postfix);
            i--;
            }
        //空栈就入栈
        else if(IsEmpty(operator))
            Push(test[i], operator);
            //左括号直接入栈
            else if(IsLeftParenthesis(test[i]))
                Push(test[i], operator);
                //遇到右括号直接弹出
                else if (IsRightParenthesis(test[i]))   //不需要纠结括号内是什么样，弹出就是了！
                {
                    /*每弹出一个操作符就进行一次运算*/
                    while (Top(operator) != '(')
                    {
                        ch = TopAndPop(operator);
                        a = TopAndPop(postfix);
                        b = TopAndPop(postfix);
                        Push(Caculate(a, b, ch), postfix);
                    }
                    Pop(operator);
            }
            //遇到运算符比较优先级
            else if((m = GetPriority(test[i])) < (n = GetPriority(Top(operator)))){
                while((m = GetPriority(test[i])) < (n = GetPriority(Top(operator))))
                {
                    ch = TopAndPop(operator);
                    a = TopAndPop(postfix);
                    b = TopAndPop(postfix);
                    Push(Caculate(a, b, ch), postfix);
                    Push(test[i], operator);
                }
            }
            else
                Push(test[i], operator);
        if(test[i + 1] == '\0')
        {
            while(!IsEmpty(operator))
            {
                ch = TopAndPop(operator);
                a = TopAndPop(postfix);
                b = TopAndPop(postfix);
                Push(Caculate(a, b, ch), postfix);
            }
        }
    }
    printf("%d\n", Top(postfix));
    DisposeStack(postfix);
    DisposeStack(operator);

    return 0;
}
int Caculate(int a, int b, char ch)
{
    int ret;
    switch (ch)
    {
    case '*':
        ret = a * b;
        break;
    case '+':
        ret = a + b;
        break;
    }
    return ret;
}
bool IsLeftParenthesis(char ch)
{
    return ch == '(';
}
bool IsRightParenthesis(char ch)
{
    return ch == ')';
}
int GetPriority(char ch)
{
    if (ch == '+' || ch == '-') return 0;
    else if (ch == '*' || ch == '/') return 1;
    else if (ch == '(' || ch == ')') return -1;
}