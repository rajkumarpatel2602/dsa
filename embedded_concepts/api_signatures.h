//DS signatures

// Arrays

void insert(int arr[], int *size, int element, int position);
void delete(int arr[], int *size, int position);
int search(int arr[], int size, int element);
void traverse(int arr[], int size);

// Singly Linked List
typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert(Node **head, int data, int position);
void delete(Node **head, int position);
Node* search(Node *head, int data);
void traverse(Node *head);

// Doubly Linked List
typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

void insert(DNode **head, int data, int position);
void delete(DNode **head, int position);
DNode* search(DNode *head, int data);
void traverse(DNode *head);

// Trees
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void insert(TreeNode **root, int data);
TreeNode* delete(TreeNode *root, int data);
TreeNode* search(TreeNode *root, int data);
void inorder(TreeNode *root);
void preorder(TreeNode *root);
void postorder(TreeNode *root);

// Binary Search Tree (BST)
typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

void insertBST(BSTNode **root, int data);
BSTNode* deleteBST(BSTNode *root, int data);
BSTNode* searchBST(BSTNode *root, int data);
void inorderBST(BSTNode *root);
void preorderBST(BSTNode *root);
void postorderBST(BSTNode *root);

// HashMap (Hash Table)
typedef struct HashMap {
    int *keys;
    int *values;
    int size;
    int capacity;
} HashMap;

void insertHashMap(HashMap *map, int key, int value);
void deleteHashMap(HashMap *map, int key);
int searchHashMap(HashMap *map, int key);
void traverseHashMap(HashMap *map);

// Sorting Algorithms
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
void heapSort(int arr[], int size);
void radixSort(int arr[], int size);
void countingSort(int arr[], int size);

// Pthread signatures

// mutex
Pthread_mutex_t mutexOb;
Pthreas_mutex_lock(&mutexOb);
Pthread_mutex_unlock(&mutexOb);

// spinlock
pthread_spin_lock()
pthread_spin_unlock()

// pthread creatinon and attribute setting apis
    
/* Mark the thread eligible for cancellation */
pthread_setcancelstate(PTHREAD_CANCEL_ENABLE /* PTHREAD_CANCEL_DISABLE */, 0);
// parent thread use below macro while creating thread
pthread_setcancelthread = PTHREAD_CANCEL_ENABLE
/* Mode of cancellation */
pthread_setcanceltype( PTHREAD_CANCEL_ASYNCHRONOUS, 0);
// thread calls this to set cancellation type. only applicable if thread is cancellable.
pthread_setcanceltype()
// deferred cancellation, checks if cancellationr requests has come or not, if yes then call cleanup handler and cancel the threads.
pthread_testcancel() 
// therad create
pthread_create()
// thread exit
pthread_exit()

// Conditional variable
pthread_cond_t cv;
/* initalization */
pthread_cond_init(&cv, 0)
/* makes the trhead go block if condition is not met */
pthread_cond_wait(&cv, &mutex)
/* makes the blocked thread go resume if condition is set by this one */
pthread_cond_signal(&cv);
/* unblock each blocked thread 1 by 1. No need to write cond_signal() 3 times, if 3 threads are blocked */
pthead_cond_broadcast(&cv);
    
// Semaphre API
1. sem_t sem;
/* Declare semaphore variable */
e.g. sem_init(&sem, 0 , 0);
Strict alternation:: always post is bound to happen by a starting thread and making other thread wait for post by started thread.
2. sem_init(sem_t * sem, int pshared, int permit_counter);
/* Initialise semaphore variable */
set pshared = 0 for threads, for precess give ~0 value.
3. sem_wait(sem_t * sem);
/* block calling thread or process if semaphore is not available */
4. sem_post(sem_t * sem);
/*  signal the blocked theread on semaphore */
5. sef_destroy(sem_t * sem);
/* destroy the thrad after use */

// Macros

// 1. offsetof: Finds the offset of a member within a structure.
#include <stddef.h>
#define offsetof(type, member) ((size_t) &((type *)0)->member)

// 2. container_of: Gets the container structure from a member pointer.
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

// 3. MIN: Finds the minimum of two values.
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// 4. MAX: Finds the maximum of two values.
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 5. BIT: Creates a bitmask with a single bit set.
#define BIT(n) (1U << (n))

// 6. ARRAY_SIZE: Finds the number of elements in an array.
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// 7. ALIGN: Aligns a value to the nearest multiple of a given alignment.
#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))

// 8. ROUND_UP: Rounds a value up to the nearest multiple of a given alignment.
#define ROUND_UP(x, a) (((x) + (a) - 1) & ~((a) - 1))

// 9. ROUND_DOWN: Rounds a value down to the nearest multiple of a given alignment.
#define ROUND_DOWN(x, a) ((x) & ~((a) - 1))

// 10. IS_ALIGNED: Checks if a value is aligned to a given alignment.
#define IS_ALIGNED(x, a) (((x) & ((a) - 1)) == 0)

// 11. likely: Hints that a condition is likely to be true.
#define likely(x) __builtin_expect(!!(x), 1)

// 12. unlikely: Hints that a condition is unlikely to be true.
#define unlikely(x) __builtin_expect(!!(x), 0)

// 13. BUG: Triggers a bug check.
#define BUG() do { \
    printf("BUG at %s:%d\n", __FILE__, __LINE__); \
    abort(); \
} while (0)

// 14. WARN: Issues a warning.
#define WARN(condition, message) do { \
    if (condition) \
        printf("Warning: %s\n", message); \
} while (0)

// 15. BUILD_BUG_ON: Causes a compile-time error if a condition is true.
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

// 16. DIV_ROUND_UP: Divides and rounds up.
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

// 17. clamp: Clamps a value between a minimum and maximum.
#define clamp(val, min, max) ((val) < (min) ? (min) : (val) > (max) ? (max) : (val))

// 18. swap: Swaps two values.
#define swap(a, b) do { \
    typeof(a) _tmp = (a); \
    (a) = (b); \
    (b) = _tmp; \
} while (0)

// 19. FIELD_SIZEOF: Gets the size of a field in a structure.
#define FIELD_SIZEOF(t, f) (sizeof(((t*)0)->f))

// 20. WRITE_ONCE: Ensures a variable is written only once.
#define WRITE_ONCE(x, val) (*((volatile typeof(x) *)&(x)) = (val))

// APIs

// 1. printf: Prints formatted output to stdout.
printf("Hello, World!\n");

// 2. scanf: Reads formatted input from stdin.
int num;
scanf("%d", &num);

// 3. fopen: Opens a file.
FILE *file = fopen("data.txt", "r");

// 4. fclose: Closes a file.
fclose(file);

// 5. fread: Reads data from a file.
fread(buffer, sizeof(char), 100, file);

// 6. fwrite: Writes data to a file.
fwrite(buffer, sizeof(char), 100, file);

// 7. malloc: Allocates memory.
int *arr = (int *)malloc(10 * sizeof(int));

// 8. calloc: Allocates and zeroes memory.
int *arr = (int *)calloc(10, sizeof(int));

//```c
// 9. realloc: Reallocates memory.
arr = (int *)realloc(arr, 20 * sizeof(int));

// 10. free: Frees allocated memory.
free(arr);

// 11. strcpy: Copies a string.
strcpy(dest, src);

// 12. strncpy: Copies a specified number of characters from a string.
strncpy(dest, src, n);

// 13. strcat: Concatenates two strings.
strcat(dest, src);

// 14. strncat: Concatenates a specified number of characters from one string to another.
strncat(dest, src, n);

// 15. strcmp: Compares two strings.
int result = strcmp(str1, str2);

// 16. strncmp: Compares a specified number of characters from two strings.
int result = strncmp(str1, str2, n);

// 17. strlen: Returns the length of a string.
size_t len = strlen(str);

// 18. memcpy: Copies memory.
memcpy(dest, src, n);

// 19. memset: Sets memory to a specified value.
memset(dest, 0, n);

// 20. memmove: Moves memory, handling overlapping regions.
memmove(dest, src, n);
