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


/*
Storing 16MB of Entries in 10MB of RAM
Problem: Given a sequence of numbers from 0 to 16MB, where each number can hold a Boolean value, design a solution to store this information in 10MB of RAM.

 You want to store a sequence of numbers from 0 to 16MB, where each number can hold a Boolean value (true or false), and you need to fit this information into 10MB of RAM. This is a classic use case for a bitmap or bit array.

Solution: Using a Bitmap
A bitmap (or bit array) is an efficient way to store Boolean values. Each bit in the bitmap represents a Boolean value for a corresponding number in the sequence. Since each bit can represent a Boolean value, we can store 8 Boolean values in a single byte.

Calculation
Total numbers: 16MB = 16 * 1024 * 1024 = 16,777,216 numbers
Bits required: 16,777,216 bits
Bytes required: 16,777,216 bits / 8 = 2,097,152 bytes = 2MB
Since 2MB is much less than 10MB, we can easily fit the bitmap into the available RAM.
*/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_NUMBERS (16 * 1024 * 1024) // 16MB
#define BITMAP_SIZE (TOTAL_NUMBERS / 8) // 2MB

uint8_t bitmap[BITMAP_SIZE];

// Set the bit at the given index
void set_bit(uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

// Clear the bit at the given index
void clear_bit(uint32_t index) {
    bitmap[index / 8] &= ~(1 << (index % 8));
}

// Get the value of the bit at the given index
bool get_bit(uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

int main(void) {
    // Initialize the bitmap to all zeros
    memset(bitmap, 0, BITMAP_SIZE);

    // Set some bits
    set_bit(0);
    set_bit(1);
    set_bit(16 * 1024 * 1024 - 1); // Last bit

    // Get and print the values of some bits
    printf("Bit 0: %d\n", get_bit(0));
    printf("Bit 1: %d\n", get_bit(1));
    printf("Bit 2: %d\n", get_bit(2));
    printf("Last bit: %d\n", get_bit(16 * 1024 * 1024 - 1));

    // Clear some bits
    clear_bit(1);
    printf("Bit 1 after clearing: %d\n", get_bit(1));

    return 0;
}
/*
Finding Duplicate Numbers in a Large Dataset
Problem: Given a large dataset of integers ranging from 0 to N, find all the duplicate numbers.
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALUE 1000000
#define BITMAP_SIZE (MAX_VALUE / 8)

uint8_t bitmap[BITMAP_SIZE];

void set_bit(uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

bool get_bit(uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

void find_duplicates(int *data, int size, int max_value) {
    memset(bitmap, 0, BITMAP_SIZE);
    for (int i = 0; i < size; i++) {
        if (get_bit(data[i])) {
            printf("Duplicate: %d\n", data[i]);
        } else {
            set_bit(data[i]);
        }
    }
}

int main(void) {
    int data[] = {1, 2, 3, 4, 5, 3, 2, 1};
    int size = sizeof(data) / sizeof(data[0]);
    find_duplicates(data, size, MAX_VALUE);
    return 0;
}
/*

Checking for Missing Numbers in a Sequence
Problem: Given a sequence of numbers from 0 to N with some numbers missing, find all the missing numbers.
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALUE 1000000
#define BITMAP_SIZE (MAX_VALUE / 8)

uint8_t bitmap[BITMAP_SIZE];

void set_bit(uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

bool get_bit(uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

void find_missing_numbers(int *data, int size, int max_value) {
    memset(bitmap, 0, BITMAP_SIZE);
    for (int i = 0; i < size; i++) {
        set_bit(data[i]);
    }
    for (int i = 0; i < max_value; i++) {
        if (!get_bit(i)) {
            printf("Missing: %d\n", i);
        }
    }
}

int main(void) {
    int data[] = {0, 1, 2, 4, 5, 7, 8, 9};
    int size = sizeof(data) / sizeof(data[0]);
    find_missing_numbers(data, size, 10);
    return 0;
}

/*

Detecting Unique Characters in a String
Problem: Given a string, determine if all characters are unique.
*/
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define CHAR_RANGE 256
#define BITMAP_SIZE (CHAR_RANGE / 8)

uint8_t bitmap[BITMAP_SIZE];

void set_bit(uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

bool get_bit(uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

bool are_all_characters_unique(char *str) {
    memset(bitmap, 0, BITMAP_SIZE);
    for (int i = 0; i < strlen(str); i++) {
        if (get_bit((uint8_t)str[i])) {
            return false;
        }
        set_bit((uint8_t)str[i]);
    }
    return true;
}

int main(void) {
    char str[] = "abcdefg";
    if (are_all_characters_unique(str)) {
        printf("All characters are unique\n");
    } else {
        printf("Characters are not unique\n");
    }
    return 0;
}

/*

Finding Intersection of Two Sets
Problem: Given two sets of integers, find their intersection.
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALUE 1000000
#define BITMAP_SIZE (MAX_VALUE / 8)

uint8_t bitmap1[BITMAP_SIZE];
uint8_t bitmap2[BITMAP_SIZE];

void set_bit(uint8_t *bitmap, uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

bool get_bit(uint8_t *bitmap, uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

void find_intersection(int *set1, int size1, int *set2, int size2, int max_value) {
    memset(bitmap1, 0, BITMAP_SIZE);
    memset(bitmap2, 0, BITMAP_SIZE);
    for (int i = 0; i < size1; i++) {
        set_bit(bitmap1, set1[i]);
    }
    for (int i = 0; i < size2; i++) {
        set_bit(bitmap2, set2[i]);
    }
    for (int i = 0; i < max_value; i++) {
        if (get_bit(bitmap1, i) && get_bit(bitmap2, i)) {
            printf("Common element: %d\n", i);
        }
    }
}

int main(void) {
    int set1[] = {1, 2, 3, 4, 5};
    int set2[] = {4, 5, 6, 7, 8};
    int size1 = sizeof(set1) / sizeof(set1[0]);
    int size2 = sizeof(set2) / sizeof(set2[0]);
    find_intersection(set1, size1, set2, size2, MAX_VALUE);
    return 0;
}
/*

Counting Distinct Elements in a Stream
Problem: Given a stream of integers, count the number of distinct elements.
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALUE 1000000
#define BITMAP_SIZE (MAX_VALUE / 8)

```c
#define MAX_VALUE 1000000
#define BITMAP_SIZE (MAX_VALUE / 8)

uint8_t bitmap[BITMAP_SIZE];

void set_bit(uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

bool get_bit(uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

int count_distinct_elements(int *stream, int size, int max_value) {
    memset(bitmap, 0, BITMAP_SIZE);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!get_bit(stream[i])) {
            set_bit(stream[i]);
            count++;
        }
    }
    return count;
}

int main(void) {
    int stream[] = {1, 2, 3, 4, 5, 3, 2, 1};
    int size = sizeof(stream) / sizeof(stream[0]);
    int distinct_count = count_distinct_elements(stream, size, MAX_VALUE);
    printf("Number of distinct elements: %d\n", distinct_count);
    return 0;
}
/*

Finding the First Missing Positive Integer
Problem: Given an unsorted array of integers, find the smallest missing positive integer.

*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALUE 1000000
#define BITMAP_SIZE (MAX_VALUE / 8)

uint8_t bitmap[BITMAP_SIZE];

void set_bit(uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

bool get_bit(uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

int find_first_missing_positive(int *data, int size) {
    memset(bitmap, 0, BITMAP_SIZE);
    for (int i = 0; i < size; i++) {
        if (data[i] > 0 && data[i] < MAX_VALUE) {
            set_bit(data[i]);
        }
    }
    for (int i = 1; i < MAX_VALUE; i++) {
        if (!get_bit(i)) {
            return i;
        }
    }
    return -1; // All positive integers up to MAX_VALUE are present
}

int main(void) {
    int data[] = {3, 4, -1, 1};
    int size = sizeof(data) / sizeof(data[0]);
    int missing = find_first_missing_positive(data, size);
    printf("First missing positive integer: %d\n", missing);
    return 0;
}
/*
Checking for Anagrams
Problem: Given two strings, determine if they are anagrams of each other.
*/
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define CHAR_RANGE 256
#define BITMAP_SIZE (CHAR_RANGE / 8)

uint8_t bitmap1[BITMAP_SIZE];
uint8_t bitmap2[BITMAP_SIZE];

void set_bit(uint8_t *bitmap, uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

bool get_bit(uint8_t *bitmap, uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

bool are_anagrams(char *str1, char *str2) {
    if (strlen(str1) != strlen(str2)) {
        return false;
    }
    memset(bitmap1, 0, BITMAP_SIZE);
    memset(bitmap2, 0, BITMAP_SIZE);
    for (int i = 0; i < strlen(str1); i++) {
        set_bit(bitmap1, (uint8_t)str1[i]);
        set_bit(bitmap2, (uint8_t)str2[i]);
    }
    for (int i = 0; i < BITMAP_SIZE; i++) {
        if (bitmap1[i] != bitmap2[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    char str1[] = "listen";
    char str2[] = "silent";
    if (are_anagrams(str1, str2)) {
        printf("The strings are anagrams\n");
    } else {
        printf("The strings are not anagrams\n");
    }
    return 0;
}

/*
Finding the Longest Consecutive Sequence
Problem: Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALUE 1000000
#define BITMAP_SIZE (MAX_VALUE / 8)

uint8_t bitmap[BITMAP_SIZE];

void set_bit(uint32_t index)```c
void set_bit(uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

bool get_bit(uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

int longest_consecutive_sequence(int *data, int size, int max_value) {
    memset(bitmap, 0, BITMAP_SIZE);
    for (int i = 0; i < size; i++) {
        if (data[i] >= 0 && data[i] < max_value) {
            set_bit(data[i]);
        }
    }
    int max_length = 0;
    int current_length = 0;
    for (int i = 0; i < max_value; i++) {
        if (get_bit(i)) {
            current_length++;
            if (current_length > max_length) {
                max_length = current_length;
            }
        } else {
            current_length = 0;
        }
    }
    return max_length;
}

int main(void) {
    int data[] = {100, 4, 200, 1, 3, 2};
    int size = sizeof(data) / sizeof(data[0]);
    int max_value = 1000;
    int longest_sequence = longest_consecutive_sequence(data, size, max_value);
    printf("Longest consecutive sequence length: %d\n", longest_sequence);
    return 0;
}

/*

Finding Common Elements in Multiple Arrays
Problem: Given multiple arrays, find the common elements among them.
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALUE 1000000
#define BITMAP_SIZE (MAX_VALUE / 8)

uint8_t bitmap[BITMAP_SIZE];

void set_bit(uint8_t *bitmap, uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

bool get_bit(uint8_t *bitmap, uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

void find_common_elements(int **arrays, int *sizes, int num_arrays, int max_value) {
    memset(bitmap, 0, BITMAP_SIZE);
    for (int i = 0; i < sizes[0]; i++) {
        set_bit(bitmap, arrays[0][i]);
    }
    for (int i = 1; i < num_arrays; i++) {
        uint8_t temp_bitmap[BITMAP_SIZE] = {0};
        for (int j = 0; j < sizes[i]; j++) {
            if (get_bit(bitmap, arrays[i][j])) {
                set_bit(temp_bitmap, arrays[i][j]);
            }
        }
        memcpy(bitmap, temp_bitmap, BITMAP_SIZE);
    }
    for (int i = 0; i < max_value; i++) {
        if (get_bit(bitmap, i)) {
            printf("Common element: %d\n", i);
        }
    }
}

int main(void) {
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {4, 5, 6, 7, 8};
    int array3[] = {5, 7, 8, 9, 10};
    int *arrays[] = {array1, array2, array3};
    int sizes[] = {5, 5, 5};
    int num_arrays = 3;
    find_common_elements(arrays, sizes, num_arrays, MAX_VALUE);
    return 0;
}

/*

Efficiently Storing and Retrieving Sparse Data
Problem: Given a large sparse dataset, efficiently store and retrieve the data.
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALUE 1000000
#define BITMAP_SIZE (MAX_VALUE / 8)

uint8_t bitmap[BITMAP_SIZE];
int sparse_data[MAX_VALUE];

void set_bit(uint32_t index) {
    bitmap[index / 8] |= (1 << (index % 8));
}

bool get_bit(uint32_t index) {
    return (bitmap[index / 8] & (1 << (index % 8))) != 0;
}

void store_sparse_data(int *data, int size, int max_value) {
    memset(bitmap, 0, BITMAP_SIZE);
    for (int i = 0; i < size; i++) {
        if (data[i] >= 0 && data[i] < max_value) {
            set_bit(data[i]);
            sparse_data[data[i]] = data[i];
        }
    }
}

int retrieve_sparse_data(int index) {
    if (get_bit(index)) {
        return```c
        return sparse_data[index];
    } else {
        return -1; // Data not present
    }
}

int main(void) {
    int data[] = {1, 2, 3, 100, 1000, 10000};
    int size = sizeof(data) / sizeof(data[0]);
    store_sparse_data(data, size, MAX_VALUE);

    // Retrieve some data
    printf("Data at index 3: %d\n", retrieve_sparse_data(3));
    printf("Data at index 100: %d\n", retrieve_sparse_data(100));
    printf("Data at index 1000: %d\n", retrieve_sparse_data(1000));
    printf("Data at index 10000: %d\n", retrieve_sparse_data(10000));
    printf("Data at index 50000: %d\n", retrieve_sparse_data(50000));

    return 0;
}
// 
