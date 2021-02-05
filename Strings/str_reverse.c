<< << << < HEAD
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string( char *str ) {
   int  i = 0;
   int  j = strlen( str ) - 1;
   char temp;

   for ( ; i < j; i++, j-- )
   {
      temp     = str[ i ];
      str[ i ] = str[ j ];
      str[ j ] = temp;
   }
}

int main( ) {
   char *str = ( char * )malloc( sizeof( char ) * 20 );

   printf( "input string to reverse : \n" );
   gets( str );
   reverse_string( str );
   printf( "reversed string is : %s", str );
}

|| || || | 56269e0
== == == =
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

   void reverse_string( char *str ) {
   int  i = 0;
   int  j = strlen( str ) - 1;
   char temp;

   for ( ; i < j; i++, j-- )
   {
      temp     = str[ i ];
      str[ i ] = str[ j ];
      str[ j ] = temp;
   }
}

int main( ) {
   char *str = malloc( sizeof( char ) * 20 );

   printf( "input string to reverse : \n" );
   gets( str );
   reverse_string( str );
   printf( "reversed string is : %s", str );
}

>> >> >> > f84fa8fdec0b8c72e9294c0013ec35a51b17104d
