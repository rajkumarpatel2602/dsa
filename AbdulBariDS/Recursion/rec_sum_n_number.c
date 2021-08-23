#include <stdio.h>

int sum_n( int n ) {
   if ( n == 0 )
      return 0;

   return sum_n( n - 1 ) + n;
}

int main( ) {
   printf( "SUM N NUMBER USING RECURSION!\n Enter n to find sum upto\n" );
   int n;
   scanf( "%d", &n );

   printf( "sum of %d is %d", n, sum_n( n ) );
}
