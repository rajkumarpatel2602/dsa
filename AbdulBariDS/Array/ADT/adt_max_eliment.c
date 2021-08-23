#include <limits.h>
#include <stdio.h>
struct Array
{
   int arr[ 10 ];
   int size;
   int length
};

int max_array_element( struct Array a ) {
   int max = INT_MIN;

   for ( int i = 0; i < a.length; i++ )
   {
      if ( a.arr[ i ] > max )
      {
         max = a.arr[ i ];
      }
   }

   return max;
}

int main( ) {
   printf( "ADT Linear Search!\n" );
   struct Array a = { { 1, 2, 3, 40, 5, 6, 7, 8, 9, 10 }, 10, 10 };
   printf( "found max element is %d\n", max_array_element( a ) );
}
