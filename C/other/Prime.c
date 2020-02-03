#include <stdio.h>

int main(void) {

	int n;
	scanf("%d", &n);

	int i;

	for (i = 2; i * i <= n; i++) {
		if (!(n % 2)) {
			break;
		}
	}	

	if (i * i >= n) {
		printf("prime");
	} else {
		printf("not prime");
	}

  return 0;
}