#include <stdlib.h>
#include "heap-m1.h"

// Creates a heap that can hold at most size integers
Heap makeHeap(int size) {
	Heap h;
	h.size = size;

	// Get dynamic memory
	h.nums = (int*)malloc(size*sizeof(int));
	h.allocated = (bool*)malloc(size*sizeof(bool));
	h.segmentHead = (bool*)malloc(size*sizeof(bool));
	h.segmentSize = (int*)malloc(size*sizeof(int));

	// Initialize
	for (int i = 0; i < size; i++) {
		h.allocated = false;
		h.segmentHead = false;
		h.segmentSize = 0;
	}

}

// Assigns "size" blocks of memory from Heap h
// by setting each "empty" member in segment to false
// Returns a pointer to the first block
// Returns NULL if unable to allocate memory
int* mmalloc(int size, Heap* h) {
	int* cur = h->nums;
	int* end = cur + h->size;
	int* next;
	int groupSize;
	// While ((end - cur) >= size)
		// Reset groupsize to 1
		// If current block isn't allocated 
			// Get next position
			next = cur+1;
			// While block at next isn't allocated
				next++;
				groupSize++;
			// If groupSize >= size
				// Get position of cur in heap
				// segmentHead for cur is true
				// set segmentSize to size
				// For size blocks staring from cur, assign each block as allocated
				return cur
			// Else, cur = next;
		// Else, cur++;
	return NULL;
}

// Given a int* b in Heap h 
// sets "empty" member for each block in segment to true
// resets segmentSize to 0 and segmentHead to false.
void mfree(int* b, Heap* h) {
	// Get position of b in h
	// If segmentHead at position is true and block is allocated
		// For segmentSize iterations, 
			// Set block to allocated
		// reset segmentHead to false
		// reset segmentSize to 1
}
