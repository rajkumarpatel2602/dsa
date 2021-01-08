#include <stdio.h>

void fooB( int n );

void fooA( int n ) {
   if ( n > 0 )
   {
      printf( "%d, ", n );
      fooB( n - 1 );
   }
}

void fooB( int n ) {
   if ( n > 0 )
   {
      printf( "%d, ", n );
      fooA( n / 2 );
   }
}

int main( ) {
   printf( " INDIRECT RECURSION EXAMPLE !\n" );
   fooA( 20 );
}
