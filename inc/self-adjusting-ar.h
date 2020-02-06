#ifndef _self_adjusting_ar_h
#define _self_adjusting_ar_h

#include "fatal.h"
#include <stdbool.h>
#include <stdio.h>
#define MINARRAYSIZE 5
#define EMPTYTOP -1

typedef int ElementType;
struct _saar
{
    ElementType *ar;
    int capacity;
    int top;
};
typedef struct _saar* Saar;
Saar CreateSaar(int MaxArraySize);
Saar SAdd(Saar sa, ElementType value);
Saar SFind(Saar sa, ElementType value);
Saar SDispose(Saar sa);
void SPrint(Saar sa);
void SMakeEmpty(Saar sa);
bool SIsEmpty(Saar sa);
bool SIsFull(Saar sa);


#endif