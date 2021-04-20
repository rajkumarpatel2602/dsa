#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int front;
    int rear;
    int *Q
} Queue;

void Create( Queue *pQ, int size )
{
    pQ->size  = size;
    pQ->front = pQ->rear = -1;
    pQ->Q     = ( int * )calloc( size, sizeof( int ) );
}

bool IsEmpty( Queue myQueue ) {
    if ( myQueue.front == myQueue.rear )
    {
        printf( "Queue is Empty!\n" );

        return true;
    }
    else
    {
        return false;
    }
}

bool IsFull( Queue myQueue ) {
    if ( myQueue.rear == myQueue.size - 1 )
    {
        printf( "Queue is Full!\n" );

        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue( Queue *pQ, int entry ) {
    if ( IsFull( *pQ ) )
        return;

    pQ->rear++;
    pQ->Q[ pQ->rear ] = entry;
}

int Dequeue( Queue *pQ ) {
    int pop;

    if ( IsEmpty( *pQ ) )
        return;

    pQ->front++;

    return pop = pQ->Q[ pQ->front ];
}

void Display( Queue myQueue ) {
    for ( int i = myQueue.front + 1; i <= myQueue.rear; i++ )
    {
        printf( " %d ", myQueue.Q[ i ] );
    }

    printf( "\n" );
}

int main( )
{
    Queue myQueue;

    Create( &myQueue, 10 );

    Enqueue( &myQueue, 1 );
    Enqueue( &myQueue, 2 );
    Enqueue( &myQueue, 3 );
    Enqueue( &myQueue, 4 );
    Enqueue( &myQueue, 5 );
    Dequeue( &myQueue );
    Dequeue( &myQueue );
    Display( myQueue );
}
