#include <stdio.h>

int gcd(int x, int y);

int main(void) {

	int a, b;
	
	printf("input two numbers \n"); scanf("%d %d", &a, &b);

	 b = b < 0 ? -b : b;

	while (a != b) {	
		if (a > b) {
			a -= b;
		} else {
			b -= a;
		}
	}

	printf("gcd is %d \n", a);

	// Solution #2
	// handle negative numbers, but uses recursion

	int gcdN = gcd(-4, 14);

	printf("%d", gcdN);

  return 0;
}

int gcd(int x, int y) {

	if (!(x % y)) {
		return y;
	}
	
	return gcd(y, x % y);
}
