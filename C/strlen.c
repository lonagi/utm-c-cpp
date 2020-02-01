#include <stdio.h>

// strlen: return length of string s
int strlenKR(char* s) {
	
	char* p = s;

	while (*p != '\0') {
		p++;
	}

	return p - s;
}

int main(void) {
  printf("Hello World\n");

	char str[10] = "hello";

	int len = strlenKR(str);

	printf("%d", len);

  return 0;
}