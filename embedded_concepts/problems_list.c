//Write a program to print numbers from 1 to 100 without using loops!

Method1 (Using recursion)
void printUp(int startNumber, int endNumber)
{
    if (startNumber > endNumber)
    return;
    printf("[%d]\n", startNumber++);
    printUp(startNumber, endNumber);
}

//How to add two numbers without using the plus operator?
Actually,
CARRY = (A AND B) OR (CARRY_IN & A & B)
SUM = A XOR B XOR CARRY
try bit-by-bit.
On a wicked note, you can add two numbers wihtout using the + operator as follows
a - (- b)

//How can we sum the digits of a given number in single statement?

# include<stdio.h>
void main()
{
int num=123456;
int sum=0;
for(;num>0;sum+=num%10,num/=10); // This is the "single line".
printf("\nsum = [%d]\n", sum);
}

Write code to round numbers
Use something like
(int)(num < 0 ? (num - 0.5) : (num + 0.5))

//How to fast multiply a number by 7?
Try
(num<<3 - num)

//How do you get the line numbers in C?
Use the following Macros
__FILE__ Source file name (string constant) format "patx.c"
__LINE__ Current source line number (integer)
__DATE__ Date compiled (string constant)format "Dec 14 1985"
__TIME__ Time compiled (string constant) format "15:24:26"
__TIMESTAMP__ Compile date/time (string constant)format "Tue Nov 19 11:39:12 1997"

//How to scan a string till we hit a new line using scanf()?
Use
scanf("%[^\n]", address);

// leap year logic
if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
divisible by 4, but not by 100, but by 400.

// compare floats
int compareFloats(float f1, float f2)
{
    char *b1, *b2;
    int i;
    b1 = (char *)&f1;
    b2 = (char *)&f2;
    /* Assuming sizeof(float) is 4 bytes) */
    for (i = 0; i<4; i++, b1++, b2++)
        {
        if (*b1 != *b2)
        {
            return(NOT_EQUAL); /* You must have defined this before */
        }
    }
    return(EQUAL);
}

// binary search 
int binarySearch(int arr[],int size, int item)
{
    int left, right, middle;
    left = 0;
    right = size-1;
    while(left<=right)
    {
        middle = ((left + right)/2);
        if(item == arr[middle])
        {
            return(middle);
        }
        if(item > arr[middle])
        {
            left = middle+1;
        }
        else
        {
            right = middle-1;
        }
    }
    return(-1);
}

// matrix multiplication
Write a C program to multiply two matrices.
Are you sure you know this? A lot of people think they already know this, but guess what? So take a good look at this C program. Its
asked in most of the interviews as a warm up question.
// Matrix A (m*n)
// Matrix B (n*k)
// Matrix C (m*k)
for(i=0; i<m; i++)
{
    for(j=0;j<k;j++)
    {
        c[i][j]=0;
        for(l=0;l<n;l++)
            c[i][j] += a[i][l] * b[l][j];
    }
}

// finding struct size without sizeof
int main()
{
    struct MyStruct *p=0;
    int size = ((char*)(p+1))-((char*)p);
    printf("\nSIZE : [%d]\nSIZE : [%d]\n", size);
    return 0;
}

// ARRAY ALLOC
Two dimensional array
Method1
int **myarray = (int **)malloc(no_of_rows * sizeof(int *));
for(i = 0; i < no_of_rows; i++)
{
myarray[i] = malloc(no_of_columns * sizeof(int));
}
// Access elements as myarray[i][j]
Method2 (keep the array's contents contiguous)
int **myarray = (int **)malloc(no_of_rows * sizeof(int *));
myarray[0] = malloc(no_of_rows * no_of_columns * sizeof(int));
for(i = 1; i < no_of_rows; i++)
myarray[i] = myarray[0] + (i * no_of_columns);
// Access elements as myarray[i][j]
Method3
int *myarray = malloc(no_of_rows * no_of_columns * sizeof(int));
// Access elements using myarray[i * no_of_columns + j].
Three dimensional array
#define MAXX 3
#define MAXY 4#define MAXZ 5
main()
{
    int ***p,i,j;
    p=(int ***) malloc(MAXX * sizeof(int ***));
    for(i=0;i<MAXX;i++)
    {
        p[i]=(int **)malloc(MAXY * sizeof(int *));
        for(j=0;j<MAXY;j++)
        p[i][j]=(int *)malloc(MAXZ * sizeof(int));
    }
    for(k=0;k<MAXZ;k++)
        for(i=0;i<MAXX;i++)
            for(j=0;j<MAXY;j++)
                p[i][j][k]=<something>;
}
// find max using ternary
Find the maximum of three integers using the ternary operator.
Here is how you do it
max = ((a>b)?((a>c)?a:c):((b>c)?b:c));
Here is another way
max = ((a>b)?a:b)>c?((a>b)?a:b):c

// find gcd
// Iterative algorithm
int gcd(int a, int b)
{
    int temp;
    while(b)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return(a);
}// Recursive algorithm
int gcd_recurse(int a, int b)
{
    int temp;
    temp = a % b;
    if (temp == 0)
    {
        return(b);
    }
    else
    {
        return(gcd_recurse(b, temp));
    }
}
And her

// power of 2
if(!(num & (num - 1)) && num)
{
// Power of 2!
}
Method2
if(((~i+1)&i)==i)
{
//Power of 2!
}

//mugging up
Write C code to solve the Tower of Hanoi problem.
Here is an example C program to solve the Tower Of Hanoi problem...
main()
{
    towers_of_hanio(n,'L','R','C');
}
towers_of_hanio(int n, char from, char to, char temp)
{
    if(n>0)
    {
        tower_of_hanio(n-1, from, temp, to);
        printf("\nMove disk %d from %c to %c\n", n, from, to);
        tower_of_hanio(n-1, temp, to, from);
    }
}

// decimal to any base
Write a C progam to convert from decimal to any base (binary, hex, oct etc...)
Here is some really cool C code
#include <stdio.h>
int main()
{
    decimal_to_anybase(10, 2);
    decimal_to_anybase(255, 16);
    getch();
}
decimal_to_anybase(int n, int base)
{
    int i, m, digits[1000], flag;
    i=0;
    printf("\n\n[%d] converted to base [%d] : ", n, base);
    while(n)
    {
        m=n%base;
        digits[i]="0123456789abcdefghijklmnopqrstuvwxyz"[m];
        n=n/base;
        i++;
    }
    //Eliminate any leading zeroes
    for(i--;i>=0;i--)
    {
    if(!flag && digits[i]!='0')flag=1;
    if(flag)printf("%c",digits[i]);
    }
}
// convert from little endian to big endian.
int myreversefunc(int num)
{
    int byte0, byte1, byte2, byte3;
    byte0 = (num & x000000FF) >> 0 ;
    byte1 = (num & x0000FF00) >> 8 ;
    byte2 = (num & x00FF0000) >> 16 ;
    byte3 = (num & xFF000000) >> 24 ;
    return((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0));
}
https://www.youtube.com/watch?v=T8E_JRqN0fY

//TODO
int reverseBytes(int num){
    int result= 0;
    for(i = 0; i < 4; i++) {
        result |= (num >> i * 8 && 0xff) << ( 8 * (4 - i - 1));
    }
}
// swap for endianness
uint8_t swap_nibbles_in_byte(uint8_t byte) {
    return ((byte & 0x0F) << 4) | ((byte & 0xF0) >> 4);
}

#define MAX 3

int swap_bytes(unsigned int num) {
    unsigned int swapped = 0;
    uint8_t src = &num;
    uint8_t dest = &swapped;
    for(int i=0; i<=MAX; i++){
        dest[i] = src[MAX - i];        
    }
}

#include <stdio.h>
int reverseBytes(int num){
    int result= 0;
    for(int i = 0; i < 4; i++) {
        result = result << 8;
        result = result | ((num >> (i * 8)) & 0XFF);
    }
// fibonacci
int fib(int n)
{
    if (n <= 2) return 1
    else return fib(n-1) + fib(n-2)
}
int fib(int n)
{
    int a = 1, b = 1;
    for (int i = 3; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return a;
}
// string reverse
for(int i = 0, j = reversed.Length - 1; i < j; i++, j--)
{
    char temp = reversed[i];
    reversed[i] = reversed[j];
    reversed[j] = temp;
}


// swap
a=a+b;
b=a-b;
a=a-b;

swap(int *a, int *b)
{
    *a ^= *b ^= *a ^= *b;
}

int temp;
temp=temp;
temp=b;
b=temp;

//Write your own strcat() function
Here is a C function which implements the strcat() function...
/* Function to concatenate string t to end of s; return s */
char *myStrcat(char *s, const char *t)
{
    char *p = s;
    if (s == NULL || t == NULL)
    return s; /* we need not have to do anything */
    
    while (*s) s++;
    
    while (*s++ = *t++);
    
    return p;
}

//Write a C program to implement your own strdup() function.
Here is a C program to implement the strdup() function.
char *mystrdup(char *s)
{
    char *result = (char*)malloc(strlen(s) + 1);
    if (result == (char*)0){return (char*)0;}
    strcpy(result, s);
    return result;
}

// ascii
A-Z - 65-90
a-z - 97-122
0-9 48-57

// file copy operation
Write your own copy() function
Here is some C code that simulates a file copy action.
#include <stdio.h> /* standard I/O routines. */
#define MAX_LINE_LEN 1000 /* maximum line length supported. */
void main(int argc, char* argv[])
{
    char* file_path_from;
    char* file_path_to;
    FILE* f_from;
    FILE* f_to;
    char buf[MAX_LINE_LEN+1];
    file_path_from = "<something>";
    file_path_to = "<something_else>";
    f_from = fopen(file_path_from, "r");
    
    if (!f_from) {exit(1);}
    f_to = fopen(file_path_to, "w+");
    
    if (!f_to) {exit(1);}
    /* Copy source to target, line by line. */
    
    while (fgets(buf, MAX_LINE_LEN+1, f_from))
    {
        if (fputs(buf, f_to) == EOF){exit(1);}
    }
    
    if (!feof(f_from)){exit(1);}
    
    if (fclose(f_from) == EOF) {exit(1);}
    if (fclose(f_to) == EOF) {exit(1);}
    return(0);
}

//substring
void mySubstr(char *dest, char *src, int position, int length)
{
    while(length > 0)
    {
        *dest = *(src+position);
        dest++;src++;
        length--;
    }
}

// memmove
#include <stdio.h>
#include <stddef.h> // for size_t

void* my_memmove(void* dest, const void* src, size_t n) {
    unsigned char* d = (unsigned char*)dest;
    const unsigned char* s = (const unsigned char*)src;

    // Check if the memory areas overlap
    if (d < s || d >= s + n) {
        // No overlap, copy from start
        while (n--) {
            *d++ = *s++;
        }
    } else {
        // Overlap, copy from end
        d += n;
        s += n;
        while (n--) {
            *(--d) = *(--s);
        }
    }
    
    return dest; // Return pointer to destination
}

int main() {
    char str1[] = "Hello, World!";
    printf("Before memmove: %s\n", str1);
    
    // Example of overlapping memory regions
    my_memmove(str1 - 1, str1, 9); // Move "Hello," to "World!"
    
    printf("After memmove: %s\n", str1 - 1);
    
    return 0;
}

//HW timer example
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TIMERS 10

typedef void (*timer_callback_t)(void);

typedef struct {
    uint32_t duration;       // Duration in milliseconds
    uint32_t start_time;    // Start time in milliseconds
    timer_callback_t callback; // Callback function
    bool active;            // Timer status
} Timer;

static Timer timers[MAX_TIMERS]; // Array of timers
static uint32_t current_time = 0; // Simulated current time in milliseconds

// Function to initialize timers
void init_timers() {
    for (int i = 0; i < MAX_TIMERS; i++) {
        timers[i].active = false;
    }
}

// Function to create a new timer
bool create_timer(uint32_t duration, timer_callback_t callback) {
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (!timers[i].active) {
            timers[i].duration = duration;
            timers[i].start_time = current_time;
            timers[i].callback = callback;
            timers[i].active = true;
            return true;
        }
    }
    return false; // No available timers
}

// Function to simulate the hardware timer interrupt
void hardware_timer_interrupt() {
    current_time++; // Increment simulated time

    for (int i = 0; i < MAX_TIMERS; i++) {
        if (timers[i].active && (current_time - timers[i].start_time >= timers[i].duration)) {
            timers[i].callback(); // Call the associated callback
            timers[i].active = false; // Deactivate the timer
        }
    }
}

// Example callback function for the timer
void my_timer_callback() {
    printf("Timer expired!\n");
}

int main() {
    init_timers(); // Initialize the timer system

    // Create a timer that expires after 5 seconds (5000 ms)
    create_timer(5000, my_timer_callback);

    // Simulate the passage of time with hardware timer interrupts
    for (int i = 0; i < 6000; i++) { // Simulate 6 seconds
        hardware_timer_interrupt();
        usleep(1000); // Sleep for 1 ms to simulate real-time passage
    }

    return 0;
}

// Ringbuffer logic
// when to read? when both are pointing to one location, buffer is empty
if (head != tail) read increament;
// when to write? when head is 1 step back from tail, buffer is full
if (head + 1 != tail) write increamnet;
// head always points to empty location.

// shell expansion routine
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPANSION 256

// Function to perform tilde expansion
char* tilde_expand(const char* input) {
    if (input[0] == '~') {
        const char* home = getenv("HOME");
        if (home) {
            char* expanded = malloc(strlen(home) + strlen(input));
            sprintf(expanded, "%s%s", home, input + 1);
            return expanded;
        }
    }
    return strdup(input); // No tilde to expand
}

// Function to perform brace expansion
void brace_expand(const char* input) {
    char* start = strchr(input, '{');
    char* end = strchr(input, '}');

    if (start && end && start < end) {
        // Extract preamble and postscript
        size_t pre_len = start - input;
        size_t post_len = strlen(end + 1);
        char preamble[MAX_EXPANSION];
        char postscript[MAX_EXPANSION];
        
        strncpy(preamble, input, pre_len);
        preamble[pre_len] = '\0';
        strncpy(postscript, end + 1, post_len);
        postscript[post_len] = '\0';

        // Extract options between braces
        char* options = strndup(start + 1, end - start - 1);
        char* token = strtok(options, ",");
        
        while (token) {
            printf("%s%s%s\n", preamble, token, postscript);
            token = strtok(NULL, ",");
        }
        
        free(options);
    } else {
        printf("%s\n", input); // No braces to expand
    }
}

// Main function to demonstrate expansions
int main() {
    const char* test_tilde = "~/.bashrc";
    const char* test_brace = "file{1,2,3}.txt";

    // Tilde Expansion
    char* expanded_tilde = tilde_expand(test_tilde);
    printf("Tilde Expansion: %s\n", expanded_tilde);
    free(expanded_tilde);

    // Brace Expansion
    printf("Brace Expansion:\n");
    brace_expand(test_brace);

    return 0;
}


// RR scheduler
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void round_robin(Process processes[], int n) {
    int time = 0, done = 0;
    int queue[MAX_PROCESSES], front = 0, rear = 0;

    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > TIME_QUANTUM) {
                    time += TIME_QUANTUM;
                    processes[i].remaining_time -= TIME_QUANTUM;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].completion_time = time;
                    done++;
                }
                
                // Add process back to queue if not finished
                if (processes[i].remaining_time > 0) {
                    queue[rear] = i;
                    rear = (rear + 1) % MAX_PROCESSES;
                }
            }
        }
        
        // If no process is ready, increment time
        if (front == rear) {
            time++;
        }
    }

    // Calculate turnaround time and waiting time
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

int main() {
    int n;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    round_robin(processes, n);

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].id, processes[i].turnaround_time, processes[i].waiting_time);
    }

    return 0;
}

    
//LRU cache

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct LRUCache {
    int capacity;
    int size;
    Node* head; // Most recently used
    Node* tail; // Least recently used
    Node** hashMap; // HashMap for O(1) access
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
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    
    // Allocate hash map with a size of 1000 (this can be adjusted)
    cache->hashMap = (Node**)malloc(sizeof(Node*) * 1000);
    for (int i = 0; i < 1000; i++) {
        cache->hashMap[i] = NULL; // Initialize hash map entries to NULL
    }
    
    return cache;
}

// Function to remove a node from the linked list
void removeNode(LRUCache* cache, Node* node) {
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        cache->head = node->next; // Update head if it's the first node
    }
    
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        cache->tail = node->prev; // Update tail if it's the last node
    }
    
    free(node);
}

// Function to add a node to the front of the linked list
void addToFront(LRUCache* cache, Node* node) {
    node->next = cache->head;
    
    if (cache->head != NULL) {
        cache->head->prev = node;
    }
    
    cache->head = node;

    if (cache->tail == NULL) {
        cache->tail = node; // If it's the first node, update tail as well
    }
    
    node->prev = NULL; // New head has no previous node
}

// Function to get a value from the cache
int get(LRUCache* cache, int key) {
    int index = key % 1000; // Simple hash function for demonstration
    Node* node = cache->hashMap[index];

    if (!node) return -1; // Key not found

    // Move accessed node to front of the linked list
    removeNode(cache, node);
    addToFront(cache, node);

    return node->value; // Return the value associated with the key
}

// Function to put a key-value pair into the cache
void put(LRUCache* cache, int key, int value) {
    int index = key % 1000; // Simple hash function for demonstration

    // Check if the key already exists in the hash map
    Node* existingNode = cache->hashMap[index];
    
    if (existingNode) {
        existingNode->value = value; // Update value
        removeNode(cache, existingNode); // Remove from current position
        addToFront(cache, existingNode); // Move to front as most recently used
        return;
    }

    // Create a new node if it doesn't exist
    Node* newNode = createNode(key, value);
    
    if (cache->size >= cache->capacity) { // Cache is full
        // Remove least recently used item from tail
        Node* lruNode = cache->tail;
        removeNode(cache, lruNode);
        
        // Remove from hash map as well
        cache->hashMap[lruNode->key % 1000] = NULL; 
        free(lruNode); 
        cache->size--;
    }

   // Add new node to front of linked list and update hash map 
   addToFront(cache, newNode);
   cache->hashMap[index] = newNode; 
   cache->size++;
}

// Function to free memory allocated for the LRU Cache
void freeCache(LRUCache* cache) {
   Node* current = cache->head;

   while (current != NULL) {
       Node* next_node = current->next;
       free(current);
       current = next_node;
   }

   free(cache->hashMap);
   free(cache);
}

// Test the LRU Cache implementation
int main() {
   LRUCache* lruCache = createCache(2); // Create an LRU Cache with capacity of 2

   put(lruCache, 1, 1); // Cache is {1=1}
   put(lruCache, 2, 2); // Cache is {1=1, 2=2}
   
   printf("Get key 1: %d\n", get(lruCache, 1)); // Returns 1 and moves key 1 to front

   put(lruCache, 3, 3); // Evicts key 2 and adds key 3. Cache is {1=1, 3=3}
   
   printf("Get key 2: %d\n", get(lruCache, 2)); // Returns -1 (not found)

   put(lruCache, 4, 4); // Evicts key 1 and adds key 4. Cache is {3=3, 4=4}

   printf("Get key 1: %d\n", get(lruCache, 1)); // Returns -1 (not found)
   printf("Get key 3: %d\n", get(lruCache, 3)); // Returns 3
   printf("Get key 4: %d\n", get(lruCache, 4)); // Returns 4

   freeCache(lruCache); // Free memory allocated for the cache

   return 0;
}

```

// 64bit timer using 32bit timer
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

typedef struct {
    uint32_t lower;      // Lower 32 bits
    uint32_t upper;      // Upper 32 bits (overflow count)
    uint32_t timeout;    // Timeout in microseconds
    void (*callback)(void); // Callback function
} Timer64;

// Global timer variable
Timer64 myTimer;

// Function to call when the timer expires
void timerCallback() {
    printf("Timer expired! Callback executed.\n");
}

// Timer handler for simulating the timer expiration
void timerHandler(int signum) {
    myTimer.lower++;
    if (myTimer.lower == 0) { // Check for overflow
        myTimer.upper++;
    }

    // Check if the timeout has been reached
    if ((myTimer.upper * (UINT32_MAX + 1) + myTimer.lower) >= myTimer.timeout) {
        myTimer.callback(); // Call the callback function
        exit(0); // Exit after callback for demonstration purposes
    }
}

// Function to initialize and start the timer
void startTimer(uint32_t timeoutMicroseconds, void (*callback)(void)) {
    myTimer.lower = 0;
    myTimer.upper = 0;
    myTimer.timeout = timeoutMicroseconds;
    myTimer.callback = callback;

    // Set up the signal handler for the timer
    signal(SIGALRM, timerHandler);
    
    // Set up a timer to trigger every microsecond
    struct itimerval it_val;
    it_val.it_value.tv_sec = 0;
    it_val.it_value.tv_usec = 1; // Trigger every microsecond
    it_val.it_interval.tv_sec = 0;
    it_val.it_interval.tv_usec = 1; // Repeat every microsecond

    setitimer(ITIMER_REAL, &it_val, NULL);
}

int main() {
    printf("Starting 64-bit Timer...\n");
    
    // Start the timer for 5 seconds (5,000,000 microseconds)
    startTimer(5000000, timerCallback);
    
    // Keep the program running to allow the timer to work
    while (1) {
        pause(); // Wait for signals (timer events)
    }

    return 0;
}
    
// traffic light

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function

// Define the states of the traffic light
typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;

// Function prototypes
void trafficLightInit();
void trafficLightRun();
void trafficLightChangeState(TrafficLightState newState);
void displayTrafficLightState(TrafficLightState state);

// Global variable to hold the current state of the traffic light
TrafficLightState currentState;

// Main function
int main() {
    // Initialize the traffic light
    trafficLightInit();

    // Run the traffic light state machine
    trafficLightRun();

    return 0;
}

// Function to initialize the traffic light state machine
void trafficLightInit() {
    currentState = RED; // Start with RED light
}

// Function to run the traffic light state machine
void trafficLightRun() {
    while (1) {
        switch (currentState) {
            case RED:
                displayTrafficLightState(RED);
                sleep(5); // Red light duration
                trafficLightChangeState(GREEN);
                break;

            case GREEN:
                displayTrafficLightState(GREEN);
                sleep(5); // Green light duration
                trafficLightChangeState(YELLOW);
                break;

            case YELLOW:
                displayTrafficLightState(YELLOW);
                sleep(2); // Yellow light duration
                trafficLightChangeState(RED);
                break;

            default:
                fprintf(stderr, "Error: Invalid Traffic Light State\n");
                exit(EXIT_FAILURE);
        }
    }
}

// Function to change the state of the traffic light
void trafficLightChangeState(TrafficLightState newState) {
    currentState = newState;
}

// Function to display the current state of the traffic light
void displayTrafficLightState(TrafficLightState state) {
    switch (state) {
        case RED:
            printf("Traffic Light is RED\n");
            break;
        case GREEN:
            printf("Traffic Light is GREEN\n");
            break;
        case YELLOW:
            printf("Traffic Light is YELLOW\n");
            break;
        default:
            fprintf(stderr, "Error: Invalid Traffic Light State\n");
            exit(EXIT_FAILURE);
    }
}

```

// bitwise logics

#include <stdio.h>

// exactly one bit is set, to check if number is power of 2 or not
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Swap odd and even bits
// get even bits in var1, get odd bits in var2
// make 
unsigned int swapOddEvenBits(unsigned int n) {
    unsigned int evenBits = n & 0xAAAAAAAA;
    unsigned int oddBits = n & 0x55555555;
    evenBits >>= 1;
    oddBits <<= 1;
    return (evenBits | oddBits);
}

//find the right most position of the bit
// n & -n -- 2s complemnet leave right most bit intact. ending will result in
// only 1 bit set and log will give position for this.
int rightmostSetBitPosition(int n) {
    return log2(n & -n) + 1;
}


int main(){
    int num = 45, result = num;
    printf("\ngiven number is %d", num);
    result = num ^ 0xff;
    printf("\nend result is %d", result);


    //reverse logic
    // test last bit, and add in result, shift result left,
    // shift number left. (test bit and add to result and shift left)
    num = 2;
    result = 0;
    printf("\ngiven number is %x", num);
    for (int i = 0; i < 32; i++) {
        result |= (num & 1);
        result <<= 1;
        num >>= 1;
    }
    printf("\nend result number is %x", result);


}

/*
Chat GPT prompt:
#1 (1st 20 qna)
I loved these explanation. You are smart. See, as you come up with this solution, can you come up with such programs where user application can use hardware or kernel resources in some ways? This are actual real life embedded system problems which embedded engineers are expected to well versed about. Give me such problems for my embedded coding interviews which uses concept of scheduling, deadlock scenario, race conditions, data structures, etc. Give me list of 20 such famous problems and what kind of embedded concepts are used in it, and then provide comprehensive solution for each, after providing list.

#2 (2nd 20 qna)
I liked this list very much, but can you please provide 20 more such questions, but consider to ignore peripheral protocol related problems, and more to include very low level problems which includes deep OS concepts like scheduling, cache etc
*/

/*
1. Blinking LED with Timer Interrupts
Concepts: Timer interrupts, GPIO control

Problem: Implement a program that blinks an LED at a fixed interval using a hardware timer interrupt.
*/

#include <stdint.h>
#include <stdbool.h>

#define LED_PIN 13

void TimerISR(void) {
    static bool led_state = false;
    led_state = !led_state;
    if (led_state) {
        // Turn on LED
        GPIO_SetPin(LED_PIN);
    } else {
        // Turn off LED
        GPIO_ClearPin(LED_PIN);
    }
}

/*
2. UART Communication with Circular Buffer
Concepts: UART, circular buffer, interrupt handling

Problem: Implement UART communication using a circular buffer to handle incoming and outgoing data.
*/

#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 128

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
} CircularBuffer;

CircularBuffer tx_buffer;
CircularBuffer rx_buffer;

void UART_ISR(void) {
    if (UART_ReceiveInterruptFlag()) {
        uint8_t data = UART_Read();
        rx_buffer.buffer[rx_buffer.head] = data;
        rx_buffer.head = (rx_buffer.head + 1) % BUFFER_SIZE;
    }
    if (UART_TransmitInterruptFlag()) {
        if (tx_buffer.head != tx_buffer.tail) {
            UART_Write(tx_buffer.buffer[tx_buffer.tail]);
            tx_buffer.tail = (tx_buffer.tail + 1) % BUFFER_SIZE;
        }```c
        }
    }
}

void UART_Send(uint8_t data) {
    tx_buffer.buffer[tx_buffer.head] = data;
    tx_buffer.head = (tx_buffer.head + 1) % BUFFER_SIZE;
    UART_EnableTransmitInterrupt();
}

uint8_t UART_Receive(void) {
    uint8_t data = rx_buffer.buffer[rx_buffer.tail];
    rx_buffer.tail = (rx_buffer.tail + 1) % BUFFER_SIZE;
    return data;
}

void InitUART(void) {
    // Initialize UART hardware and enable interrupts
}

int main(void) {
    InitUART();
    while (1) {
        // Main loop
    }
    return 0;
}

/*
3. Task Scheduling with Round-Robin Algorithm
Concepts: Task scheduling, round-robin algorithm, context switching

Problem: Implement a simple round-robin scheduler to manage multiple tasks.
 */
#include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 5

typedef void (*TaskFunction)(void);

typedef struct {
    TaskFunction task;
    uint32_t period;
    uint32_t remaining_time;
} Task;

Task tasks[MAX_TASKS];
uint8_t current_task = 0;

void SchedulerISR(void) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].remaining_time > 0) {
            tasks[i].remaining_time--;
            if (tasks[i].remaining_time == 0) {
                tasks[i].task();
                tasks[i].remaining_time = tasks[i].period;
            }
        }
    }
}

void AddTask(TaskFunction task, uint32_t period) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].task == NULL) {
            tasks[i].task = task;
            tasks[i].period = period;
            tasks[i].remaining_time = period;
            break;
        }
    }
}

void InitScheduler(void) {
    // Configure the hardware timer to generate an interrupt at a regular interval
}

int main(void) {
    InitScheduler();
    AddTask(Task1, 1000);
    AddTask(Task2, 2000);
    while (1) {
        // Main loop
    }
    return 0;
}

  
  /*
4. Priority Inversion in Real-Time Systems
Concepts: Priority inversion, real-time scheduling, mutex

Problem: Implement a solution to handle priority inversion using priority inheritance.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

pthread_mutex_t resource_mutex;
int resource;

void LowPriorityTask(void) {
    pthread_mutex_lock(&resource_mutex);
    // Access shared resource
    resource++;
    pthread_mutex_unlock(&resource_mutex);
}

void MediumPriorityTask(void) {
    // Perform some work
}

void HighPriorityTask(void) {
    pthread_mutex_lock(&resource_mutex);
    // Access shared resource
    resource--;
    pthread_mutex_unlock(&resource_mutex);
}

int main(void) {
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);
    pthread_mutex_init(&resource_mutex, &attr);

    // Create and start tasks
    pthread_create(&low_priority_thread, NULL, LowPriorityTask, NULL);
    pthread_create(&medium_priority_thread, NULL, MediumPriorityTask, NULL);
    pthread_create(&high_priority_thread, NULL, HighPriorityTask, NULL);

    while (1) {
        // Main loop
    }
    return 0;
}

/*
5. Producer-Consumer Problem with Semaphores
Concepts: Semaphores, synchronization, shared resources

Problem: Implement the producer-consumer problem using semaphores to synchronize access to a shared buffer.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;
sem_t full;
pthread_mutex_t buffer_mutex;

void *Producer(void *arg) {
    while (1) {
        int item = ProduceItem();
        sem_wait(&empty);
        pthread_mutex_lock(&buffer_mutex);
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&full);
    }
}

void *Consumer(void *arg) {
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&buffer_mutex);
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
       ```c
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&empty);
        ConsumeItem(item);
    }
}

int main(void) {
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&buffer_mutex, NULL);

    pthread_create(&producer_thread, NULL, Producer, NULL);
    pthread_create(&consumer_thread, NULL, Consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}

/*
6. Deadlock Detection and Avoidance
Concepts: Deadlock detection, resource allocation graph, avoidance algorithms

Problem: Implement a system to detect and avoid deadlocks using the Banker's algorithm.
 */
#include <stdbool.h>
#include <stdio.h>

#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

int available[NUM_RESOURCES] = {3, 3, 2};
int maximum[NUM_PROCESSES][NUM_RESOURCES] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};
int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int need[NUM_PROCESSES][NUM_RESOURCES];

void CalculateNeed() {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

bool IsSafe() {
    int work[NUM_RESOURCES];
    bool finish[NUM_PROCESSES] = {false};

    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    while (true) {
        bool found = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (!finish[i]) {
            return false;
        }
    }
    return true;
}

bool RequestResources(int process_id, int request[]) {
    for (int i = 0; i < NUM_RESOURCES; i++) {
        if (request[i] > need[process_id][i]) {
            return false;
        }
        if (request[i] > available[i]) {
            return false;
        }
    }

    for (int i = 0; i < NUM_RESOURCES; i++) {
        available[i] -= request[i];
        allocation[process_id][i] += request[i];
        need[process_id][i] -= request[i];
    }

    if (IsSafe()) {
        return true;
    } else {
        for (int i = 0; i < NUM_RESOURCES; i++) {
            available[i] += request[i];
            allocation[process_id][i] -= request[i];
            need[process_id][i] += request[i];
        }
        return false;
    }
}

int main(void) {
    CalculateNeed();

    int request1[] = {1, 0, 2};
    if (RequestResources(1, request1)) {
        printf("Request granted.\n");
    } else {
        printf("Request denied.\n");
    }

    return 0;
}

/*
7. Race Condition in Shared Memory Access
Concepts: Race condition, critical section, mutex

Problem: Implement a solution to prevent race conditions when accessing shared memory.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

```c
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

int shared_data = 0;
pthread_mutex_t data_mutex;

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&data_mutex);
        shared_data++;
        pthread_mutex_unlock(&data_mutex);
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&data_mutex);
        shared_data--;
        pthread_mutex_unlock(&data_mutex);
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    pthread_mutex_init(&data_mutex, NULL);

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    pthread_mutex_destroy(&data_mutex);
    return 0;
}

/*
8. Implementing a Software Watchdog Timer
Concepts: Watchdog timer, system reliability, timer interrupts

Problem: Implement a software watchdog timer that resets the system if the main loop becomes unresponsive.
 */
#include <stdint.h>
#include <stdbool.h>

volatile bool watchdog_reset = false;

void WatchdogISR(void) {
    if (!watchdog_reset) {
        // Reset the system
        SystemReset();
    }
    watchdog_reset = false;
}

void InitWatchdogTimer(void) {
    // Configure the hardware timer to generate an interrupt at a regular interval
}

void ResetWatchdog(void) {
    watchdog_reset = true;
}

int main(void) {
    InitWatchdogTimer();
    while (1) {
        // Main loop
        ResetWatchdog();
    }
    return 0;
}

/*
9. Memory Management with Dynamic Allocation
Concepts: Dynamic memory allocation, fragmentation, memory pools

Problem: Implement a memory pool allocator to manage dynamic memory allocation efficiently.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define POOL_SIZE 1024
#define BLOCK_SIZE 32

uint8_t memory_pool[POOL_SIZE];
bool block_used[POOL_SIZE / BLOCK_SIZE];

void *AllocateBlock(void) {
    for (int i = 0; i < POOL_SIZE / BLOCK_SIZE; i++) {
        if (!block_used[i]) {
            block_used[i] = true;
            return &memory_pool[i * BLOCK_SIZE];
        }
    }
    return NULL; // No available blocks
}

void FreeBlock(void *block) {
    int index = ((uint8_t *)block - memory_pool) / BLOCK_SIZE;
    block_used[index] = false;
}

int main(void) {
    void *block1 = AllocateBlock();
    void *block2 = AllocateBlock();
    FreeBlock(block1);
    void *block3 = AllocateBlock();
    return 0;
}

/*
10. Inter-Process Communication with Message Queues
Concepts: IPC, message queues, synchronization

Problem: Implement inter-process communication using message queues to exchange data between tasks.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <mqueue.h>

#define QUEUE_NAME "/message_queue"
#define MAX_MESSAGES 10
#define MAX_MESSAGE_SIZE 256

mqd_t mq;

void *SenderTask(void *arg) {
    char message[MAX_MESSAGE_SIZE] = "Hello, World!";
    while (1) {
        mq_send(mq, message, sizeof(message), 0);
        sleep(1);
    }
    return NULL;
}

void *ReceiverTask(void *arg) {
    char message[MAX_MESSAGE_SIZE];
    while (1) {
        mq_receive(mq, message, sizeof(message), NULL);
        printf("Received message: %s\n", message);
    }
    return NULL;
}

int main(void) {
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MESSAGE_SIZE;
    attr.mq_curmsgs = 0;

    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);

    pthread_t sender_thread, receiver_thread;
    pthread_create(&sender_thread, NULL, SenderTask, NULL);
    pthread_create(&receiver_thread, NULL, ReceiverTask, NULL);

    pthread_join(sender_thread, NULL);
    pthread_join(receiver_thread, NULL);

    mq_close(mq);
```c
    mq_unlink(QUEUE_NAME);
    return 0;
}

/*
11. Real-Time Clock (RTC) Implementation
Concepts: RTC, timekeeping, low-power modes

Problem: Implement a real-time clock (RTC) to keep track of the current time and date.
 */
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

struct tm current_time;

void RTCISR(void) {
    // Update the current time
    current_time.tm_sec++;
    if (current_time.tm_sec >= 60) {
        current_time.tm_sec = 0;
        current_time.tm_min++;
        if (current_time.tm_min >= 60) {
            current_time.tm_min = 0;
            current_time.tm_hour++;
            if (current_time.tm_hour >= 24) {
                current_time.tm_hour = 0;
                current_time.tm_mday++;
                // Handle month and year changes
            }
        }
    }
}

void InitRTC(void) {
    // Configure the RTC hardware to generate an interrupt every second
}

int main(void) {
    InitRTC();
    while (1) {
        // Main loop
    }
    return 0;
}

/*
12. I2C Communication with Multiple Slaves
Concepts: I2C protocol, multi-master, multi-slave communication

Problem: Implement I2C communication to interface with multiple slave devices.
 */
#include <stdint.h>
#include <stdbool.h>

#define I2C_ADDRESS_SLAVE1 0x50
#define I2C_ADDRESS_SLAVE2 0x60

void I2C_Write(uint8_t slave_address, uint8_t *data, uint8_t length) {
    // Implement I2C write operation
}

void I2C_Read(uint8_t slave_address, uint8_t *data, uint8_t length) {
    // Implement I2C read operation
}

int main(void) {
    uint8_t data_to_write[] = {0x01, 0x02, 0x03};
    uint8_t data_to_read[3];

    I2C_Write(I2C_ADDRESS_SLAVE1, data_to_write, sizeof(data_to_write));
    I2C_Read(I2C_ADDRESS_SLAVE2, data_to_read, sizeof(data_to_read));

    while (1) {
        // Main loop
    }
    return 0;
}

/*
13. SPI Communication with DMA
Concepts: SPI protocol, DMA, data transfer efficiency

Problem: Implement SPI communication using DMA to transfer data efficiently.
 */
#include <stdint.h>
#include <stdbool.h>

#define SPI_BUFFER_SIZE 256

uint8_t spi_tx_buffer[SPI_BUFFER_SIZE];
uint8_t spi_rx_buffer[SPI_BUFFER_SIZE];

void InitSPI(void) {
    // Configure SPI hardware
}

void InitDMA(void) {
    // Configure DMA for SPI data transfer
}

void StartSPITransfer(void) {
    // Start SPI data transfer using DMA
}

int main(void) {
    InitSPI();
    InitDMA();

    // Fill the transmit buffer with data
    for (int i = 0; i < SPI_BUFFER_SIZE; i++) {
        spi_tx_buffer[i] = i;
    }

    StartSPITransfer();

    while (1) {
        // Main loop
    }
    return 0;
}

/*
14. Implementing a Finite State Machine (FSM)
Concepts: FSM, state transitions, event handling

Problem: Implement a finite state machine to control a simple traffic light system.
 */
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    STATE_RED,
    STATE_GREEN,
    STATE_YELLOW
} TrafficLightState;

TrafficLightState current_state = STATE_RED;

void TrafficLightFSM(void) {
    switch (current_state) {
        case STATE_RED:
            // Turn on red light
            if (/* condition to change to green */) {
                current_state = STATE_GREEN;
            }
            break;
        case STATE_GREEN:
            // Turn on green light
            if (/* condition to change to yellow */) {
                current_state = STATE_YELLOW;
            }
            break;
        case STATE_YELLOW:
            // Turn on yellow light
            if (/* condition to change to red */) {
                current_state = STATE_RED;
            }
            break;
    }
}

int main(void) {
    while (1) {
        TrafficLightFSM();
        // Delay to simulate time passing
    }
    return 0;
}

/*
15. Handling Multiple ADC Channels
Concepts: ADC, multiplexing, data acquisition

Problem: Implement a system to read data from multiple ADC channels and process the data.
 */
#include <stdint.h>
#include <stdbool.h>

#define NUM_ADC_CHANNELS 4

uint16_t adc_values[NUM_ADC_CHANNELS];

void ADCISR(void) {
    static uint8_t current_channel = 0;
    adc_values[current_channel] = ADC_Read(current_channel);
    current_channel = (current_channel + 1) % NUM_ADC_CHANNELS;
    ADC_StartConversion(current_channel);
}

void InitADC(void) {
    // Configure ADC hardware and enable interrupts
    ADC_StartConversion(0);
}

int main(void) {
    InitADC();
    while (1) {
        // Process ADC values
    }
    return 0;
}

/*
16. PWM Signal Generation for Motor Control
Concepts: PWM, motor control, duty cycle adjustment

Problem: Implement PWM signal generation to control the speed of a motor.
 */
#include <stdint.h>
#include <stdbool.h>

#define PWM_FREQUENCY 1000 // 1 kHz

void SetPWMDutyCycle(uint8_t duty_cycle) {
    // Set the PWM duty cycle (0-100%)
}

void InitPWM(void) {
    // Configure PWM hardware
}

int main(void) {
    InitPWM();
    while (1) {
        for (uint8_t duty_cycle = 0; duty_cycle <= 100; duty_cycle++) {
            SetPWMDutyCycle(duty_cycle);
            // Delay to observe the change in motor speed
        }
    }
    return 0;
}

/*
17. Implementing a Circular Buffer for Data Logging
Concepts: Circular buffer, data logging, memory management

Problem: Implement a circular buffer to log data efficiently.
 */
#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 128

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
} CircularBuffer;

CircularBuffer log_buffer;

void LogData(uint8_t data) {
    log_buffer.buffer[log_buffer.head] = data;
    log_buffer.head = (log_buffer.head + 1) % BUFFER_SIZE;
    if (log_buffer.head == log_buffer.tail) {
        log_buffer.tail = (log_buffer.tail + 1) % BUFFER_SIZE; // Overwrite oldest data
    }
}

uint8_t ReadLog(void) {
    if (log_buffer.head == log_buffer.tail) {
        return 0; // Buffer is empty
    }
    uint8_t data = log_buffer.buffer[log_buffer.tail];
    log_buffer.tail = (log_buffer.tail + 1) % BUFFER_SIZE;
    return data;
}

int main(void) {
    while (1) {
        // Log data and read log
    }
    return 0;
}

/*
19. Implementing a Bootloader
Concepts: Bootloader, firmware update, memory management

Problem: Implement a bootloader to update firmware over UART.
 */
#include <stdint.h>
#include <stdbool.h>

#define FIRMWARE_START_ADDRESS 0x08004000

void UART_ReceiveFirmware(void) {
    // Receive firmware data over UART and write to flash memory
}

void JumpToFirmware(void) {
    void (*firmware_start)(void) = (void (*)(void))(*(uint32_t *)(FIRMWARE_START_ADDRESS + 4));
    __set_MSP(*(uint32_t *)FIRMWARE_START_ADDRESS);
    firmware_start();
}

int main(void) {
    UART_ReceiveFirmware();
    JumpToFirmware();
    while (1) {
        // Main loop
    }
    return 0;
}

/*
20. Handling External Interrupts with Debouncing
Concepts: External interrupts, debouncing, GPIO

Problem: Implement a system to handle external interrupts withdebouncing.
 */
#include <stdint.h>
#include <stdbool.h>

#define DEBOUNCE_DELAY 50 // 50 milliseconds

volatile bool button_pressed = false;
volatile uint32_t last_interrupt_time = 0;

void ExternalInterruptISR(void) {
    uint32_t current_time = GetSystemTime();
    if ((current_time - last_interrupt_time) > DEBOUNCE_DELAY) {
        button_pressed = true;
        last_interrupt_time = current_time;
    }
}

void InitExternalInterrupt(void) {
    // Configure external interrupt and enable it
}

int main(void) {
    InitExternalInterrupt();
    while (1) {
        if (button_pressed) {
            // Handle button press
            button_pressed = false;
        }
    }
    return 0;
}

/*
1. Implementing a Round-Robin Scheduler
Concepts: Task scheduling, round-robin algorithm, context switching

Problem: Implement a simple round-robin scheduler to manage multiple tasks.
 */
 #include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 5

typedef void (*TaskFunction)(void);

typedef struct {
    TaskFunction task;
    uint32_t period;
    uint32_t remaining_time;
} Task;

Task tasks[MAX_TASKS];
uint8_t current_task = 0;

void SchedulerISR(void) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].remaining_time > 0) {
            tasks[i].remaining_time--;
            if (tasks[i].remaining_time == 0) {
                tasks[i].task();
                tasks[i].remaining_time = tasks[i].period;
            }
        }
    }
}

void AddTask(TaskFunction task, uint32_t period) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].task == NULL) {
            tasks[i].task = task;
            tasks[i].period = period;
            tasks[i].remaining_time = period;
            break;
        }
    }
}

void InitScheduler(void) {
    // Configure the hardware timer to generate an interrupt at a regular interval
}

int main(void) {
    InitScheduler();
    AddTask(Task1, 1000);
    AddTask(Task2, 2000);
    while (1) {
        // Main loop
    }
    return 0;
}
/*
2. Priority-Based Preemptive Scheduler
Concepts: Priority scheduling, preemption, context switching

Problem: Implement a priority-based preemptive scheduler to manage multiple tasks.
 */
#include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 5

typedef void (*TaskFunction)(void);

typedef struct {
    TaskFunction task;
    uint32_t period;
    uint32```c
#include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 5

typedef void (*TaskFunction)(void);

typedef struct {
    TaskFunction task;
    uint32_t period;
    uint32_t remaining_time;
    uint8_t priority;
    bool active;
} Task;

Task tasks[MAX_TASKS];

void SchedulerISR(void) {
    uint8_t highest_priority = 255;
    int highest_priority_task = -1;

    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].active && tasks[i].remaining_time > 0) {
            tasks[i].remaining_time--;
            if (tasks[i].remaining_time == 0) {
                tasks[i].remaining_time = tasks[i].period;
                if (tasks[i].priority < highest_priority) {
                    highest_priority = tasks[i].priority;
                    highest_priority_task = i;
                }
            }
        }
    }

    if (highest_priority_task != -1) {
        tasks[highest_priority_task].task();
    }
}

void AddTask(TaskFunction task, uint32_t period, uint8_t priority) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (!tasks[i].active) {
            tasks[i].task = task;
            tasks[i].period = period;
            tasks[i].remaining_time = period;
            tasks[i].priority = priority;
            tasks[i].active = true;
            break;
        }
    }
}

void InitScheduler(void) {
    // Configure the hardware timer to generate an interrupt at a regular interval
}

int main(void) {
    InitScheduler();
    AddTask(Task1, 1000, 1);
    AddTask(Task2, 2000, 2);
    while (1) {
        // Main loop
    }
    return 0;
}
/*
3. Implementing a Mutex for Synchronization
Concepts: Mutex, critical section, synchronization

Problem: Implement a mutex to protect a critical section in a multi-threaded environment.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

pthread_mutex_t mutex;
int shared_data = 0;

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&mutex);
        shared_data++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&mutex);
        shared_data--;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    pthread_mutex_destroy(&mutex);
    return 0;
}
/*
4. Semaphore-Based Synchronization
Concepts: Semaphores, synchronization, inter-process communication

Problem: Implement semaphore-based synchronization to manage access to a shared resource.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;
int shared_data = 0;

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        sem_wait(&semaphore);
        shared_data++;
        sem_post(&semaphore);
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        sem_wait(&semaphore);
        shared_data--;
        sem_post(&semaphore);
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    sem_init(&semaphore, 0, 1);

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    sem_destroy(&semaphore);
    return 0;
}
/*
5. Implementing a Spinlock
Concepts: Spinlock, busy-waiting, synchronization

Problem: Implement a spinlock to protect a critical section in a multi-threaded environment.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

volatile bool lock = false;

void SpinlockAcquire(void) {
    while (__sync_lock_test_and_set(&lock, 1)) {
        // Busy-wait until the lock is acquired
    }
}

void SpinlockRelease(void) {
    __sync_lock_release(&lock);
}

int shared_data = 0;

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        SpinlockAcquire();
        shared_data++;
        SpinlockRelease();
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        SpinlockAcquire();
        shared_data--;
        SpinlockRelease();
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    return 0;
}
/*
6. Cache Coherence in Multi-Core Systems
Concepts: Cache coherence, multi-core, memory consistency

Problem: Implement a mechanism to ensure cache coherence in a multi-core system.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

volatile int shared_data = 0;

void *Core1Task(void *arg) {
    for (int i = 0; i < 1000; i++) {
        __sync_fetch_and_add(&shared_data, 1);
    }
    return NULL;
}

void *Core2Task(void *arg) {
    for (int i = 0; i < 1000; i++) {
        __sync_fetch_and_sub(&shared_data, 1);
    }
    return NULL;
}

int main(void) {
    pthread_t core1_thread, core2_thread;

    pthread_create(&core1_thread, NULL, Core1Task, NULL);
    pthread_create(&core2_thread, NULL, Core2Task, NULL);

    pthread_join(core1_thread, NULL);
    pthread_join(core2_thread, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    return 0;
}
/*
7. Implementing a Memory Barrier
Concepts: Memory barrier, instruction ordering, synchronization

Problem: Implement a memory barrier to ensure proper instruction ordering in a multi-core system.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

volatile int shared_data = 0;
volatile bool flag = false;

void MemoryBarrier(void) {
    __sync_synchronize();
}

void *ProducerTask(void *arg) {
    shared_data = 42;
    MemoryBarrier();
    flag = true;
    return NULL;
}

void *ConsumerTask(void *arg) {
    while (!flag) {
        // Busy-wait until flag is set
    }
    MemoryBarrier();
    printf("Shared data: %d\n", shared_data);
    return NULL;
}

int main(void) {
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, ProducerTask, NULL);
    pthread_create(&consumer_thread, NULL, ConsumerTask, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
/*
8. Page Replacement Algorithms
Concepts: Memory management, page replacement, algorithms

Problem: Implement the Least Recently Used (LRU) page replacement algorithm.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define NUM_PAGES 4
#define NUM_FRAMES 3

int pages[NUM_PAGES] = {1, 2, 3, 4};
int frames[NUM_FRAMES] = {-1, -1, -1};
int lru[NUM_FRAMES] = {0, 0, 0};

int FindLRU(void) {
    int min = lru[0], pos = 0;
    for (int i = 1; i < NUM_FRAMES; i++) {
        if (lru[i] < min) {
            min = lru[i];
            pos = i;
        }
    }
    return pos;
}

void PageReplacement(void) {
    int page_faults = 0;
    for (int i = 0; i < NUM_PAGES; i++) {
        int page =```c
        pages[i];
        bool found = false;
        for (int j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == page) {
                found = true;
                lru[j] = i;
                break;
            }
        }
        if (!found) {
            int pos = FindLRU();
            frames[pos] = page;
            lru[pos] = i;
            page_faults++;
        }
    }
    printf("Page faults: %d\n", page_faults);
}

int main(void) {
    PageReplacement();
    return 0;
}
/*
9. Implementing a Simple Virtual Memory System
Concepts: Virtual memory, paging, memory management

Problem: Implement a simple virtual memory system with paging.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 16
#define NUM_FRAMES 4

typedef struct {
    int frame_number;
    bool valid;
} PageTableEntry;

PageTableEntry page_table[NUM_PAGES];
int frames[NUM_FRAMES] = {-1, -1, -1, -1};

int AllocateFrame(void) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (frames[i] == -1) {
            return i;
        }
    }
    return -1; // No available frames
}

void AccessMemory(int virtual_address) {
    int page_number = virtual_address / PAGE_SIZE;
    int offset = virtual_address % PAGE_SIZE;

    if (!page_table[page_number].valid) {
        int frame_number = AllocateFrame();
        if (frame_number == -1) {
            printf("Page fault: No available frames\n");
            return;
        }
        page_table[page_number].frame_number = frame_number;
        page_table[page_number].valid = true;
        frames[frame_number] = page_number;
    }

    int physical_address = page_table[page_number].frame_number * PAGE_SIZE + offset;
    printf("Virtual address %d maps to physical address %d\n", virtual_address, physical_address);
}

int main(void) {
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i].valid = false;
    }

    AccessMemory(0);
    AccessMemory(4096);
    AccessMemory(8192);
    AccessMemory(12288);
    AccessMemory(16384);

    return 0;
}
/*
10. Handling Page Faults
Concepts: Page faults, memory management, exception handling

Problem: Implement a mechanism to handle page faults in a virtual memory system.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 16
#define NUM_FRAMES 4

typedef struct {
    int frame_number;
    bool valid;
} PageTableEntry;

PageTableEntry page_table[NUM_PAGES];
int frames[NUM_FRAMES] = {-1, -1, -1, -1};

int AllocateFrame(void) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (frames[i] == -1) {
            return i;
        }
    }
    return -1; // No available frames
}

void HandlePageFault(int page_number) {
    int frame_number = AllocateFrame();
    if (frame_number == -1) {
        printf("Page fault: No available frames\n");
        return;
    }
    page_table[page_number].frame_number = frame_number;
    page_table[page_number].valid = true;
    frames[frame_number] = page_number;
}

void AccessMemory(int virtual_address) {
    int page_number = virtual_address / PAGE_SIZE;
    int offset = virtual_address % PAGE_SIZE;

    if (!page_table[page_number].valid) {
        HandlePageFault(page_number);
    }

    int physical_address = page_table[page_number].frame_number * PAGE_SIZE + offset;
    printf("Virtual address %d maps to physical address %d\n", virtual_address, physical_address);
}

int main(void) {
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i].valid = false;
    }

    AccessMemory(0);
    AccessMemory(4096);
    AccessMemory(8192);
    AccessMemory(12288);
    AccessMemory(16384);

    return 0;
}
/*
11. Implementing a Memory Pool Allocator
Concepts: Memory management, dynamic allocation, memory pools

Problem:Implement a memory pool allocator to manage dynamic memory allocation efficiently.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define POOL_SIZE 1024
#define BLOCK_SIZE 32

uint8_t memory_pool[POOL_SIZE];
bool block_used[POOL_SIZE / BLOCK_SIZE];

void *AllocateBlock(void) {
    for (int i = 0; i < POOL_SIZE / BLOCK_SIZE; i++) {
        if (!block_used[i]) {
            block_used[i] = true;
            return &memory_pool[i * BLOCK_SIZE];
        }
    }
    return NULL; // No available blocks
}

void FreeBlock(void *block) {
    int index = ((uint8_t *)block - memory_pool) / BLOCK_SIZE;
    block_used[index] = false;
}

int main(void) {
    void *block1 = AllocateBlock();
    void *block2 = AllocateBlock();
    FreeBlock(block1);
    void *block3 = AllocateBlock();
    return 0;
}
/*
12. Deadlock Detection and Recovery
Concepts: Deadlock detection, recovery, resource allocation

Problem: Implement a system to detect and recover from deadlocks using a resource allocation graph.
 */
#include <stdbool.h>
#include <stdio.h>

#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int request[NUM_PROCESSES][NUM_RESOURCES] = {
    {0, 0, 0},
    {2, 0, 2},
    {0, 0, 0},
    {1, 0, 0},
    {0, 0, 2}
};
int available[NUM_RESOURCES] = {3, 3, 2};

bool IsSafe(void) {
    int work[NUM_RESOURCES];
    bool finish[NUM_PROCESSES] = {false};

    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    while (true) {
        bool found = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    if (request[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (!finish[i]) {
            return false;
        }
    }
    return true;
}

void RequestResources(int process_id, int request[]) {
    for (int i = 0; i < NUM_RESOURCES; i++) {
        if (request[i] > available[i]) {
            printf("Request denied: Not enough resources\n");
            return;
        }
    }

    for (int i = 0; i < NUM_RESOURCES; i++) {
        available[i] -= request[i];
        allocation[process_id][i] += request[i];
    }

    if (IsSafe()) {
        printf("Request granted\n");
    } else {
        for (int i = 0; i < NUM_RESOURCES; i++) {
            available[i] += request[i];
            allocation[process_id][i] -= request[i];
        }
        printf("Request denied: Would cause deadlock\n");
    }
}

int main(void) {
    int request1[] = {1, 0, 2};
    RequestResources(1, request1);
    return 0;
}
/*
13. Implementing a Priority Inheritance Protocol
Concepts: Priority inversion, priority inheritance, synchronization

Problem: Implement a priority inheritance protocol to handle priority inversion.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

pthread_mutex_t resource_mutex;
int resource;

void LowPriorityTask(void) {
    pthread_mutex_lock(&resource_mutex);
    // Access shared resource
    resource++;
    pthread_mutex_unlock(&resource_mutex);
    pthread_mutex_unlock(&resource_mutex);
}

void MediumPriorityTask(void) {
    // Perform some work
}

void HighPriorityTask(void) {
    pthread_mutex_lock(&resource_mutex);
    // Access shared resource
    resource--;
    pthread_mutex_unlock(&resource_mutex);
}

int main(void) {
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);
    pthread_mutex_init(&resource_mutex, &attr);

    // Create and start tasks
    pthread_create(&low_priority_thread, NULL, LowPriorityTask, NULL);
    pthread_create(&medium_priority_thread, NULL, MediumPriorityTask, NULL);
    pthread_create(&high_priority_thread, NULL, HighPriorityTask, NULL);

    while (1) {
        // Main loop
    }
    return 0;
}
/*
14. Race Condition in Multi-Threaded Environment
Concepts: Race condition, critical section, synchronization

Problem: Implement a solution to prevent race conditions when accessing shared memory in a multi-threaded environment.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

int shared_data = 0;
pthread_mutex_t data_mutex;

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&data_mutex);
        shared_data++;
        pthread_mutex_unlock(&data_mutex);
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&data_mutex);
        shared_data--;
        pthread_mutex_unlock(&data_mutex);
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    pthread_mutex_init(&data_mutex, NULL);

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    pthread_mutex_destroy(&data_mutex);
    return 0;
}
/*
15. Implementing a Software Timer
Concepts: Timer, scheduling, interrupt handling

Problem: Implement a software timer using a hardware timer interrupt.
 */
#include <stdint.h>
#include <stdbool.h>

#define MAX_TIMERS 5

typedef void (*TimerCallback)(void);

typedef struct {
    uint32_t duration;
    uint32_t remaining_time;
    TimerCallback callback;
    bool active;
} SoftwareTimer;

SoftwareTimer timers[MAX_TIMERS];

void TimerISR(void) {
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (timers[i].active && timers[i].remaining_time > 0) {
            timers[i].remaining_time--;
            if (timers[i].remaining_time == 0) {
                timers[i].callback();
                timers[i].active = false;
            }
        }
    }
}

void InitHardwareTimer(void) {
    // Configure the hardware timer to generate an interrupt every 1 millisecond
}

int CreateSoftwareTimer(uint32_t duration, TimerCallback callback) {
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (!timers[i].active) {
            timers[i].duration = duration;
            timers[i].remaining_time = duration;
            timers[i].callback = callback;
            timers[i].active = true;
            return i;
        }
    }
    return -1;
}

void StartSoftwareTimer(int timer_id) {
    if (timer_id >= 0 && timer_id < MAX_TIMERS) {
        timers[timer_id].remaining_time = timers[timer_id].duration;
        timers[timer_id].active = true;
    }
}

void StopSoftwareTimer(int timer_id) {
    if (timer_id >= 0 && timer_id < MAX_TIMERS) {
        timers[timer_id].active = false;
    }
}

void TimerExpiredCallback(void) {
    // Handle timer expiration
}

int main(void) {
    InitHardwareTimer();

    int timer_id = CreateSoftwareTimer(1000, TimerExpiredCallback);
    StartSoftwareTimer(timer_id);

    while (1) {
        // Main loop
    }

    return 0;
}
/*
16. Thread Creation and Management
Concepts: Threading, task management, context switching

Problem: Implement thread creation and management in a multi-threaded environment.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

void```c
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        // Perform some work
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        // Perform some work
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
/*
17. Implementing a Real-Time Operating System (RTOS) Kernel
Concepts: RTOS, task scheduling, inter-task communication

Problem: Implement a simple RTOS kernel with task scheduling and inter-task communication.
 */
#include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 5

typedef void (*TaskFunction)(void);

typedef struct {
    TaskFunction task;
    uint32_t period;
    uint32_t remaining_time;
    bool active;
} Task;

Task tasks[MAX_TASKS];

void SchedulerISR(void) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].active && tasks[i].remaining_time > 0) {
            tasks[i].remaining_time--;
            if (tasks[i].remaining_time == 0) {
                tasks[i].task();
                tasks[i].remaining_time = tasks[i].period;
            }
        }
    }
}

void AddTask(TaskFunction task, uint32_t period) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (!tasks[i].active) {
            tasks[i].task = task;
            tasks[i].period = period;
            tasks[i].remaining_time = period;
            tasks[i].active = true;
            break;
        }
    }
}

void InitRTOS(void) {
    // Configure the hardware timer to generate an interrupt at a regular interval
}

int main(void) {
    InitRTOS();
    AddTask(Task1, 1000);
    AddTask(Task2, 2000);
    while (1) {
        // Main loop
    }
    return 0;
}
/*
18. Implementing a Double-Ended Queue (Deque)
Concepts: Data structures, deque, memory management

Problem: Implement a double-ended queue (deque) to manage data efficiently.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define DEQUE_SIZE 128

typedef struct {
    int data[DEQUE_SIZE];
    int front;
    int rear;
    int size;
} Deque;

Deque deque;

void InitDeque(void) {
    deque.front = -1;
    deque.rear = 0;
    deque.size = 0;
}

bool IsFull(void) {
    return deque.size == DEQUE_SIZE;
}

bool IsEmpty(void) {
    return deque.size == 0;
}

void InsertFront(int value) {
    if (IsFull()) {
        return;
    }
    if (deque.front == -1) {
        deque.front = 0;
        deque.rear = 0;
    } else if (deque.front == 0) {
        deque.front = DEQUE_SIZE - 1;
    } else {
        deque.front--;
    }
    deque.data[deque.front] = value;
    deque.size++;
}

void InsertRear(int value) {
    if (IsFull()) {
        return;
    }
    if (deque.front == -1) {
        deque.front = 0;
        deque.rear = 0;
    } else if (deque.rear == DEQUE_SIZE - 1) {
        deque.rear = 0;
    } else {
        deque.rear++;
    }
    deque.data[deque.rear] = value;
    deque.size++;
}

int DeleteFront(void) {
    if (IsEmpty()) {
        return -1;
    }
    int value = deque.data[deque.front];
    if (deque.front == deque.rear) {
        deque.front = -1;
        deque.rear = 0;
    } else if (deque.front == DEQUE_SIZE - 1) {
        deque.front = 0;
    } else {
        deque.front++;
    }
    deque.size--;
    return value;
}

int DeleteRear(void) {
    if (IsEmpty()) {
        return -1;
    }
    int value = deque.data[deque.rear];
    if (deque.front == deque.rear) {
        deque.front = -1;
        deque.rear = 0;
    } else if (deque.rear == 0) {
        deque.rear = DEQUE_SIZE - 1;
    } else {
        deque.rear--;
    }
    deque.size--;
    return value;
}

int main(void) {
    InitDeque();
    InsertFront(10);
    InsertRear(20);
    printf("Front: %d\n", DeleteFront());
    printf("Rear: %d\n", DeleteRear());
    return 0;
}
/*
19. Implementing a Bounded Buffer
Concepts: Bounded buffer, synchronization, inter-process communication

Problem: Implement a bounded buffer to manage data between producer and consumer tasks.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;
sem_t full;
pthread_mutex_t buffer_mutex;

void *Producer(void *arg) {
    for (int i = 0; i < 100; i++) {
        int item = i; // Produce an item
        sem_wait(&empty);
        pthread_mutex_lock(&buffer_mutex);
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&full);
    }
    return NULL;
}

void *Consumer(void *arg) {
    for (int i = 0; i < 100; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&buffer_mutex);
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&empty);
        printf("Consumed: %d\n", item);
    }
    return NULL;
}

int main(void) {
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&buffer_mutex, NULL);

    pthread_create(&producer_thread, NULL, Producer, NULL);
    pthread_create(&consumer_thread, NULL, Consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&buffer_mutex);

    return 0;
}
/*
20. Implementing a Priority Queue
Concepts: Data structures, priority queue, scheduling

Problem: Implement a priority queue to manage tasks based on their priority.
*/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

typedef struct {
    int priority;
    void (*task)(void);
} Task;

Task priority_queue[MAX_TASKS];
int task_count = 0;

void Swap(Task *a, Task *b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void InsertTask(int priority, void (*task)(void)) {
    if (task_count == MAX_TASKS) {
        printf("Priority queue is full\n");
        return;
    }
    Task new_task = {priority, task};
    priority_queue[task_count] = new_task;
    int i = task_count;
    while (i > 0 && priority_queue[i].priority < priority_queue[(i - 1) / 2].priority) {
        Swap(&priority_queue[i], &priority_queue[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    task_count++;
}

Task ExtractMin(void) {
    if (task_count == 0) {
        printf("Priority queue is empty\n");
        exit(1);
    }
    Task min_task = priority_queue[0];
    priority_queue[0] = priority_queue[--task_count];
    int i = 0;
    while (2 * i + 1 < task_count) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < task_count && priority_queue[left].priority < priority_queue[smallest].priority) {
            smallest = left;
        }
        if (right < task_count && priority_queue[right].priority < priority_queue[smallest].priority) {
            smallest = right;
        }
        if (smallest == i) {
            break;
        }
        Swap(&priority_queue[i], &priority_queue[[smallest]);
        i = smallest;
    }
    return min_task;
}

void Task1(void) {
    printf("Executing Task 1\n");
}

void Task2(void) {
    printf("Executing Task 2\n");
}

int main(void) {
    InsertTask(2, Task1);
    InsertTask(1, Task2);

    while (task_count > 0) {
        Task task = ExtractMin();
        task.task();
    }

    return 0;
}

//BONUS QNA

/*
Now, Imagine I want to use Hardware timer internally to make software timer on top of it. Show me how would you design this?

Designing a software timer on top of a hardware timer involves leveraging the hardware timer's capabilities to create multiple software-based timers. Here's a step-by-step approach to achieve this:

1. Understanding the Hardware Timer
A hardware timer typically has the following features:

A counter that increments or decrements based on a clock source.
An interrupt that triggers when the counter reaches a specific value (overflow or compare match).
2. Designing the Software Timer
The software timer will use the hardware timer's interrupt to keep track of elapsed time and manage multiple software timers.

3. Implementation Steps
Step 1: Initialize the Hardware Timer
Configure the hardware timer to generate an interrupt at a regular interval (e.g., every 1 millisecond).

Step 2: Define Software Timer Structures
Create a structure to represent each software timer, including fields for the timer's duration, remaining time, and a callback function to be executed when the timer expires.

Step 3: Implement the Timer Management Functions
Implement functions to create, start, stop, and manage software timers.

Step 4: Handle the Hardware Timer Interrupt
In the hardware timer interrupt service routine (ISR), decrement the remaining time for each active software timer and call the callback function if a timer expires.
*/

#include <stdint.h>
#include <stdbool.h>

#define MAX_SOFTWARE_TIMERS 10

typedef void (*TimerCallback)(void);

typedef struct {
    uint32_t duration;       // Timer duration in milliseconds
    uint32_t remaining_time; // Remaining time in milliseconds
    TimerCallback callback;  // Callback function to be called when timer expires
    bool active;             // Timer active flag
} SoftwareTimer;

SoftwareTimer timers[MAX_SOFTWARE_TIMERS];

// Hardware timer interrupt service routine (ISR)
void TimerISR(void) {
    for (int i = 0; i < MAX_SOFTWARE_TIMERS; i++) {
        if (timers[i].active && timers[i].remaining_time > 0) {
            timers[i].remaining_time--;
            if (timers[i].remaining_time == 0) {
                timers[i].callback();
                timers[i].active = false; // Deactivate the timer
            }
        }
    }
}

// Initialize the hardware timer
void InitHardwareTimer(void) {
    // Configure the hardware timer to generate an interrupt every 1 millisecond
    // This is platform-specific and depends on the microcontroller being used
}

// Create a software timer
int CreateSoftwareTimer(uint32_t duration, TimerCallback callback) {
    for (int i = 0; i < MAX_SOFTWARE_TIMERS; i++) {
        if (!timers[i].active) {
            timers[i].duration = duration;
            timers[i].remaining_time = duration;
            timers[i].callback = callback;
            timers[i].active = true;
            return i; // Return the timer ID
        }
    }
    return -1; // No available timer slots
}

// Start a software timer
void StartSoftwareTimer(int timer_id) {
    if (timer_id >= 0 && timer_id < MAX_SOFTWARE_TIMERS) {
        timers[timer_id].remaining_time = timers[timer_id].duration;
        timers[timer_id].active = true;
    }
}

// Stop a software timer
void StopSoftwareTimer(int timer_id) {
    if (timer_id >= 0 && timer_id < MAX_SOFTWARE_TIMERS) {
        timers[timer_id].active = false;
    }
}

// Example callback function
void TimerExpiredCallback(void) {
    // Handle timer expiration
}

int main(void) {
    InitHardwareTimer();

    // Create and start a software timer with a duration of 1000 milliseconds (1 second)
    int timer_id = CreateSoftwareTimer(1000, TimerExpiredCallback);
    StartSoftwareTimer(timer_id);

    while (1) {
        // Main loop
    }

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Sure! Let's go through each of the 30 coding problems, explaining the concept in depth and providing a working C program for each. Due to the length and complexity of these problems, I'll provide detailed explanations and code for the first few problems. If you need more, please let me know, and I can continue with the rest.

1. Implement a Simple Thread Pool in C
Concept:
A thread pool is a collection of pre-initialized threads that stand ready to perform tasks. When a task is submitted, a thread from the pool is assigned to execute it. This approach helps in managing a large number of short-lived tasks efficiently by reusing threads, thus reducing the overhead of thread creation and destruction.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_POOL_SIZE 4
#define TASK_QUEUE_SIZE 10

typedef struct {
    void (*function)(void*);
    void* argument;
} Task;

typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t notify;
    pthread_t threads[THREAD_POOL_SIZE];
    Task taskQueue[TASK_QUEUE_SIZE];
    int taskCount;
    int head;
    int tail;
    int shutdown;
} ThreadPool;

ThreadPool pool;

void* threadFunction(void* arg) {
    while (1) {
        pthread_mutex_lock(&pool.lock);

        while (pool.taskCount == 0 && !pool.shutdown) {
            pthread_cond_wait(&pool.notify, &pool.lock);
        }

        if (pool.shutdown) {
            pthread_mutex_unlock(&pool.lock);
            pthread_exit(NULL);
        }

        Task task = pool.taskQueue[pool.head];
        pool.head = (pool.head + 1) % TASK_QUEUE_SIZE;
        pool.taskCount--;

        pthread_mutex_unlock(&pool.lock);

        (*(task.function))(task.argument);
    }
    return NULL;
}

void threadPoolInit() {
    pthread_mutex_init(&pool.lock, NULL);
    pthread_cond_init(&pool.notify, NULL);
    pool.taskCount = 0;
    pool.head = 0;
    pool.tail = 0;
    pool.shutdown = 0;

    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_create(&pool.threads[i], NULL, threadFunction, NULL);
    }
}

void threadPoolShutdown() {
    pthread_mutex_lock(&pool.lock);
    pool.shutdown = 1;
    pthread_cond_broadcast(&pool.notify);
    pthread_mutex_unlock(&pool.lock);

    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_join(pool.threads[i], NULL);
    }

    pthread_mutex_destroy(&pool.lock);
    pthread_cond_destroy(&pool.notify);
}

void threadPoolAddTask(void (*function)(void*), void* argument) {
    pthread_mutex_lock(&pool.lock);

    pool.taskQueue[pool.tail].function = function;
    pool.taskQueue[pool.tail].argument = argument;
    pool.tail = (pool.tail + 1) % TASK_QUEUE_SIZE;
    pool.taskCount++;

    pthread_cond_signal(&pool.notify);
    pthread_mutex_unlock(&pool.lock);
}

void sampleTask(void* arg) {
    int num = *(int*)arg;
    printf("Task %d is being processed by thread %ld\n", num, pthread_self());
    sleep(1);
}

int main() {
    threadPoolInit();

    int taskArgs[TASK_QUEUE_SIZE];
    for (int i = 0; i < TASK_QUEUE_SIZE; i++) {
        taskArgs[i] = i;
        threadPoolAddTask(sampleTask, &taskArgs[i]);
    }

    sleep(5);
    threadPoolShutdown();
    return 0;
}
2. Write a Program to Simulate the Dining Philosophers Problem Using Semaphores
Concept:
The Dining Philosophers problem is a classic synchronization problem. It involves philosophers sitting at a table with a fork between each pair. A philosopher needs both forks to eat but can only pick up one fork at a time. The challenge is to design a protocol that prevents deadlock and ensures that no philosopher starves.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

sem_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];

void* philosopher(void* num) {
    int id = *(int*)num;
    int leftFork = id;
    int rightFork = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        printf(""Philosopher %d is hungry.\n", id);

        // Pick up forks
        sem_wait(&forks[leftFork]);
        sem_wait(&forks[rightFork]);

        printf("Philosopher %d is eating.\n", id);
        sleep(1);

        // Put down forks
        sem_post(&forks[leftFork]);
        sem_post(&forks[rightFork]);
    }
    return NULL;
}

int main() {
    int ids[NUM_PHILOSOPHERS];
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&forks[i]);
    }

    return 0;
}
3. Implement the Banker's Algorithm for Deadlock Avoidance in C
Concept:
The Banker's Algorithm is used to avoid deadlock by ensuring that resource allocation does not leave the system in an unsafe state. It checks if granting a resource request will keep the system in a safe state.

Code:
c
#include <stdio.h>
#include <stdbool.h>

#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

int available[NUM_RESOURCES] = {3, 3, 2};
int maximum[NUM_PROCESSES][NUM_RESOURCES] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};
int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int need[NUM_PROCESSES][NUM_RESOURCES];

void calculateNeed() {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

bool isSafe() {
    int work[NUM_RESOURCES];
    bool finish[NUM_PROCESSES] = {false};

    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    while (true) {
        bool found = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                bool canProceed = true;
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        canProceed = false;
                        break;
                    }
                }
                if (canProceed) {
                    for (int j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (!finish[i]) {
            return false;
        }
    }
    return true;
}

bool requestResources(int process, int request[]) {
    for (int i = 0; i < NUM_RESOURCES; i++) {
        if (request[i] > need[process][i]) {
            return false;
        }
    }

    for (int i = 0; i < NUM_RESOURCES; i++) {
        if (request[i] > available[i]) {
            return false;
        }
    }

    for (int i = 0; i < NUM_RESOURCES; i++) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

    if (isSafe()) {
        return true;
    } else {
        for (int i = 0; i < NUM_RESOURCES; i++) {
            available[i] += request[i];
            allocation[process][i] -= request[i];
            need[[i][j] += request[i];
        }
        return false;
    }
}

int main() {
    calculateNeed();

    int process = 1;
    int request[NUM_RESOURCES] = {1, 0, 2};

    if (requestResources(process, request)) {
        printf("Request granted.\n");
    } else {
        printf("Request denied.\n");
    }

    return 0;
}
4. Write a Program to Demonstrate the Use of Mutexes for Thread Synchronization
Concept:
Mutexes (mutual exclusions) are used to prevent multiple threads from accessing a shared resource simultaneously, which can lead to data corruption. Mutexes ensure that only one thread can access the critical section at a time.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t mutex;
int counter = 0;

void* incrementCounter(void* arg) {
    pthread_mutex_lock(&mutex);
    counter++;
    printf("Thread %ld incremented counter to %d\n", pthread_self(), counter);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, incrementCounter, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}
5. Implement a Producer-Consumer Problem Using Condition Variables and Mutexes
Concept:
The producer-consumer problem is a classic synchronization problem where producers generate data and place it in a buffer, and consumers take data from the buffer. Condition variables and mutexes are used to synchronize access to the buffer.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

pthread_mutex_t mutex;
pthread_cond_t notEmpty;
pthread_cond_t notFull;

void* producer(void* arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        pthread_mutex_lock(&mutex);

        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&notFull, &mutex);
        }

        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Produced: %d\n", i);

        pthread_cond_signal(&notEmpty);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        pthread_mutex_lock(&mutex);

        while (count == 0) {
            pthread_cond_wait(&notEmpty, &mutex);
        }

        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumed: %d\n", item);

        pthread_cond_signal(&notFull);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t prodThread, consThread;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&notEmpty, NULL);
    pthread_cond_init(&notFull, NULL);

    pthread_create(&prodThread, NULL, producer, NULL);
    pthread_create(&consThread, NULL, consumer, NULL);

    pthread_join(prodThread, NULL);
    pthread_join(consThread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&notEmpty);
    pthread_cond_destroy(&notFull);

    return 0;
}
6. Write a Program to Simulate a Priority Queue Scheduler
Concept:
A priority queue scheduler assigns tasks based on their priority. Higher priority tasks are executed before lower priority ones. This can be implemented using a priority queue data structure.

Code:
c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int priority;
    int taskID;
} Task;

typedef struct {
    Task* tasks;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->tasks = (Task*)malloc(sizeof(Task) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(Task* a, Task* b)```c
void swap(Task* a, Task* b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue* pq, int index) {
    if (index && pq->tasks[(index - 1) / 2].priority < pq->tasks[index].priority) {
        swap(&pq->tasks[index], &pq->tasks[(index - 1) / 2]);
        heapifyUp(pq, (index - 1) / 2);
    }
}

void heapifyDown(PriorityQueue* pq, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < pq->size && pq->tasks[left].priority > pq->tasks[largest].priority) {
        largest = left;
    }

    if (right < pq->size && pq->tasks[right].priority > pq->tasks[largest].priority) {
        largest = right;
    }

    if (largest != index) {
        swap(&pq->tasks[index], &pq->tasks[largest]);
        heapifyDown(pq, largest);
    }
}

void insertTask(PriorityQueue* pq, int priority, int taskID) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is full\n");
        return;
    }

    pq->tasks[pq->size].priority = priority;
    pq->tasks[pq->size].taskID = taskID;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

Task extractMax(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        Task emptyTask = {0, 0};
        return emptyTask;
    }

    Task root = pq->tasks[0];
    pq->tasks[0] = pq->tasks[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);

    return root;
}

void printTasks(PriorityQueue* pq) {
    for (int i = 0; i < pq->size; i++) {
        printf("Task ID: %d, Priority: %d\n", pq->tasks[i].taskID, pq->tasks[i].priority);
    }
}

int main() {
    PriorityQueue* pq = createPriorityQueue(10);

    insertTask(pq, 3, 101);
    insertTask(pq, 5, 102);
    insertTask(pq, 1, 103);
    insertTask(pq, 4, 104);

    printf("Tasks in Priority Queue:\n");
    printTasks(pq);

    printf("\nExtracting tasks based on priority:\n");
    while (pq->size > 0) {
        Task task = extractMax(pq);
        printf("Task ID: %d, Priority: %d\n", task.taskID, task.priority);
    }

    free(pq->tasks);
    free(pq);

    return 0;
}
7. Implement a Simple Round-Robin Scheduler in C
Concept:
A round-robin scheduler assigns a fixed time slice to each task in a cyclic order. This ensures that all tasks get an equal share of the CPU time.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_TASKS 4
#define TIME_SLICE 1

typedef struct {
    int taskID;
    int burstTime;
} Task;

void roundRobinScheduler(Task tasks[], int numTasks, int timeSlice) {
    int remainingBurstTime[NUM_TASKS];
    for (int i = 0; i < numTasks; i++) {
        remainingBurstTime[i] = tasks[i].burstTime;
    }

    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < numTasks; i++) {
            if (remainingBurstTime[i] > 0) {
                done = 0;
                if (remainingBurstTime[i] > timeSlice) {
                    time += timeSlice;
                    remainingBurstTime[i] -= timeSlice;
                } else {
                    time += remainingBurstTime[i];
                    remainingBurstTime[i] = 0;
                    printf("Task %d finished at time %d\n", tasks[i].taskID, time);
                }
            }
        }
        if (done) {
            break;
        }
    }
}

int main() {
    Task tasks[NUM_TASKS] = {
        {1, 5},
        {2, ```c
        {2, 3},
        {3, 8},
        {4, 6}
    };

    printf("Round-Robin Scheduling:\n");
    roundRobinScheduler(tasks, NUM_TASKS, TIME_SLICE);

    return 0;
}
8. Write a Program to Demonstrate the Use of Read-Write Locks
Concept:
Read-write locks allow multiple threads to read a shared resource simultaneously while ensuring exclusive access for writing. This improves performance when reads are more frequent than writes.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

pthread_rwlock_t rwlock;
int sharedData = 0;

void* reader(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_rwlock_rdlock(&rwlock);
        printf("Reader %d: read sharedData = %d\n", id, sharedData);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_rwlock_wrlock(&rwlock);
        sharedData++;
        printf("Writer %d: updated sharedData to %d\n", id, sharedData);
        pthread_rwlock_unlock(&rwlock);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int ids[NUM_READERS + NUM_WRITERS];

    pthread_rwlock_init(&rwlock, NULL);

    for (int i = 0; i < NUM_READERS; i++) {
        ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &ids[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        ids[NUM_READERS + i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &ids[NUM_READERS + i]);
    }

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    pthread_rwlock_destroy(&rwlock);
    return 0;
}
9. Implement a Barrier Synchronization Mechanism in C
Concept:
A barrier synchronization mechanism ensures that multiple threads reach a certain point in their execution before any of them proceed. This is useful for coordinating phases of parallel computation.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_barrier_t barrier;

void* threadFunction(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d reached the barrier\n", id);
    pthread_barrier_wait(&barrier);
    printf("Thread %d passed the barrier\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    pthread_barrier_init(&barrier, NULL, NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, threadFunction, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_barrier_destroy(&barrier);
    return 0;
}
10. Write a Program to Simulate a Simple Memory Allocator Using the Buddy System
Concept:
The buddy system is a memory allocation technique that divides memory into partitions to try to satisfy a memory request as suitably as possible. Memory is allocated in powers of two, and adjacent free blocks of the same size can be combined to form a larger block.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEVEL 5
#define MIN_BLOCK_SIZE 32

typedef struct Block {
    int size;
    int isFree;
    struct Block* next;
} Block;

Block* freeList[MAX_LEVEL + 1];

void initializeMemory() {
    for (int i = 0; i <= MAX_LEVEL; i++) {
        freeList[i] = NULL;
    }
    Block* initialBlock = (Block*)malloc(sizeof(Block));
    initialBlock->size = MIN_BLOCK_SIZE * (1 << MAX_LEVEL);
```c
    initialBlock->isFree = 1;
    initialBlock->next = NULL;
    freeList[MAX_LEVEL] = initialBlock;
}

int getLevel(int size) {
    int level = 0;
    while ((MIN_BLOCK_SIZE * (1 << level)) < size) {
        level++;
    }
    return level;
}

void* allocateMemory(int size) {
    int level = getLevel(size);
    if (level > MAX_LEVEL) {
        return NULL;
    }

    for (int i = level; i <= MAX_LEVEL; i++) {
        if (freeList[i] != NULL) {
            Block* block = freeList[i];
            freeList[i] = block->next;
            block->isFree = 0;

            while (i > level) {
                i--;
                Block* buddy = (Block*)((char*)block + (MIN_BLOCK_SIZE * (1 << i)));
                buddy->size = MIN_BLOCK_SIZE * (1 << i);
                buddy->isFree = 1;
                buddy->next = freeList[i];
                freeList[i] = buddy;
            }
            return (void*)(block + 1);
        }
    }
    return NULL;
}

void freeMemory(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    Block* block = (Block*)ptr - 1;
    int level = getLevel(block->size);

    while (level < MAX_LEVEL) {
        Block* buddy = (Block*)((char*)block ^ (MIN_BLOCK_SIZE * (1 << level)));
        if (buddy->isFree && buddy->size == block->size) {
            Block** current = &freeList[level];
            while (*current != NULL && *current != buddy) {
                current = &(*current)->next;
            }
            if (*current == buddy) {
                *current = buddy->next;
                if (block > buddy) {
                    block = buddy;
                }
                level++;
                block->size *= 2;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    block->isFree = 1;
    block->next = freeList[level];
    freeList[level] = block;
}

int main() {
    initializeMemory();

    void* ptr1 = allocateMemory(100);
    void* ptr2 = allocateMemory(200);
    void* ptr3 = allocateMemory(50);

    printf("Allocated memory at %p, %p, %p\n", ptr1, ptr2, ptr3);

    freeMemory(ptr1);
    freeMemory(ptr2);
    freeMemory(ptr3);

    return 0;
}
11. Implement a Memory Pool Allocator in C
Concept:
A memory pool allocator pre-allocates a large block of memory and manages it internally, providing fixed-size chunks to the application. This reduces the overhead of frequent dynamic memory allocations and deallocations.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 1024
#define BLOCK_SIZE 32

typedef struct Block {
    struct Block* next;
} Block;

typedef struct {
    Block* freeList;
    char pool[POOL_SIZE];
} MemoryPool;

void initializePool(MemoryPool* pool) {
    pool->freeList = (Block*)pool->pool;
    Block* current = pool->freeList;
    for (int i = 0; i < POOL_SIZE / BLOCK_SIZE - 1; i++) {
        current->next = (Block*)((char*)current + BLOCK_SIZE);
        current = current->next;
    }
    current->next = NULL;
}

void* allocateBlock(MemoryPool* pool) {
    if (pool->freeList == NULL) {
        return NULL;
    }
    Block* block = pool->freeList;
    pool->freeList = block->next;
    return (void*)block;
}

void freeBlock(MemoryPool* pool, void* ptr) {
    Block* block = (Block*)ptr;
    block->next = pool->freeList;
    pool->freeList = block;
}

int main() {
    MemoryPool pool;
    initializePool(&pool);

    void* ptr1 = allocateBlock(&pool);
    void* ptr2 = allocateBlock(&pool);
    void* ptr3 = allocateBlock(&pool);

    printf("Allocated blocks at %p, %p, %p\n", ptr1, ptr2, ptr3);

    freeBlock(&pool, ptr1);
    freeBlock(&pool, ptr2);
    freeBlock(&pool, ptr3);

    return 0;
}
12. Write a Program to Demonstrate Memory-Mapped I/O
Concept:
Memory-m-mapped I/O allows hardware devices to be controlled by reading and writing specific memory addresses. This technique is commonly used in embedded systems to interact with peripherals.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define GPIO_BASE 0x3F200000
#define GPIO_LEN  0xB4

int main() {
    int mem_fd;
    void *gpio_map;

    // Open /dev/mem
    if ((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Map GPIO
    gpio_map = mmap(NULL, GPIO_LEN, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, GPIO_BASE);
    if (gpio_map == MAP_FAILED) {
        perror("mmap");
        close(mem_fd);
        exit(EXIT_FAILURE);
    }

    // Access GPIO registers
    volatile unsigned *gpio = (volatile unsigned *)gpio_map;
    gpio[10] = 1 << 17; // Set GPIO pin 17

    // Unmap and close
    if (munmap(gpio_map, GPIO_LEN) == -1) {
        perror("munmap");
    }
    close(mem_fd);

    return 0;
}
13. Implement a Simple Garbage Collector in C
Concept:
A garbage collector automatically reclaims memory that is no longer in use by the program. This example demonstrates a simple mark-and-sweep garbage collector.

Code:
c
#include <stdio.h>
#include <stdlib.h>

typedef struct Object {
    int marked;
    struct Object* next;
} Object;

typedef struct {
    Object* firstObject;
} VM;

VM* newVM() {
    VM* vm = (VM*)malloc(sizeof(VM));
    vm->firstObject = NULL;
    return vm;
}

Object* newObject(VM* vm) {
    Object* object = (Object*)malloc(sizeof(Object));
    object->marked = 0;
    object->next = vm->firstObject;
    vm->firstObject = object;
    return object;
}

void mark(Object* object) {
    if (object->marked) return;
    object->marked = 1;
}

void markAll(VM* vm) {
    Object* object = vm->firstObject;
    while (object) {
        mark(object);
        object = object->next;
    }
}

void sweep(VM* vm) {
    Object** object = &vm->firstObject;
    while (*object) {
        if (!(*object)->marked) {
            Object* unreached = *object;
            *object = unreached->next;
            free(unreached);
        } else {
            (*object)->marked = 0;
            object = &(*object)->next;
        }
    }
}

void gc(VM* vm) {
    markAll(vm);
    sweep(vm);
}

int main() {
    VM* vm = newVM();

    Object* obj1 = newObject(vm);
    Object* obj2 = newObject(vm);

    gc(vm);

    free(vm);
    return 0;
}
14. Write a Program to Simulate a Page Replacement Algorithm (e.g., LRU, FIFO)
Concept:
Page replacement algorithms decide which memory pages to swap out when a new page needs to be loaded into memory. This example demonstrates the Least Recently Used (LRU) algorithm.

Code:
c
#include <stdio.h>
#include <stdlib.h>

#define FRAME_SIZE 3

typedef struct {
    int page;
    int age;
} Frame;

void lru(int pages[], int numPages) {
    Frame frames[FRAME_SIZE];
    for (int i = 0; i < FRAME_SIZE; i++) {
        frames[i].page = -1;
        frames[i].age = 0;
    }

    int pageFaults = 0;
    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j].page == page) {
                frames[j].age = 0;
                found = 1;
                break;
            }
        }

        if (!found) {
            int oldest = 0;
            for (int j = 1; j < FRAME_SIZE; j++) {
                if (frames[j].age > frames[oldest].age) {
                    oldest = j;
                }
            }
            frames[oldest].page = page;
            frames[oldest].age = 0;
            pageFaults++;
        }

       frames[oldest].page = page;
            frames[oldest].age = 0;
            pageFaults++;
        }

        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j].page != -1) {
                frames[j].age++;
            }
        }

        printf("Page %d: ", page);
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j].page != -1) {
                printf("%d ", frames[j].page);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int numPages = sizeof(pages) / sizeof(pages[0]);

    lru(pages, numPages);

    return 0;
}
15. Implement a Stack-Based Memory Allocator in C
Concept:
A stack-based memory allocator allocates memory in a last-in, first-out (LIFO) manner. This is useful for scenarios where memory allocation and deallocation follow a strict order.

Code:
c
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1024

typedef struct {
    char stack[STACK_SIZE];
    int top;
} StackAllocator;

void initializeStack(StackAllocator* allocator) {
    allocator->top = 0;
}

void* allocate(StackAllocator* allocator, int size) {
    if (allocator->top + size > STACK_SIZE) {
        return NULL;
    }
    void* ptr = &allocator->stack[allocator->top];
    allocator->top += size;
    return ptr;
}

void deallocate(StackAllocator* allocator, int size) {
    if (allocator->top - size < 0) {
        return;
    }
    allocator->top -= size;
}

int main() {
    StackAllocator allocator;
    initializeStack(&allocator);

    void* ptr1 = allocate(&allocator, 100);
    void* ptr2 = allocate(&allocator, 200);
    void* ptr3 = allocate(&allocator, 50);

    printf("Allocated memory at %p, %p, %p\n", ptr1, ptr2, ptr3);

    deallocate(&allocator, 50);
    deallocate(&allocator, 200);
    deallocate(&allocator, 100);

    return 0;
}
16. Write a Program to Demonstrate the Use of Virtual Memory
Concept:
Virtual memory allows a computer to compensate for physical memory shortages by temporarily transferring data from random access memory (RAM) to disk storage. This example demonstrates a simple virtual memory system.

Code:
c
#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 256
#define NUM_PAGES 4
#define MEMORY_SIZE (PAGE_SIZE * NUM_PAGES)

typedef struct {
    int pageTable[NUM_PAGES];
    char memory[MEMORY_SIZE];
} VirtualMemory;

void initializeMemory(VirtualMemory* vm) {
    for (int i = 0; i < NUM_PAGES; i++) {
        vm->pageTable[i] = -1;
    }
}

int allocatePage(VirtualMemory* vm, int pageNumber) {
    for (int i = 0; i < NUM_PAGES; i++) {
        if (vm->pageTable[i] == -1) {
            vm->pageTable[i] = pageNumber;
            return i;
        }
    }
    return -1;
}

void writeMemory(VirtualMemory* vm, int pageNumber, int offset, char value) {
    int frameNumber = allocatePage(vm, pageNumber);
    if (frameNumber == -1) {
        printf("Memory full\n");
        return;
    }
    vm->memory[frameNumber * PAGE_SIZE + offset] = value;
}

char readMemory(VirtualMemory* vm, int pageNumber, int offset) {
    for (int i = 0; i < NUM_PAGES; i++) {
        if (vm->pageTable[i] == pageNumber) {
            return vm->memory[i * PAGE_SIZE + offset];
        }
    }
    printf("Page not found\n");
    return -1;
}

int main() {
    VirtualMemory vm;
    initializeMemory(&vm);

    writeMemory(&vm, 1, 0, 'A');
    writeMemory(&vm, 2, 1, 'B');
    writeMemory(&vm, 3, 2, 'C');

    printf("Read memory: %c %```c
    printf("Read memory: %c %c %c\n", readMemory(&vm, 1, 0), readMemory(&vm, 2, 1), readMemory(&vm, 3, 2));

    return 0;
}
17. Implement a Simple Memory Leak Detector in C
Concept:
A memory leak detector helps identify memory that has been allocated but not freed. This example demonstrates a simple memory leak detector using a linked list to track allocations.

Code:
c
#include <stdio.h>
#include <stdlib.h>

typedef struct Allocation {
    void* ptr;
    size_t size;
    struct Allocation* next;
} Allocation;

Allocation* head = NULL;

void* myMalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr) {
        Allocation* newAlloc = (Allocation*)malloc(sizeof(Allocation));
        newAlloc->ptr = ptr;
        newAlloc->size = size;
        newAlloc->next = head;
        head = newAlloc;
    }
    return ptr;
}

void myFree(void* ptr) {
    Allocation** current = &head;
    while (*current) {
        if ((*current)->ptr == ptr) {
            Allocation* toFree = *current;
            *current = (*current)->next;
            free(toFree);
            break;
        }
        current = &(*current)->next;
    }
    free(ptr);
}

void checkForLeaks() {
    Allocation* current = head;
    while (current) {
        printf("Memory leak detected: %p (%zu bytes)\n", current->ptr, current->size);
        current = current->next;
    }
}

int main() {
    char* ptr1 = (char*)myMalloc(100);
    int* ptr2 = (int*)myMalloc(200);
    float* ptr3 = (float*)myMalloc(50);

    myFree(ptr1);
    myFree(ptr2);

    checkForLeaks();

    myFree(ptr3);

    return 0;
}
18. Write a Program to Simulate a Simple Paging System
Concept:
A paging system divides memory into fixed-size pages and maps them to physical memory frames. This example demonstrates a simple paging system with a page table.

Code:
c
#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 256
#define NUM_PAGES 4
#define MEMORY_SIZE (PAGE_SIZE * NUM_PAGES)

typedef struct {
    int pageTable[NUM_PAGES];
    char memory[MEMORY_SIZE];
} PagingSystem;

void initializePagingSystem(PagingSystem* ps) {
    for (int i = 0; i < NUM_PAGES; i++) {
        ps->pageTable[i] = -1;
    }
}

int allocatePage(PagingSystem* ps, int pageNumber) {
    for (int i = 0; i < NUM_PAGES; i++) {
        if (ps->pageTable[i] == -1) {
            ps->pageTable[i] = pageNumber;
            return i;
        }
    }
    return -1;
}

void writeMemory(PagingSystem* ps, int pageNumber, int offset, char value) {
    int frameNumber = allocatePage(ps, pageNumber);
    if (frameNumber == -1) {
        printf("Memory full\n");
        return;
    }
    ps->memory[frameNumber * PAGE_SIZE + offset] = value;
}

char readMemory(PagingSystem* ps, int pageNumber, int offset) {
    for (int i = 0; i < NUM_PAGES; i++) {
        if (ps->pageTable[i] == pageNumber) {
            return ps->memory[i * PAGE_SIZE + offset];
        }
    }
    printf("Page not found\n");
    return -1;
}

int main() {
    PagingSystem ps;
    initializePagingSystem(&ps);

    writeMemory(&ps, 1, 0, 'A');
    writeMemory(&ps, 2, 1, 'B');
    writeMemory(&ps, 3, 2, 'C');

    printf("Read memory: %c %c %c\n", readMemory(&ps, 1, 0), readMemory(&ps, 2, 1), readMemory(&ps, 3, 2));

    return 0;
}
19. Implement a Dynamic Memory Allocator Using a Free List
Concept:
A dynamic memory allocator manages memory allocation and deallocation using a free list to keep track of free memory blocks. This example demonstrates a simple dynamic memory allocator.

Code:
c
#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    size_t size;
    struct Block* next;
```c
    struct Block* next;
} Block;

Block* freeList = NULL;

void* myMalloc(size_t size) {
    Block* current = freeList;
    Block* previous = NULL;

    while (current) {
        if (current->size >= size) {
            if (previous) {
                previous->next = current->next;
            } else {
                freeList = current->next;
            }
            return (void*)(current + 1);
        }
        previous = current;
        current = current->next;
    }

    Block* newBlock = (Block*)malloc(sizeof(Block) + size);
    newBlock->size = size;
    return (void*)(newBlock + 1);
}

void myFree(void* ptr) {
    if (!ptr) return;

    Block* block = (Block*)ptr - 1;
    block->next = freeList;
    freeList = block;
}

int main() {
    char* ptr1 = (char*)myMalloc(100);
    int* ptr2 = (int*)myMalloc(200);
    float* ptr3 = (float*)myMalloc(50);

    printf("Allocated memory at %p, %p, %p\n", ptr1, ptr2, ptr3);

    myFree(ptr1);
    myFree(ptr2);
    myFree(ptr3);

    return 0;
}
20. Write a Program to Demonstrate the Use of Shared Memory for IPC
Concept:
Shared memory allows multiple processes to access the same memory segment, enabling fast inter-process communication (IPC). This example demonstrates how to use shared memory for IPC.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    char* str = (char*)shmat(shmid, (void*)0, 0);

    printf("Write Data: ");
    fgets(str, SHM_SIZE, stdin);

    printf("Data written in memory: %s\n", str);

    shmdt(str);

    return 0;
}
21. Implement a Software Timer in C
Concept:
A software timer is a timer implemented in software, typically using a hardware timer or system clock to keep track of elapsed time. This example demonstrates a simple software timer.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void timerHandler(int signum) {
    static int count = 0;
    printf("Timer expired %d times\n", ++count);
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();
    }

    return 0;
}
22. Write a Program to Demonstrate the Use of a Watchdog Timer
Concept:
A watchdog timer is a hardware timer that resets the system if the software fails to reset the timer within a specified interval. This example demonstrates a simple watchdog timer.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void watchdogHandler(int signum) {
    printf("Watchdog timer expired! Resetting system...\n");
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &watchdogHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 5;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        printf("Resetting watchdog timer...\n");
        timer.it_value.tv_sec = 5;
        setitimer(ITIMER_REAL, &timer, NULL);
        sleep(3);
    }

    return 0;
}
23. Implement a Simple Real-Time### 23. Implement a Simple Real-Time Clock in C
Concept:
A real-time clock (RTC) keeps track of the current time and date. This example demonstrates a simple RTC using the system clock.

Code:
c
#include <stdio.h>
#include <time.h>

void printCurrentTime() {
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    printf("Current local time and date: %s", asctime(timeinfo));
}

int main() {
    while (1) {
        printCurrentTime();
        sleep(1);
    }
    return 0;
}
24. Write a Program to Measure Memory Utilization in an Embedded System
Concept:
Measuring memory utilization involves tracking the amount of memory used by the program. This example demonstrates a simple way to measure memory utilization.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

void printMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("Memory usage: %ld KB\n", usage.ru_maxrss);
}

int main() {
    char* ptr1 = (char*)malloc(100 * 1024);
    char* ptr2 = (char*)malloc(200 * 1024);

    printMemoryUsage();

    free(ptr1);
    free(ptr2);

    printMemoryUsage();

    return 0;
}
25. Implement a Simple Task Scheduler with Timer Interrupts
Concept:
A task scheduler manages the execution of multiple tasks based on timer interrupts. This example demonstrates a simple task scheduler using timer interrupts.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void task1() {
    printf("Task 1 executed\n");
}

void task2() {
    printf("Task 2 executed\n");
}

void timerHandler(int signum) {
    static int count = 0;
    if (count % 2 == 0) {
        task1();
    } else {
        task2();
    }
    count++;
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();
    }

    return 0;
}
26. Write a Program to Demonstrate the Use of Hardware Timers
Concept:
Hardware timers are used to generate precise time delays and periodic interrupts. This example demonstrates the use of hardware timers in an embedded system.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void timerHandler(int signum) {
    printf("Hardware timer interrupt\n");
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();
    }

    return 0;
}
27. Implement a Simple Delay Function Using Busy-Waiting
Concept:
A delay function introduces a time delay in the program execution. This example demonstrates a simple delay function using busy-waiting.

Code:
c
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

int main() {
    printf("Starting delay...\n");
    delay(1000); // 1 second delay
    printf("Delay finished\n");
    return 0;
}
28. Write a Program to Simulate a Timer-Based Event Scheduler
Concept:
A timer-based event scheduler triggers events at specified intervals. This example demonstrates a simpletimer-based event scheduler.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void event1() {
    printf("Event 1 triggered\n");
}

void event2() {
    printf("Event 2 triggered\n");
}

void timerHandler(int signum) {
    static int count = 0;
    if (count % 2 == 0) {
        event1();
    } else {
        event2();
    }
    count++;
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();
    }

    return 0;
}
29. Implement a Simple Time-Sharing System in C
Concept:
A time-sharing system allows multiple tasks to share CPU time by switching between them at regular intervals. This example demonstrates a simple time-sharing system.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void task1() {
    printf("Task 1 running\n");
}

void task2() {
    printf("Task 2 running\n");
}

void timerHandler(int signum) {
    static int count = 0;
    if (count % 2 == 0) {
        task1();
    } else {
        task2();
    }
    count++;
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();
    }

    return 0;
}
30. Write a Program to Demonstrate the Use of High-Resolution Timers
Concept:
High-resolution timers provide precise timing for applications that require accurate time measurements. This example demonstrates the use of high-resolution timers.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void timerHandler(int signum) {
    printf("High-resolution timer interrupt\n");
}

int main() {
    struct sigaction sa;
    struct itimerspec timerSpec;
    timer_t timerID;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGRTMIN, &sa, NULL);

    timerSpec.it_value.tv_sec = 0;
    timerSpec.it_value.tv_nsec = 500000000; // 500 ms
    timerSpec.it_interval.tv_sec = 0;
    timerSpec.it_interval.tv_nsec = 500000000; // 500 ms

    timer_create(CLOCK_REALTIME, NULL, &timerID);
    timer_settime(timerID, 0, &timerSpec, NULL);

    while (1) {
        pause();
    }

    return 0;
}
These examples cover a wide range of topics relevant to embedded systems engineering, including OS internals, process/thread synchronization, memory layout and access, timers, and memory utilization. Each example provides a working C program to help you understand the concepts and prepare for coding interviews. If you need further explanations or additional examples, feel free to ask!

// PIPE
#include <stdio.h>
#include <unistd.h>

int main() {
    // Get and print the process ID
    pid_t pid = getpid();
    printf("Current Process ID: %d\n", pid);

    // Create a pipe
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork a new process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return 1;
    }

    if (child_pid == 0) { // Child process
        close(pipefd[1]); // Close write end
        char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer)); // Read from pipe
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else { // Parent process
        close(pipefd[0]); // Close read end
        const char *message = "Hello from parent!";
        write(pipefd[1], message, sizeof(message)); // Write to pipe
        close(pipefd[1]);
    }

    return 0;
}

// Important headerfile
Header File	Description	Common Functions/Macros/Types
<stdio.h>	Input/Output functions	printf(), scanf(), fopen(), FILE
<stdlib.h>	General utility functions	malloc(), free(), atoi(), exit()
<string.h>	String handling functions	strlen(), strcpy(), strcat(), strcmp()
<math.h>	Mathematical functions	sin(), cos(), pow(), sqrt()
<ctype.h>	Character handling functions	isalpha(), isdigit(), toupper(), tolower()
<time.h>	Date and time functions	time(), asctime(), gmtime()
<float.h>	Limits of floating-point types	Constants like FLT_MAX, DBL_MIN
<limits.h>	Size of basic data types	Constants like CHAR_BIT, INT_MAX
<errno.h>	Error handling	Macros like errno, functions like perror()
<signal.h>	Signal handling	Functions like signal(), macros like SIGINT
<stdint.h>  typedefs for int typess. like uint8_t, UINT8_MAX etc.

// time usage
#include <stdio.h>
#include <time.h>

int main(void) {
    // Declare a variable to hold the time
    time_t rawtime;
    struct tm *timeinfo;

    // Get the current time
    time(&rawtime);

    // Convert it to local time representation
    timeinfo = localtime(&rawtime);

    // Print the formatted date and time
    printf("Current local time and date: %s", asctime(timeinfo));

    return 0;
}

Thread synchornization apis:
1. accessing hall with 10Guest capacity
2. producer - consumer problme with 2 producer and 2 consumer
3. strict alternation
4. listerner threads // server threads
5. write a program to print odd and even number by 2 threads. (zero semaphore to avoid race condition)
https://www.youtube.com/watch?v=AD3EylLiI7U&list=PLTjcBkvRBqGGbSckyAGLTy05sbPPl6dJA&index=36
https://www.youtube.com/watch?v=Ognzlifblsc&list=PLTjcBkvRBqGGbSckyAGLTy05sbPPl6dJA&index=42

Certainly! Here are more detailed and extensive lists of Reddit threads for each of the mentioned topics. These threads are sourced from various subreddits like r/embedded, r/embeddedlinux, and r/ECE.

Alignments
What is data alignment and why is it important in embedded systems?
How do you handle unaligned memory access in embedded systems?
Alignment issues in embedded systems
Why is data alignment critical in embedded programming?
https://www.linkedin.com/pulse/understanding-aligned-unaligned-memory-access-embedded-shetty/
https://medium.com/@jkstoyanov/aligned-and-unaligned-memory-access-9b5843b7f4ac
Handling unaligned data in embedded C
Data alignment and performance in embedded systems
Alignment and padding in embedded C structures
How to ensure proper data alignment in embedded systems
https://tabreztalks.medium.com/memory-aligned-malloc-6c7b562d58d0?gi=sd
https://m.youtube.com/watch?v=VVoeTIbTK0U&t=574s
Alignment constraints in embedded systems
Data alignment and memory access in embedded systems

Macros

Best practices for using macros in embedded C programming
Why are macros used in embedded systems and what are the alternatives?
Common pitfalls when using macros in embedded C
How to write safe and efficient macros in embedded C
Macros vs inline functions in embedded C
Using macros for register access in embedded systems
Debugging issues caused by macros in embedded C
Conditional compilation using macros in embedded C
Macros for bit manipulation in embedded C
How to avoid macro pitfalls in embedded C programming

Memory Handling

How do you manage memory in embedded systems with limited resources?
What are the common pitfalls in memory management in embedded systems?
[Dynamic memory allocation in embedded systems](https://www.reddit.com/r/embedded/comments/3x9z5j/dynamic_memory_allocation_in_embedded### Memory Handling
How do you manage memory in embedded systems with limited resources?
What are the common pitfalls in memory management in embedded systems?
Dynamic memory allocation in embedded systems
Memory fragmentation issues in embedded systems
Static vs dynamic memory allocation in embedded systems
Memory leaks in embedded systems and how to prevent them
Best practices for memory management in embedded C
https://www.linkedin.com/pulse/memory-management-embedded-systems-kwvkc?utm_source=share&utm_medium=member_ios&utm_campaign=share_via
https://cppcat.com/memory-management-in-embedded-c/
https://moldstud.com/articles/p-addressing-the-challenges-of-memory-management-in-embedded-systems
https://stackoverflow.com/questions/5685454/how-to-optimize-or-reduce-ram-size-in-embedded-system-software
https://www.comarch.com/sw-and-hw-services/blog/part-1-memory-optimization-in-embedded-systems-in-the-c-language-where-to-start/
Handling memory constraints in low-resource embedded systems
https://www.quora.com/How-can-you-reduce-memory-requirements-in-embedded-systems
Memory management techniques for real-time embedded systems
Optimizing memory usage in embedded systems
https://www.linkedin.com/pulse/memory-management-embedded-systems-maximizing-yamil-garcia-5uuae?utm_source=share&utm_medium=member_ios&utm_campaign=share_via
https://www.reddit.com/r/embedded/comments/1fdccl5/why_must_embedded_systems_have_low_ram/

ISR (Interrupt Service Routines)

How to write efficient ISRs in embedded systems?
https://www.linkedin.com/advice/0/what-best-practices-writing-interrupt?utm_source=share&utm_medium=member_ios&utm_campaign=share_via
https://www.embedded.com/5-best-practices-for-writing-interrupt-service-routines/
https://runtimerec.com/best-practices-for-writing-interrupt-service-routines/
What are the best practices for handling interrupts in embedded systems?
Nested interrupts in embedded systems
ISR latency and how to minimize it
https://www.eevblog.com/forum/microcontrollers/interrupt-latency-and-how-can-it-be-minimized/
Common pitfalls in writing ISRs for embedded systems
https://stackoverflow.com/questions/77144545/are-hardware-interrupts-still-needed-on-embedded-devices-as-opposed-to-flags
https://medium.com/@aareshbachana/embedded-systems-interrupts-ab193ecb09e1

How to debug ISRs in embedded systems
ISR vs task in embedded systems
https://www.reddit.com/r/embedded/comments/nthlw7/tasks_in_embedded_systems_from_isr/
https://www.embedded.com/tasks-the-context-switch-and-interrupts/
https://forums.freertos.org/t/understanding-priority-levels-of-isr-and-freertos-apis/10453/2
https://www.geeksforgeeks.org/difference-between-isr-and-function-call/
Handling shared resources in ISRs
https://stackoverflow.com/questions/12738672/c-volatile-keyword-in-isr-and-multithreaded-program
ISR stack usage and optimization
How to handle spurious interrupts in embedded systems

Deadlock

How to avoid deadlocks in embedded systems?
What are the common causes of deadlocks in embedded systems and how to debug them?
Deadlock detection and recovery in embedded systems
https://www.geeksforgeeks.org/deadlock-detection-recovery/

Strategies to prevent deadlocks in real-time systems
[Deadlock vs livelock in embedded systems](### Deadlock
How to avoid deadlocks in embedded systems?
What are the common causes of deadlocks in embedded systems and how to debug them?
Deadlock detection and recovery in embedded systems
Strategies to prevent deadlocks in real-time systems
Deadlock vs livelock in embedded systems
How to handle deadlocks in multi-threaded embedded systems
Common deadlock scenarios in embedded systems
Deadlock prevention techniques in embedded systems
How to debug deadlocks in embedded systems
Deadlock in resource-constrained embedded systems
https://www.baeldung.com/cs/os-deadlock

Cache

https://www.youtube.com/watch?v=dDA3PUr16As&t=13s (find DMA and other topics as well, this is the one for interrupt.)
How does cache memory work in embedded systems?
What are the strategies for cache optimization in embedded systems?
https://library.fiveable.me/embedded-systems-design/unit-11/cache-optimization-strategies/study-guide/IQn5yXgVpESBZV4U#:~:text=Cache%20optimization%20strategies%20are%20crucial,caches%20for%20instructions%20and%20data.
Cache coherence in multi-core embedded systems
How to handle cache misses in embedded systems
https://stackoverflow.com/questions/25984553/is-there-a-way-to-avoid-cache-misses-completely
https://medium.com/@wassimdhokkar/embedded-systems-cache-memory-af3d97f9c4f6
Cache vs no-cache in embedded systems
Cache locking techniques in embedded systems
How to optimize cache usage in embedded systems
Cache hierarchy in embedded systems
Cache-aware programming in embedded systems
How to measure cache performance in embedded systems
https://stackoverflow.com/questions/16242136/how-to-write-a-program-in-c-to-measure-the-speed-of-cache
https://www.geeksforgeeks.org/lru-cache-implementation/

Timer
How to use hardware timers in embedded systems?
What are the best practices for implementing software timers in embedded systems?
Timer interrupts in embedded systems
How to configure timers in embedded systems
[Using timers### Timer
How to use hardware timers in embedded systems?
What are the best practices for implementing software timers in embedded systems?
Timer interrupts in embedded systems
How to configure timers in embedded systems
Using timers for task scheduling in embedded systems
High-resolution timers in embedded systems
Timer accuracy and precision in embedded systems
How to handle timer overflows in embedded systems
Timers and counters in embedded systems
Best practices for using watchdog timers in embedded systems

Scheduler

How to design a real-time scheduler for embedded systems?
What are the common scheduling algorithms used in embedded systems?
Preemptive vs cooperative scheduling in embedded systems
How to implement a round-robin scheduler in embedded systems
https://www.quora.com/Is-context-switching-used-in-a-round-robin-algorithm
https://www.embeddedrelated.com/showarticle/1278.php
https://www.geeksforgeeks.org/program-for-round-robin-scheduling-for-the-same-arrival-time/
Real-time scheduling and deadlines in embedded systems
Priority-based scheduling in embedded systems
How to handle task scheduling in embedded systems
Dynamic vs static scheduling in embedded systems
Scheduler latency and how to minimize it
How to debug scheduling issues in embedded systems
These links should provide you with a wealth of information and community insights on these critical topics in embedded systems. Feel free to explore these discussions for more detailed explanations and practical advice.

Interview questions
https://www.youtube.com/watch?v=qR0rygzxnE4&list=PLW4ZYwPyx8R1V3FUMHb26cRQr1APmZ6fX (Dinesh Panicker 45QnA list on youtube)
