#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int         data;
   struct Node *next;
};

int Add_all_members_recursively( struct Node *node_ptr ) {
   if ( node_ptr )
   {
      return Add_all_members_recursively( node_ptr->next ) + node_ptr->data;
   }
   else
   {
      return 0;
   }
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
   printf( "Linked-List : add members recursively!\n" );
   struct Node *head = NULL;

   int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   create_ll( A, 10, &head );
   printf( "\nTotal members are : %d \n", Add_all_members_recursively( head ) );
}
