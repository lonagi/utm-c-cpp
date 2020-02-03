#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Hello World\n");
	
	int rows = 3, cols = 4;

	int *arr = malloc(rows * cols * sizeof(int));

	int i, j, count = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			// is the same as arr[i][j]
			// i is a current row
			// j is a current column
			*(arr + i * cols + j) = ++count;
		}
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%3d ", *(arr + i * cols + j));
		}
		printf("\n");
	}

  return 0;
}