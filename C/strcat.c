//strcat через for

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strcat2(char *a, char *b) {

        size_t len1 = strlen(a);
        size_t len2 = strlen(b);                      

        char *result = (char*)malloc(len1 + len2 + 1); 

        for(int i = 0; i < len1; i++)
        {
          result[i] = a[i];
        }
        for(int i = 0; i < len2; i++)
        {
          result[i+len1] = b[i];
        }

        return result;
    }

int main(void) {
  char *a = "Hello";
  char *b = "World";

  a = strcat2(a,b);
  printf("%s\n",a);

  return 0;
}