#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int          data;
    struct Queue *next;
} Queue;

Queue *front = NULL, *rear = NULL;

void Enqueue( int x ) {
    Queue *q = ( Queue * )malloc( sizeof( Queue ) );

    if ( q == NULL )
    {
        printf( "Queue is Full\n" );
    }
    else
    {
        q->data = x;

        if ( front == NULL )
        {
            front = rear = q;
        }
        else
        {
            rear->next = q;
            rear       = q;
        }
    }
}

int Dequeue( ) {
    if ( front == NULL )
    {
        printf( "Queue is Empty\n" );

        return -1;
    }
    else
    {
        int   x;
        Queue *temp = front;
        front = front->next;
        x     = temp->data;
        free( temp );

        return x;
    }
}

void Display( ) {
    if ( front )
    {
        Queue *temp = front;

        for ( ; temp != rear; temp = temp->next )
        {
            printf( " %d ->", temp->data );
        }

        printf( " %d \n", temp->data );
    }
}

int main( void ) {
    Enqueue( 1 );
    Enqueue( 2 );
    Enqueue( 3 );
    Enqueue( 4 );
    Enqueue( 5 );
    Enqueue( 6 );
    Enqueue( 7 );
    Enqueue( 8 );
    Enqueue( 9 );
    Enqueue( 10 );

    Display( );

    Dequeue( );
    Dequeue( );
    Dequeue( );
    Dequeue( );
    Dequeue( );
    Dequeue( );

    Display( );

    return 0;
}
