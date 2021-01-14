#include <math.h>
#include <stdbool.h>
#include <stdio.h>

unsigned int fib( unsigned int term ) {
   if ( term <= 1 )
   {
      return 1;
   }
   else
   {
      return fib( term - 1 ) + fib( term - 2 );
   }
}

int main( ) {
   unsigned int num;

   printf( " FIBONACCI_RECURSION !\nenter a number terms required!\n" );
   scanf( "%d", &num );

   printf( "Fibonacci value with %d is - %d", num, fib( num ) );
}
