#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int         data;
   struct Node *next;
};

int insert_at_last( struct Node **head, struct Node **last, int data ) {
   int         ret       = -1;
   struct Node *p        = *head;
   struct Node *new_node = ( struct Node * )malloc( sizeof( struct Node ) );

   new_node->data = data;
   new_node->next = NULL;

   if ( *head == NULL )
   {
      *last = new_node;
      *head = new_node;
      ret   = 0;
   }
   else
   {
      ( *last )->next = new_node;
      *last           = new_node;
   }

   return ret;
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

void display_ll( struct Node *node_ptr ) {
   while ( node_ptr )
   {
      printf( " %d ->", node_ptr->data );
      node_ptr = node_ptr->next;
   }
}

void main( ) {
   int pos = 0, data = 0;
   int operation = 0;

   printf( "Linked-List : create and display!\n" );
   struct Node *head = NULL, *last = NULL;

   //int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   //create_ll( A, 10, &head );

   while ( 1 )
   {
      printf( "Enter data for new entry!\n" );
      scanf( "%d", &data );
      printf( "Insertion done or not? : %d\n", insert_at_last( &head, &last, data ) );
      display_ll( head );

      printf( "\n\nENTER -1 TO EXIT\n" );
      scanf( "%d", &operation );

      if ( -1 == operation )
         exit( 0 );
   }
}
