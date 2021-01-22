#include <stdio.h>

int find_sum( int arr[], int len ) {
   static int sum = 0;

   if ( len == 0 )
      return sum;

   return find_sum( arr, len - 1 ) + arr[ len - 1 ];
}

int main( ) {
   printf( "ADT FIND SUM\n" );
   int arr[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   printf( "sum of the array is %d\n", find_sum( arr, 10 ) );
}
