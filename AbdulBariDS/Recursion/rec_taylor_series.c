#include <math.h>
#include <stdbool.h>
#include <stdio.h>

//int x = 0;
//int num = 0;

double taylor_exp( int x, int num ) {
   static double p = 1, f = 1;
   double        res;

   if ( num == 0 )
   {
      return 1;
   }

   res = taylor_exp( x, num - 1 );
   f   = f * num;
   p   = p * x;

   return res + p / f;
}

int main( ) {
   int    num    = 3;
   double result = 0;
   int    x      = 0;

   printf( " Taylor's series !\nPlease, enter a number of terms required num and x to find e raised to x\n" );
   scanf( "%d", &num );
   scanf( "%d", &x );
   result = taylor_exp( x, num );
   printf( "result of requested expansion is - %f", result );
}
