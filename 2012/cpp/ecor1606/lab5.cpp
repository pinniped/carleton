#include <iostream>
#include <cmath>

using namespace std;

// My cross-platform replacement for system("pause")
void waitReturn()
    {
        char c;
        cout << "Return to continue...";
        cin.read(&c,1);
        if (cin.peek() == 0xA) {;}
    }

bool isInt (double value) {
	double dummy;
	return bool(modf(value, &dummy) == 0);
}

double sqr(double value) { return value * value; }

int main (void) {
	// Variables
	int value,
		remainder,
		thousands,
		hundreds,
		tens,
		ones;

	// Prompt for number to be converted to Roman numerals and store
	cout << "Please enter an integer between 1 and 3999 (0 to stop): ";
	cin >> value;
		
		
	// Sentinel loop
	while (value != 0) {
		// Check for valid input
		if (value > 0 && value < 4000) {
			// Separate the value into its digits
			thousands = value / 1000;
			remainder = value % 1000;
			hundreds = remainder / 100;
			remainder = remainder % 100;
			tens = remainder / 10;
			ones = remainder % 10;

			// Output results
			cout << value << " in Roman numerals is ";

			// Output thousands
			while (thousands > 0) {
				cout << "M";
				thousands--;
			} // End While

			// Output hundreds
			if (hundreds == 9) {
				cout << "CM";
			} else if (hundreds == 4) {
				cout << "CD";
			} else {
				if (hundreds >= 5) {
					cout << "D";
					hundreds -= 5;
				} // End if
				while (hundreds != 0) {
					cout << "C";
					hundreds --;
				} // End While
			} // End If
		
			// Output tens
			if (tens == 9) {
				cout << "XC";
			} else if (tens == 4) {
				cout << "XL";
			} else {
				if (tens >= 5) {
					cout << "L";
					tens -= 5;
				} // End if

				while (tens != 0) {
					cout << "X";
					tens --;
				} // End While
			} // End If

			// Output ones
			if (ones == 9) {
				cout << "IX";
			} else if (ones == 4) {
				cout << "IV";
			} else {
				if (ones >= 5) {
					cout << "V";
					ones -= 5;
				} // End if

				while (ones != 0) {
					cout << "I";
					ones --;
				} // End While
			} // End If

			// cout << endl
			cout << endl;
		} else {
			cout << "Invalid value ignored." << endl;
		} //End If

		// Repromt for value input and store
		cout << "Please enter an integer between 1 and 3999 (0 to stop): ";
		cin >>  value;
		
	}
	
	waitReturn();
	return 0;
}
