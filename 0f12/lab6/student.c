
int scanName(NAME *name) {
	printf("Please enter your first name: ");
	scanf("%s", name->first);
	printf("Please enter your last name: ");
	scanf("%s", name->last);
}
int scanAddress( ADDRESS *address) {
}
int scanStudent(STUDENT *student) {
}

void printName(NAME name) {
	printf("%s, %s\n", name->last, name->first);
}
void printAddress( ADDRESS address) {
}
void printStudent(STUDENT student) {
}

// Returns true if the given postalCode has the proper format.
// More details: See Canada Post
bool isValidPostalCode( char *postalCode ) {
}
