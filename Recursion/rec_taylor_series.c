#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int x   = 0;
int num = 0;

unsigned int taylor_exp( ) {
   static int p = 1, f = 1, i, r;

   if ( i > num )
   {
      return r;
   }
   else
   {
   }
}

int main( ) {
   unsigned int num;

   printf( " Taylor's series !\nPlease, enter a number of terms required! and X to find e raised to X\n" );
   scanf( "%d", &num );
   scanf( "%d", &x );

   printf( "Fibonacci value with %d is - %d", tailor_exp( num ) );
}
