#include "stackar.h"
#include "fatal.h"

int StIsEmpty( Stack S )
{
    return S->TopOfStack == EmptyTOS;
}
int StIsFull( Stack S )
{
    return S->TopOfStack == S->Capacity - 1;
}
Stack CreateStack( int MaxElements )
{
    Stack S;

    if( MaxElements < MinStackSize )
        Error( "Stack size is too small" );

    S = (Stack)malloc( sizeof( struct StackRecord ) );
    if( S == NULL )
        FatalError( "Out of space!!!" );

    S->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if( S->Array == NULL )
        FatalError( "Out of space!!!" );
    S->Capacity = MaxElements;
    StMakeEmpty( S );

    return S;
}
void StMakeEmpty( Stack S )
{
    S->TopOfStack = EmptyTOS;
}
void DisposeStack( Stack S )
{
    if( S != NULL )
    {
        free( S->Array );
        free( S );
    }
}
void Push( ElementType X, Stack S )
{
    if( StIsFull( S ) )
        Error( "Full stack" );
    else
        S->Array[ ++S->TopOfStack ] = X;
}
ElementType Top( Stack S )
{
    if( !StIsEmpty( S ) )
        return S->Array[ S->TopOfStack ];
    Error( "Empty stack" );
    return 0;  /* Return value used to avoid warning */
}
void Pop( Stack S )
{
    if( StIsEmpty( S ) )
        Error( "Empty stack" );
    else
        S->TopOfStack--;
}
ElementType TopAndPop( Stack S )
{
    if( !StIsEmpty( S ) )
        return S->Array[ S->TopOfStack-- ];
    Error( "Empty stack" );
    return 0;  /* Return value used to avoid warning */
}