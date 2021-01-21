#include <stdio.h>

int arr[ 10 ] = { 12, 32, 38, 41, 58, 60, 70, 89, 91, 100 };

int binary_search_recursion( int l, int h, int key ) {
   if ( l < h )
   {
      int mid = ( l + h ) / 2;

      if ( arr[ mid ] == key )
         return mid;
      else if ( arr[ mid ] > key )
      {
         return binary_search_recursion( l, mid - 1, key );
      }
      else
      {
         return binary_search_recursion( mid + 1, h, key );
      }
   }

   return -1;
}

int main( ) {
   int key;

   printf( "ADT Binary serach using recursion!\n" );
   printf( "Enter your key value\n" );
   scanf( "%d", &key );
   printf( "index found on array index %d\n", binary_search_recursion( 0, 10, key ) );
}
