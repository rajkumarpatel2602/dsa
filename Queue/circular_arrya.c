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
    pQ->front = pQ->rear = 0;
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
    if ( ( myQueue.rear + 1 ) % myQueue.size == myQueue.front )
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

    pQ->rear              = ( pQ->rear + 1 ) % pQ->size;
    pQ->Q[ ( pQ->rear ) ] = entry;
}

int Dequeue( Queue *pQ ) {
    int pop;

    if ( IsEmpty( *pQ ) )
        return;

    ( pQ->front ) = ( pQ->front + 1 ) % pQ->size;

    pop = pQ->Q[ pQ->front ];

    pQ->Q[ pQ->front ] = -1;

    return pop;
}

void Display( Queue myQueue ) {
    int i;

    for ( i = ( myQueue.front + 1 ) % myQueue.size; ( i ) != ( ( myQueue.rear + 1 ) % myQueue.size ); i = ( i + 1 ) % myQueue.size )
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
    Enqueue( &myQueue, 6 );
    Enqueue( &myQueue, 7 );
    Enqueue( &myQueue, 8 );
    Enqueue( &myQueue, 9 );
    Display( myQueue );
    Enqueue( &myQueue, 10 );
    Enqueue( &myQueue, 11 );
    Display( myQueue );
    Dequeue( &myQueue );
    Dequeue( &myQueue );
    Display( myQueue );
}
