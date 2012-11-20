#include <stdlib.h>
#include <stdio.h>
#include "heap-m2.h"

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
		h.allocated[i] = false;
		h.segmentHead[i] = false;
		h.segmentSize[i] = 0;
	}
	return h;
}

// Assigns "size" blocks of memory from Heap h
// by setting each "empty" member in segment to false
// Returns a pointer to the first block
// Returns NULL if unable to allocate memory
int* mmalloc(int size, Heap* h) {
	int* cur = h->nums;
	int curPosn;
	int* end = cur + h->size;
	int* next;
	int nextPosn;
	int groupSize;

	while((end - cur) >= size) {
		// Reset groupsize to 1
		groupSize = 1;
		// Get position of cur in heap
		curPosn = getPosn(cur, h);
		// If current block isn't allocated 
		if (!h->allocated[curPosn]) {
			// Get next position
			next = cur+1;
			nextPosn = getPosn(next, h);
			// While block at next isn't allocated
			while (!h->allocated[nextPosn]) {
				nextPosn = getPosn(++next, h);
				groupSize++;
			}
			// If groupSize >= size
			if (groupSize >= size) {
				// segmentHead for cur is true
				h->segmentHead[curPosn] = true;
				// set segmentSize to size
				h->segmentSize[curPosn] = size;
				// For size blocks staring from cur, assign each block as allocated
				for (int i = 0; i < size; i++) {
					h->allocated[curPosn] = true;
				}
				return cur;
			} else {
				// Skip entire group if group size isn't big enough
				cur = next;
			}
		} 
		// We know next left off on a allocated block, so no point checking it
		cur++;
	}
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

// Gets position of a pointer in heap
int getPosn(int* ptr, Heap* h) {
	return ptr - h->nums;
}
