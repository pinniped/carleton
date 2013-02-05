/* This program takes in user input for number of digits and
 * the highest valid digit, and generates a random combination
 * of numbers between 0 and the highest valid digit. The user 
 * can then guess for the number combination, and the program
 * prints to screen the number of correctly guessed digits, but
 * in the wrong location, and the number of correctly guessed 
 * digits in the right location. */

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;


const int MAXDIGITS = 8;

// Clears cin flags and removes input from stream
void cleanStream() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}



// picks a number between 1 and "maxValidDigit" (inclusive)
int pickDigit (int maxValidDigit) {

	return 1 + int((rand() / (RAND_MAX + 1.0)) * maxValidDigit);

}


// selects a code (Hint: use pickDigit)
//*************************************
// write function "pickCode" here
//*************************************
void pickCode (int digits, int code[], int highestValidDigit) {
	for (int i = 0; i < digits; i++) {
		code[i] = pickDigit(highestValidDigit);
	}
}


// returns "true" if guess successfully obtained.
// returns "false" if "quit" entered.
bool readGuess (int numberOfDigits, int guess[], int highestValidDigit) {

	char guessString [MAXDIGITS + 2];
	bool allValid;
	int i;

	for (;;) {

		cout << "Enter guess (\"quit\" to end game): ";
		cin >> setw(MAXDIGITS + 2) >> guessString;
		cin.ignore (INT_MAX, '\n'); // discard reset of input line

		if (stricmp(guessString, "quit") == 0) {

			return false;

		}

		if (strlen(guessString) != (unsigned) numberOfDigits) {

			cout << "*** Invalid code (bad length) ***" << endl;

		} else {

			allValid = true; // make assumption
			for (i = 0; i < numberOfDigits; i++) {
				if (!isdigit(guessString[i])) {
					allValid = false; break;
				}
				guess[i] = guessString[i] - '0';
				if ((guess[i] == 0) || (guess[i] > highestValidDigit)) {
					allValid = false; break;
				}
			}

			if (allValid) {
				return true; // code successfully obtained
			}

			cout << "*** Invalid code (bad digit) ***" << endl;

		}

	}

}


// analyzes the guess by the user to figure out how many blacks and whites
// the user gets to help him/her make a better next guess
//*********************************************
// write function analyzeGuess here
//*********************************************
void analyzeGuess (int digits, int code[], int guess[], int &blacks, int &whites) {
	const int UNMARKED = 0, BLACK = 1, WHITE = 2;
	int flag[MAXDIGITS];

	// Initialize blacks and whites
	blacks = 0, whites = 0;

	// Initialize flag
	for (int i = 0; i < digits; i++) {
		flag[i] = UNMARKED;
	}

	// Check for blacks
	for (int i = 0; i < digits; i++) {
		if (code[i] == guess[i]) {
			flag[i] = BLACK;
		}
	}

	// Check for whites
	for (int i = 0; i < digits; i++) {
		for (int j = 0; j < digits; j++) {
			// Compare values of code and guess at i and j
			// respectively when flag at j is UNMARKED, and marks
			// them WHITE if they are equal
			if ((flag[j] == UNMARKED) && (code[i] == guess[j])) {
				flag[j] = WHITE;	
			}
		}
	}

	// Count blacks and whites from flags
	for (int i = 0; i < digits; i++) {
		if (flag[i] == BLACK) {
			blacks++;
		} else if (flag[i] == WHITE) {
			whites++;
		}
	}
}


int main () {

	int digits, highestValidDigit,
	    code[MAXDIGITS], guess[MAXDIGITS], blacks, whites;
	char reply;

   // "seed" the random number generator with the current system
   // time. this ensures that we won't get exactly the same
   // sequnce of "random" numbers every time we run the program.
   srand (time(NULL));

	//****************************************************************************
	// Insert code that reads in the number of digits and the highest valid digit.
	// This code should loop until valid values are entered.
	//****************************************************************************
	for (;;) {
		cout << "Enter number of digits and highest valid digit: ";
		cin >> digits >> highestValidDigit;
		if (!(cin.fail())
				&& (digits >= 3 && digits <= MAXDIGITS)
				&& (highestValidDigit >= 2 && highestValidDigit <= 9)) {
			break;
		} else {
			cout << "*** Inalid selection ignored ***" << endl;
			cleanStream();
		}
	}

	do {

        // get the code that the user must guess
		pickCode (digits, code, highestValidDigit);

		/*
		// useful when debugging
		cout << "The code is ";
		for (int i = 0; i < digits; i++) {
			cout << code[i];
		}
		cout << endl; */

		for (;;) {

			if (!readGuess (digits, guess, highestValidDigit)) { // user has quit
                system("PAUSE");
                return 0;
			}

			// work out how many blacks and whites should be displayed
			analyzeGuess (digits, code, guess, blacks, whites);
			
			if (blacks == digits) {
				cout << "Congratulations - you have broken the code!!" << endl;
				break;
			}

			cout << "Blacks : " << blacks << " Whites: " << whites << endl;

		}

		cout << "Do you wish to play again (Y/N): ";
		cin >> reply;
		cin.ignore (INT_MAX, '\n'); // discard rest of input line

	} while (toupper(reply) == 'Y');
	
	system("PAUSE");
	return 0;

}
