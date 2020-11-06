#include "fatal.h"
#include "stackar.h"
#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 20
bool IsMatch(Stack S, char ch);
int main(void)
{
    char test[] = {'{', '\0'};
    Stack symbols;
    int i;
    bool isRight = true;

    symbols = CreateStack(MAXSIZE);
    for (i = 0; test[i] != '\0'; i++)
    {
        if(test[i] == '(' || test[i] == '[' || test[i] == '{')
            Push(test[i], symbols);
        else if(Top(symbols) == EmptyTOS){
            Error("Symbols deletion!");
            isRight = false;
            break;
        }
        else if(!IsMatch(symbols, test[i])){
            Error("Symbols can't match!");
            isRight = false;
            break;
        }
        else
            Pop(symbols);    //很重要啊啊啊啊
    }
    if(isRight)
        puts("Syntax confirmed.");
    DisposeStack(symbols);
    
    return 0;
}
bool IsMatch(Stack S, char ch)
{
    bool ret = true;
    switch (Top(S))
    {
    case '(':
        if(ch != ')')
            ret = false;
        break;
    case '[':
        if(ch != ']')
            ret = false;
        break;
    case '{':
        if(ch != '}')
            ret = false;
        break;
    }
    return ret;
}