#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>

#define MAX_NUM_STR 40
#define STRING_SIZE 80

int main(int argc, const char *argv[])
{
	char fileName[STRING_SIZE];
	char word[MAX_NUM_STR][STRING_SIZE];
	int flag[MAX_NUM_STR];
	FILE * lesson;
	srand((unsigned)time(NULL));

	// Initialize words
	for (int i = 0; i < MAX_NUM_STR; i++) {
		strcpy(word[i], "\n\0");
		// 0 means unmarked
		flag[i] = 0;
	}

	// Prompt for input
	printf("This is a exercise program for ASLA 1010.\n");
	printf("Please enter the name of the file to read: ");
	// Get file name from user. Stores into fileName
	scanf("%s", &fileName);

	// Open fileName into lesson
	lesson = fopen(fileName,"r");

	// Counter for words in file
	int count = 0;
	// Reads each line of lesson into word array
	while(fscanf(lesson, "%s", word[count]) != EOF)
	{
		printf("\nThe flag is %d", flag[count]);
		//printf("The word is %s\n", word[count]);
		count++;
	}
	fclose(lesson);

	// Store number of string in file
	int numOfStr = count;

	// Used to break out of sentinel loop
	char dump[80] = "";
	int index = -1;
	for (;;) {
		printf("Press ENTER to continue (0 to exit): ");
		scanf("%s", dump);
		printf("%s\n",dump);

		if (dump[0] == '0') {
			break;
		}
		else if (count < 1) {
			printf("End of file reached.\n");
		}
		else if (count > 0) {
			index = rand() % numOfStr;
			
			// printf("%i\n", index);
			if (flag[index] == 0) {

				count--;
				flag[index] = -1;
				printf("%s\n", word[index]);
			}
		}
	}
	//printf("There are %i words in this file", count);

	return 0;
}
