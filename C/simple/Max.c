#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int a[] = {0, 1, -3, -1, -2};
	int n = sizeof(a)/sizeof(a[0]);
	int max = INT_MIN;

	for (int i = 0; i < n; i++)
	{
    if(a[i] > max)
      max = a[i];
	}

  printf("max is %i\n", max);

	return 0;
}