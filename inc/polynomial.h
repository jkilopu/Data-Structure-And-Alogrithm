#ifndef _polynomial_h
#define _polynomial_h
#include <stdbool.h>
#include <stdlib.h>

typedef int ElementType;
struct _pnode;
struct _polynomial;
typedef struct _pnode PNode;
typedef struct _polynomial* Polynomial;

Polynomial CreatePolynomial(void);
void PAdd(Polynomial pol, ElementType coefficient, ElementType exponent);
int PLength(Polynomial po);
void PClear(Polynomial po);
void PClearElement(Polynomial po);
Polynomial PMerge(Polynomial po1, Polynomial po2, Polynomial po3);
Polynomial PMultiply(Polynomial po1, Polynomial po2, Polynomial po3);
void PPrint(const Polynomial po);
void PMakeEmpty(Polynomial pol);
bool PIsEmpty(Polynomial pol);
#endif