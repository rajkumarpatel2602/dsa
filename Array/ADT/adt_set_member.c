#include <stdbool.h>
#include <stdio.h>

int length = 10;

bool set_mem( int *A, int mem, int val ) {
   if ( mem < length )
   {
      A[ mem ] = val;

      return true;
   }
   else
   {
      return false;
   }
}

int main( ) {
   printf( "ADT set value\n" );
   int arr[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   printf( "Enter location and value to set\n" );
   int index;
   int value;
   scanf( "%d %d", &index, &value );

   if ( set_mem( &arr, index, value ) )
   {
      printf( "updated value at location %d is %d\n", index, arr[ index ] );
   }
   else
   {
      printf( "INVALID INPUT\n" );
   }
}
