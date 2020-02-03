#include <stdio.h>

int main(void) {
	
	int arr[5] = {1, 1, 3, 4, 5};
	
	int currChain = 1;
	int longestChain = 1;

	for (int i = 0; i < 5; i++) {
		if (arr[i] == arr[i + 1]) {
			currChain++;
		} else if (currChain > 1) {
			if (currChain > longestChain) {
				longestChain = currChain;
			}
			currChain = 1;
		}
	}

	printf("%d", longestChain);

  return 0;
}