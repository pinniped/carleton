#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "minesweeper.h"


int main(int argc, const char *argv[])
{
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	// test printf("argv[2]: %s, argv[3]: %s\n", argv[2], argv[3]);
	// test printf("width: %d, height %d\n", width, height);


	// Game mode expects four args and test mode expects six
	if (argc != 4 && argc != 6) {
		fprintf(stderr, "ERROR: Invalid number of options. Please run with either \"-t\" or \"-g\".\n");
	// Valid number of args, check for correct arg names
	} else if (!strcmp(argv[1],"-t") || !strcmp(argv[1],"-g")) {
		// Seed random
		srand(time(NULL));
		// Create board
		Board b = makeBoard(width, height);
		FILE *inFile = NULL;
			//
		// Set mines
		// If test mode
		if (!strcmp(argv[1],"-t")) {
			FILE *outFile;
			inFile = fopen(argv[4], "r");
			outFile = fopen(argv[5], "w");
			setMines(inFile, &b);
		} else {
			// Set random mines
			// Number of mines determined as a ratio of
			// the area of the board (width * height)
			// The ratio is set with a define macro
			// in the header file (RATIO)
			generateMines(&b);
		}

		// Set mines

		// Optionally display instructions
		char r;
		printf("Would you like to see the instructions? ");
		scanf("%c", &r);
		if (tolower(r) == 'y') {
			printInstructions();
		}
		

		char move[80];
		int down, right;
		// Do
		do {
			do {
				// Display board
				drawBoard(&b);
				// Prompt for move 
				printf("Please make your move: ");
				scanf("%s %d %d", move, &down, &right);
			// While move doesn't reveal
			} while (strcmp(move, "dig"));
			
			// Reveals square at down, right 
			// Game ends if it was a mine
			// Otherwise, appropriate squares are revealed
			digSquare(&b, down, right);
			if (checkWin(&b)) {
				b.state = WIN;
			}
		} while (b.state == PLAY);


		// Display appropriate ending message to console
		if (b.state == WIN) {
			printf("\nCongratulations! You cleared the minefield!\n");
		} else {
			printf("\nBOOM! You hit a mine! Better luck next time.\n");
			revealMines(&b);
		}
		drawBoard(&b);


	// Throw error for invalid error names
	} else {
		fprintf(stderr, "ERROR: Invalid option. Please use either \"-t\" or \"-g\".\n");
	}
	return 0;
}
