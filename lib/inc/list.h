#ifndef _LIST_h
#define _LIST_h

#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct _node{
    ElementType value;
    struct _node *next;
} Node;
typedef struct _list{
    Node* head;   
    Node* tail;
} List;
void Add(List *pList, int number);
void Print(const List *pList);
Node *find(List *pList, int number);
void Delete(List *pList, int number);
void InsertAfter(List *pList, int nFind, int nInsert);
Node *Reverse(List *pList);
void Bsort(List *pList);
void Swap(List *pList, int n);
List *Merge(List *pL1, List *pL2, List *pL3);
List *Intersect(List *pL1, List *pL2, List *pL3);
void Clear(List *pList);

#endif