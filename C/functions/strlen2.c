#include <stdio.h>

// strlen: return length of string s

int strlen2(char *s)
{
	int i = 0;
	while(s[i]!=0)
	{
		i++;
	}

	return i;
}

int main(void) {
  printf("Hello World\n");

	char str[10] = "hello";

	int len = strlen2(str);

	printf("%d", len);

  return 0;
}