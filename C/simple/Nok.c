#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int a, b, lcm;
	
	printf("enter two numbers \n"); scanf("%d %d", &a, &b);

	a = abs(a);
	b = abs(b);

 	lcm = a * b;

	while (a != b) {
		if (a > b) {
			a -= b;
		} else {
			b -= a;
		}
	}

	printf("%d is gcd \n", a);

	lcm /= a;

	printf("lcm is %d", lcm);

  return 0;
}