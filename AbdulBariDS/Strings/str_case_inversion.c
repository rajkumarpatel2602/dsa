#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invert_string( char *str ) {
   int i;

   for ( i = 0; str[ i ] != 0; i++ )
   {
      if ( str[ i ] >= 97 && str[ i ] <= 122 )
      {
         str[ i ] -= 32;
      }
      else if ( ( str[ i ] >= 65 && str[ i ] <= 90 ) )
      {
         str[ i ] += 32;
      }
      else
      {
         // do nothing!
      }
   }
}

int main( ) {
   char *str = ( char * )malloc( sizeof( char ) * 20 );

   printf( "input string to invert characters : \n" );
   gets( str );
   invert_string( str );
   printf( "inverted string is : %s", str );
}
