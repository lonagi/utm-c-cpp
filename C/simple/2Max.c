#include <stdio.h>
#include <limits.h>

int main(void) {

	int maxOne, maxTwo;
	maxOne = maxTwo = INT_MIN;

	int arr[20] = {34, 54, 1, 5, 4, 8, 8, 88, 70};

	for (int i = 1; i < 20; i++) {
		if (arr[i] > maxOne) {
			maxTwo = maxOne;
			maxOne = arr[i];
		} else if (maxTwo < arr[i]) {
		 	maxTwo = arr[i];
		}
	}

	printf("max one is %d two is %d", maxOne, maxTwo);
  return 0;
}