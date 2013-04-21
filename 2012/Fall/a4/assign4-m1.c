#include <stdio.h>
#include <stdlib.h>
#include "heap-m1.h"

int main(int argc, const char *argv[])
{
	// 1.Allocating memory larger than heap has available (when heap has no allocations yet).
	// EXPECTED: Print error, return null.
	// b = malloc(size+1, &h);
	
	// 2.Multiple normal allocations.
	// EXPECTED: Return Block pointers

	// 3.Freeing normal allocations.
	// EXPECTED: Block member empty for each Block in segment, member segmentSize=0 

	// 4.Freeing allocations that do not exist.
	// EXPECTED: Print appropriate error.

	// 5.Allocating memory larger than heap has available (when heap has allocations).
	// EXPECTED: Print error, return null.
	//
	// 6.Free remaining memory.
	// EXPECTED: For all blocks in heap, empty=true, segmentSize=0, segmentHead=false.

	return 0;
}
