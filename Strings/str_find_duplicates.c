#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_duplicate( char *str ) {
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
   char *result   = ( char * )malloc( sizeof( char ) * 20 );
   char str[ 20 ] = { 0 };

   printf( "input string to invert characters : \n" );
   gets( str );
   find_duplicate( str, result );
   if()
}

//WIP