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

bool if_list_is_sorted( struct Node *p ) {
   if ( p == NULL )
   {
      printf( "List is empty!\n" );
   }
   else
   {
      int max = INT_MIN;

      while ( p )
      {
         if ( max < p->data )
         {
            max = p->data;
            p   = p->next;
         }
         else
         {
            return false;
         }
      }

      return true;
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
   printf( "Linked-List : check if list is sorted!\n" );
   struct Node *head = NULL;

   int A[] = { 10, 20, 30, 40, 50, 60, 70, 80, 999, 100 };
   create_ll( A, 10, &head );

   if ( true == if_list_is_sorted( head ) )
   {
      printf( "List is sorted!\n" );
   }
   else
   {
      printf( "List is not sorted!\n" );
   }

   display_ll( head );
}
