#ifndef _dlist_h
#define _dlist_h

#include <stdbool.h>
typedef int ElementType;
struct DNodeRecord;
struct DListRecord;
typedef struct DNodeRecord DNode;
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