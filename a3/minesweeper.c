#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "minesweeper.h"

// Creates a minesweeper game and 
// initalizes it with a board
// of size (width * height)
Game makeGame(int width, int height) {
	Game g;
	g.mode = GAME;
	g.nMines = 0;
	g.width = width;
	g.height = height;
	g.board = (Square *)malloc(width * height * sizeof(Square));
	g.state = PLAY;

	// Initialize square array
	for (int i = 0; i < (width * height); i++) {
		initSquare(&(g.board[i]));
	}

	return g;
}

// Frees up memory allocated in game from makeGame
void delGame(Game *g) {
	free(g->board);
}

// Initialize square
void initSquare(Square *s) {
	s->nSurround = 0;
	s->hidden = true;
	s->flagged = false;
	s->mined = false;
}

// Checks if a given move is valid
bool isValid(Game *g, char *move, int down, int right) {
	bool validDown = down < (g->height);
	bool validRight = right < (g->width);
	bool validMove = 
		!strcmp(move, "dig") || !strcmp(move, "d") ||
		!strcmp(move, "flag") || !strcmp(move, "f");
	return validDown && validRight && validMove;
}

// Sets mines on game g 
// Mines locations are determined from inFile
void setMines(FILE *inFile, Game *g) {
	int down, right;
	while (!feof(inFile)) {
		g->nMines++;
		fscanf(inFile, "%d ", &down);
		fscanf(inFile, "%d ", &right);
		mine(g, down, right);
	}
}

// Randomly generate mines on Game b
// Random number of mines are determined as a
// ratio of the board size
void generateMines(Game *g) {
	g->nMines = ceil((float)RATIO * (g->width * g->height));
	int randD, randR;
	Square *s;
	for (int i = 0; i < g->nMines; i++) {
		do {
			// Randomize right and down
			randD = rand() % g->height;
			randR = rand() % g->width;
			s = getSquare(g, randD, randR);
		} while (s->mined);
		mine(g, randD, randR);
	}
}

// Sets a mine at down, right
// Surrounding squares' nSurround are all incremented
void mine(Game *g, int down, int right) {
	Square *s = getSquare(g, down, right);
	s->mined = true;
	updateSurround(g, down, right);
}

// Reveals all mines on board for end of game
void revealMines(Game *g) {
	Square *s;
	// Traverse entire board
	for (int i = 0; i < g->height; i++) {
		for (int j = 0; j < g->width; j++) {
			s = getSquare(g, i, j);
			if (s->mined) {
				s->hidden = false;
			}
		}
	}
}

// Update nSurround for squares around down, right
void updateSurround(Game *g, int down, int right) {
	Square *s;
	for (int i = down-1; i < down+2; i++) {
		for (int j = right-1; j < right+2; j++) {
			s = getSquare(g, i, j);
			if (s != NULL) {
				s->nSurround++;
			}
		}
	}
}

// Reveals square at down, right 
// Game ends if it was a mine
// Otherwise, appropriate squares are revealed
void digSquare(Game *g, int down, int right) {
	Square *s = getSquare(g, down, right);

	// Reveal square
	s->hidden = false;

	if (s->mined) {
		g->state = LOSE;
	} else if (s->nSurround == 0) {
		// If square as 0 surrounding mines,
		// reveal all squares surrounding it
		digSurround(g, down, right);
	}
}

// Digs the surrounding squares of down, right
void digSurround(Game *g, int down, int right) {
	Square *s;
	// Row iteration from (down-1) to (down+1)
	for (int i = down-1; i < down+2; i++) {
		// Column iteration from (right-1) to (right+1)
		for (int j = right-1; j < right+2; j++) {
			s = getSquare(g, i, j);
			if (s != NULL && s->hidden) {
				// Dig appropriate square if it's not off 
				// the edge and not already dug
				digSquare(g, i, j);
			}
		}
	}
}

// Toggles the flag on square at down, right
void toggleFlag(Game *g, int down, int right) {
	Square *s = getSquare(g, down, right);
	s->flagged = !s->flagged;
}

// Prints instructions to console
void printInstructions(void) {
	printf("\nHello soldier. It is presumed you are familiar with the art of minesweeping.\n");
	printf("The moves you make must be a COMMMAND followed by a COORDINATE.\n");
	printf("The COMMAND can be either \"dig\" or \"flag\" (alternately, \"d\" or \"f\").\n");
	printf("The COORDINATE must be two numbers: the first and second number represent the\n");
	printf("row and colomn number repectively. The row number is given on the left border\n");
	printf("and the column number on the top border.\n");
	printf("For example, \"d 2 3\" digs the square 2 down from the top row and\n");
	printf("3 right from the left-most column.\n\n");
	printf("Good luck and godspeed.\n");
	printf("\n\n");
}

// Returns the pointer to a square on Game g, at down, right 
// Returns null if the square is off the board
Square *getSquare(Game *g, int down, int right) { 
	bool tEdge = (down < 0);
	bool bEdge = (down >= g->height); 
	bool lEdge = (right < 0);
	bool rEdge = (right >= g->width); 
	if (tEdge || bEdge || lEdge || rEdge) {
		return NULL;
	} else {
		return g->board + (g->width * down) + right;
	}
}

// Prints board to screen
void drawGame(Game *g, FILE *outFile) {
	Square *s;
	for (int i = 0; i < g->height+1; i++) {
		for (int j = 0; j < g->width+1; j++) {
			// Prints top border
			if (i == 0) {
				if (j == 0) {
					if (g->mode == TEST) {
						fprintf(outFile, " ");
					}
					printf(" ");
				} else {
					if (g->mode == TEST) {
						fprintf(outFile, "%d", j-1);
					}
					printf("%d", j-1);
				}
				if (j-1 < 10) {
					if (g->mode == TEST) {
						fprintf(outFile, " ");
					}
					printf(" ");
				}
			} else {
				// Prints side border
				if (j == 0) {
					if ((i-1) < 10) {
						if (g->mode == TEST) {
							fprintf(outFile, " ");
						}
						printf(" ");
					} 
					if (g->mode == TEST) {
						fprintf(outFile, "%d", i-1);
					}
					printf("%d", i-1);
				} else {
					// Prints squares
					s = getSquare(g, i-1, j-1);
					// Hidden squares
					if (s->hidden) {
						if (s->flagged) {
							if (g->mode == TEST) {
								fprintf(outFile, "%c ", FLAG);
							}
							printf("%c ", FLAG);
						} else {
							if (g->mode == TEST) {
								fprintf(outFile, "%c ", BLK_SQR);
							}
							printf("%c ", BLK_SQR);
						}
					} else {
						// Revealed squares
						if (s->mined) {
							if (g->mode == TEST) {
								fprintf(outFile, "%c ", MINE);
							}
							printf("%c ", MINE);
						} else {
							if (s->nSurround == 0) {
								smartPrint(g->mode, outFile, "  ");
							} else {
								if (g->mode == TEST) {
									fprintf(outFile, "%d ", s->nSurround);
								}
								printf("%d ", s->nSurround);
							}
						}
					}
				}
			}
		}
		smartPrint(g->mode, outFile, "\n");
		// Start of new row
	}
	smartPrint(g->mode, outFile, "\n");
	//Separates last board display with new prompt
}

// Checks if user has won
bool checkWin(Game *g) {
	bool win = true;
	Square *s;
	for (int i = 0; i < g->height; i++) {
		for (int j = 0; j < g->width; j++) {
			s = getSquare(g, i, j);
			if (!(s->mined) && s->hidden) {
				win = false;
			}
		}
	}
	return win;
}

// Prints s to outFile is test mode
// otherwise, prints to console
void smartPrint(int mode, FILE *outFile, char *s) {
	if (mode == TEST) {
		fprintf(outFile, "%s", s);
	}
	printf("%s", s);
}
