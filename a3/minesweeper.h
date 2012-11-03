#define LOSE -1
#define PLAY 0
#define WIN 1

#define BLK_SQR 178
#define MINE 233

#define RATIO 1/8

typedef struct {
	int nSurround; 	// Number of surrounding mines
	bool hidden;    // Whether square is hidden or revealed
	bool flagged; 		// If the user has flagged the square as mined
	bool mined; 	// Whether the square contains a mine
} Square;

typedef struct {
	int nMines; 	// Total number of mines
	int width; 		// Width of playable board
	int height; 	// Height of playable board
	Square *sqr; 	// Array of Square (individual board grids)
	int state; 		// LOSE, WIN, or PLAY
} Board;

// Returns a board of containing n x m Squares
Board makeBoard(int n, int m);

// Frees up allocated memory in board
void delBoard(Board *b);

// Initialize square 
void initSquare(void); 

// Returns the point to a square on Board b, at down, right
Square *getSquare(Board *b, int down, int right);

// Sets mines on board b. 
// Mines locations are determined from inFile
// If inFile is null, we set mines randomly
// Random number of mines are determined as a
// ratio of the board size
// Each time a mine is placed, the surrounding squares
// have their nSurround value incremented.
void setMines(FILE *inFile, Board *b);

// Randomly generate mines on Board b
// Random number of mines are determined as a
// ratio of the board size
void generateMines(Board *b);

// Sets mined to true for square at down, right
void mine(Board *b, int down, int right);

// Reveals all mines on board for end of game
void revealMines(Board *b);

// Update nSurround for squares around down, right
void updateSurround(Board *b, int down, int right);

// Prints board to screen
void drawBoard(Board *b);

// Reveals square at down, right
// Game ends if it was a mine
// Otherwise, appropriate squares are revealed
void digSquare(Board *b, int down, int right);

// Digs the surrounding squares
void digSurround(Board *b, int down, int right);

void toggleFlag(S

// Handles moves from user
void move(Board *b, char *move, int down, int right);

// Prints instructions to console
void printInstructions(void);

// Checks if user has won
bool checkWin(Board *b);
