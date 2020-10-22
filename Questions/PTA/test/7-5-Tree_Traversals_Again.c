#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int val;
    struct _node *left;
    struct _node *right;
} Node;

typedef Node* Tree;

void print_array(int *a, int size);
Tree create_tree(int *preorder, int *inorder, int *root, int lo, int hi);
int get_pos(int *a, int val, int size);
void post_traverse(Tree t);
void delete_tree(Tree t);

Tree global_head;

int main(void)
{
    int N;
    char buf[5]; // 暂存"Push"或"Pop"
    int *inorder, *preorder;
    int *tmp; // 以栈的形式存取先序序列，以产生后序序列

    scanf("%d", &N);
    inorder = (int *)malloc(sizeof(int) * N);
    preorder = (int *)malloc(sizeof(int) * N);
    tmp = (int *)malloc(sizeof(int) * N);
    for (int i = 0, j = 0, k = 0, m = 0; i < N * 2; i++)
    {
        // j是先序序列的数组顶端指针，k是后序序列的数组顶端指针，m是先序序列的栈顶指针
        scanf("%s", buf);
        if (buf[1] == 'u')                 // Push
        {
            scanf("%d", &preorder[j]);
            tmp[m++] = preorder[j++];
        }
        else                               // Pop
            inorder[k++] =  tmp[--m];
    }

    // print_array(inorder, N);
    // print_array(preorder, N);
    
    int root = 0;
    Tree tree = create_tree(preorder, inorder, &root, 0, N);
    global_head = tree; // 避免格式错误：最后一个输出的元素（树根结点）后面不能跟括号
    post_traverse(tree);

    free(inorder);
    free(preorder);
    free(tmp);
    delete_tree(tree);

    return 0;
}

void print_array(int *a, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    putchar('\n');
}

/* 连蒙带猜看别人的博客弄出来的。。。
 * 做不出来的原因可能是细节还搞不清楚。。。比如结束情况：空结点、叶子结点
 * 把任意一棵树看成三部分比较好。。。
 * 还是要一步一步弄清楚。。。
 * */
Tree create_tree(int *preorder, int *inorder, int *root, int lo, int hi)
{
    if (lo == hi) // 空结点
        return NULL;
    Tree t = (Tree) malloc(sizeof(struct _node));
    t->val = preorder[*root];
    int pos = get_pos(inorder, preorder[*root], hi);
    (*root)++;
    if (lo == hi - 1) // 叶子结点
    {
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    t->left = create_tree(preorder, inorder, root, lo, pos);
    t->right = create_tree(preorder, inorder, root, pos + 1, hi);
    return t;
}

int get_pos(int *a, int val, int size)
{
    for (int i = 0; i < size; i++)
        if (a[i] == val)
            return i;
    return -1;
}

void post_traverse(Tree t)
{
    if (t == NULL)
        return;
    post_traverse(t->left);
    post_traverse(t->right);
    printf("%d", t->val);
    if (t != global_head)
        putchar(' ');
}

void delete_tree(Tree t)
{
    if (t == NULL)
        return;
    delete_tree(t->left);
    delete_tree(t->right);
    free(t);
    t = NULL;
}