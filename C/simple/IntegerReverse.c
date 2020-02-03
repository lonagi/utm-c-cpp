#include <stdio.h>

int main(void) {

	int n = -123;
	
	int reverseN = 0;

	while (n) {
		reverseN = reverseN * 10 + (n % 10);
		n /= 10;
	}

	printf("%d ", reverseN);

  return 0;
}