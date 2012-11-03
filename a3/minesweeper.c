#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "minesweeper.h"

// Initialize square
void initSquare(Square *sqr) {
	sqr->nSurround = 0;
	sqr->hidden = true;
	sqr->flagged = false;
	sqr->mined = false;
}

// Returns a board of containing n x m squares
// n left<->right, n=0 at bottom left
// m up<->down, m=0 at bottom left
Board makeBoard(int n, int m) {
	Board b;
	b.nMines = 0;
	b.width = n;
	b.height = m;
	b.sqr = (Square *)malloc(n * m * sizeof(Square));
	b.state = PLAY;

	// Initialize square array
	for (int i = 0; i < (n * m); i++) {
		initSquare(&(b.sqr[i]));
	}


	return b;
}

// Sets mines on board b 
// Mines locations are determined from inFile
// If inFile is null, we set mines randomly
// Each time a mine is placed, the surrounding squares
// have their nSurround value incremented.
void setMines(FILE *inFile, Board *b) {
	int down, right;
	while (!feof(inFile)) {
		b->nMines++;
		fscanf(inFile, "%d ", &down);
		fscanf(inFile, "%d ", &right);
		mine(b, down, right);
	}
	printf("nMines: %d\n", b->nMines);
}

// Randomly generate mines on Board b
// Random number of mines are determined as a
// ratio of the board size
void generateMines(Board *b) {
	int nMines = ceil((float)RATIO * (b->width * b->height));
	printf("nMines: %d\n", nMines);
	int randD, randR;
	Square *s;
	for (int i = 0; i < nMines; i++) {
		do {
			// randomize right and down
			randD = rand() % b->height;
			randR = rand() % b->width;
			s = getSquare(b, randD, randR);
		} while (s->mined);
		mine(b, randD, randR);
	}
}

// Sets mined to true for square at down, right
void mine(Board *b, int down, int right) {
	Square *s = getSquare(b, down, right);
	s->mined = true;
	updateSurround(b, down, right);
}

// Reveals all mines on board for end of game
void revealMines(Board *b) {
	Square *s;
	for (int i = 0; i < b->height; i++) {
		for (int j = 0; j < b->width; j++) {
			s = getSquare(b, i, j);
			if (s->mined) {
				s->hidden = false;
			}
		}
	}
}

// Update nSurround for squares around down, right
void updateSurround(Board *b, int down, int right) {
	Square *s;
	for (int i = down-1; i < down+2; i++) {
		for (int j = right-1; j < right+2; j++) {
			s = getSquare(b, i, j);
			if (s != NULL) {
				s->nSurround++;
			}
		}
	}
}

// Reveals square at down, right 
// Game ends if it was a mine
// Otherwise, appropriate squares are revealed
void digSquare(Board *b, int down, int right) {
	Square *s = getSquare(b, down, right);
	if (s->hidden) {
		s->hidden = false;
		if (s->mined) {
			b->state = LOSE;
		} else if (s->nSurround == 0) {
			digSurround(b, down, right);
		}
	} else {
		printf("You already digged that square!\n\n");
	}
}

// Digs the surrounding squares
void digSurround(Board *b, int down, int right) {
	Square *s;
	for (int i = down-1; i < down+2; i++) {
		for (int j = right-1; j < right+2; j++) {
			s = getSquare(b, i, j);
			if (s != NULL && s->hidden) {
				digSquare(b, i, j);
			}
		}
	}
}

// Handles moves from user
void move(Board *b, char *move, int down, int right) {
	if (!strcmp(move,"dig")) {

	}
}

// Prints instructions to console
void printInstructions(void) {
}

// Returns the pointer to a square on Board b, at down, right 
// Returns null if the square is off the board
Square *getSquare(Board *b, int down, int right) { 
	bool tEdge = (down < 0);
	bool bEdge = (down >= b->height); 
	bool lEdge = (right < 0);
	bool rEdge = (right >= b->width); 
	if (tEdge || bEdge || lEdge || rEdge) {
		return NULL;
	} else {
		return b->sqr + (b->width * down) + right;
	}
}

// Prints board to screen
void drawBoard(Board *b) {
	Square *s;
	for (int i = 0; i < b->height+1; i++) {
		for (int j = 0; j < b->width+1; j++) {
			// Prints top border
			if (i == 0) {
				if (j == 0) {
					printf("  ");
				} else {
					printf("%d", j-1);
					if (j-1 < 10) {
						printf(" ");
					}
				}
			} else {
				// Prints side border
				if (j == 0) {
					if (i < 10) {
						printf(" ");
					} 
					printf("%d", i);
				} else {
					// Prints squares
					s = getSquare(b, i-1, j-1);
					if (s->hidden) {
						printf("%c ", BLK_SQR);
					} else {
						if (s->mined) {
							printf("%c ", 'x');
						} else {
							if (s->nSurround == 0) {
								printf("  ");
							} else {
								printf("%d ", s->nSurround);
							}
						}
					}
				}
			}
		}
		printf("\n");
		// Start of new row
	}
	printf("\n");
}

// Checks if user has won
bool checkWin(Board *b) {
	bool win = true;
	Square *s;
	for (int i = 0; i < b->height; i++) {
		for (int j = 0; j < b->width; j++) {
			s = getSquare(b, i, j);
			if (!(s->mined) && s->hidden) {
				win = false;
			}
		}
	}
	return win;
}
