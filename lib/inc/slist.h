/*
 * 泛型单链表
 * 1. 基于void *的泛型（不是基于宏的）
 * 2. 支持对已分配空间（比如栈、.data、.bss区）的链表创建和销毁（名字中有Local）
 * 
 */

#ifndef _LIST_H
#define _LIST_H

#include <ctype.h>
#include <stdbool.h>

typedef struct _node{
    void *data;
    struct _node *next;
} * Node;

typedef struct _s_list{
    Node head;   
    Node tail;
    size_t elem_size;
} * SList;

SList CreateSList(const size_t elem_size);
void CreateLocalSList(struct _s_list *slist, const size_t elem_size);

void AddTailSList(SList slist, const void *data); // void Add(List *pList, int number);
// void Print(const List *pList);
Node FindNodeSList(const SList slist, const void *data); // Node *find(List *pList, int number);
void DeleteNodeSList(SList slist, const void *data); // void Delete(List *pList, int number);
bool InsertAfterSList(SList slist, const void *found_data, const void *insert_data); // void InsertAfter(List *pList, int nFind, int nInsert);
void ReverseSList(SList slist); // Node *Reverse(List *pList);
bool SwapSList(SList slist, unsigned int pos); // void Swap(List *pList, int n);
void MergeLocalSList(const SList s1, const SList s2, struct _s_list *s3, int (*cmp)(void *a, void *b)); // List *Merge(List *pL1, List *pL2, List *pL3); 
void IntersectLocalSList(const SList s1, const SList s2, struct _s_list *s3, int (*cmp)(void *a, void *b)); // List *Intersect(List *pL1, List *pL2, List *pL3);
void BsortSList(SList slist, int (*cmp)(void *a, void *b)); // void Bsort(List *pList);
void DisposeLocalSList(struct _s_list *slist); // void Clear(List *pList);
void DisposeSList(SList slist);

#endif