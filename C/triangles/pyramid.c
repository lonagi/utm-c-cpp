#include <stdio.h>

/*
         *
        +*+
       *+*+*
      +*+*+*+
     *+*+*+*+*
    +*+*+*+*+*+
 */


int main(void) {

    int n = 6;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }

        for (int k = -i; k <= i; k++) {
            
            if (k % 2) {
                printf("+");
            } else {
                printf("*");
            }
        }

        printf("\n");
    }

  return 0;
}
