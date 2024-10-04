// Datastructure suggestions
DS operations
1. array
- Improving linear search in array
-- transpostion, or move to head method can help here, where we are moving recently searched element forward.
-- find max, min
-- bring negative in one size, positive in other side.
-- merging of an arrays (arrays has to be sorted)
-- add data in sorted list

2. String
-- Permutation
-- Combination
-- strlen, strcat, strtok, strstr
-- reverse
-- finding duplicates
-- Counting words, vowels, letters, alphabets
-- Anagram, palindrom

3. Linkedlist
-- 

4. binary tree
-- creating binary tree we need 2 data structure. 1st is linkedlist and 2nd is queue. https://www.udemy.com/course/datastructurescncpp/learn/lecture/13168486#overview
    method to create is. first have root as input from user, push address to queue. enter while, p = dequeue(q); and ask for left child, if present, alloc temp, update fields, point p->left = temp, and enqueue temp.
    go to right, and repeat same. such, level by level keep on adding left and right child to tree. [check uploaded pic]
    POST order iterative is a bit trickier. 
-- traversing can happen in preorder, postorder and inorder. recursion is really easy, but for iteration we need to maintain our own stack.
-- inorder of bst gives a sorted list.
    
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
