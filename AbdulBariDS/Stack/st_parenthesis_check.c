#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10

typedef struct stack
{
    int  size;
    int  top;
    char *pStack;
} Stack;

void push( Stack *st ) {
    st->top              += 1;
    st->pStack[ st->top ] = '(';
}

char pop( Stack *st ) {
    char ch;

    ch       = st->pStack[ st->top ];
    st->top -= 1;

    return ch;
}

bool isValidExpression( char *exp ) {
    Stack st;

    st.size   = strlen( exp );
    st.top    = -1;
    st.pStack = ( char * )malloc( st.size );
    memset( st.pStack, 0, st.size );

    if ( st.pStack == NULL )
    {
        printf( "ERROR : Couldn't allocate stack...\n" );

        return false;
    }
    else
    {
        for ( int i = 0; exp[ i ] != 0; i++ )
        {
            printf( "character is : %c\n",
                    exp[ i ] );

            if ( exp[ i ] == '(' )
            {
                printf( "Push called\n" );
                push( &st );
            }

            if ( exp[ i ] == ')' )
            {
                if ( st.top == -1 )
                {
                    printf( "ERROR : Stack is empty!\n" );

                    return false;
                }
                else
                {
                    printf( "Pop called\n" );
                    pop( &st );
                }
            }
        }

        if ( st.top != -1 )
        {
            printf( "ERROR : Stack is non-empty after expression parsing!\n" );

            return false;
        }
    }

    return true;
}

int main( void ) {
    char *exp = "(a+i(b((((c))jfsl)))";

    if ( true == isValidExpression( exp ) )
        printf( "Expression is valid!\n" );
    else
        printf( "Expression is invalid!\n" );
}
