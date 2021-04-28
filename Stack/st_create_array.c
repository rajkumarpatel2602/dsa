#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

int st[ STACK_SIZE ] = { 0 };

int Top = -1;

void Peek( ) {
    if ( Top >= 0 )
    {
        printf( "Peek value : %d\n", st[ Top ] );
    }
    else
    {
        printf( "Stack is empty!\n" );
    }
}

bool isEmpty( ) {
    if ( Top < 0 )
    {
        return true;
    }

    return false;
}

bool isFull( ) {
    if ( Top == ( STACK_SIZE - 1 ) )
    {
        printf( "Stack overflow!\n" );

        return true;
    }

    return false;
}

void Push( int x ) {
    if ( Top == ( SIZE_MAX - 1 ) )
    {
        printf( "Stack is Full\n" );
    }
    else
    {
        Top++;
        st[ Top ] = x;
    }
}

int Pop( ) {
    if ( Top == -1 )
    {
        printf( "Stack is Empty!\n" );

        return -1;
    }
    else
    {
        int x;
        x = st[ Top ];
        Top--;

        return x;
    }
}

void Display( ) {
    if ( Top == -1 )
    {
        printf( "Stack is empty!\n" );

        return;
    }
    else
    {
        int temp = Top;

        for ( int temp = 0; temp <= Top; temp++ )
        {
            printf( " %d ->", st[ temp ] );
        }

        printf( "\n" );
    }
}

int main( void ) {
    Push( 1 );
    Push( 2 );
    Push( 3 );
    Push( 4 );
    Display( );
    Pop( );
    Pop( );
    Pop( );
    Pop( );
    Pop( );
    Display( );
    Push( 5 );
    Push( 6 );
    Push( 7 );
    Push( 8 );
    Push( 9 );
    Push( 10 );
    Peek( );

    Display( );

    Pop( );
    Pop( );
    Peek( );
    Display( );
    Push( 8 );
    Push( 9 );
    Push( 10 );
    Peek( );
    Display( );
    Pop( );
    Pop( );
    Pop( );
    Pop( );
    Peek( );
    Display( );

    return 0;
}
