#include <stdio.h>
#include <string.h>

void itoal(int n, char s[]) {

     int i, sign;
 
		/* record sign */
    /* make n positive */

		if ((sign = n) < 0) {
			 n = -n;
		 } 

		  /* generate digits in reverse order */
			/* get next digit */
			/* delete it */
    
		 i = 0;

		 do {       
         s[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);     

     if (sign < 0) {
			 s[i++] = '-';
		 }

     s[i] = '\0';
		 
 }

int main(void) {

	int n;
	scanf("%d", &n);

	char strN[10];

	itoal(n, strN);

	printf("%s as a sequence of characters", strN);

  return 0;
}