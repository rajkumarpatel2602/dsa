#include <stdio.h>

int arr[ 10 ] = { 12, 32, 38, 41, 58, 60, 70, 89, 91, 100 };

int binary_search_iteration( int l, int h, int key ) {
   while ( l < h )
   {
      int mid = ( l + h ) / 2;

      if ( arr[ mid ] == key )
         return mid;
      else if ( arr[ mid ] > key )
      {
         h = mid - 1;
      }
      else
      {
         l = mid + 1;
      }
   }

   return -1;
}

int main( ) {
   int key;

   printf( "ADT Binary serach using iteration!\n" );
   printf( "Enter your key value\n" );
   scanf( "%d", &key );
   printf( "index found on array index %d\n", binary_search_iteration( 0, 10, key ) );
}
