#include <stdio.h>

#define MAX_PLS 20
#define MAX_VTS 50

// Vote structure
// int 	id 		Holds id for the current vote
// int  count 	Holds number of occurences of votes with current id
struct vote {
	int id;
	int count;
};

// Structure for poll
// int 	id 		Holds ID for the current poll
// vote vote[] 	Array of vote structures
struct poll {
	int id;
	struct vote vote[MAX_VTS];
};

// This program reads in a file of a specific format and outputs a file with
// information with the pollID and the count of each voteID (see Assignment 2)
int main(int argc, const char *argv[])
{
	FILE *ifile = NULL;
	FILE *ofile = NULL;
	char iname[80];
	char oname[80];

	struct poll poll[MAX_PLS];

	int pollCount = 0;
	int voteCount = 0;

	// Get input file name and attempt to open
	while (ifile == NULL) {
		/*
		printf("Please enter a INPUT file name: ");
		scanf("%s", iname);
		ifile = fopen(iname, "r");
		*/
		ifile = fopen(argv[1], "r");
		if (ifile == NULL) {
			printf("No such file exists; try again!\n");
		}
	}

	// Get output file name and attempt to open
	/*printf("Please enter a OUTPUT file name: ");
	scanf("%s", oname);
	ofile = fopen(oname, "w");*/
	ofile = fopen(argv[2], "w");

	// Initialize poll
	for (int i = 0; i < MAX_PLS; i++) {
		poll[i].id = -1;
		for (int j = 0; j < MAX_VTS; j++) {
			poll[i].vote[j].id = -1;
			poll[i].vote[j].count = 0;
		}
	}

	// Read in poll and vote IDs
	for (;;) {
		fscanf(ifile, "%d", &poll[pollCount].id);
		if (poll[pollCount].id == 0) {
			break;
		} 
		voteCount = 0;
		for (;;) {
			fscanf(ifile, "%d", &poll[pollCount].vote[voteCount].id);
			if (poll[pollCount].vote[voteCount].id == 0) {
				break;
			}
			if (voteCount++ == MAX_VTS) {
				printf("TOO MANY VOTES. Go into program and increase MAX_VTS.\n");
				break;
			}
		}
		if (pollCount++ == MAX_PLS) {
			printf("TOO MANY POLLS. Go into program and increase MAX_PLS.\n");
			break;
		}
	}


	int pollID,
		voteID;
	// Read in data
	for (;;) {
		fscanf(ifile, "%d %d", &pollID, &voteID);
		// Check for EOF after reading
		if (feof(ifile)) {
			break;
		}
		for (int i = 0; poll[i].id != 0; i++) {
			if (pollID == poll[i].id) {
				for (int j = 0; poll[i].vote[j].id != 0; j++) {
					if (voteID == poll[i].vote[j].id) {
						poll[i].vote[j].count++;
					}
				}
			}
		}
	}

	for (int i = 0; poll[i].id != 0; i++) {
		fprintf(ofile, "Poll %d (%d)\n", i, poll[i].id);
		for (int j = 0; poll[i].vote[j].id != 0; j++) {
			fprintf(ofile, "\t%d (%d): %d\n", j, poll[i].vote[j].id, poll[i].vote[j].count);
		}
		fprintf(ofile, "\n");
	}

	// Close files
	fclose(ifile);
	fclose(ofile);
	return 0;
}
