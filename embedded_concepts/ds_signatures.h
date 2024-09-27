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
