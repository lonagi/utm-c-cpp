#include <stdio.h>

int main(void) {

	int n;
	scanf("%d", &n);
	
	int arr[100] = {0, 1};

	for (int i = 2; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	
	// test
	for (int k = 0; k < n; k++) {
		printf("%d ", arr[k]);
	}

	printf("%d Fibonacci number is %d ", n, arr[n - 1]);

  return 0;
}