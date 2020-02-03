#include <stdio.h> 
  
int myAtoi(char* str) { 
    int res = 0; 
    int sign = 1; 
    int i = 0; // 
  
    // If number is negative, then update sign 
    if (str[0] == '-') { 
        sign = -1; 
        i++; // Also update index of first digit 
    } 
  
    // Iterate through all digits and update the result 
    for (; str[i] != '\0'; ++i) {
			res = res * 10 + str[i] - '0';
		}
		
    // Return result with sign 
    return sign * res; 
} 
  
int main() { 
    char str[] = "-123"; 
    int val = myAtoi(str); 
    printf("%d ", val); 
    return 0; 
}
