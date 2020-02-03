#include <stdio.h>
#include <limits.h>

int main(void) {

	int arr[5] = {2, 3, 7, 6, 1};

	int minO, minT;

	minO = minT = INT_MAX;

	for (int i = 0; i < 5; i++) {
		if (minO > arr[i]) {
			minT = minO;
			minO = arr[i];
		} else if (minT > arr[i]) {
			minT = arr[i];
		}
	}

	printf("Min1 = %d , Min2 = %d", minO, minT);

  return 0;
}