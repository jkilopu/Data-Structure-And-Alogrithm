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
Saar SAAdd(Saar sa, ElementType value);
Saar SAFind(Saar sa, ElementType value);
Saar SADispose(Saar sa);
void SAPrint(Saar sa);
void SAMakeEmpty(Saar sa);
bool SAIsEmpty(Saar sa);
bool SAIsFull(Saar sa);

#endif