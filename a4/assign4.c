#include <stdio.h>
#include <stdlib.h>
#include "heap-m3.h"

int main(int argc, const char *argv[])
{
	if (argc == 2) {
		// Supposed to take size of heap form cmd line arg
		// but for testing we use a set heap size of 20
		// int size = atoi(argv[1]);

		Heap h = makeHeap(20);

		// 8 test pointers used initialized to NULL
		int** a = (int**)malloc(8 * sizeof(int*));
		for (int i = 0; i < 8; i++) {
			a[i] = NULL;
		}

		// 1.Allocating memory larger than heap has available (when heap has no allocations yet).
		// EXPECTED: Return null.
		printf("Running TEST 1.\n");

		a[0] = mmalloc(20+1, &h);

		if (a[0] != NULL) {
			fprintf(stderr, "TEST 1 FAIL!\n");
		}
		
		// 2.Multiple normal allocations.
		// EXPECTED: Return Block pointers
		printf("Running TEST 2.\n");
		a[1] = mmalloc(2, &h);
		a[2] = mmalloc(8, &h);
		a[3] = mmalloc(6, &h);
		a[4] = mmalloc(3, &h);
		
		bool fail = (a[1]==NULL) || (a[2]==NULL) || (a[3]==NULL) || (a[4]==NULL);
		if (fail) {
			fprintf(stderr, "TEST 2 FAIL!\n");
		}

		// 3.Freeing normal allocations.
		// EXPECTED: Block member empty for each Block in segment, member segmentSize=0 
		printf("Running TEST 3.\n");
		bool pass = true;

		// Try to allocate memory from a full heap
		a[5] = mmalloc(2, &h);
		// Expects NULL
		pass = pass && (a[5]==NULL); 
		// Free sufficient memory
		mfree(a[2], &h);
		// Try to allocate again, expects success
		a[5] = mmalloc(2, &h);
		pass = pass && (a[5]!=NULL); 

		if (!pass) {
			fprintf(stderr, "TEST 3 FAIL!\n");
		}

		// Recreate 8 integer gap
		mfree(a[5], &h);


		// 4.Freeing allocations that do not exist.
		// EXPECTED: Print appropriate error.
		// NB: This test is removed because the user will be
		// expected to ensure that arguments passed into 
		// mfree are valid and handled appropriately.
		printf("Running TEST 4.\n");

		// 5.Allocating memory larger than heap has available (when heap has allocations).
		// EXPECTED: Return null.
		printf("Running TEST 5.\n");

		// Should have gap of size 8 and 1 in array at this point
		a[2] = mmalloc(9, &h);
		// Expects NULL
		if (a[2] != NULL) {
			fprintf(stderr, "TEST 5 FAIL!\n");
		}

		// 5b.Allocating memory in gaps freed from last test (results are void if 5 FAILS)
		printf("Running TEST 5b.\n");
		fail = false;
		a[2] = mmalloc(7, &h);
		a[5] = mmalloc(1, &h);
		// Allocate a block thats too big (only gap of 1 left)
		a[6] = mmalloc(2, &h);
		if (a[6] != NULL) {
			fail = true;
		}
		// Allocate last block
		a[6] = mmalloc(1, &h);
		// Allocate more space, expects null
		a[7] = mmalloc(1, &h);
		fail = (a[2]==NULL) || (a[5]==NULL) || (a[6]==NULL) || (a[7]!=NULL);
		if (fail) {
			fprintf(stderr, "TEST 5b FAIL!\n");
		}
		
		// 6.Free remaining memory.
		// EXPECTED: All 20 blocks freed
		printf("Running TEST 6.\n");
		// a[7] should not be allocated, only need to free up to 6
		// a[0] was never assigned (used to large malloc call)
		for (int i = 1; i < 7; i++) {
			mfree(a[i], &h);
		}

		// Try to allocate entire heap; should be okay
		a[0] = mmalloc(20, &h);
		if (a[0] == NULL) {
			fprintf(stderr, "TEST 6 FAIL!\n");
		}
		mfree(a[0], &h);

		printf("End of heap API test suite.\n");
	} else {
		fprintf(stderr, "This program expects exactly ONE integer option.\n");
	}

	return 0;
}
