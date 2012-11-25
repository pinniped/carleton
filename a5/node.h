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
POLL makePoll(int voteID);

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
