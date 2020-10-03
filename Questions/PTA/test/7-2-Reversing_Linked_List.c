#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Addr;

typedef struct _node {
    Addr addr;
    int data;
    Addr next;
} Node;

typedef struct _list {
    Node *head;
} List;

Node *addr2node(Addr addr, Node a[], int n);
Addr get_k_addr(Addr h, int k, Node a[], int n);
void reverse_k(List *p_list, int k, Node a[], int n);
Node *reverse(Addr h, Addr tail, Node a[], int n);
Node *get_tail(Addr h, Node a[], int n);
void print(List *p_list, Node a[], int n);

int main(void)
{
    Addr head = 0, n, k;
    Node *arr;
    List list;

    scanf("%d%d%d", &head, &n, &k);
    arr = (Node *) malloc(sizeof(struct _node) * n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &arr[i].addr, &arr[i].data, &arr[i].next);
    list.head = addr2node(head, arr, n);

    // putchar('\n');
    // print(&list, arr, n);
    // putchar('\n');
    reverse_k(&list, k, arr, n);
    print(&list, arr, n);

    free(arr);
    return 0;
}

/* 导致效率低的地方... */
Node *addr2node(Addr addr, Node a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i].addr == addr)
            return a + i;
    return NULL;
}

/* 得到距头k个结点的结点的地址 */
Addr get_k_addr(Addr h, int k, Node a[], int n)
{
    int i;
    for (i = 0; i < k && h != -1; i++)
    {
        Node *p = addr2node(h, a, n);
        h = p->next;
    }
    if (i != k)
        return -2; // 未达到k个结点,不能反转
    return h;
}

void reverse_k(List *p_list, int k, Node a[], int n)
{
    Addr h = p_list->head->addr;
    Addr prev_h = h;
    Addr tail = -1;
    bool set_head = false;
    while ((tail = get_k_addr(h, k, a, n)) != -2)
    {
        Node *new_head = reverse(h, tail, a, n); // 反转
        /* 重新连接链表 */
        if (!set_head)
        {
            p_list->head = new_head;
            set_head = true;
        }
        else
        {
            Node *p = get_tail(prev_h, a, n);
            p->next = new_head->addr;
            prev_h = h;
        }
        h = tail;
    }
    /* 连接未被反转的(多余的)链表 */
    if (tail == -2)
    {
        Node *p = get_tail(prev_h, a, n);
        p->next = h;
    }
}

/* 反转并分离从h到tail的节点 */
Node *reverse(Addr h, Addr tail, Node a[], int n)
{
    Node *new_head;
    Addr b = h;
    Addr end = -1; // 将链表分裂
    Node *p = addr2node(b, a, n); // 指向当前要分离的节点
    Node *q = addr2node(p->next, a, n); // 保存下一个节点的位置
    while (p->next != tail)
    {
        p->next = end;
        end = p->addr;
        p = q;
        b = p->addr;
        q = addr2node(q->next, a, n);
    }
    new_head = p;
    p->next = end;
    return new_head; // 返回被反转链表的新头
}

Node *get_tail(Addr h, Node a[], int n)
{
    Node *p = addr2node(h, a, n);
    while(p->next != -1)
        p = addr2node(p->next, a, n);
    return p;
}

void print(List *p_list, Node a[], int n)
{
    Addr h = p_list->head->addr;
    while(h != -1)
    {
        Node *p = addr2node(h, a, n);
        /* **的格式 */
        if (p->next >= 0)
            printf("%05d %d %05d\n", p->addr, p->data, p->next); 
        else
            printf("%05d %d %d\n", p->addr, p->data, p->next); 
        h = p->next;
    }
}