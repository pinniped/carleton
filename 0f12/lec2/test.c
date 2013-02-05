#include <stdio.h>
int main(int argc, const char *argv[])
{
	char c='a';
	printf("Prompt:");
	int count = 0;
	// scanf(%c): characters are queued/buffered internally until newline/ENTER
	while (c != 'A') {
		// If there are characters in buffer, scanf will read that first
		// NB Buffer takes '\n' as well and scanf will will read that
		// Console input is always text-based characters
		scanf("%c",&c);
		printf("%c",c);
		count++;
		printf("\n%i\n",count);
	}

	printf("\n%i\n",count);
	printf("Done\n");
	return 0;
}
