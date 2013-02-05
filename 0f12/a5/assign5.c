// THIS PROGRAM IS AT 100% COMPLETION ACCORDING TO THE ASSIGNMENT SPECIFICATION
#include <stdio.h>
#include <stdlib.h>

typedef struct pnode{
	int pollID;
	int voteID;
	struct pnode* next;
} POLL_NODE;

typedef POLL_NODE* POLL;

typedef struct vnode{
	int voteID;
	int voteCount;
	struct vnode* next;
} VOTE_NODE;

typedef VOTE_NODE* VOTE;


// Creates initializes a POLL_NODE with pollID and voteID
// initialized according to the arguments it's called with
POLL makePoll(int pollID, int voteID);

// Creates initializes a VOTE_NODE with voteID initialized 
// according to the arguments it's called with voteCount 
// initialized to 1
VOTE makeVote(int voteID);

// Prepends p to plist
POLL prependPoll(POLL p, POLL plist);

// Prepends v to vlist
VOTE prependVote(VOTE v, VOTE vlist);

// Prints a list of POLL_NODE to console
void printPollList(POLL plist);

// Returns a list of VOTE_NODE for given pollID where
// which each VOTE_NODE counting the number of
// voteID's contained in the pollList
VOTE search(int pollID, POLL plist);

// Prints each VOTE_NODE to console and to file
void printVoteList(FILE* ofile, VOTE vlist);

// Frees memory from each node of the POLL_NODE list
void delPoll(POLL plist);

// Frees memory from each node of the VOTE_NODE list
void delVote(VOTE vlist);

// Returns true if VOTE_NODE list has a voteID
// that matches and false otherwise
bool hasVoteID(int voteID, VOTE vlist);

// This program reads in a file of a specific format and outputs to console and file
// information with the pollID and the count of each voteID (see Assignment 5)
int main(int argc, const char *argv[])
{
	FILE *ifile = NULL;
	FILE *ofile = NULL;

	// Initialized to -2 to differentiate from setting to -1
	// as being a used ID in later logic
	int pollID = -2;
	int voteID = -2;

	POLL pollList = NULL;

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
	while (fscanf(ifile, "%d %d", &pollID, &voteID) == 2) {
		pollList = prependPoll(makePoll(pollID, voteID), pollList);
	}

	// Print pollList to screen
	printf("Printing polls to screen:\n");
	printPollList(pollList);
	printf("\n");

	// Do search on each node of pollList
	// And print it to console and ofile
	POLL pTemp = pollList;
	VOTE vTemp = NULL;
	while (pTemp != NULL) {
		// Skip if ID is already used
		if (pTemp->pollID != -1) {
			// We should print pollID to console and file
			// here because search sets pollID to -1 after
			// using them
			printf("Poll %d\n", pTemp->pollID);
			fprintf(ofile, "Poll %d\n", pTemp->pollID);
			// Get a list of votes for current pollID
			// and print it to console/file
			vTemp = search(pTemp->pollID, pTemp);
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

// Creates initializes a POLL_NODE with pollID and voteID
// initialized according to the arguments it's called with
POLL makePoll(int pollID, int voteID) {
	POLL plist = (POLL)malloc(sizeof(POLL_NODE));
	plist->pollID = pollID;
	plist->voteID = voteID;
	plist->next = NULL;
	return plist;
}

// Creates initializes a VOTE_NODE with voteID initialized 
// according to the arguments it's called with voteCount 
// initialized to 1
VOTE makeVote(int voteID) {
	VOTE vlist = (VOTE)malloc(sizeof(VOTE_NODE));
	vlist->voteID = voteID;
	vlist->voteCount = 1;
	vlist->next = NULL;
	return vlist;
}

// Prepends p to plist
POLL prependPoll(POLL p, POLL plist) {
	p->next = plist;
	return p;
}

// Prepends v to vlist
VOTE prependVote(VOTE v, VOTE vlist) {
	v->next = vlist;
	return v;
}

// Prints a list of POLL_NODE to console
void printPollList(POLL plist) {
	if (plist != NULL) {
		// Make recursive call first since our list order is
		// reversed (that is first node is the last row in file)
		printPollList(plist->next);
		printf("pID: %d, vID: %d\n", plist->pollID, plist->voteID);
	}
}

// Returns a list of VOTE_NODE for given pollID where
// which each VOTE_NODE counting the number of
// voteID's contained in the pollList
VOTE search(int pollID, POLL plist) {
	VOTE vlist = NULL;
	// Traverse p
	while (plist != NULL) {
		// We're looking for matching pollID's
		if (plist->pollID == pollID) {
			// First traversal (logic only reaches here if 
			// p isn't NULL)
			if (vlist == NULL || !hasVoteID(plist->voteID, vlist)) {
				vlist = prependVote(makeVote(plist->voteID), vlist);
			} 
			// Change pollID to "used"
			plist->pollID = -1;
		}
		plist = plist->next;
	}
	return vlist;
}

// Prints each VOTE_NODE to console and to file
void printVoteList(FILE* ofile, VOTE vlist) {
	if (vlist != NULL) {
		printVoteList(ofile, vlist->next);
		printf("\t%d: %d\n", vlist->voteID, vlist->voteCount);
		fprintf(ofile, "\t%d: %d\n", vlist->voteID, vlist->voteCount);
	}
}

// Frees memory from each node of the POLL_NODE list
void delPoll(POLL plist) {
	if (plist != NULL) {
		// Delete last item first so we don't run
		// so we don't have to declare a temp to avoid
		// a memory leak
		delPoll(plist->next);
		free(plist);
	}
}

// Frees memory from each node of the VOTE_NODE list
void delVote(VOTE vlist) {
	if (vlist != NULL) {
		// Delete last item first so we don't run
		// so we don't have to declare a temp to avoid
		// a memory leak
		delVote(vlist->next);
		free(vlist);
	}
}

// Returns true if VOTE_NODE list has a voteID
// that matches and increments voteCount for that
// VOTE, otherwise returns false
bool hasVoteID(int voteID, VOTE vlist) {
	while (vlist != NULL) {
		if (vlist->voteID == voteID) {
			vlist->voteCount++;
			return true;
		}
		vlist = vlist->next;
	}
	return false;
}
