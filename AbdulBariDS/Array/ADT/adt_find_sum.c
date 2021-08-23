#include <stdio.h>

int find_sum( int arr[], int len ) {
   int sum = 0;

   for ( int i = 0; i < len; i++ )
      sum += arr[ i ];

   return sum;
}

int main( ) {
   printf( "ADT FIND SUM\n" );
   int arr[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   printf( "sum of the array is %d\n", find_sum( arr, 10 ) );
}
