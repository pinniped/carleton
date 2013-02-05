/* Assignment 1: Mastermind */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

#define MAX_TRIES 10
#define NUM_PEGS  3
#define CLUE_SIZE  5
#define SPACES_IN_TAB  5
#define BORDER_SIZE  31

int initializeGame(char colours[]);
void clearClue(char clue[]);
char prompt_and_inputChar( char prompt[] );
void prompt_and_inputString(char prompt[], char input[] );
void generateSolution(char colours[], int nColours, char solution[]);
bool match(char solution[], char guess[], char clue[]);
void printInstructions(char colours[], char solution[]);
void printHeader();
void printBorder();

int main(void)
{
	char colours[] = "rgcytowb";	// Red, Green, Cerulean-Blue, Yellow, Tan-Brown, Orange, White, Black
	int numColours;

	int tries;						// Number of tries user has guessed, limited to MAX_TRIES
	bool correct;					// Flag to control loop.
	char answer;					// Response to prompt whether to play-again.
	char solution[NUM_PEGS+1];		// The hidden code randomly generated
	char guess[NUM_PEGS+1];		// The most recent guess entered by the user
	char clue[CLUE_SIZE+1];		// The clues returned to the user, made up of Black(Bulls) and White(Cows)

	correct = 0;
	numColours = initializeGame(colours);
	do {

		clearClue(clue);
		// Initialize clue
		clue[0] = '0';
		clue[1] = 'B';
		clue[2] = ':';
		clue[3] = '0';
		clue[4] = 'C';


		// Optionally display instructions
		answer = prompt_and_inputChar("Do you want to see instructions? ");
		if (answer == 'y' || answer == 'Y') {
			generateSolution(colours, numColours, solution);
			printInstructions(colours, solution);
		}

		printHeader();

		// Start game
		generateSolution(colours, numColours, solution);
		tries = 0;
		do {
			printf("%d\t", tries + 1);
			prompt_and_inputString (clue, guess);
			correct = match(solution, guess, clue);
		} while (++tries < MAX_TRIES && !correct);
		if (correct)
			printf ("\nCongratulations. You have successfully guessed the code: %s!\n", solution);
		else 
			printf ("\nSorry, you have used up all your guesses. The code was: %s.\n", solution);
		answer = prompt_and_inputChar("\nDo you want to play again? ");
	} while (answer == 'y' || answer == 'Y');

	return 0;
}

/* Prints instructions to the console for playing the game
 * @param	colours 	A string containing one-letter names for all available colours
 * @param	solution	The randomly generated colours, stored as a STRING.
 */
void printInstructions(char colours[], char solution[]) {
	printf("\nYou must follow these instructions EXACTLY or the game will break:\n\n", NUM_PEGS);
	printf("I am thinking of %d colours represented by the characters ");
	printf("\"%s\".", colours);
	printf("\n\n\tFor example: %s\n\n", solution);
	printf("You have %d tries to guess my colors by typing in characters representing colours.\n", MAX_TRIES);
	printf("After each guess, I will give you a clue telling you how many colors you have\n");
	printf("that are the RIGHT COLOUR and RIGHT POSITION, represented by BULLS ");
	printf("and how many \ncolors you have");
	printf("that are the RIGHT COLOUR and WRONG POSITION, represented by COWS.");
	printf("\n\n\tFor example: 2B:1C\n\n");
	printf("means you have 2 colors that are the RIGHT COLOUR and RIGHT POSITION, \nand ");
	printf("1 color that is the RIGHT COLOUR and WRONG POSITION.\n");
	printf("\nYou must only enter exactly %d characters for each guess. Good luck and have fun!\n", NUM_PEGS);
}

// Prints the header for the game
void printHeader() {
	// Print out a nice formatted header for the next round of guess 
	// Suggestion:    Try #        |     Clue        |    Your next guess
	//                          --------------------------------------------------------
	printf ("\n\nTry\tClue\tYour next guess\n");    
	// Print border for words
	for (int i = 0; i < BORDER_SIZE; i++) {
		printf("-");
	}
	// To make it perfect need to "stretch" it vis-a-vis NUM_PEGS
	printBorder();
}

// Stretches border to an appropriate size based on NUMP_PEGS
void printBorder() {
	int numTabs = NUM_PEGS/SPACES_IN_TAB;
	for (int i = 0; i < numTabs; i++) {
		for (int j = 0; j < SPACES_IN_TAB; j++) {
			printf("-");
		}
	}
	printf("\n");
}

/* Initialize data structures used to maintain the colours.  
 * @param	colours 	A string containing one-letter names for all available colours
 * @return  Returns the number of colours available 
 */
int initializeGame(char colours[])
{
	// Initialize the random number generator.  See C Library reference stdutil.h
	srand( time(NULL) );
	return strlen(colours);
}

/* Reset the clue to be "all-wrong" (where wrong is represented as a blank-character, or any character
 * not present in the colours-array.
 * @param  clue		The clue feedback given back to the user, stored as a STRING.
 */
void clearClue(char clue[])
{ 
	for (int i = 0; i < CLUE_SIZE; i++) {
		clue[i] = ' ';
	}
	clue[CLUE_SIZE] = '\0';
}

/* Prompt the user with the provided string and wait for a single-character response.
 * @param	prompt		A string to be printed as a prompt to the user for input.
 * @return	The first character typed by the user in response.    
 */
char prompt_and_inputChar( char prompt[] )
{
	char inputChar;
	printf("%s\t", prompt);
	scanf(" %c", &inputChar);
	return inputChar;

}


/* Prompt the user with the provided string and wait for a string response 
 *    (i.e. sequence of character with no whitespace).
 * @param	prompt		A string to be printed as a prompt to the user for input.
 * @param	input		A string typed in by the user in response to the prompt.    
 */
void prompt_and_inputString(char prompt[], char input[] )
{
	printf("%s\t", prompt);
	scanf("%s", input);
}

/* Generate a sequence of random colours, using the provided set of legal colour-"names"
 * @param	colours	A set of one-letter names for legal colours
 * @param    nColours	The number of colours provided in colours
 * @param	solution	The randomly generated colours, stored as a STRING.
 */
void generateSolution(char colours[], int nColours, char solution[])
{
	int randomNum;
	for(int i = 0; i < NUM_PEGS; i++) {
		randomNum = rand() % nColours;
		solution[i] = colours[randomNum];
	}

	solution[NUM_PEGS] = '\0';

}

/* Compares the secret solution with the user's guess, returning clues consisting of Black-Bulls and
 * White-Cows. (See Background information)
 * @param	solution		The correct, secret solution that the user is trying to guess
 * @param	guess		The current guess provided by the user
 * @param	clue			A list of clues, containing Black-blues (correct colour & position) and White-cows
 *						(correct colour but wrong position)
 * @return	True if the guess is completely correct; otherwise, false.
 */
bool match(char solution[], char guess[], char clue[])
{
	const int UNMARKED = 0, BLACK = 1, WHITE = 2;
	int flag[NUM_PEGS];
	int bulls = 0,
		cows = 0;

	// Initialize flag
	for (int i = 0; i < NUM_PEGS; i++) {
		flag[i] = UNMARKED;
	}

	// Check for blacks
	for (int i = 0; i < NUM_PEGS; i++) {
		if (solution[i] == guess[i]) {
			flag[i] = BLACK;
		}
	}

	// Check for whites
	for (int i = 0; i < NUM_PEGS; i++) {
		//Skip if letter has already been matched as a Bull
		if (flag[i] == BLACK) {
			continue;
		}
		
		// Check each element in both array for matches if the element has
		// not been matched in the previous traversal
		for (int j = 0; j < NUM_PEGS; j++) {
			if ((flag[j] == UNMARKED) && (solution[j] == guess[i])) {
				flag[j] = WHITE;	
			}
		}
	}
	// Count bulls and cows from flags
	for (int i = 0; i < NUM_PEGS; i++) {
		if (flag[i] == BLACK) {
			bulls++;
		} else if (flag[i] == WHITE) {
			cows++;
		}

	}

	// Stores the clue information into the clue array.
	clue[0] = '0' + bulls;
	clue[3] = '0' + cows;

	return (bulls == NUM_PEGS); 
}
