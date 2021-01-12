#include <stdio.h>

int foo( int n ) {
   if ( n > 100 )
      return n - 10;
   else
      return foo( foo( n + 11 ) );
}

int main( ) {
   int n = 95;

   printf( " NESTED_RECURSION !\n" );
   //foo( foo(95) );
   printf( " %d \n", foo( foo( 95 ) ) );
}
