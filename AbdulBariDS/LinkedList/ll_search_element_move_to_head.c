#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int         index;
   int         data;
   struct Node *next;
} *first; // this global var is taken for test purpose

void display_ll( struct Node *node_ptr ) {
   while ( node_ptr )
   {
      printf( " %d ->", node_ptr->data );
      node_ptr = node_ptr->next;
   }
}

int ll_search_element_movetohead( struct Node **head, int num )
{
   int         max       = 0;
   struct Node *tail     = *head;
   struct Node *node_ptr = *head;

   while ( node_ptr )
   {
      if ( node_ptr->data == num )
      {
         tail->next = node_ptr->next;

         if ( *head != node_ptr )
            node_ptr->next = ( *head );

         *head = node_ptr;

         return 0;
      }

      tail     = node_ptr;
      node_ptr = node_ptr->next;
   }

   return -1;
}

/// if head global

/*int ll_search_element_movetohead( struct Node *p, int num )
   {
   struct Node *q;

   while ( p != NULL )
   {
      if ( num == p->data )
      {
         q->next = p->next;
         p->next = first;
         first   = p;

         return p;
      }

      q = p;
      p = p->next;
   }

   return NULL;
   }
 */
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

   while ( 1 )
   {
      printf( "\nEnter the element : \n" );
      scanf( "%d", &num );

      if ( -1 != ll_search_element_movetohead( &head, num ) )
         printf( "\nelement Found!\n" );
      else
         printf( "\nelement not found!\n\n" );

/*      first = head;

      if ( -1 != ll_search_element_movetohead( first, num ) )
         printf( "\nelement Found!\n" );
      else
         printf( "\nelement not found!\n\n" );
 */
      display_ll( head );
   }
}
