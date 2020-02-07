#ifndef _binary_search_tree_h
#define _binary_search_tree_h

#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"

typedef int ElementType;
typedef struct _binary_treenode
{
    ElementType value;
    struct _binary_treenode *left;
    struct _binary_treenode *right;
} BNode;
typedef BNode *STree;
typedef BNode *Position; 

STree SMakeEmpty(STree t);
STree SInsert(ElementType x, STree t);
STree PTraversal(STree t);
Position SFind(ElementType x, STree t);
Position SFindMax(STree t);
Position SFindMin(STree t);

#endif