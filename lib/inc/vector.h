#ifndef _cvector_h
#define _cvector_h

#include "fatal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFULT_CAPACITY 3

typedef int Rank;
typedef int ElementType;
typedef struct _vector
{
    ElementType *_data;
    Rank _capacity, _size;
    size_t _elemSize;
} * Vector;

Vector CreateVector(Rank capacity);
Vector VCopy(Vector v, ElementType *a);
static void VMakeEmpty(Vector v);
Rank VSize(const Vector v);

#endif