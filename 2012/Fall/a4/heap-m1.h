typedef struct {
	int size; 	 		// Maximum number of integers heap can hold total
	int* nums; 			// Heap represented as an array integers
	bool* allocated; 	// True if corresponding memory has been allocated
	bool* segmentHead; 	// True if corresponding memory is the beginning of a allocated segment
	int* segmentSize; 	// When allocating an array, the head contains the size of array
} Heap;

// Creates a heap that can hold at most size integers
Heap makeHeap(int size);

// Assigns "size" blocks of memory from Heap h
// by setting each "empty" member in segment to false
// Returns a pointer to the first block
// Returns NULL if unable to allocate memory
int* mmalloc(int size, Heap* h);

// Given a int* b in Heap h 
// sets "empty" member for each block in segment to true
// resets segmentSize to 0 and segmentHead to false.
void mfree(int* b, Heap* h);
