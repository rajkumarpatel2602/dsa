#include <stdio.h>

int pow( int x, int y ) {
   if ( y == 0 )
      return 1;

   return pow( x, y - 1 ) * x;
}

int main( ) {
   printf( "POWER FUNCTION USING RECURSION!\n Enter X and Y to find x power y\n" );
   int x, y;
   scanf( "%d %d", &x, &y );

   printf( "power of %d to %d is %d", x, y, pow( x, y ) );
}
