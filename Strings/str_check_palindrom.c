#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_palindrom( char *str ) {
   int i = 0;
   int j = strlen( str ) - 1;

   for ( ; i < j; i++, j-- )
   {
      if ( str[ i ] != str[ j ] )
         return false;
   }

   return true;
}

int main( ) {
   char str[ 20 ];

   printf( "intput string to check whether it is palindrom or not! : \n" );
   gets( str );
   printf( "are these strings equal? : %d", is_palindrom( str ) );
}
