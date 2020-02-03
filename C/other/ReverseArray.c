#include <stdio.h>

int main(void) {

	int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

	int leng = sizeof(arr) / sizeof(arr[0]);

	int temp;

	// in place
	for (int i = leng - 1, j = 0; i >= leng / 2; i--, j++) {
		temp = arr[j]; 
		arr[j] = arr[i];
		arr[i] = temp;
	}

	// int arr1[5];

	// with new array
	// for (int i = leng - 1, j = 0; i >= 0; i--, j++) {
	// 	arr1[j] = arr[i];
	// }

	// test
	for (int k = 0; k < leng; k++) {
		printf("%d ", arr[k]);
	}

  return 0;
}