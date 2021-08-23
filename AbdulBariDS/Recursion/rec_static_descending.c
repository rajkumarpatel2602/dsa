#include <stdio.h>

int foo( int n ) {
   static int x = 5;

   if ( n > 0 )
   {
      return foo( n - 1 ) + x;
      x++;
   }
   else
   {
      return 0;
   }
}

int main( ) {
   int n = 3, r = 0;

   printf( "DESCENDING PHASE WITH STATIC VARIABLE\n" );
   r = foo( n );
   printf( "final returned value is : %d", r );
}
