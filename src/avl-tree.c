#include "avl-tree.h"
ATree AMakeEmpty(ATree t)
{
    if (t != NULL)
    {
        AMakeEmpty(t->left);
        AMakeEmpty(t->right);
        free(t);
    }
    return NULL;
}
ATree AInsert(ElementType x, ATree t)
{
    if (t == NULL)
    {
        t = (ATree)malloc(sizeof(ANode));
        if (t == NULL)
            FatalError("Out of space!");
        else
        {
            t->value = x;
            t->height = 0; //这里是0!
            t->left = t->right = NULL;
        }
    }
    else if (x < t->value)
    {
        t->left = AInsert(x, t->left);
        if (AHeight(t->left) - AHeight(t->right) == 2)
            if (x < t->left->value)
                t = SRotate_left(t);
            else
                t = DRotate_left(t);
    }
    else if (x > t->value)
    {
        t->right = AInsert(x, t->right);
        if (AHeight(t->right) - AHeight(t->left) == 2)
            if (x > t->right->value)
                t = SRotate_right(t);
            else
                t = DRotate_right(t);
    }
    // Else x is in the tree already, we'll do nothing.
    t->height = Max(AHeight(t->left), AHeight(t->right)) + 1;
    return t;
}
ATree ATraversal(ATree t)
{
    if (t != NULL)
    {
        /* 先序的话printf放这里 */
        // 这里先小后大
        if (t->left)
            ATraversal(t->left);
        if (t->right)
            ATraversal(t->right);
        printf("%d ", t->value);
    }
    return t;
}
static APosition SRotate_left(APosition k2)
{
    APosition k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = Max(AHeight(k2->left), AHeight(k2->right)) + 1;
    k1->height = Max(AHeight(k1->left), AHeight(k1->right)) + 1;
    return k1;// return的是k1!
}
static APosition DRotate_left(APosition k3)
{
    /* Rotate between k1 and k2 */
    k3->left = SRotate_right(k3->left);
    /* Rotate between k3 and k2*/
    return SRotate_left(k3);
}
static APosition SRotate_right(APosition k2)
{
    APosition k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = Max(AHeight(k2->left), AHeight(k2->right)) + 1;
    k1->height = Max(AHeight(k1->left), AHeight(k1->right)) + 1;
    return k1;
}
static APosition DRotate_right(APosition k3)
{
    /* Rotate between k1 and k2 */
    k3->right = SRotate_left(k3->right);
    /* Rotate between k3 and k2*/
    return SRotate_right(k3);
}
static int AHeight(APosition p)
{
    if (p == NULL)
        return -1;
    else
        return p->height;
}