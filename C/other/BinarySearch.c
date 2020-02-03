#include <stdio.h>

int main(void) {

	int arr[10] = {1, 5, 7, 10, 20, 40, 71, 80, 83, 85};  
	
	int x;

	scanf("%d", &x);

	int mid;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;

	while (left <= right) {

		mid = (left + right) / 2;

		if (arr[mid] == x) {
			printf("%d was found at %d", x, mid);
			break;
		} else if (x < arr[mid]) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
		
	}

  return 0;
}