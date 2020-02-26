#ifndef _stackar_h
#define _stackar_h

#include"fatal.h"
#include <stdio.h>
#include <stdlib.h>
typedef char ElementType;
struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};
typedef struct StackRecord *Stack;

#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

int StIsEmpty( Stack S );
int StIsFull( Stack S );
Stack CreateStack( int MaxElements );
void DisposeStack( Stack S );
void StMakeEmpty( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
void Pop( Stack S );
ElementType TopAndPop( Stack S );

#endif  /* _stackar_h */