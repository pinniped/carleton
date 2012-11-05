#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "minesweeper.h"

int main(int argc, const char *argv[])
{
	FILE *inFile;
	FILE *outFile;

	int width;
	int height;

	// Game mode expects four args and test mode expects six
	if (argc != 4 && argc != 6) {
		fprintf(stderr, "ERROR: Invalid number of options. Please run with either \"-t\" or \"-g\".\n");
	// Valid number of args, check for correct arg names
	} else if (!strcmp(argv[1],"-t") || !strcmp(argv[1],"-g")) {
		// Get command line arguments are width and height
		width = atoi(argv[2]);
		height = atoi(argv[3]);

		// Seed random
		srand(time(NULL));
		// Create a game and initalize
		Game g = makeGame(width, height);
		
		// Set mines
		// If test mode
		if (!strcmp(argv[1],"-t")) {
			// Get mines from inFile and put them on board
			g.mode = TEST;
			inFile = fopen(argv[4], "r");
			outFile = fopen(argv[5], "w");
			setMines(inFile, &g);
		} else {
			// Set random mines
			// Number of mines determined as a ratio of
			// the area of the board (width * height)
			// The ratio is set with a define macro
			// in the minesweeper.h (RATIO)
			generateMines(&g);
		}

		// Optionally display instructions
		char r;
		printf("\nWould you like to see the instructions? ");
		scanf("%c", &r);
		if (tolower(r) == 'y') {
			printInstructions();
		}

		// Display total number of mines on board
		printf("There are %d mines total on this board.\n\n", g.nMines);

		int down, right;
		// Do
		do {
			// Display board
			drawGame(&g, outFile);
			// First iteration is always a invalid move because
			// of initialization of move
			// Gets new input until valid
			char move[80] = "";
			while (!isValid(&g, move, down, right)) {
				// Prompt for move 
				printf("Please make your move: ");
				scanf("%s %d %d", move, &down, &right);
			}

			if (!strcmp(move, "flag") || !strcmp(move, "f")) {
				toggleFlag(&g, down, right);
			} else if (!strcmp(move, "dig") || !strcmp(move, "d")) {
				Square *s = getSquare(&g, down, right);
				if (s->flagged) {
					printf("Cannot dig a flagged square.\n\n");
				} else {
					// Reveals square at down, right 
					// Game ends if it was a mine
					// Otherwise, appropriate squares are revealed
					if (s->hidden) {
						digSquare(&g, down, right);
					} else {
						printf("You already digged that square!\n\n");
					}
					if (checkWin(&g)) {
						// Game wins if it was the last unmined square
						g.state = WIN;
					}
				}
			}
		} while (g.state == PLAY);


		// Display appropriate ending message to console
		if (g.state == WIN) {
			printf("\nCongratulations! You cleared the minefield. Promotions and awards all around!\n");
		} else {
			printf("\nBOOM! Your body shatters into a million pieces and your blood rains over the battlefield. Better luck next time.\n");
			revealMines(&g);
		}
		drawGame(&g, outFile);

		if (g.mode == TEST) {
			fclose(inFile);
			fclose(outFile);
		}
		delGame(&g);
		// Throw error for invalid error names
	} else {
		fprintf(stderr, "ERROR: Invalid option. Please use either \"-t\" or \"-g\".\n");
	}

	return 0;
}
