#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int         data;
   struct Node *next;
};

int insert_in_sorted_list( struct Node **head, int data ) {
   int         ret       = -1;
   struct Node *forward  = *head;
   struct Node *tail     = NULL;
   struct Node *new_node = ( struct Node * )malloc( sizeof( struct Node ) );

   new_node->data = data;
   new_node->next = NULL;

   while ( forward && ( forward->data < data ) )
   {
      tail    = forward;
      forward = forward->next;
   }

   if ( forward == *head )
   {
      new_node->next = *head;
      *head          = new_node;
   }
   else
   {
      new_node->next = tail->next;
      tail->next     = new_node;
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

   printf( "Linked-List : create and display!\n" );
   struct Node *head = NULL;

   printf( "Enter data and position to enter new node!\n" );
   scanf( "%d", &data );

   int A[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
   create_ll( A, 10, &head );
   printf( "Insertion succeed : %d\n", insert_in_sorted_list( &head, data ) );

   display_ll( head );
}
