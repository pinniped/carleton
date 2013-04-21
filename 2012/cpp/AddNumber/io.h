#ifndef IO_H
#define IO_H
// This function is only called when cin.fail returns true.
// Given a std::string, error message, prints it to console and
// returns true. Error flag is reset and stream is flushed.
bool printError(std::string &errMsg);

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
void getInput(std::string prompt, int &n, std::string error);

// Gets user input for a integer and returns it. Loops until valid
// input for the integer is given.
int readNumber();

// Prints integer n to screen via cout
void writeAnswer(int userInteger);
#endif
