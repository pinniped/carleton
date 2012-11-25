#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// This program reads in a file of a specific format and outputs a file with
// information with the pollID and the count of each voteID (see Assignment 2)
int main(int argc, const char *argv[])
{
	FILE *ifile = NULL;
	FILE *ofile = NULL;

	// Initialized to -2 to differentiate from setting to -1
	// as being a used ID in later logic
	int pollID = -2;
	int voteID = -2;

	POLL pollList = null;
	VOTE voteList = null;

	// Get input file name from cmd line arg and attempt to open
	ifile = fopen(argv[1], "r");
	// Check for valid input file
	if (ifile == NULL) {
		fprintf(stderr, "Input file does not exist; please try again. Terminating program.\n");
		exit(EXIT_FAILURE);
	}

	// Get output file name and attempt to open
	ofile = fopen(argv[2], "w");

	// Read in poll IDs EOF
	while (scanf("%d %d", pollID, voteID) == 2) {
		pollList = append(makePoll(pollID, voteID), pollList);
	}

	// Do searchList on each node of pollList
	// And print it to console and ofile
	POLL pTemp = pollList;
	VOTE vTemp = null;
	while (pTemp != null) {
		// Skip if ID is already used
		if (pTemp->pollID != -1) {
			vTemp = searchList(pTemp->pollID, pTemp);
			printVoteList(ofile, vTemp);
			// vTemp points to a new VOTE_NODE each iteration
			// We must free it before we lose the handle on its
			// memory block in heap
			delVote(vTemp);
		}
		pTemp = pTemp->next;
	}

	// Done with pollList: free memory
	delPoll(pollList);

	// Close files
	fclose(ifile);
	fclose(ofile);

	return 0;
}
