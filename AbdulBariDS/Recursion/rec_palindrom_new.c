#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isPalindrom( unsigned int num, int len ) {
   if ( len <= 1 )
   {
      return true;
   }

   int          a, b;
   unsigned int modtemp;
   a       = num / ( int )( pow( 10, ( len - 1 ) ) );
   modtemp = ( unsigned int )( pow( 10, ( len - 1 ) ) + 1 );
   b       = modtemp % 10;
   num     = modtemp / 10;

   if ( a != b )
   {
      return false;
   }
   else
   {
      len -= 2;

      return isPalindrom( num, len );
   }
}

int main( ) {
   unsigned int num;

   printf( " PALINDROM_RECURSION...\nenter a number to check if palindrom or not!\n" );
   scanf( "%d", &num );

   printf( "Provided number is palindrom? - %d", isPalindrom( num, 5 ) );
}
