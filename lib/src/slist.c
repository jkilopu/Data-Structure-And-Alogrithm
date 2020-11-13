#include "slist.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

SList CreateSList(const size_t elem_size)
{
    SList new_slist = malloc(sizeof(struct _s_list));
    if (new_slist == NULL)
        FatalError("CreateSList: Out of space!!!");
    CreateLocalSList(new_slist, elem_size);
    return new_slist;
}

void CreateLocalSList(struct _s_list *slist, const size_t elem_size)
{
    slist->head = slist->tail = NULL;
    slist->elem_size = elem_size;
}

/*
 * 加入一个结点到链表尾
 */
void AddTailSList(SList slist, const void *data)
{
    Node node = (Node)malloc(sizeof(struct _node));
    if (node == NULL)
        FatalError("AddSList: Out of space!!!");
    node->data = malloc(slist->elem_size);
    if (node->data == NULL)
        FatalError("AddSList: Out of space!!!");

    /* Copy */
    memcpy(node->data, data, slist->elem_size);
    node->next = NULL;

    /* Attach */
    if (slist->head)
    {
        slist->tail->next = node;
        slist->tail = node;
    }
    else
    {
        slist->head = node;
        slist->tail = slist->head;
    }
}

/*
 * 根据node->data找到第一个结点
 */
Node FindNodeSList(const SList slist, const void *data)
{
    for (Node node = slist->head; node; node = node->next)
    {
        if (memcmp(node->data, data, slist->elem_size) == 0)
            return node;
    }
    return NULL;
}

/*
 * 根据node->data，删除找到的第一个结点 
 */
void DeleteNodeSList(SList slist, const void *data)
{
    for (Node p = slist->head, q = NULL; p; q = p, p = p->next)
    {
        if (memcmp(p->data, data, slist->elem_size) == 0)
        {
            if (q)
                q->next = p->next; // 不会出现野指针
            else
                slist->head = p->next;
            free(p);
            break;
        }
    }
}

/*
 * 根据node->data，在找到的第一个结点后插入一个结点，返回true
 * 若没找到，什么也不做，返回false
 */
bool InsertAfterSList(SList slist, const void *found_data, const void *insert_data)
{
    Node found_node;
    if (found_node = FindNodeSList(slist, found_data))
    {
        Node new_node = (Node)malloc(sizeof(struct _node));
        memcpy(new_node->data, insert_data, slist->elem_size);
        new_node->next = found_node->next;
        found_node->next = new_node;
        return true;
    }
    return false;
}

void ReverseSList(SList slist)
{
    Node p, next, prev;
    if (slist->head == NULL || slist->head->next == NULL)
        return;
    prev = (Node)malloc(sizeof(struct _node));
    prev->next = slist->head;
    p = slist->head;
    while (p->next != NULL)
    {
        next = p->next;
        p->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    slist->head = prev->next;
    free(prev);
    prev = NULL;
}

bool SwapSList(SList slist, unsigned int pos)
{
    Node p = slist->head, q, prev;
    if (p == NULL || p->next == NULL) // 不能没有或只有一个节点
        return false;
    
    for (int i = 0; i < pos; i++)
    {
        if (!p->next)
            return false;
        prev = p; // pre必须有
        p = p->next;
    }
    q = p->next;          // q必须有

    if (p == slist->head) // 头节点交换
        slist->head = q;
    else
        prev->next = q;
    p->next = q->next;
    q->next = p;
    return true;
}

/*
 * 按大小顺序合并s1和s2链表，组成s3链表，s1、s2不被修改
 */
void MergeLocalSList(const SList s1, const SList s2, struct _s_list *s3, int (*cmp)(void *a, void *b))
{
    Node p1 = s1->head;
    Node p2 = s2->head;
    while (p1 && p2)
    {
        if (cmp(p1->data, p2->data) <= 0)
        {
            AddTailSList(s3, p1->data);
            /* p3->next = p1;
             p3 = p1; 不能这么做!!!应为会改变L1或L2的结构 */
            p1 = p1->next;
        }
        else
        {
            AddTailSList(s3, p2->data);
            p2 = p2->next;
        }
    }
    /* s1、s2中剩余元素 */
    while (p1)
    {
        AddTailSList(s3, p1->data);
        p1 = p1->next;
    }
    while (p2)
    {
        AddTailSList(s3, p2->data);
        p2 = p2->next;
    }
}

/* 求交集，结果放在s3中 */
void IntersectLocalSList(const SList s1, const SList s2, struct _s_list *s3, int (*cmp)(void *a, void *b))
{
    if (s1->elem_size != s2->elem_size || s2->elem_size != s3->elem_size)
        return;
    Node p1 = s1->head;
    Node p2 = s2->head;
    /* 逐个比较 */
    while (p1)
    {
        while (cmp(p1->data, p2->data) != 0 && p2)
            p2 = p2->next;
        if (!p2)
            AddTailSList(s3, p1->data);
        p1 = p1->next;
    }
}

/* 最低效率的冒泡排序 */
void BsortSList(SList slist, int (*cmp)(void *a, void *b)) //最低效率的冒泡排序
{
    for (Node p = slist->head; p; p = p->next)
    {
        for (Node q = slist->head; q != slist->tail; q = q->next)
        {
            if (cmp(q->data, q->next->data) < 0)
            {
                void *temp = q->data;
                q->data = q->next->data;
                q->next->data = temp;
            }
        }
    }
}

void DisposeLocalSList(struct _s_list *slist)
{
    for (Node p = slist->head, q; p; p = q)
    {
        q = p->next;
        free(p->data);
        free(p);
    }
    slist->head = slist->tail = NULL; 
}

void DisposeSList(SList slist)
{
    DisposeLocalSList(slist);
    free(slist);
}
