#include <stdio.h>

void print_string(char str[]);
int str_length( char str[] );
void max_occurrence(char str[], char *character, int *num);

int main(void)
{
	// Test print_array

	char str1[] = {'h','e','l','l','o','\0'};
	char str2[] = "a";  // String with 1 character
	char str3[] = "";  // String with 0 character

	printf("Calling print_string\n");
	printf("Expected output: hello\n");
	printf("Actual output:   ");
	print_string(str1);
	printf("\n\n");

	printf("Calling print_string\n");
	printf("Expected output: a\n");
	printf("Actual output:   ");
	print_string(str2);
	printf("\n\n");

	printf("Calling print_string\n");
	printf("Expected output: a\n");
	printf("Actual output:   ");
	print_string(str2);
	printf("\n\n");

	// Test str_length

	printf("Calling str_length\n");
	printf("Expected output: 5\n");
	printf("Actual output:   ");
	printf ("%d", str_length(str1));
	printf("\n\n");

	printf("Calling str_length\n");
	printf("Expected output: 1\n");
	printf("Actual output:   ");
	printf ("%d", str_length(str2));
	printf("\n\n");

	printf("Calling str_length\n");
	printf("Expected output: 0\n");
	printf("Actual output:   ");
	printf ("%d", str_length(str3));
	printf("\n\n");

	// Test max_occurrence

	char maxChar;
	int maxOccur;

	maxChar = '-';
	maxOccur = -1;
	printf("Calling max_occurrence\n");
	printf("Expected output: l 2 \n");
	printf("Actual output:   ");
	max_occurrence(str1, &maxChar, &maxOccur);
	printf ("%c %d",maxChar, maxOccur);
	printf("\n\n");

	maxChar = '-';
	maxOccur = -1;
	printf("Calling max_occurrence\n");
	printf("Expected output: a 1 \n");
	printf("Actual output:   ");
	max_occurrence(str2, &maxChar, &maxOccur);
	printf ("%c %d",maxChar, maxOccur);
	printf("\n\n");

	maxChar = '\0';
	maxOccur = -1;
	printf("Calling max_occurrence\n");
	printf("Expected output: null(or blank) 0 \n");
	printf("Actual output:   ");
	max_occurrence(str3, &maxChar, &maxOccur);
	printf ("%c %d",maxChar, maxOccur);
	printf("\n\n");

	return 0;
}

void print_string(char str[]) {
	printf("%s\n", str);
}
int str_length( char str[] ) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}
void max_occurrence(char str[], char *character, int *num) {
	*character = '\0';
	*num = 0;
	int i = 0;

	while (str[i] != '\0') {
		int j = 0;
		int occurences = 0;

		while (str[j] != '\0') {
			if (str[i] == str[j]) {
				occurences++;
			}
			j++;
		}

		if (occurences >= *num) {
			*character = str[i];
			*num = occurences;
		}

		i++;
	}
}
