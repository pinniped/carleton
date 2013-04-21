#include <stdio.h>
#include <stdlib.h>

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

	struct poll poll[MAX_PLS];

	int pollCount = 0;
	int voteCount = 0;

	// Get input file name from cmd line arg and attempt to open
	ifile = fopen(argv[1], "r");
	// Check for valid input file
	if (ifile == NULL) {
		fprintf(stderr, "Input file does not exist; please try again. Terminating program.\n");
		exit(EXIT_FAILURE);
	}

	// Get output file name and attempt to open
	ofile = fopen(argv[2], "w");

	// Initialize poll
	for (int i = 0; i < MAX_PLS; i++) {
		poll[i].id = -1;
		for (int j = 0; j < MAX_VTS; j++) {
			poll[i].vote[j].id = -1;
			poll[i].vote[j].count = 0;
		}
	}

	// Get the first poll ID
	// (We assume there is at least ONE poll ID)
	fscanf(ifile, "%d", &poll[pollCount].id);

	// Read in poll IDs until 0
	while (poll[pollCount].id != 0) {
		// Reset vote count for current poll ID to 0
		voteCount = 0;

		// Read in a vote ID
		// (We assume there is at least ONE vote ID)
		fscanf(ifile, "%d", &poll[pollCount].vote[voteCount].id);

		// Loop for reading vote IDs until 0
		while (poll[pollCount].vote[voteCount].id != 0) {
			// Error handling for too many vote IDs
			if (voteCount++ == MAX_VTS) {
				fprintf(stderr, "Too many vote IDs: Please increase MAX_VTS in main(). Terminating program.\n");
				exit(EXIT_FAILURE);
			}
			// Get new vote ID
			fscanf(ifile, "%d", &poll[pollCount].vote[voteCount].id);
		}
		// Error handling for too many poll IDs
		if (pollCount++ == MAX_PLS) {
			fprintf(stderr, "Too many poll IDs: Please increase MAX_PLS in main(). Terminating program.\n");
			exit(EXIT_FAILURE);
		}
		// Get new poll ID
		fscanf(ifile, "%d", &poll[pollCount].id);
	}


	// Temporarily hold in data to campare with IDs
	int pollID,
		voteID;
	// Read in data
	fscanf(ifile, "%d %d", &pollID, &voteID);
	// Check for EOF after reading
	while (!feof(ifile)) {
		// Looks for matching poll ID
		for (int i = 0; poll[i].id != 0; i++) {
			if (pollID == poll[i].id) {
				// Looks for matching vote ID
				for (int j = 0; poll[i].vote[j].id != 0; j++) {
					if (voteID == poll[i].vote[j].id) {
						// Increment count for current vote ID if match found
						poll[i].vote[j].count++;
					}
				}
			}
		}
		// Get new data
		fscanf(ifile, "%d %d", &pollID, &voteID);
	}

	// Print data to appropriate output file
	for (int i = 0; poll[i].id != 0; i++) {
		// Print poll ID
		fprintf(ofile, "Poll %d (%d)\n", i, poll[i].id);
		// Print all vote IDs and count for current poll ID
		for (int j = 0; poll[i].vote[j].id != 0; j++) {
			fprintf(ofile, "\t%d (%d): %d\n", j, poll[i].vote[j].id, poll[i].vote[j].count);
		}
		// Formatting
		fprintf(ofile, "\n");
	}

	// Close files
	fclose(ifile);
	fclose(ofile);
	return 0;
}
