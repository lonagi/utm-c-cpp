#include <stdio.h>

// strcat: copy t to s
void strcatKR(char* s, char* t) {
	while (*s++);
	s--;
	while ((*s++ = *t++));
}

int main(void) {

	char str[10] = "hello";
	char str1[20] = "world";

	strcatKR(str, str1);

	printf("%s \n", str);

  return 0;
}