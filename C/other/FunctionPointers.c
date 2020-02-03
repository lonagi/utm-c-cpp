#include <stdio.h>

int add(int a, int b);

int main(void) {

	// array of pointers pointing to 10 integers
	int *arrOfPtr[10]; 

	// pointer to array of integers
	int (*ptrToArray)[10];

	int (*ptr)(int a, int b);
	ptr = &add; // or just name of the function
	// because name of the function represents its address

	printf("%p \n", add);

	int result = ptr(1, 2);
	printf("result is %d ", result);

  return 0;
}

int add(int a, int b) {
	return a + b;
}
