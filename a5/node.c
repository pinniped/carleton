#include <stdio.h>
#include <stdlib.h>
#include "node.h"

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
