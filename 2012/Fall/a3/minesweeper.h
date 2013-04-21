#define GAME 0
#define TEST 1

#define LOSE -1
#define PLAY 0
#define WIN 1

#define BLK_SQR 178
#define FLAG '#'
#define MINE 'x'

// This number can be set from 0 and 1 inclusive
#define RATIO 1/8

typedef struct {
	int nSurround; 	// Number of surrounding mines
	bool hidden;    // Whether square is hidden or revealed
	bool flagged; 	// If the user has flagged the square as mined
	bool mined; 	// Whether the square contains a mine
} Square;

typedef struct {
	int mode; 		// TEST or GAME(default)
	int nMines; 	// Total number of mines
	int width; 		// Width of playable board
	int height; 	// Height of playable board
	Square *board; 	// Array of Square (individual board grids)
	int state; 		// LOSE, WIN, or PLAY
} Game;

// Creates a minesweeper game and 
// initalizes it with a board
// of size (width * height)
Game makeGame(int widt, int height);

// Frees up memory allocated in game from makeGame
void delGame(Game *g);

// Initialize square 
void initSquare(Square *s); 

// Checks if a given move is valid
bool isValid(Game *g, char *move, int down, int right);

// Returns the point to a square on Game b, at down, right
Square *getSquare(Game *g, int down, int right);

// Sets mines on board g. 
// Mines locations are determined from inFile
// If inFile is null, we set mines randomly
// Random number of mines are determined as a
// ratio of the board size
// Each time a mine is placed, the surrounding squares
// have their nSurround value incremented.
void setMines(FILE *inFile, Game *g);

// Randomly generate mines on Game b
// Random number of mines are determined as a
// ratio of the board size
void generateMines(Game *g);

// Sets mined to true for square at down, right
void mine(Game *g, int down, int right);

// Reveals all mines on board for end of game
void revealMines(Game *g);

// Update nSurround for squares around down, right
void updateSurround(Game *g, int down, int right);

// Prints board to screen
void drawGame(Game *g, FILE *outFile);

// Reveals square at down, right
// Game ends if it was a mine
// Otherwise, appropriate squares are revealed
void digSquare(Game *g, int down, int right);

// Digs the surrounding squares
void digSurround(Game *g, int down, int right);

// Toggles the flag on square at down, right
void toggleFlag(Game *g, int down, int right);

// Prints instructions to console
void printInstructions(void);

// Checks if user has won
bool checkWin(Game *g);

// Prints s to outFile is test mode
// otherwise, prints to console
void smartPrint(int mode, FILE *outFile, char *s);
