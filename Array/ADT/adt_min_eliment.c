#include <stdio.h>
struct Array
{
   int arr[ 10 ];
   int size;
   int length
};

int min_array_element( struct Array a ) {
   int min = a.arr[ 0 ];

   for ( int i = 0; i < a.length; i++ )
   {
      if ( a.arr[ i ] < min )
      {
         min = a.arr[ i ];
      }
   }

   return min;
}

int main( ) {
   printf( "ADT Linear Search!\n" );
   struct Array a = { { 1, 2, 3, 40, 5, 6, 7, 8, 9, 10 }, 10, 10 };
   //printf( "Enter your key value\n" );
   //scanf( "%d", &key );
   printf( "found min element is %d\n", min_array_element( a ) );
}
