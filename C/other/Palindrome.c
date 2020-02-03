#include <stdio.h>

int main(void) {

	int n;
	scanf("%d", &n);

	int arr[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int j, k;

	for (j = 0, k = n - 1; j <= n / 2; j++, k--) {
		if (arr[j] != arr[k]) {
			break;
		}
	}

	if (j <= n / 2) {
		printf("Not a palindrom");
	} else {
		printf("Palindrom");
	}

  return 0;
}