#include <stdio.h>

/*
    *+*+
    +*+
    *+
    +
 */

int main(void) {

    int n = 4;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j % 2) {
                printf("+");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}
