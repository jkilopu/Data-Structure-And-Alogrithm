#include <stdlib.h>
typedef struct splay_node *splay_ptr;
typedef int element_type;
struct splay_node
{
    element_type element;
    splay_ptr left;
    splay_ptr right;
    splay_ptr parent;
};
typedef splay_ptr SERACH_TREE;

void splay(splay_ptr current)
{
    splay_ptr father;
    father = current->parent;
    while (father != NULL)
    {
        if (father->parent == NULL) // the last rotate
            single_rotate(current); // only use zig
        else
            double_rotate(current);
        father = current->parent;
    }
}
void single_rotate(splay_ptr x)
{
    if (x->parent->left == x)
        zig_left(x);
    else
        zig_right(x);
}
void zig_left(splay_ptr x)
{
    splay_ptr p, B;
    p = x->parent;
    B = x->right;
    x->right = p;     // x's new right child is p
    x->parent = NULL; // x will now be a root
    if (B != NULL)
        B->parent = p;
    p->left = B;
    p->parent = x;
}
void zig_zig_left(splay_ptr x) // or implied with two single_rotate
{
    splay_ptr p, g, B, C, ggp;
    p = x->parent;
    g = p->parent;
    ggp = g->parent;
    B = x->right;
    C = p->right;
    x->right = p; // x's new right child is p
    p->parent = x;
    p->right = g; // p's new right child is g
    g->parent = p;
    p->left = B; // p's new left child is subtree B
    if (B != NULL)
        B->parent = p;
    g->left = C; // g's new left child is subtreee C
    if (C != NULL)
        C->parent = g;
    x->parent = ggp; // connect to rest of the tree
    if (ggp != NULL)
        if (ggp->left == g)
            ggp->left = x;
        else
            ggp->right = x;
}