#include <stdbool.h>

typedef struct {
	char first[80];
	char last[80];
} NAME;

typedef struct {
	int number;
	char street[80];
	char city[80];
	char postalCode[6];
} ADDRESS;

typedef struct {
	NAME name;
	int number;
	ADDRESS address;
} STUDENT;

int scanName(NAME *name);
int scanAddress( ADDRESS *address);
int scanStudent(STUDENT *student);

void printName(NAME name);
void printAddress( ADDRESS address);
void printStudent(STUDENT student);

// Returns true if the given postalCode has the proper format.
// More details: See Canada Post
bool isValidPostalCode( char *postalCode );



