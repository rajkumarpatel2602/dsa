#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool compare_str( char *str1, char *str2 ) {
   while ( ( *str1 == *str2 ) && ( *str1 != 0 ) )
   {
      str1++, str2++;
   }

   if ( *str1 != 0 )
   {
      return false;
   }
   else
   {
      return true;
   }
}

int main( ) {
   char str1[ 20 ];
   char str2[ 10 ];

   printf( "intput string 1:" );
   gets( str1 );
   printf( "input string 2:" );
   gets( str2 );
   printf( "are these strings equal? : %d", compare_str( str1, str2 ) );
}
