#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int         data;
   struct Node *next;
};

int ll_count_mem( struct Node *node_ptr ) {
   static cnt = 0;

   while ( node_ptr )
   {
      cnt++;
      printf( " %d ->", node_ptr->data );
      node_ptr = node_ptr->next;
   }

   return cnt;
}

void create_ll( int A[], int len, struct Node **node_ptr ) {
   if ( len > 0 )
   {
      struct Node *new_node = ( struct Node * )malloc( sizeof( struct Node ) );

      new_node->data = A[ 0 ];
      new_node->next = NULL;
      *node_ptr      = new_node;

      for ( int i = 1; i < len; i++ )
      {
         struct Node *incoming_node = ( struct Node * )malloc( sizeof( struct Node ) );
         incoming_node->data = A[ i ];
         incoming_node->next = NULL;
         new_node->next      = incoming_node;
         new_node            = incoming_node;
      }
   }
}

void main( ) {
   printf( "Linked-List : create and display!\n" );
   struct Node *head = NULL;

   int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   create_ll( A, 10, &head );
   printf( "\nTotal members are : %d \n", ll_count_mem( head ) );
}
