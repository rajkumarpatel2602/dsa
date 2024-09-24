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

// 
