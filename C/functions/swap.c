#include <stdio.h>

void swap(int* a, int* b) {

	int tmp;

	tmp = *a; 
	*a = *b;
	*b = tmp;

}

int main(void) {

	int x, y;
	scanf("%d %d", &x, &y);
	swap(&x, &y);
	printf("x is %d y is %d \n", x, y);

  return 0;
}