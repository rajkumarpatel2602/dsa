#include <stdio.h>

int fact( int n ) {
   if ( n > 0 )
   {
      return n * fact( n - 1 );
   }
   else
   {
      return 1;
   }
}

int main( ) {
   int n, r;

   printf( " COMPUTE FACTORIAL! \n Please enter the number to compute factorial! \n" );
   scanf( "%d", &n );
   r = fact( n );
   printf( "factorial of %d is %d", n, r );
}
