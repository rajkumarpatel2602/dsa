#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int         index;
   int         data;
   struct Node *next;
};

struct Node *ll_search_element_recursively( struct Node *node_ptr, int num )
{
   if ( node_ptr == NULL )
      return NULL;

   if ( node_ptr->data == num )
      return node_ptr;
   else
      return ll_search_element_recursively( node_ptr->next, num );
}

void create_ll( int A[], int len, struct Node **node_ptr ) {
   if ( len > 0 )
   {
      struct Node *new_node = ( struct Node * )malloc( sizeof( struct Node ) );

      new_node->index = 0;
      new_node->data  = A[ 0 ];
      new_node->next  = NULL;
      *node_ptr       = new_node;

      for ( int i = 1; i < len; i++ )
      {
         struct Node *incoming_node = ( struct Node * )malloc( sizeof( struct Node ) );
         incoming_node->index = i;
         incoming_node->data  = A[ i ];
         incoming_node->next  = NULL;
         new_node->next       = incoming_node;
         new_node             = incoming_node;
      }
   }
}

void main( ) {
   int num;

   printf( "Linked-List : search element in the linkedList!\n" );
   struct Node *head = NULL;

   int A[] = { 1, 2, 3, 4, 5, 11, 7, 8, 9, 10 };
   create_ll( A, 10, &head );
   printf( "Enter the element : \n" );
   scanf( "%d", &num );

   if ( ll_search_element_recursively( head, num ) )
      printf( "Found at index : %d \n", ( ll_search_element_recursively( head, num ) )->index );
   else
      printf( "element not found!\n" );
}
