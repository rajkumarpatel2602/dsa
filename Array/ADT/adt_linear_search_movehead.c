#include <stdio.h>

struct Array
{
   int arr[ 10 ];
   int size;
   int length
};

void swap( int *a, int *b ) {
   int temp;

   temp = *a;
   *a   = *b;
   *b   = temp;
}

int linear_search( struct Array a, int key ) {
   for ( int i = 0; i < a.length; i++ )
   {
      if ( a.arr[ i ] == key )
      {
         swap( &a.arr[ i ], &a.arr[ 0 ] ); // move to head method to imporve time
         return i;
      }
   }

   return -1;
}

int main( ) {
   int key;

   printf( "ADT Linear Search Move head optimisation!\n" );
   struct Array a = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10, 10 };
   printf( "Enter your key value\n" );
   scanf( "%d", &key );
   printf( "index found on location %d\n", linear_search( a, key ) );
}
