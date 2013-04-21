#include <iostream>
#include <cmath>

using namespace std;

// Cross-platform replacement to system("pause")
void waitReturn() {
	cout << "Press ENTER to continue...";
	cin.get();
}

// Sanitize input stream
void iClear() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main (void) {

	// Variables
	int roomLength,
		roomWidth,
		buffer,
		carpetLength,
		carpetWidth,
		validRoomTries = 0,
		carpetSizesEntered = 0,
		invalidCarpetSizes = 0,
		validCarpetSizes = 0,
		carpetFits = 0,
		carpetTrims = 0,
		carpetFails = 0,
		carpetAreaSum = 0,
		currentCarpetArea,
		minCarpetArea,
		maxCarpetArea;

	double avgCarpetArea;

	// Loop for room dimension input
	do {
		// Prompt user for room dimensions and take input
		cout << "Please enter room dimensions: ";
		cin >> roomLength >> roomWidth;
		iClear();

		// Count room dimension inputs
		validRoomTries++;

		// Check for valid room dimension input
		if (roomLength > 0 && roomWidth > 0) {
			// Switches roomLength and roomWidth if roomLength is less than roomWidth
			if (roomLength < roomWidth) {
				buffer = roomWidth;
				roomWidth = roomLength;
				roomLength = buffer;
			} // end if
		} else {
			// Invalid input
			cout << "Those dimensions are invalid." << endl;
		} // end if
	} while (roomLength <= 0 || roomWidth <= 0);

	// Promt user for carpet dimensions and take input
	cout << "Please enter carpet dimensions (0 0 to stop): ";
	cin >> carpetLength >> carpetWidth;
	iClear();

	// Sentinel loop for carpet dimensions input
	while (!(carpetLength == 0 && carpetWidth == 0)) {
		//Count carpet sizes entered
		carpetSizesEntered++;

		// Check for valid input
		if (carpetLength > 0 && carpetWidth > 0) {
			//Valid carpet dimension count
			validCarpetSizes++;
			// Calculate area of current carpet
			currentCarpetArea = carpetLength * carpetWidth;
			// Calculate sum of valid carpet dimensions
			carpetAreaSum +=  currentCarpetArea;
			
			// Update max carpet area
			if (validCarpetSizes == 1) {
				maxCarpetArea = currentCarpetArea;
			} else if (currentCarpetArea > maxCarpetArea) {
				maxCarpetArea = currentCarpetArea;
			}

			// Update min carpet area
			if (validCarpetSizes == 1) {
				minCarpetArea = currentCarpetArea;
			} else if (currentCarpetArea < minCarpetArea) {
				minCarpetArea = currentCarpetArea;
			}

			// Switches carpetLength and carpetWidth if carpetLength is less than carpetWidth
			if (carpetLength < carpetWidth) {
				buffer = carpetWidth;
				carpetWidth = carpetLength;
				carpetLength = buffer;
			} // end if

			// Output appropriate response
			if (carpetLength == roomLength && carpetWidth == roomWidth) {
				// Count perfect carpets
				carpetFits++;
				cout << "The carpet is a perfect fit." << endl;
			} else if (carpetLength < roomLength || carpetWidth < roomWidth) {
				// Count unusable carpets
				carpetFails++;
				cout << "The carpet cannot be used." << endl;
			} else {
				// Count trimmable carpets
				carpetTrims++;
				cout << "The carpet can be trimmed to size." << endl;
			} // end if
		} else {
			// Count invalid carpet inputs
			invalidCarpetSizes++;

		// Invalid input
		cout << "Those dimensions are invalid." << endl;
		} // end if

		// Promt user for carpet dimensions and take input
		cout << "Please enter carpet dimensions (0 0 to stop): ";
		cin >> carpetLength >> carpetWidth;
		iClear();
	} // end while

	// Output statistics
	// Unconditional outputs
	cout << "\nThe number of tries to get a valid room size was: " << validRoomTries << "." << endl << endl;

	cout << "The number of carpet sizes entered was: " << carpetSizesEntered << "." << endl;
	cout << "The number of invalid carpet sizes was: " << invalidCarpetSizes << "." << endl;
	cout << "The number of valid carpet sizes was: " << validCarpetSizes << "." << endl << endl;

	// Number of carpets that can be trimmed, were perfect, or were useless
	cout << "The number of carpets that fit exactly was: " << carpetFits << "." << endl;
	cout << "The number of carpets that could be trimmed was: " << carpetTrims << "." << endl;
	cout << "The number of carpets that could not be used was: " << carpetFails << "." << endl << endl;

	// Conditional outputs
	// At least one carpet size entered (non-sentinel)
	if (carpetSizesEntered > 0) {
		// Percent of valid/invalid carpets
		cout << "The percent of invalid carpets was: "
			<< invalidCarpetSizes / carpetSizesEntered * 100 << "%." << endl;
		cout << "The percent of valid carpets was: "
			<< validCarpetSizes / carpetSizesEntered * 100 << "%." << endl << endl;

		// At least one valid carpet size entered
		if (validCarpetSizes > 0) {
			// Percent of carpets that can be trimmed, were perfect, or were useless
			cout << "Of the valid carpets:" << endl;
			cout << "The percent of trim to size carpets was: "
				<< carpetTrims / validCarpetSizes * 100 << "%." << endl;
			cout << "The percent of carpets that could be used was: "
				<< carpetFits / validCarpetSizes * 100 << "%." << endl;
			cout << "The percent of carpets that could not be used was: "
				<< carpetFails / validCarpetSizes * 100 << "%." << endl << endl;

			// Avg area
			cout << "The average valid carpet area was "
				<< carpetAreaSum / validCarpetSizes << "." << endl; 

			// Min/max area
			cout << "The smallest valid carpet area was "
				<< minCarpetArea << "." << endl;
			cout << "The largest valid carpet area was "
				<< maxCarpetArea << "." << endl;

		}
	}

	waitReturn();
	return 0;
}
