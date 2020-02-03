#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int j, i;
    
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    
    //   I
    // 1 2 3
// IV  4 5 6 II
    // 7 8 9
    //  III
    
    int m[4][4] = {
        {1, 2, 3, 7},
        {4, 5, 6, 8},
        {7, 8, 9, 1},
        {3, 4, 5, 6}
    };
    
    int n = 4;
    
    // 1
    for (i = 0; i < n; i++) {
        for (j = i; j < n - i; j++) {
            sum3 += m[i][j];
            printf("%d ", m[i][j]);
        }
    }
    
    printf("\t%d \n", sum3);
    
    // 2
    for (j = n - 1; j >= n / 2; j--) {
        for (i = n - 1 - j; i <= j; i++) {
            sum += m[i][j];
            printf("%d ", m[i][j]);
        }
    }
    
    printf("\t%d \n", sum);
    
    // 3
    for (i = n - 1; i >= n / 2; i--) {
        for (j = n - 1 - i; j <= i; j++) {
            sum1 += m[i][j];
            printf("%d ", m[i][j]);
        }
    }
    
    printf("\t%d \n", sum1);
    
    // 4
    for (j = 0; j <= n / 2; j++) {
        for (i = n - 1 - j; i >= j; i--) {
            sum2 += m[i][j];
            printf("%d ", m[i][j]);
        }
    }
    
    printf("\t%d \n", sum2);
    
    // 1 and 3 are triangles
        
    return 0;
}
