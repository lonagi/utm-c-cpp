#include <stdio.h>

int main(void) {

	int arr[9] = {567, 5, 4, 2, 9, 6, 5, 1, 8};

	int leng = sizeof(arr) / 4;

	int swapped, temp;

	do {

		swapped = 0;
		
		for (int i = 0; i < leng - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp; 
				swapped = 1;
			}
		}

	} while (swapped);

	// or

	// for (int i = 0; i < leng; i++) {
  //     for (int j = 0; j < leng - 1; j++) {
  //         if (arr[j] < arr[j + 1]) {
  //             temp = arr[j];
  //             arr[j] = arr[j + 1];
  //             arr[j + 1] = temp;
  //         }
  //     }
  // }


	// test
	for (int j = 0; j < leng; j++) {
		printf("%d ", arr[j]);
	}
	
  return 0;
}