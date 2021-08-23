#include <stdio.h>

int length = 10;

int get_mem( int arr[], int mem ) {
   if ( mem < length )
   {
      return arr[ mem ];
   }
   else
   {
      return -1;
   }
}

int main( ) {
   printf( "ADT Get member\n" );
   int arr[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   printf( "array member at location %d is %d\n", 9, get_mem( arr, 9 ) );
}
