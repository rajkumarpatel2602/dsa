#include <stdio.h>

void foo( int n ) {
   if ( n > 0 )
   {
      printf( "%d, ", n );
      foo( n - 1 );
      foo( n - 1 );
   }
}

int main( ) {
   int n = 3;

   printf( " RECURSION_TREE !\n" );
   foo( n );
}
