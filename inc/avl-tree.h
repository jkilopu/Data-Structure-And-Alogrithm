#ifndef _avl_tree_h
#define _avl_tree_h

#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>
#define Max(a, b) a > b ? a : b

typedef int ElementType;
typedef struct _avl_node
{
    ElementType value;
    struct _avl_node *left;
    struct _avl_node *right;
    int height;
} ANode;
typedef struct _avl_node *ATree;
typedef struct _avl_node *APosition;

ATree AMakeEmpty(ATree t);
ATree AInsert(ElementType x, ATree t);
ATree ATraversal(ATree t);
static APosition SRotate_left(APosition k2);
static APosition DRotate_left(APosition k3);
static APosition SRotate_right(APosition k2);
static APosition DRotate_right(APosition k3);
static int AHeight(APosition p);

#endif