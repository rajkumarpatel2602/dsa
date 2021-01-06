#include <stdio.h>

void foo( int n ) {
   if ( n > 0 )
   {
      printf( "call will be made now!\n" );
      foo( n - 1 );
      printf( "%d ", n );
   }
}

int main( ) {
   int n = 3;

   printf( "This program will print number while ascending phase\n" );
   foo( n );
}
