#include "binary-search-tree.h"
STree SMakeEmpty(STree t)
{
    if (t != NULL)
    {
        SMakeEmpty(t->left);
        SMakeEmpty(t->right);
        free(t);
    }
    return NULL;
}
STree SInsert(ElementType x, STree t)
{
    if (t == NULL)
    {
        // Create and return a one-node tree. 必须在该函数中，最好不要独立成一个函数
        t = (STree)malloc(sizeof(BNode));
        if (t == NULL)
            FatalError("Out of space!");
        else
        {
            t->value = x;
            t->left = t->right = NULL;
        }
    }
    else if (x < t->value)
        t->left = SInsert(x, t->left);
    else if (x > t->value)
        t->right = SInsert(x, t->right);
    /* Else x is in the tree already, and we will do nothing.*/
    return t; // Don't forget this line!
}
STree SDelete(ElementType x, STree t)
{
    BNode *tmpCell;
    if (t == NULL)
        Error("Element not found");
    else if (x < t->value) //Go left
        t->left = SDelete(x, t->left);
    else if (x > t->value) //Go right
        t->right = SDelete(x, t->right);
    else if (t->left && t->right)
    {
        tmpCell = SFindMin(t->right);
        t->value = tmpCell->value;
        t->right = SDelete(t->value, t->right);
    }
    else //one and zero child
    {
        tmpCell = t;
        //also handle zero chile
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        free(tmpCell);
    }

    return t;
}
STree PTraversal(STree t)
{
    if (t != NULL)
    {
        /* 先序的话printf放这里 */
        // 这里先小后大
        if (t->left)
            PTraversal(t->left);
        if (t->right)
            PTraversal(t->right);
        printf("%d ", t->value);
    }
    return t;
}
Position SFind(ElementType x, STree t)
{
    if (t == NULL)
        return NULL;
    else if (x < t->value)
        return SFind(x, t->left);
    else if (x > t->value)
        return SFind(x, t->right);
    else
        return t;
}
Position SFindMax(STree t)
{
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return SFindMax(t->right);
}
Position SFindMin(STree t)
{
    if (t != NULL)
        while (t->left != NULL)
            t = t->left;
    return t;
}