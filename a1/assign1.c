/* Assignment 1: Mastermind */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

#define MAX_TRIES 3
#define NUM_PEGS  3
#define NUM_COLOURS 8

/* Initialize data structures used to maintain the colours.  
 * @param	A string containing one-letter names for all available colours
 * @return      Returns the number of colours available 
 */
int initializeGame(char colours[]);

/* Reset the clue to be "all-wrong" (where wrong is represented as a blank-character, or any character
 * not present in the colours-array.
 * @param  clue		The clue feedback given back to the user, stored as a STRING.
 */
void clearClue(char clue[]);

/* Prompt the user with the provided string and wait for a single-character response.
 * @param	prompt		A string to be printed as a prompt to the user for input.
 * @return	The first character typed by the user in response.    
 */
char prompt_and_inputChar( char prompt[] );

/* Prompt the user with the provided string and wait for a string response 
 *    (i.e. sequence of character with no whitespace).
 * @param	prompt		A string to be printed as a prompt to the user for input.
 * @param	input		A string typed in by the user in response to the prompt.    
 */
void prompt_and_inputString( int n,  char prompt[], char input[] );

/* Generate a sequence of random colours, using the provided set of legal colour-"names"
 * @param	colours	A set of one-letter names for legal colours
 * @param    nColours	The number of colours provided in colours
 * @param	solution	The randomly generated colours, stored as a STRING.
 */
void generateSolution(char colours[], int nColours, char solution[]);

/* Compares the secret solution with the user's guess, returning clues consisting of Black-Bulls and
 * White-Cows. (See Background information)
 * @param	solution		The correct, secret solution that the user is trying to guess
 * @param	guess		The current guess provided by the user
 * @param	clue			A list of clues, containing Black-blues (correct colour & position) and White-cows
 *						(correct colour but wrong position)
 * @return	True if the guess is completely correct; otherwise, false.
 */
bool match(char solution[], char guess[], char clue[]);

/* Prints the string at given location to console.
 * @param 	prompt 	Pointer to string to print.
 */
void printStr(char *prompt);

int main(void)
{
	char colours[] = "rgcytowb";	// Red, Green, Cerulean-Blue, Yellow, Tan-Brown, Orange, White, Black
	int numColours;

	int tries;						// Number of tries user has guessed, limited to MAX_TRIES
	bool correct;					// Flag to control loop.
	char answer;					// Response to prompt whether to play-again.
	char solution[NUM_PEGS+1];		// The hidden code randomly generated
	char guess[NUM_PEGS+1];		// The most recent guess entered by the user
	char clue[NUM_PEGS+1];		// The clues returned to the user, made up of Black(Bulls) and White(Cows)

	//printf("Size of colours array is: %d.\n", test);
	char c = prompt_and_inputChar("Enter a character please: ");
	printf("Your char was: %c\n", c);
	return 0;
}


/* Initialize data structures used to maintain the colours.  
 * @param	A string containing one-letter names for all available colours
 * @return      Returns the number of colours available 
 */
int initializeGame(char colours[])
{
	// Initialize the random number generator.  See C Library reference stdutil.h
	srand((unsigned)time(NULL));

	return NUM_COLOURS;
}

/* Reset the clue to be "all-wrong" (where wrong is represented as a blank-character, or any character
 * not present in the colours-array.
 * @param  clue		The clue feedback given back to the user, stored as a STRING.
 */
void clearClue(char clue[])
{ 


}

/* Prints the string at given location to console.
 * @param 	prompt 	Pointer to string to print.
 */
void printStr(char *prompt)
{
	while (*prompt != '\0') {
		printf("%c", *(prompt++));
	}
}

/* Prompt the user with the provided string and wait for a single-character response.
 * @param	prompt		A string to be printed as a prompt to the user for input.
 * @return	The first character typed by the user in response.    
 */
char prompt_and_inputChar( char prompt[] )
{
	char inputChar;

	printStr(prompt);

	scanf(" %c", &inputChar);
	return inputChar;
}


/* Prompt the user with the provided string and wait for a string response 
 *    (i.e. sequence of character with no whitespace).
 * @param	prompt		A string to be printed as a prompt to the user for input.
 * @param	input		A string typed in by the user in response to the prompt.    
 */
void prompt_and_inputString( int n,  char prompt[], char input[] )
{
	printStr(prompt);

}

/* Generate a sequence of random colours, using the provided set of legal colour-"names"
 * @param	colours	A set of one-letter names for legal colours
 * @param    nColours	The number of colours provided in colours
 * @param	solution	The randomly generated colours, stored as a STRING.
 */
void generateSolution(char colours[], int nColours, char solution[])
{

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


}
