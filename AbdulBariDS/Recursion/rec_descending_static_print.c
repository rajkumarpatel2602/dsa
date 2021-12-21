#include <stdio.h>

void foo( int n ) {
   static x = 0;
   if ( n > 0 )
   {
      x++;

      // resucrsive call.
      // This x will get referred from data not from activation record. 
      return foo( n - 1 ) + x;
   }
}

int main( ) {
   int n = 3;
   printf("Final result is  : %d\n", foo( n ));

}
