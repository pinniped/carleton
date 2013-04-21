#include <iostream>
#include <string>
#include <limits>

using namespace std;

// This function is only called when cin.fail returns true.
// Given a string, error message, prints it to console and
// returns true. Error flag is reset and stream is flushed.
bool printError(string &errMsg) {
	// Output error to console
	cout << errMsg << endl;
	cout << "Test";

	// Reset cin flag and flushes stream
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return 1;
}

// Given a intger variable and a prompt message, and
// an error message, prints message to screen and stores
// input to varaible. This process loops until valid input
// is given, and ouputs error message to screen when input
// is invalid.
// Eg. getInput("Please enter a number: ", myNumber, "Invalid input!")
// Please enter a number: [5]
// myNumber -> 5
// Please enter a number: [asdf]
// Invalid input!
void getInput(string prompt, int &n, string error) {
	do {
		// Prompt for input and store in userInteger
		// Loops until valid input is given
		cout << prompt;
		cin >> n; 
	} while (cin.fail() && printError(error));
}

// Gets user input for a integer and returns it. Loops until valid
// input for the integer is given.
int readNumber() {
	// For storing user input
	int userInteger;
	
	const string prompt 	= "Please enter number of children you produced: "; 
	const string error 	= "Invalid input!";
	
	//  Prompt for input until valid input is given and stores in
	//  userInteger. Outputs error when input invalid and reprompts.
	getInput(prompt, userInteger, error);

	return userInteger;
}

// Prints integer n to screen via cout
void writeAnswer(int userInteger) {
	cout << "The sum is: " << userInteger << endl;
}
