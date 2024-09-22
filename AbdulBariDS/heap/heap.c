#include<stdio.h>
#include<stdint.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

void insert_heap(int arr[], int end){
    int i = end;
    int temp = arr[i];

    // O(logn)
    while(i > 0 && temp > arr[ i%2 ? i/2 : i/2 - 1]){
        arr[i] = arr[i%2 ? i/2 : i/2 - 1];
        i = i%2 ? i/2 : i/2 -1;
    }
    arr[i] = temp;
}


void insert_heap_idx_one(int a[], int n) {
    int temp = a[n];
    int i = n;
    while(i > 1 && temp > a[i/2]) {
            a[i] = a[i/2];
            i = i/2;
    }
    a[i] = temp;
}

void create_heap() {

    // input array
    int arr[] = {10, 20, 30, 25, 5, 40, 35};
    int arr_size =  sizeof(arr)/sizeof(int);

    // insert in heap
    // O(nlogn)
    for (int end=0; end < arr_size; end++){
        insert_heap(arr, end);
    }

    // print max heap
    for(int i=0; i < arr_size; i++) {
        printf("%d ::", arr[i]);
    }
}

void swap(int *m, int *n) {
    int temp = *m;
    *m = *n;
    *n = temp;
}

void delete_heap(int arr[], int last) {
    int x = arr[last], res = INT32_MIN;
    arr[0] = x;

    int pos= 0, j = pos+1;

    while((pos < last) && (arr[pos] < (res = MAX(arr[j], arr[j + 1])))) {
        if (res == arr[j]){
            swap(&arr[pos], &arr[j]);
            pos = j;
        } else {
            swap(&arr[pos], &arr[j + 1]);
            pos = j + 1;;
        }
        j = pos * 2 + 1;
    }
}

void delete_heap_idx_one(int a[], int end) {
    int temp = a[1];
    a[1] = a[end];

    int i = 1, j = 2 * i;
    
    while( j < end ){
        if ( a[j] < a[j+1] ) {
            j = j + 1;
        }
        swap(&a[i], &a[j]);
        i = j;
        j = 2 * i;
    }
    a[end] = temp;
}

int main(int args, char **argv) {
    //inplace
    create_heap();

    int arr[] = {40, 25, 35, 10, 5, 20, 30};

    printf("\ndelete first element : %d\n", arr[0]);

    delete_heap(arr, 6);

    // print max heap
    for(int i=0; i < 6; i++) {
        printf("%d ::", arr[i]);
    }

    int a[] = {0, 10, 100, 23, 17, 8, 200, 90, 2};

    O(nlogn)
    // heapify array
    for(int i=2; i < 9; i++){
        insert_heap_idx_one(a, i);
    }

    // print heap
    printf("\nwith indexing 1:\n");
    for(int i = 0; i < 9; i++) {
        printf("%d ::", a[i]);
    }

    O(nlogn)
    // delete heap and place elements properly
    for(int end=8; end > 0; end--) {
        delete_heap_idx_one(a, end);
    }

    // print sorted array
    printf("\nafter heap sort\n");
    for(int i = 0; i < 9; i++) {
        printf("%d ::", a[i]);
    }
}
