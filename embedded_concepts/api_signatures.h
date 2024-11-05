//DS signatures

// row major form (A)mxn, m is row, n is column
addr(A[i][j]) = Base_addr + [i * n + j] * word_size; // column is needed for row major 
// column major form
addr(A[i][j]) = Base_addr + [j * m + i] * word_size; // row is needed for row major

Above calculation changes to this, if index starts with 1. and hence due to its complex computation, indexing start with 1 is avoided.
// row major form (A)mxn, m is row, n is column
addr(A[i][j]) = Base_addr + [(i-1) * n + (j-1)] * word_size; // column is needed for row major 
// column major form
addr(A[i][j]) = Base_addr + [(j-1) * m + (i-1)] * word_size; // row is needed for row major

for nD array // A[d1][d2][d3][d4]
// row major
addr(A[i1][i2][i3][i4]) = Base_addr + [i1 * d2 * d3 * d4 + i2 * d3 * d4 + i3 * d4 + i4 ] * word_size;
// column major
addr(A[i1][i2][i3][i4]) = Base_addr + [i4 * d1 * d2 * d3 + i3 * d1 * d2 + i2 * d1 + i1 ] * word_size;

//

// permutation
// C program to print all permutations 
// with duplicates allowed 
#include <stdio.h> 
#include <string.h> 

/* Function to swap values at 
two pointers */
void swap(char *x, char *y) 
{ 
	char temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 

/* Function to print permutations 
of string 
This function takes three parameters: 
1. String 
2. Starting index of the string 
3. Ending index of the string. */
void permute(char *a, int l, int r) 
{ 
	int i; 
	if (l == r) 
		printf("%s\n", a); 
	else
	{ 
		for (i = l; i <= r; i++) 
		{ 
			swap((a + l), (a + i)); 
			permute(a, l + 1, r); 

			//backtrack 
			swap((a + l), (a + i)); 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	char str[] = "ABC"; 
	int n = strlen(str); 
	permute(str, 0, n-1); 
	return 0; 
} 


TIMER

typedef struct {
    uint32_t lower;      // Lower 32 bits
    uint32_t upper;      // Upper 32 bits (overflow count)
    uint32_t timeout;    // Timeout in microseconds
    void (*callback)(void); // Callback function
} Timer64;

 // Set up the signal handler for the timer
signal(SIGALRM, timerHandler);

// Set up a timer to trigger every microsecond
struct itimerval it_val;
it_val.it_value.tv_sec = 0;
it_val.it_value.tv_usec = 1; // Trigger every microsecond
it_val.it_interval.tv_sec = 0;
it_val.it_interval.tv_usec = 1; // Repeat every microsecond

setitimer(ITIMER_REAL, &it_val, NULL);

// LRU
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
LRUCache* createCache(int capacity);
void removeNode(LRUCache* cache, Node* node);
void addToFront(LRUCache* cache, Node* node);
int get(LRUCache* cache, int key);
void put(LRUCache* cache, int key, int value);
void freeCache(LRUCache* cache);

// lru cache miss
typedef struct Cache {
    int* data;
    int size;
    int hits;
    int misses;
} Cache;

void accessCache(Cache* cache, int value);
Cache* createCache(int size);

//ut
#include <gmock/gmock.h>
#include <gmock-global/gmock-global.h>
// for registering the mock api
MOCK_GLOBAL_FUNC2(mock_write_reg32, void(volatile uint32_t *, uint32_t));
MOCK_GLOBAL_FUNC2(mock_read_reg32, void(volatile uint32_t *, uint32_t *));
// for mapping
USE_GMOCK(write_reg32, mock_write_reg32);
USE_GMOCK(read_reg32, mock_read_reg32);
#include <gtest/gtest.h>
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
TEST_F(RegisterTest, ReadRegisterValue){
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

void insert(DNode **head, int data, int position); // cases, 
// add at a given position [stop before position]
// before first node, code is different, after given pos, then need loop till pos-1 and make pointer P point there and change pointers with t, and next node.
// basically code gets split in pos==0 and pos>0 condition. in while also check if p is non-null.
https://www.udemy.com/course/datastructurescncpp/learn/lecture/13133198#overview

// creating a list
// you can opt for always adding at last, so use adt and use pointer which is pointing to last

// adding in a sorted list
// use slow and fast pointer, q=NULL and p=head pinter apporach.
// use while to just keep on moving, don't forget the condition to check if p is non-null.

void delete(DNode **head, int position);
// case
// 2 cases are present. 
// 1. Delete at head
// 2. Delete the node at given position.
// two pointers required for deleting at the given position, so use slow and fast pointer. q=NULL and p=head. same as case in adding at sorted list. always check p non-null

DNode* search(DNode *head, int data); 
// case
// search the node and move to head.
// This needs q pointer, slow pointer

void traverse(DNode *head);

// misc
// problem - check if list is sorted.
// keep on moving in list, but store the value in x, before moving, so that next time you can compare prev value. if condition fail, then return false.

// problem - remove elements in sorted linkedlist
// 2 pointers required. p on head, and next q, if current and next data same, then delete next node, and change pointers, delete q, and make q = p->next;
// while q or fast pointer doesn't get null.

// reversing the linked list
// case reversing the data
// this needs extra array, and 2 sequential while loop.
// case reversing list
// 1. using sliding pointerse
// p = first, q, r = NULL. 
// while(p){
// 	r = q;
//	q = p;
// 	p = p->next;
//	q->next = r;
// }
// first = q;

// 2. recusion
// reverse(NULL, head);
//
// void reverse(node *q, node *p){
// 	if(p){
//		revese(p, p->next);
//		p->next = q; // NULL assignment is taken care here.
//	} else {
//		head = q;
//	}
// }

// problem : concating two list
// keep until end of first list, and then keep attach next's head as last node's next.

// problem: merging two list
// you need first third pinter for poiting to new merged list, 
// then last pointer, which is always waiting for right node to move ahead.
// fist and second will move in their list respectively.
// if (f->data > s->data)
// third = first,
// last = first,
// last->next = null;
// first = first->next;
// then while(first && second){
//	if(first < second){
//		last->next = first, last = first, first = first->next, last->next = NULL;
//	} else {
//		last->next = second, last = second, second = second->next, last->next = NULL;
// 	}
//    }
//	if (first) last->next = first;
//	else last->next = second;
//}

// problem check loop
// fast and slow pointer,
// keep on going in while, till we have fast pointer doesn't reach null,
// start with p =head ,q= head, use do while, and keep on progressing, while(q && q!=p);

// circular linkedlist
// 2 representation. 1 is standard, but then it becomes hard to identify if list is circular or not in case of empty. so there is second representation
// which helps to have one node, just to make point at any list node. and this special extra node would be called as head node.

// problem: display all elements of circular linked list
// this needs flag. if(flag == 0 || p != head) {enter the loop}

// problem: insert in circular linkedlist.
// inserting at head means, reaching to last node, and then modify next pointer, and insert. inserting at head or after last node are same. 
// if (pos == 0){ 
//	if (!head) { do something } else {do something. by the way, here, you don't need to change head as it's circular list};
// 	else add as if inserting at particular position. 

// problem: delete in circluar list. 
// anyother node (pose-2), head node (move upto last node). 2 cases will be there.

// doubly list

// problem: insert in doubly linkedlist.
// case
// 1. head node. directly possible
// 2. any other node. move to before that location, and play around pointers.
// 


// problem: reverse a doubly list
// while(p){
//	temp = p->next;
//	p->next = p->prev;
// 	p->prev = temp;
//	p = p->prev;
// 	// now check for the last node to move head there.
//	if(p->next == NULL) head = p;
//}

// problem: finding loop
// p = q = head;
// while(q){
//	q = q->next;
//	if(q) q = q->next;
//	p = p->next;
//	if(p==q) return true;
// }
// return false;
//

// problem: finding intersection
// p = first;
// while(p) push(&stk1, p);
// p = second;
// while(p) push(&stk2, p);
// while(top(&stk1) == top(&stk2)){
//	p = pop(&stk1); pop(&stk2);
// }
// printf("%d", p->data);

//HEAP

// problem - insert in heap
// make sure to start with 1 index, then add at last, check with parent [i/2], swap(just move parent to i location), keep on doing that, until right spot found.
// at last assign at ith position. (outside loop).
// you give array and poisiton for insertion
// insert_heap(int a[], int n) {
//	temp = a[n];
//	while(i>1 && temp > A[i/2]){
//		A[i] = A[i/2];
//		i = i/2;
//	}
//	A[i] = temp;
//}

// problem: delete from heap. always take highest element/root/priority element from the heap.
// remove root,
// shift last element to root position
// compare it's child (left child is j, right is j+1), and swap with max element.
// now as last lement at the second level, compare its child and swap with max.
// keep on going, until we reach a point where child are not anymore greater than that element.
// int x, i =1, j = 2*i;
// x = A[n];
// A[1] = A[n];
// while(j < n-1){
//	if(a[j+1] > A[j]){
//		j = j+1;
//	}
//	if(A[j] > A[i]){
//		swap(A[i], A[j]);
//		i = j;
//		j = 2*i;
//	} else {
//		break;
//	}
//}

// heap support insertion and deletion in log(n) which is better than linear approach.

// problelm: heapify O(n) // half of elements are not moved.
// this works opposite to insert/create heap operation O(nlogn)
// start from last, and compare with both child, if lesser, swap.
// keep on moving towards root node like this.

// problem: 
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
Pthreas_mutex_trylock(&mutexOb); // returns EBUSY if lock is already acquired
https://youtu.be/OIKr2ll2Nd8?si=Ow5FjHWo8JWvKpzg
Pthread_mutex_unlock(&mutexOb);
pthread_mutexattr_t attr;
pthread_mutexattr_init(&attr);
pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);
pthread_mutex_init(&resource_mutex, &attr);

// barrier
pthread_barrier_t barrier; // can be global so that in routine one can wait.
pthread_barrier_init(&barrier, NULL, barrier_cnt);
pthread_barrier_destroy(&barrier);
pthread_barrier_wait(&barrier); // call this in thread routine so that it gets bloacked until barrier_cnt gets hit
https://www.youtube.com/watch?v=_P-HYxHsVPc&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=14
https://youtube.com/watch?v=MDgVJVIRBnM&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=15

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

//message quuee
#include <mqueue.h>
#define QUEUE_NAME "/message_queue"
#define MAX_MESSAGES 10
#define MAX_MESSAGE_SIZE 256
mqd_t mq;

struct mq_attr attr;
attr.mq_flags = 0;
attr.mq_maxmsg = MAX_MESSAGES;
attr.mq_msgsize = MAX_MESSAGE_SIZE;
attr.mq_curmsgs = 0;

mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);

char message[MAX_MESSAGE_SIZE] = "Hello, World!";
while (1) {
    mq_send(mq, message, sizeof(message), 0);
    sleep(1);
}

char message[MAX_MESSAGE_SIZE];
while (1) {
    mq_receive(mq, message, sizeof(message), NULL);
    printf("Received message: %s\n", message);
}

mq_close(mq);
mq_unlink(QUEUE_NAME);

// spinlock

volatile bool lock = false;

void SpinlockAcquire(void) {
    while (__sync_lock_test_and_set(&lock, 1)) {
        // Busy-wait until the lock is acquired
    }
}

void SpinlockRelease(void) {
    __sync_lock_release(&lock);
}

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

// 1. ALIGN: Aligns a value to the nearest multiple of a given alignment.
#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))

// 2. IS_ALIGNED: Checks if a value is aligned to a given alignment.
#define IS_ALIGNED(x, a) (((x) & ((a) - 1)) == 0)

// 3. ALIGN_DOWN: Aligns a value down to the nearest multiple of a given alignment.
#define ALIGN_DOWN(x, a) ((x) & ~((a) - 1))

// 4. ALIGN_UP: Aligns a value up to the nearest multiple of a given alignment.
#define ALIGN_UP(x, a) ALIGN((x), (a))

// 5. PTR_ALIGN: Aligns a pointer to the nearest multiple of a given alignment.
#define PTR_ALIGN(p, a) ((typeof(p))ALIGN((unsigned long)(p), (a)))

// 6. PTR_ALIGN_DOWN: Aligns a pointer down to the nearest multiple of a given alignment.
#define PTR_ALIGN_DOWN(p, a) ((typeof(p))ALIGN_DOWN((unsigned long)(p), (a)))

// 7. PTR_ALIGN_UP: Aligns a pointer up to the nearest multiple of a given alignment.
#define PTR_ALIGN_UP(p, a) ((typeof(p))ALIGN_UP((unsigned long)(p), (a)))

// 8. ALIGN_MASK: Aligns a value to the nearest multiple of a given alignment mask.
#define ALIGN_MASK(x, mask) (((x) + (mask)) & ~(mask))

// 9. IS_POWER_OF_TWO: Checks if a value is a power of two.
#define IS_POWER_OF_TWO(x) ((x) != 0 && ((x) & ((x) - 1)) == 0)

// 10. ROUND_UP: Rounds a value up to the nearest multiple of a given alignment.
#define ROUND_UP(x, a) ALIGN((x), (a))

// 11. ROUND_DOWN: Rounds a value down to the nearest multiple of a given alignment.
#define ROUND_DOWN(x, a) ALIGN_DOWN((x), (a))

// 12. PAGE_ALIGN: Aligns a value to the nearest page boundary.
#define PAGE_ALIGN(x) ALIGN((x), PAGE_SIZE)

// 13. CACHE_LINE_SIZE: Defines the size of a cache line.
#define CACHE_LINE_SIZE 64

// 14. CACHE_ALIGN: Aligns a value to the nearest cache line boundary.
#define CACHE_ALIGN(x) ALIGN((x), CACHE_LINE_SIZE)

// 15. CACHE_ALIGNED: Ensures a variable is cache line aligned.
#define CACHE_ALIGNED __attribute__((aligned(CACHE_LINE_SIZE)))

// 16. ALIGNOF: Gets the alignment requirement of a type.
#define ALIGNOF(type) __alignof__(type)

// 17. ALIGNED: Ensures a variable is aligned to a specified boundary.
#define ALIGNED(x) __attribute__((aligned(x)))

// 18. UNALIGNED: Marks a pointer as unaligned.
#define UNALIGNED __attribute__((packed))

// 19. READ_ONCE: Reads a variable once, ensuring no reordering.
#define READ_ONCE(x) (*(volatile typeof(x) *)&(x))

// 20. WRITE_ONCE: Writes to a variable once, ensuring no reordering.
#define WRITE_ONCE(x, val) (*(volatile typeof(x) *)&(x) = (val))

// 21. ACCESS_ONCE: Accesses a variable once, ensuring no reordering.
#define ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x))

```c
// 22. BARRIER: Prevents compiler reordering of memory accesses.
#define BARRIER() asm volatile("" ::: "memory")

// 23. MEM_BARRIER: Ensures memory operations are completed before proceeding.
#define MEM_BARRIER() asm volatile("" ::: "memory")

// 24. DATA_BARRIER: Ensures data memory operations are completed before proceeding.
#define DATA_BARRIER() asm volatile("" ::: "memory")

// 25. INSTRUCTION_BARRIER: Ensures instruction memory operations are completed before proceeding.
#define INSTRUCTION_BARRIER() asm volatile("" ::: "memory")

// 26. READ_MEMORY_BARRIER: Ensures read memory operations are completed before proceeding.
#define READ_MEMORY_BARRIER() asm volatile("" ::: "memory")

// 27. WRITE_MEMORY_BARRIER: Ensures write memory operations are completed before proceeding.
#define WRITE_MEMORY_BARRIER() asm volatile("" ::: "memory")

// 28. FULL_MEMORY_BARRIER: Ensures all memory operations are completed before proceeding.
#define FULL_MEMORY_BARRIER() asm volatile("" ::: "memory")

// 29. VOLATILE_READ: Reads a volatile variable.
#define VOLATILE_READ(x) (*(volatile typeof(x) *)&(x))

// 30. VOLATILE_WRITE: Writes to a volatile variable.
#define VOLATILE_WRITE(x, val) (*(volatile typeof(x) *)&(x) = (val))


// passing an array
int arr[3]
print(arr); in function definition, print(int *arr) or print(int arr[])
array name is pointer to first element of the array.
here, arr means pointer to int. i.e. int *arr
if arr is 2D. ie..e arr[3][4]
print(arr), then while catching
it is interpreted as, pointer to first element, which is int [4]
i.e. print(int (*arr)[4]), which is basically pointer to array of 4 integer.
catching collumn size is mandatory as it will give idea to compiler about step size, while increamenting.
hence, if we want to print 2D array, one need to pass additional row element, as use, 
might not be aware of how many pointer to int [4] array might be having.


malloc rule:
collecting pointer type and malloc return pointer type has to be same.
malloc return type's dereference will be type of used inside sizeof()
so if we have int **arr.
and we want to do malloc
arr = (int **)malloc(sizeof(int *) * num)
if you see here, arr is double pointer, but dereferncing double pointer will give int *
which is inside sizeof().

// Ideal hashing
h(x)=x // constant storing and retrival time. disadvantage: collision.

-- resolve collision

- open hashing
--> allowed to consume extraspaces. 
- 1. Chaining, 
make linkedlist in case of collision, keys are inserted in sorted order.
analysis is based on loading factor. lembda = number of keys / hash table size. 
if h(x) = x%10, and keys are 100, and as size is 10. lembda = 10. each position takes 10 keys in the idea scenario.
- search time = 1 + lembda/2. 1 for hash function location, and lembda/2 for searching in list. this is average time.
- worse case time = 1 + lebda, in unsuccessful search
- delete is like, delete in linkedlist.
5, 115, 45, 95, 35, 335, 45. here be wise and choose right hash function. e.g. h(x) = (x/10) % 10. i.e. hashing based on second digit.
based on key, choose your hash function

- closed hashing
--> allowed to store at anyother free space. not by force will store at given space only, which is provided by hash function.
-- open addressing
1. linear : h'(x) = (h(x) + f(i)) % 10. i = 0, 1, ..., 9
2. quadratic : h'(x) = (h(x) + i ^ 2) % 10. i = 0, 1, ..., 9 . to store element at distant place, and avoid clustering of elements.
3. Double hashing : h1(x) = x % 10,  h2(x) = R - (x % R), h'(x) = (h1(x) + i *h2(x)) i = 0, 1, ..., 9. R is closest prime number to size of hash table, i.e. 7.
here idea is to use all the places which of the table, and also avoid clustering.

-- tree traversal
- pre, pos, in. if given number of nodes in any traversal manner or order, then 2nCn/(n+1) , catalon number, these many shapes are possible.
- to create a tree, we need post-in or pre-in these kind of 2 orders for given nodes, then only tree can be generated. pre-post gives more than 1 tree possible shapes.
- tree level order traversal and creation is possible only using queue.
- pre, in, post are easy recursive way of traversals.

