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
Pthread_mutex_t mutexOb;
Pthreas_mutex_lock(&mutexOb);
Pthread_mutex_unlock(&mutexOb);
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
