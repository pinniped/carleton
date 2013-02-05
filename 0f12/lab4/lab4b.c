#include <stdio.h>

#define N_ROWS 5
#define N_COLS 3

int main(int argc, const char *argv[])
{
	FILE *oFile = fopen("outfile.txt", "w");
	int array[N_ROWS][N_COLS]; 

	for (int i = 0; i < N_ROWS; i++) {
		for (int j = 0; j < N_COLS; j++) {
			array[i][j] = i*100 + j;

			if (j != 0) {
				fprintf(oFile, ", ");
			}
			fprintf(oFile, "%d", array[i][j]);
		}
		fprintf(oFile, "\n");
	}


	for (int i = 0; i < N_ROWS; i++) {
		for (int j = 0; j < N_COLS; j++) {
			fscanf(oFile, "%d", &array[i][j]);
		}
	}

	for (int j = 0; j < N_COLS; j++) {
		for (int i = 0; i < N_ROWS; i++) {
			if (i != 0) {
				printf(", ");
			}
			printf("%d", array[i][j]);
		}
		printf("\n");
	}

	fclose(oFile);

	return 0;
}
