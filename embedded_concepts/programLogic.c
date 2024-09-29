// use bit map for finding sequence, missing in sequence, duplicate entry, presence of a number or not. most of the time, data will be unsorted.
// these operations doesn't need to store element, it just need to validate if number is there or not.

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



