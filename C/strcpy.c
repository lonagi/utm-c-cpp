#include <stdio.h>

// strcpy: copy t to s
void strcpyKR(char* s, char* t) {
	while ((*s++ = *t++));
}

int main(void) {

	char str1[20] = "hello";
	char str2[20] = "world";

	printf("before %s %s \n", str1, str2);

	strcpyKR(str1, str2);

	printf("after %s %s", str1, str2);

  return 0;
}