#include <stdio.h>
int main(int argc, const char *argv[])
{
	int i = 0;
	char c = 'Z';
	printf("Prompt:");
	int count = 0;
	int sum = 0;
	// scanf(%c): characters are queued/buffered internally until newline/ENTER
	while (i != 10) {
		// For scanf("%i");
		// Whitespace ('\n', space, tab) ignored
		scanf("%i",&i);
		printf("%i",i);
		sum += i;
		printf("SUM: %i\n",sum);
		count++;
	}

	printf("\n%i\n",count);
	printf("Done\%i\%d\n");
	return 0;
}
