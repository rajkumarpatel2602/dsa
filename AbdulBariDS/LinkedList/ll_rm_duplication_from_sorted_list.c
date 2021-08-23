#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int         data;
   struct Node *next;
};

bool remove_duplicate( struct Node *head ) {
   struct Node *p = head, *q = head;

   while ( p )
   {
      q = p;
      p = p->next;

      if ( p && ( p->data == q->data ) )
      {
         q->next = p->next;
         free( p );
         p = q->next;
      }
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

void display_ll( struct Node *node_ptr ) {
   while ( node_ptr )
   {
      printf( " %d ->", node_ptr->data );
      node_ptr = node_ptr->next;
   }
}

void main( ) {
   printf( "Linked-List : Remove duplicate entry!\n" );
   struct Node *head = NULL;

   int A[] = { 10, 10, 30, 40, 50, 50, 70, 80, 999, 999 };
   create_ll( A, 10, &head );

   printf( "\nExisting list is : \n" );
   display_ll( head );

   remove_duplicate( head );

   printf( "\n\nUpdated list is : \n" );
   display_ll( head );
}
