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
