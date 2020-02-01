#include <stdio.h>

/*
    strcmp: return < 0 if s < t,
                     0 if s == t,
                   > 0 if s > t
*/
int strcmpKR(char* s, char* t) {
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int main(void) {

	char str[10] = "abd";
	char str1[10] = "abc";

	int comp = strcmpKR(str, str1);

	printf("%d", comp);

  return 0;
}
