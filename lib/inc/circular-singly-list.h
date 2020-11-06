#ifndef _clist_h
#define _clist_h

#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct _cnode
{
    ElementType value;
    struct _cnode* next;
}CNode;
struct _clist
{
    CNode *head;
    CNode *tail;
};
typedef struct _clist* CList;

CList CreateCList(void);
CList CAdd(CList clist, ElementType number);
CList CDelete_n(CList clist, int order);
void CPrint(CList clist);
CList CClearElement(CList clist);
void CClear(CList clist);
void CMakeEmpty(CList clist);
bool CIsEmpty(CList clist);

#endif