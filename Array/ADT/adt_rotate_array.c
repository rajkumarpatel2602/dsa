#include <stdbool.h>
#include <stdio.h>

int length = 10;

void rotate_right( int *arr, int rotation, int length ) {
   int block_size = length % rotation;
   int iteration  = length / block_size;

   printf( "block size : %d\n", block_size );
   printf( "iterations required are : %d\n", iteration );

   for ( int j = 0; j < 2; j++ )
   {
      int src = j;

      int dest = ( src + rotation ) % length;
      int temp;

      printf( "src : %d\n", src );
      printf( "dest : %d\n", dest );

      for ( int i = 0; i < iteration; i++ )
      {
         printf( "src : %d\n", src );
         printf( "dest : %d\n", dest );
         temp        = arr[ dest ];
         arr[ dest ] = arr[ src ];
         src         = dest;
         dest        = ( dest + rotation ) % length;
         arr[ src ]  = temp;
         printf( "%d -", arr[ dest ] );
      }
   }
}

void print_array( int arr[], int length ) {
   for ( int i = 0; i < length; i++ )
   {
      printf( "%d -", arr[ i ] );
   }

   printf( "\n" );
}

int main( ) {
   printf( "ADT ROTATE RIGHT ARRAY\n" );
   int arr[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   printf( "Number of rotations\n" );
   int rotation;
   //scanf( "%d", &rotation );

   rotate_right( &arr, 4, length );

   print_array( arr, length );
}
