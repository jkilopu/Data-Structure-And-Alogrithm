#ifndef _dlist_h
#define _dlist_h

#include <stdbool.h>
#include "fatal.h"
typedef int ElementType;
typedef struct DNodeRecord
{
    int value;
    struct DNodeRecord *next;
    struct DNodeRecord *front;
}DNode;
struct DListRecord
{
    DNode *head;
    DNode *tail;
};
typedef struct DListRecord *DList;

DList CreateDList(void);
void DMakeEmpty(DList dlist);
void DAdd(DList dlist, ElementType number);
void DDelete(DList dlist, ElementType number);
DNode *DFind(const DList dlist, ElementType number);
void DSwap(DList dlist, ElementType number);
void DPrint(const DList dlist);
bool DIsEmpty(const DList dlist);
void DClear(DList dlist);

#endif