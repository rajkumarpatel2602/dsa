// Datastructure suggestions
DS operations
1. array
- Improving linear search in array
-- transpostion, or move to head method can help here, where we are moving recently searched element forward.
-- find max, min
-- bring negative in one size, positive in other side.
-- merging of an arrays (arrays has to be sorted)
-- add data in sorted list
-- array vs list

2. String
-- Permutation
-- Combination
-- strlen, strcat, strtok, strstr
-- reverse
-- finding duplicates
-- Counting words, vowels, letters, alphabets
-- Anagram, palindrom

3. Linkedlist
-- Display, recursively display,
-- counting nodes
-- Sum of nodes, max, min in list
-- Search
-- Delete
-- insert
-- sorted insert https://www.udemy.com/course/datastructurescncpp/learn/lecture/13133238#overview
-- Remove duplicate in sorted list
-- Reverse a list, recursively as well as iteratively

* Heap
- can be max heap/ min heap. can have duplicate node.
- only condition is that it has to be complete/almost complete binary tree. i.e. no blank spaces in array representation. 
- as it is a complete binary tree. hieght will be always logN.
- insert: add at the end of array, check with parent, if parent is small(in case of max heap) swap, repeat this operation until condition fails.
- 
///////////////////////////////
rev(first){
    r = NULL, q = NULL, p = head;
    while(p){
        //first 3 for movmenet forward
        //last for link change
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    } 
    head = q; // head assumed to be global.
}
//////////////////////////////
rev(q, p) {
    if(p){
        rev(p, p->next);
        p->next = q;
    } else {
        first = q;
    }
} // hear head is assumted to be globle.
//////////////////////////////

-- Merge 2 sorted list, concate 2 list
    https://www.udemy.com/course/datastructurescncpp/learn/lecture/13133298#overview
-- circular list
    display in iteration need do..while, for recursion, it uses static flag.
    in circular there's no need for head movment for insertion operation.
-- doubly linked list and all operation
-- delete in circular and doubly linkedlist
-- Reverse a doubly linkedlist
-- Compare list
-- find circle in node
-- finding middle element in list
-- comparision of lists https://www.udemy.com/course/datastructurescncpp/learn/lecture/13145274#overview

5. bitwise
- set, 
- clear, 
- toggle, 
- byte shift, 
- bit shift, 
- swap byte, 
- swap bit, 
- xor as inequality checker and also for toggling, 
- finding power 

4. binary tree
-- creating binary tree we need 2 data structure. 1st is linkedlist and 2nd is queue. https://www.udemy.com/course/datastructurescncpp/learn/lecture/13168486#overview
    method to create is. first have root as input from user, push address to queue. enter while, p = dequeue(q); and ask for left child, if present, alloc temp, update fields, point p->left = temp, and enqueue temp.
    go to right, and repeat same. such, level by level keep on adding left and right child to tree. [check uploaded pic]
    POST order iterative is a bit trickier. 
-- traversing can happen in preorder, postorder and inorder. recursion is really easy, but for iteration we need to maintain our own stack.
-- level order travarsing need queue.
-- most of the problems like finding height, counting nodes, counting nodes with 2 child, these can be solved by performing post order traversal. left, right, print method.
-- for given n number of nodes, 2nCn/(n+1) these many trees can be gneerated.
    
5. BST
-- inorder of bst gives a sorted list.
-- no duplicates
-- Searching can be done recursively, as well as using loop. generally changing recursion to iteration needs stack, but that's not always. here, using iterative loop doesn't need stack in this case.
-- create, search, insert (need extra/tail pointer), delete (need to remmeber this logic https://www.udemy.com/course/datastructurescncpp/learn/lecture/13190284#overview)
// use bit map for finding sequence, missing in sequence, duplicate entry, presence of a number or not. most of the time, data will be unsorted.
// these operations doesn't need to store element, it just need to validate if number is there or not.

// get any mask

// Function to create a mask with all 1s between positions m and n (inclusive)
unsigned int createMask(int m, int n) {
    // Step 1: Create a mask with all bits set to 1
    unsigned int allOnes = ~0;
    
    // Step 2: Shift the mask left by m positions to clear lower bits
    unsigned int leftShifted = allOnes << m;
    
    // Step 3: Shift the mask right by (sizeof(int) * 8 - n - 1) positions to clear higher bits
    unsigned int rightShifted = allOnes >> ((sizeof(int) * 8) - n - 1);
    
    // Combine the two masks to get the final mask with 1s between m and n
    unsigned int mask = leftShifted & rightShifted;
    
    return mask;
}

// bit map set and get

#define MAX_VALUE 1000000
#define BITMAP_SIZE (MAX_VALUE / 8)

uint8_t bitmap[BITMAP_SIZE];

void set_bit(uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

bool get_bit(uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

// Delay logic

#include <stdio.h>
#include <time.h>

void delay(int milliseconds) {
    long pause;
    clock_t now, then;

    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause) {
        now = clock();
    }
}

// queue using stack.
// for enqueue, push in s1 always,
// for dequeue, if s2 is empty, pop everything from  s1 and push into s2.
// if s2 is not empty, simply pop from s2.
// always push in s1 and pop from s2. if s2 gets empty, push everything from s1 to s2. 


// stack using 2 queues
// enqueue in q1 for push operation.
// for pop or top, dequeue everything until last node and enqueue them in q2
// return last node. before returning swap q1, q2
// for top operation enqueue the last element after reading to q2.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Define the structure for a queue
typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

// Function to create a new queue node
QueueNode* newQueueNode(int data) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue an element to the queue
void enqueue(Queue* q, int data) {
    QueueNode* temp = newQueueNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (q->front == NULL)
        return -1;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    int data = temp->data;
    free(temp);
    return data;
}

// Define the structure for a stack using two queues
typedef struct Stack {
    Queue *q1, *q2;
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    enqueue(stack->q1, data);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->q1->front == NULL)
        return -1;
    while (stack->q1->front->next != NULL) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    int popped = dequeue(stack->q1);
    Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    return popped;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->q1->front == NULL;
}

// Function to get the top element of the stack
int top(Stack* stack) {
    if (stack->q1->front == NULL)
        return -1;
    while (stack->q1->front->next != NULL) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    int topElement = dequeue(stack->q1);
    enqueue(stack->q2, topElement);
    Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    return topElement;
}

// Main function to test the stack implementation
int main() {
    Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Top element is %d\n", top(stack));
    printf("Popped element is %d\n", pop(stack));
    printf("Top element is %d\n", top(stack));
    printf("Popped element is %d\n", pop(stack));
    printf("Popped element is %d\n", pop(stack));
    printf("Stack is empty: %d\n", isEmpty(stack));
    return 0;
}

// loop detection
while(p!=NULL && q!=NULL)
{
    if(p==q)
    {
        //Loop detected!
        exit(0);
    }
    p=p->next;
    q=(q->next)?(q->next->next):q->next;
}
// No loop.

// middle node
mynode *p = head;
mynode *q = head;
if(q!=NULL)
{
    while((q->next)!=NULL && (q->next->next)!=NULL)
    {
        p=(p!=(mynode *)NULL?p->next:(mynode *)NULL);
        q=(q!=(mynode *)NULL?q->next:(mynode *)NULL);
        q=(q!=(mynode *)NULL?q->next:(mynode *)NULL);
    }
    printf("The middle element is [%d]",p->value);
}

// Generic linked list
struct check {
    int i;
    char c;
    double d;
} chk[] = { { 1, 'a', 1.1 },
            { 2, 'b', 2.2 },
            { 3, 'c', 3.3 } };

void insert(List **p, void *data, unsigned int n)
{
    List *temp;
    int i;
    /* Error check is ignored */
    temp = malloc(sizeof(List));
    temp->data = malloc(n);
    for (i = 0; i < n; i++)
    *(char *)(temp->data + i) = *(char *)(data + i);
    temp->next = *p;
    *p = temp;
}
void print(List *p, void (*f)(void *))
{
    while (p)
    {
        (*f)(p->data);
        p = p->next;
    }
}
void printstr(void *str)
{
    printf(" \"%s\"", (char *)str);
}
void printint(void *n)
{
    printf(" %d", *(int *)n);
}
void printchar(void *c)
{
    printf(" %c", *(char *)c);
}
void printcomp(void *comp)
{
    struct check temp = *(struct check *)comp;
    printf(" '%d:%c:%f", temp.i, temp.c, temp.d);
}

//copy of linkedlist
copy_linked_lists(struct node *q, struct node **s)
{
    if(q!=NULL)
    {
        *s=malloc(sizeof(struct node));
        (*s)->data=q->data;
        (*s)->link=NULL;
        copy_linked_list(q->link, &((*s)->link));
    }
}

// commpare two list
int compare_linked_lists(struct node *q, struct node *r)
{
    static int flag;
    if((q==NULL ) && (r==NULL))
    {
        flag=1;
    }
    else
    {
        if(q==NULL || r==NULL)
        {
            flag=0;
        }
        if(q->data!=r->data)
        {
            flag=0;
        }
        else
        {
            compare_linked_lists(q->link,r->link);
        }
    }
    return(flag);
}
// free linkedlist
struct list *listptr, *nextptr;
for(listptr = head; listptr != NULL; listptr = listptr->next)
{
    free(listptr);
}
/*
Storing 16MB of Entries in 10MB of RAM
Problem: Given a sequence of numbers from 0 to 16MB, where each number can hold a Boolean value, design a solution to store this information in 10MB of RAM.

Finding Duplicate Numbers in a Large Dataset
Problem: Given a large dataset of integers ranging from 0 to N, find all the duplicate numbers.

Checking for Missing Numbers in a Sequence
Problem: Given a sequence of numbers from 0 to N with some numbers missing, find all the missing numbers.

Detecting Unique Characters in a String
Problem: Given a string, determine if all characters are unique.

Finding Intersection of Two Sets
Problem: Given two sets of integers, find their intersection.

Counting Distinct Elements in a Stream
Problem: Given a stream of integers, count the number of distinct elements.

Finding the First Missing Positive Integer
Problem: Given an unsorted array of integers, find the smallest missing positive integer.

Checking for Anagrams
Problem: Given two strings, determine if they are anagrams of each other.

Finding the Longest Consecutive Sequence
Problem: Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Finding Common Elements in Multiple Arrays
Problem: Given multiple arrays, find the common elements among them.

Efficiently Storing and Retrieving Sparse Data
Problem: Given a large sparse dataset, efficiently store and retrieve the data.
*/

// 


///////////////////// Sorting

What is the difference between Merge Sort and Quick sort?
Both Merge-sort and Quick-sort have same time complexity i.e. O(nlogn). In merge sort the file a[1:n] was divided at its midpoint into subarrays which are independently sorted and later merged. Whereas, in quick sort the division into two sub-arrays is made so that the sorted
sub-arrays do not need to be merged latter

Mergesort(a, left, right)
{
    if(left<right)
    {
        I=(left+right)/2;
        Mergesort(a,left, I);
        Mergesort(a,I+1,right);
        Merge(a,b,left,I,right);
        Copy(b,a,left,right);
    }
}

void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for(j = 1; j < n; j++)
    {
        for(i = 0; i < (n - j); i++)
        {
            if(a[i] >= a[i + 1])
            {
            //Swap a[i], a[i+1]
            }
        }
    }
}

To improvise this basic algorithm, keep track of whether a particular pass results in any swap or not. If not, you can break out without
wasting more cycles.
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    int flag;
    for(j = 1; j < n; j++)
    {
        flag = 0;
        for(i = 0; i < (n - j); i++)
        {
            if(a[i] >= a[i + 1])
            {
                //Swap a[i], a[i+1]
                flag = 1;
            }
        }
        if(flag==0)break;
    }
}

void selection_sort(int a[], int n)
{
    int i, j, small, pos, temp;
    for(i = 0; i < (n - 1); i++)
    {
        small = a[i];
        pos = i;
        for(j = i + 1; j < n; j++)
        {
            if(a[j] < small)
            {
            small = a[j];
            pos = j;
            }
        }
        temp = a[pos];
        a[pos] = a[i];
        a[i] = temp;
    }
}

int partition(int a[], int low, int high)
{
    int i, j, temp, key;
    key = a[low];
    i = low + 1;
    j = high;
    while(1)
    {
        while(i < high && key >= a[i])i++;
        while(key < a[j])j--;
        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return(j);
        }
    }
}

void quicksort(int a[], int low, int high)
{
    int j;
    if(low < high)
    {
        j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int main()
{// Populate the array a
quicksort(a, 0, n - 1);
}

void insertion_sort(int a[], int n)
{
    int i, j, item;
    for(i = 0; i < n; i++)
    {
        item = a[i];
        j = i - 1;
        while(j >=0 && item < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = item;
    }
}
//preorder
preorder(mynode *root)
{
    if(root)
    {
        printf("Value : [%d]", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
//Postorder
//same logic is used to solve the problem
//to delete the tree. while returning, free node.
postorder(mynode *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("Value : [%d]", root->value);
        }
    }
}
//Inorder
inorder(mynode *root)
{
    if(root)
    {
        inorder(root->left);
        printf("Value : [%d]", root->value); // simple condition checking like root->left == NULL && root->right == NULL count++
                                            // will work as a program to find leaf nodes. Check below
        inorder(root->right);
    }
}
void count_leaf(mynode *root)
{
    if(root!=NULL)
    {
        count_leaf(root->left);
        if(root->left == NULL && root->right==NULL)
        {
            // This is a leaf!
            count++;
        }
        count_leaf(root->right);
    }
}

Time complexity of traversals is O(n).


//copy of the tree

mynode *copy(mynode *root)
{
    mynode *temp;
    if(root==NULL)return(NULL);
    temp = (mynode *) malloc(sizeof(mynode));
    temp->value = root->value;
    // if left assigned with righ,and right with left, 
    // then this will give mirror.
    temp->left = copy(root->left);
    temp->right = copy(root->right);
    return(temp);
}

// TODO 
level order traversal
You need to use a queue to do this kind of a traversal
Let t be the tree root.
while (t != null)
{
    visit t and put its children on a FIFO queue;
    remove a node from the FIFO queue and
    call it t;
    // Remove returns null when queue is empty
}
Pseduocode
Level_order_traversal(p)
{
    while(p)
    {
        Visit(p);
        If(p->left)Q.Add(p->left);
        If(p->right)Q.Add(p->right);
        Delete(p);
    }
}

// searching in binary tree.

mynode *search(int value, mynode *root)
{
    while(root!=NULL && value!=root->value)
    {
        root = (value < root->value)?root->left:root->right;
    }
    return(root);
}
Here is another way to do the same
mynode *recursive_search(int item, mynode *root)
{
    if(root==NULL || item == root->value){return(root);}
    if(item<root->info)return{recursive_search(item, root->left);}
    return{recursive_search(item, root->right);}
}

// synchronization logic
https://www.youtube.com/watch?v=mtjcoL-sGEM
https://www.youtube.com/watch?v=Bue0ozYd7DM
https://www.youtube.com/watch?v=NuEXG6jW3nY
producer always post semaphore after producing, and consuder always consume after getting semaphore
consumer will always be of hight priority and should get blocked asap. prodcuer will be of lower priority

void isr (void) {
    // disable interrupt
    // ack interrupt, clear interrupt
    // post semaphore or do some work
    // enable all itnerrupts
}

// Little or big endian
// using union
#include <stdio.h>

union {
    unsigned int i;
    char c[4];
} u;

int main(void) {
    u.i = 1; // Set the integer value to 1

    if (u.c[0] == 1) { // Check the first byte
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }

    return 0;
}
// using pointer
#include <stdio.h>

int main(void) {
    unsigned int i = 1; // Initialize an integer with value 1
    char *c = (char *) &i; // Point to the first byte of the integer

    if (*c == 1) { // If the first byte is 1
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }

    return 0;
}

// stack direction
#include <stdio.h>

void fun(int *main_local_addr) {
    int fun_local; // Local variable in fun
    if (main_local_addr < &fun_local) {
        printf("Stack grows upward\n");
    } else {
        printf("Stack grows downward\n");
    }
}

int main() {
    int main_local; // Local variable in main
    fun(&main_local); // Pass address of main's local variable
    return 0;
}

// custom malloc which supports alignment
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void* aligned_malloc(size_t size, size_t alignment) {
    // Ensure alignment is a power of 2
    if (alignment & (alignment - 1)) {
        return NULL; // Not a power of 2
    }

    // Allocate extra memory for alignment adjustment
    void* ptr = malloc(size + alignment + sizeof(void*));
    if (!ptr) {
        return NULL; // Allocation failed
    }

    // Calculate the aligned address
    uintptr_t addr = (uintptr_t)ptr + sizeof(void*);
    uintptr_t aligned_addr = (addr + (alignment - 1)) & ~(alignment - 1);

    // Store the original pointer just before the aligned address
    *((void**)(aligned_addr - sizeof(void*))) = ptr;

    return (void*)aligned_addr; // Return the aligned address
}

void aligned_free(void* ptr) {
    if (!ptr) return; // Nothing to free

    // Retrieve the original pointer
    void* original_ptr = *((void**)((uintptr_t)ptr - sizeof(void*)));
    free(original_ptr); // Free the original pointer
}

int main() {
    size_t alignment = 32; // Desired alignment
    size_t size = 100;     // Size of allocation

    void* aligned_ptr = aligned_malloc(size, alignment);
    
    if (aligned_ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Aligned pointer: %p\n", aligned_ptr);
    
    // Use the allocated memory...
    
    aligned_free(aligned_ptr); // Free the allocated memory

    return 0;
}
Considerations
Error Handling: The implementation checks for allocation failures and invalid alignments.
Performance: This implementation may introduce overhead due to additional calculations and storage.
Thread Safety: This code does not handle multithreading; consider using mutexes or other synchronization mechanisms if needed.
Alignment Requirements: Ensure that your system supports the requested alignments, especially for larger values.

/// Poll allocator using dynamic memory
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MemoryPool {
    size_t block_size;      // Size of each block
    size_t block_count;     // Number of blocks
    void* pool;             // Pointer to the memory pool
    char* free_list;        // Pointer to the free list
} MemoryPool;

// Initialize the memory pool
MemoryPool* create_pool(size_t block_size, size_t block_count) {
    MemoryPool* pool = (MemoryPool*)malloc(sizeof(MemoryPool));
    if (!pool) return NULL;

    pool->block_size = block_size;
    pool->block_count = block_count;
    pool->pool = malloc(block_size * block_count);
    if (!pool->pool) {
        free(pool);
        return NULL;
    }

    // Initialize the free list
    pool->free_list = (char*)pool->pool;
    for (size_t i = 0; i < block_count - 1; ++i) {
        *(void**)(pool->free_list + i * block_size) = pool->free_list + (i + 1) * block_size;
    }
    *(void**)(pool->free_list + (block_count - 1) * block_size) = NULL; // Last block points to NULL

    return pool;
}

// Allocate a block from the pool
void* pool_malloc(MemoryPool* pool) {
    if (!pool->free_list) return NULL; // No free blocks available

    void* block = pool->free_list; // Get the first free block
    pool->free_list = *(void**)block; // Update the free list to the next free block

    return block;
}

// Allocate a zero-initialized block from the pool (similar to calloc)
void* pool_calloc(MemoryPool* pool) {
    void* block = pool_malloc(pool);
    if (block) {
        memset(block, 0, pool->block_size); // Zero-initialize the allocated memory
    }
    return block;
}

// Free a block back to the pool
void pool_free(MemoryPool* pool, void* ptr) {
    if (!ptr || ptr < pool->pool || ptr >= (char*)pool->pool + (pool->block_size * pool->block_count)) {
        return; // Invalid pointer
    }

    *(void**)ptr = pool->free_list; // Add the block back to the free list
    pool->free_list = (char*)ptr;   // Update the free list
}

// Destroy the memory pool and free all resources
void destroy_pool(MemoryPool* pool) {
    if (pool) {
        free(pool->pool);
        free(pool);
    }
}

int main() {
    const size_t BLOCK_SIZE = 32;
    const size_t BLOCK_COUNT = 10;

    MemoryPool* my_pool = create_pool(BLOCK_SIZE, BLOCK_COUNT);
    
    if (!my_pool) {
        printf("Failed to create memory pool\n");
        return 1;
    }

    // Allocate some blocks
    void* ptr1 = pool_malloc(my_pool);
    void* ptr2 = pool_calloc(my_pool);

    if (ptr1 && ptr2) {
        printf("Allocated blocks at %p and %p\n", ptr1, ptr2);
        
        // Free blocks back to the pool
        pool_free(my_pool, ptr1);
        printf("Freed block at %p\n", ptr1);

        void* ptr3 = pool_malloc(my_pool); // Reallocate from freed space
        printf("Reallocated block at %p\n", ptr3);
        
        // Free remaining blocks
        pool_free(my_pool, ptr2);
        printf("Freed block at %p\n", ptr2);
        
        // Freeing again should work for ptr3 too
        pool_free(my_pool, ptr3);
        printf("Freed reallocated block at %p\n", ptr3);
        
        destroy_pool(my_pool); // Clean up memory pool
        printf("Memory pool destroyed\n");
        
        return 0;
    }

    destroy_pool(my_pool); // Clean up on failure
    return 1;
}

// array based

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 1024 // Total size of the memory pool
#define BLOCK_SIZE 32  // Size of each block

typedef struct MemoryPool {
    char pool[POOL_SIZE];       // Memory pool
    int free_map[POOL_SIZE / BLOCK_SIZE]; // Free block map
} MemoryPool;

// Initialize the memory pool
MemoryPool* create_pool() {
    MemoryPool* pool = (MemoryPool*)malloc(sizeof(MemoryPool));
    if (!pool) return NULL;

    memset(pool->free_map, 0, sizeof(pool->free_map)); // Initialize free map to 0 (all blocks are free)
    return pool;
}

// Allocate a block from the pool
void* pool_malloc(MemoryPool* pool) {
    for (int i = 0; i < (POOL_SIZE / BLOCK_SIZE); ++i) {
        if (pool->free_map[i] == 0) { // Check if the block is free
            pool->free_map[i] = 1; // Mark the block as used
            return (void*)&pool->pool[i * BLOCK_SIZE]; // Return pointer to the allocated block
        }
    }
    return NULL; // No free blocks available
}

// Free a block back to the pool
void pool_free(MemoryPool* pool, void* ptr) {
    if (ptr < (void*)pool->pool || ptr >= (void*)(pool->pool + POOL_SIZE)) {
        return; // Pointer out of bounds
    }

    // Calculate block index and mark it as free
    int index = ((char*)ptr - pool->pool) / BLOCK_SIZE;
    if (index >= 0 && index < (POOL_SIZE / BLOCK_SIZE)) {
        pool->free_map[index] = 0; // Mark the block as free
    }
}

// Destroy the memory pool and free resources
void destroy_pool(MemoryPool* pool) {
    if (pool) {
        free(pool);
    }
}

int main() {
    MemoryPool* my_pool = create_pool();
    
    if (!my_pool) {
        printf("Failed to create memory pool\n");
        return 1;
    }

    // Allocate some blocks from the pool
    void* ptr1 = pool_malloc(my_pool);
    void* ptr2 = pool_malloc(my_pool);

    if (ptr1 && ptr2) {
        printf("Allocated blocks at %p and %p\n", ptr1, ptr2);
        
        // Free blocks back to the pool
        pool_free(my_pool, ptr1);
        printf("Freed block at %p\n", ptr1);

        void* ptr3 = pool_malloc(my_pool); // Reallocate from freed space
        printf("Reallocated block at %p\n", ptr3);
        
        // Free remaining blocks
        pool_free(my_pool, ptr2);
        printf("Freed block at %p\n", ptr2);
        
        // Freeing again should work for ptr3 too
        pool_free(my_pool, ptr3);
        printf("Freed reallocated block at %p\n", ptr3);
        
        destroy_pool(my_pool); // Clean up memory pool
        printf("Memory pool destroyed\n");
        
        return 0;
    }

    destroy_pool(my_pool); // Clean up on failure
    return 1;
}

Considerations
Fixed Size: This implementation only supports fixed-size allocations defined by BLOCK_SIZE. If you need variable sizes, consider implementing multiple pools or more complex management techniques.
Performance: This allocator is efficient for scenarios with many small allocations and deallocations.
Error Handling: Basic error handling is included but could be expanded for robustness in production code.
Thread Safety: This implementation is not thread-safe. If used in multi-threaded applications, consider adding synchronization mechanisms.

//LRU fully functional program
#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 3 // Define the maximum size of the cache

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct LRUCache {
    Node* head;
    Node* tail;
    Node** hashMap; // Hash map for O(1) access
    int capacity;
} LRUCache;

// Function to create a new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create an LRU Cache
LRUCache* createCache(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->head = NULL;
    cache->tail = NULL;
    cache->hashMap = (Node**)malloc(sizeof(Node*) * capacity);
    
    for (int i = 0; i < capacity; i++) {
        cache->hashMap[i] = NULL; // Initialize hash map
    }
    
    return cache;
}

// Function to remove a node from the linked list
void removeNode(LRUCache* cache, Node* node) {
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        cache->head = node->next; // Update head if needed
    }
    
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        cache->tail = node->prev; // Update tail if needed
    }
}

// Function to add a node to the front of the linked list
void addToFront(LRUCache* cache, Node* node) {
    node->next = cache->head;

    if (cache->head) {
        cache->head->prev = node;
    }

    cache->head = node;

    if (!cache->tail) {
        cache->tail = node; // First element added
    }

    node->prev = NULL;
}

// Function to get a value from the cache
int get(LRUCache* cache, int key) {
    int index = key % cache->capacity; // Simple hash function

    Node* node = cache->hashMap[index];
    
    if (!node) {
        return -1; // Not found
    }

    // Move the accessed node to the front (most recently used)
    removeNode(cache, node);
    addToFront(cache, node);

    return node->value; // Return the value
}

// Function to put a key-value pair into the cache
void put(LRUCache* cache, int key, int value) {
    int index = key % cache->capacity;

    if (cache->hashMap[index]) {
        // Key already exists, update the value and move it to front
        Node* existingNode = cache->hashMap[index];
        existingNode->value = value;

        removeNode(cache, existingNode);
        addToFront(cache, existingNode);
        
        return;
    }

    // If we reach capacity, remove the least recently used item
    if (cache->tail && !cache->hashMap[cache->tail->key % cache->capacity]) {
        // Remove from hash map
        int tailKey = cache->tail->key;
        removeNode(cache, cache->tail);
        free(cache->hashMap[tailKey % cache->capacity]);
        cache->hashMap[tailKey % cache->capacity] = NULL; // Remove from hash map
    }

    // Create a new node and add it to the front
    Node* newNode = createNode(key, value);
    
    addToFront(cache, newNode);
    
    // Add to hash map
    cache->hashMap[key % cache->capacity] = newNode;
}

// Function to free the LRU Cache memory
void freeCache(LRUCache* cache) {
    Node* current = cache->head;
    
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
   free(cache->hashMap);
   free(cache);
}

// Test the LRU Cache implementation
int main() {
   LRUCache* lruCache = createCache(CACHE_SIZE);

   put(lruCache, 1, 1);
   put(lruCache, 2, 2);
   printf("Get 1: %d\n", get(lruCache, 1)); // Returns 1

   put(lruCache, 3, 3); // Evicts key 2
   printf("Get 2: %d\n", get(lruCache, 2)); // Returns -1 (not found)

   put(lruCache, 4, 4); // Evicts key 1
   printf("Get 1: %d\n", get(lruCache, 1)); // Returns -1 (not found)
   printf("Get 3: %d\n", get(lruCache, 3)); // Returns 3
   printf("Get 4: %d\n", get(lruCache, 4)); // Returns 4

   freeCache(lruCache); // Free allocated memory

   return 0;
}

Explanation of the Code:
Data Structures:
Node: Represents each entry in the LRU Cache with pointers for a doubly linked list.
LRUCache: Contains pointers for head and tail nodes of the linked list and an array for the hash map.
Functions:
createNode: Allocates memory for a new node.
createCache: Initializes an LRU Cache with specified capacity.
removeNode: Removes a specified node from the linked list.
addToFront: Adds a specified node to the front of the linked list.
get: Retrieves a value by key and moves it to the front of the list.
put: Inserts or updates a key-value pair and manages eviction if necessary.
Memory Management: The freeCache function ensures that all allocated memory is released when done.

// cache miss problem
count hit and miss on cache.
#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 5 // Size of the cache

typedef struct Cache {
    int* data;
    int size;
    int hits;
    int misses;
} Cache;

// Function to create a new cache
Cache* createCache(int size) {
    Cache* cache = (Cache*)malloc(sizeof(Cache));
    cache->data = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        cache->data[i] = -1; // Initialize with -1 indicating empty
    }
    cache->size = size;
    cache->hits = 0;
    cache->misses = 0;
    return cache;
}

// Function to access data from the cache
void accessCache(Cache* cache, int value) {
    int found = 0;

    // Check for a hit
    for (int i = 0; i < cache->size; i++) {
        if (cache->data[i] == value) {
            found = 1;
            printf("Cache Hit: %d\n", value);
            cache->hits++;
            break;
        }
    }

    // If not found, it's a miss
    if (!found) {
        printf("Cache Miss: %d\n", value);
        cache->misses++;

        // Add to the cache (simple FIFO eviction)
        for (int i = 0; i < cache->size - 1; i++) {
            cache->data[i] = cache->data[i + 1]; // Shift left
        }
        cache->data[cache->size - 1] = value; // Add new value at the end
    }
}

// Function to print statistics
void printStats(Cache* cache) {
    printf("Total Hits: %d\n", cache->hits);
    printf("Total Misses: %d\n", cache->misses);
}

// Function to free the allocated memory
void freeCache(Cache* cache) {
    free(cache->data);
    free(cache);
}

// Test the Cache Simulation
int main() {
    Cache* myCache = createCache(CACHE_SIZE);

    int accesses[] = {1, 2, 3, 4, 5, 2, 3, 6, 2, 4};
    
    for (int i = 0; i < sizeof(accesses) / sizeof(accesses[0]); i++) {
        accessCache(myCache, accesses[i]);
    }

    printStats(myCache); // Print hit/miss statistics

    freeCache(myCache); // Free allocated memory

    return 0;
}

Cache Miss: 1
Cache Miss: 2
Cache Miss: 3
Cache Miss: 4
Cache Miss: 5
Cache Hit: 2
Cache Hit: 3
Cache Miss: 6
Cache Hit: 2
Cache Miss: 4
Total Hits: 5
Total Misses: 5

// FSM
always ask for states, those are enum values
always ask conditions for transitions, those will be signal of state machine sequence. 
    
1. Vending Machine State Machine
Question: Design a state machine for a vending machine that accepts coins (nickels, dimes, quarters) and dispenses a product once the correct amount is inserted.
Solution:
The vending machine can be modeled as a finite state machine with the following states:
States:
S0: 0 cents
S1: 5 cents
S2: 10 cents
S3: 15 cents
S4: 20 cents (product dispensed)
Inputs:
NICKEL: Adds 5 cents
DIME: Adds 10 cents
QUARTER: Adds 25 cents
Outputs:
Dispense product when reaching S4.

#include <stdio.h>

typedef enum {S0, S1, S2, S3, S4} State;

void dispenseProduct() {
    printf("Product Dispensed!\n");
}

int main() {
    State currentState = S0;
    char input;

    while (1) {
        printf("Insert coin (n for nickel, d for dime, q for quarter, r to reset): ");
        scanf(" %c", &input);

        switch (currentState) {
            case S0:
                if (input == 'n') currentState = S1;
                else if (input == 'd') currentState = S2;
                else if (input == 'q') currentState = S3;
                break;
            case S1:
                if (input == 'n') currentState = S2;
                else if (input == 'd') currentState = S3;
                else if (input == 'q') {
                    dispenseProduct();
                    currentState = S4;
                }
                break;
            case S2:
                if (input == 'n') currentState = S3;
                else if (input == 'd') {
                    dispenseProduct();
                    currentState = S4;
                }
                break;
            case S3:
                if (input == 'n') {
                    dispenseProduct();
                    currentState = S4;
                }
                break;
            case S4:
                if (input == 'r') currentState = S0; // Reset
                break;
        }
    }

    return 0;
}

2. Traffic light
#include <stdio.h>
#include <unistd.h> // For sleep function

typedef enum {RED, GREEN, YELLOW} TrafficLightState;

int main() {
    TrafficLightState state = RED;

    while (1) {
        switch (state) {
            case RED:
                printf("Traffic Light: RED\n");
                sleep(5); // Red for 5 seconds
                state = GREEN; // Transition to GREEN
                break;

            case GREEN:
                printf("Traffic Light: GREEN\n");
                sleep(5); // Green for 5 seconds
                state = YELLOW; // Transition to YELLOW
                break;

            case YELLOW:
                printf("Traffic Light: YELLOW\n");
                sleep(2); // Yellow for 2 seconds
                state = RED; // Transition back to RED
                break;
        }
    }

    return 0;
}

3. Game Controller State Machine
Question: Design a state machine for a game controller that manages different modes like idle, active, and sleep.
Solution:
The game controller can have the following states:
States:
IDLE
ACTIVE
SLEEP
Transitions:
From IDLE to ACTIVE on button press.
From ACTIVE to SLEEP after inactivity.
From SLEEP to IDLE on button press.

#include <stdio.h>

typedef enum {IDLE, ACTIVE, SLEEP} ControllerState;

int main() {
    ControllerState state = IDLE;
    char input;

    while (1) {
        switch (state) {
            case IDLE:
                printf("Controller is IDLE. Press 'a' to activate.\n");
                scanf(" %c", &input);
                if (input == 'a') state = ACTIVE; // Transition to ACTIVE
                break;

            case ACTIVE:
                printf("Controller is ACTIVE. Press 's' to sleep.\n");
                scanf(" %c", &input);
                if (input == 's') state = SLEEP; // Transition to SLEEP
                break;

            case SLEEP:
                printf("Controller is in SLEEP mode. Press 'r' to wake up.\n");
                scanf(" %c", &input);
                if (input == 'r') state = IDLE; // Transition back to IDLE
                break;
        }
    }

    return 0;
}

// ringbuffer
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>  // For sleep()

#define BUFFER_SIZE 5

typedef struct {
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
    sem_t empty;
    sem_t full;
    pthread_mutex_t mutex;
} RingBuffer;

RingBuffer rb;  // Global ring buffer

void init(RingBuffer *rb) {
    rb->head = 0;
    rb->tail = 0;
    sem_init(&rb->empty, 0, BUFFER_SIZE);
    sem_init(&rb->full, 0, 0);
    pthread_mutex_init(&rb->mutex, NULL);
}

void produce(RingBuffer *rb, int item) {
    sem_wait(&rb->empty);
    pthread_mutex_lock(&rb->mutex);
    
    rb->buffer[rb->head] = item;
    rb->head = (rb->head + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&rb->mutex);
    sem_post(&rb->full);
}

int consume(RingBuffer *rb) {
    sem_wait(&rb->full);
    pthread_mutex_lock(&rb->mutex);

    int item = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&rb->mutex);
    sem_post(&rb->empty);
    
    return item;
}

void* producer(void* arg) {
    int item = 0;

    while (1) {
        produce(&rb, item);
        printf("Produced: %d\n", item++);
        sleep(1); // Simulate work by sleeping
    }
    
    return NULL; // This line will never be reached
}

void* consumer(void* arg) {
    
    while (1) {
        int item = consume(&rb);
        printf("Consumed: %d\n", item);
        sleep(2); // Simulate work by sleeping
    }
    
    return NULL; // This line will never be reached
}

int main() {
    init(&rb);

    pthread_t prod, cons;

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for threads to finish (they won't unless interrupted)
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Clean up resources (this part will never be reached)
    sem_destroy(&rb.empty);
    sem_destroy(&rb.full);
    pthread_mutex_destroy(&rb.mutex);

    return 0;
}

```
// our code
// writting test for read-write
OUR REPO

#include <gmock/gmock.h>
#include <gmock-global/gmock-global.h>

// for registering the mock api
MOCK_GLOBAL_FUNC2(mock_write_reg32, void(volatile uint32_t *, uint32_t));
MOCK_GLOBAL_FUNC2(mock_read_reg32, void(volatile uint32_t *, uint32_t *));
// for mapping
USE_GMOCK(write_reg32, mock_write_reg32);
USE_GMOCK(read_reg32, mock_read_reg32);

#include <gtest/gtest.h>
#include <cstring>

// Test fixture for setting up tests
class RegisterTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Reset mock register before each test
        mock_register = 0;
    }

    void TearDown() override {
        // Cleanup if needed
    }
};

//
TEST_F(RegisterTest, ReadRegisterValue) {
	//
	EXPECT_GLOBAL_CALL(mock_write_reg32, mock_write_reg32(_, _)).Times(2); // set expectation of exact calls
	ON_GLOBAL_NICE_CALL(mock_read_reg32, mock_read_reg32(_, _)).WillByDefault(Return()); // do nothing and return
	ON_GLOBAL_NICE_CALL(mock_write_reg32, mock_write_reg32(_, _)).WillByDefault(Return());
	ON_GLOBAL_NICE_CALL(mock_read_reg32, mock_read_reg32(_, _))
	.WillByDefault(SetArgPointee<1>(0x02)); // set value.
    EXPECT_GLOBAL_CALL(mock_read_reg32, mock_read_reg32(_,
			   _)).Times(AtLeast(1)).WillRepeatedly(SetArgPointee<1>(0));
	EXPECT_GLOBAL_CALL(mock_write_reg32, mock_write_reg32(_, _)).Times(AtLeast(1));
	EXPECT_GLOBAL_CALL(mock_wait_for, mock_wait_for(_, _, _)).WillRepeatedly(Return(true));


    EXPECT_GLOBAL_CALL(mock_npi_mmio_get_pfvf_map, mock_npi_mmio_get_pfvf_map(_, _, _, _)).Times(1)
	.WillOnce(DoAll(SetArgPointee<2>(base), SetArgPointee<3>(len)));
}

class mmg__ut_npi_sram : public mmg__ut_npi_no_init_base,
	public WithParamInterface<std::tuple<npi_quirk_state /* quirk state */, uint32_t /* device state */>> {};
INSTANTIATE_TEST_SUITE_P(Instance_of_, mmg__ut_npi_sram,
			 /* all combinations of listed quirk states and device states */
			 Combine(Values(NPI_QUIRK_DISABLE, NPI_QUIRK_ENABLE), Values(NVME_CPF_SYS_STATE_HW_CLEAN,
					 NVME_CPF_SYS_STATE_HW_INITIALIZED)));
//
GPT
```c
#include <stdint.h>

#define READ_REGISTER(base, offset) (*(volatile uint32_t *)((base) + (offset)))
#define WRITE_REGISTER(base, offset, value) (*(volatile uint32_t *)((base) + (offset)) = (value))

// Function to get the value of a specific register
void get_register_value(uint32_t base_address, uint32_t offset, uint32_t *value) {
    *value = READ_REGISTER(base_address, offset);  // Correctly assign the read value
}

// Function to set the value of a specific register
void set_register_value(uint32_t base_address, uint32_t offset, uint32_t value) {
    WRITE_REGISTER(base_address, offset, value);
}

```

```cpp
#include <gtest/gtest.h>
#include <cstring>

// Mock register variable
static uint32_t mock_register;

// Mock functions to replace actual hardware access
extern "C" {
    #define READ_REGISTER(base, offset) (mock_register)
    #define WRITE_REGISTER(base, offset, value) (mock_register = (value))
}

// Test fixture for setting up tests
class RegisterTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Reset mock register before each test
        mock_register = 0;
    }

    void TearDown() override {
        // Cleanup if needed
    }
};

// Test case for reading the register value
TEST_F(RegisterTest, ReadRegisterValue) {
    WRITE_REGISTER(0x40000000, 0x04, 42);  // Write to mock register
    uint32_t value;
    get_register_value(0x40000000, 0x04, &value); // Get the value
    EXPECT_EQ(value, 42);                      // Check read value
}

// Test case for writing to the register value
TEST_F(RegisterTest, WriteRegisterValue) {
    set_register_value(0x40000000, 0x04, 100); // Set mock register value
    EXPECT_EQ(mock_register, 100);            // Verify the mock register value
}

// Main function to run tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

```

// writting test for read-write
```c
#include <stdint.h>

#define READ_REGISTER(base, offset) (*(volatile uint32_t *)((base) + (offset)))
#define WRITE_REGISTER(base, offset, value) (*(volatile uint32_t *)((base) + (offset)) = (value))

// Function to get the value of a specific register
void get_register_value(uint32_t base_address, uint32_t offset, uint32_t *value) {
    *value = READ_REGISTER(base_address, offset);  // Correctly assign the read value
}

// Function to set the value of a specific register
void set_register_value(uint32_t base_address, uint32_t offset, uint32_t value) {
    WRITE_REGISTER(base_address, offset, value);
}

```

// macros
#include <stddef.h>

#define offset_of(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
Explanation:
This macro takes two parameters: the type of the structure (TYPE) and the member name (MEMBER).
It effectively computes the offset by taking the address of the member in a hypothetical instance of the structure located at address 0. 
This is safe because it only uses the type information, not the actual memory.

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offset_of(type, member)); \
})
How It Works:
The first line creates a pointer (__mptr) that points to the member specified by ptr.
The second line calculates the address of the containing structure by subtracting the offset of that member from the address stored in __mptr.

#include <stdlib.h>
#include <stddef.h>

#define aligned_alloc(size, alignment) \
    (((size) + (alignment) - 1) & ~((alignment) - 1))
This macro adjusts a given size up to ensure it is aligned to a specified boundary.
Parameters:
size: The size of memory requested.
alignment: The desired alignment (must be a power of two).
How It Works:
The expression ensures that size is rounded up to the nearest multiple of alignment.
