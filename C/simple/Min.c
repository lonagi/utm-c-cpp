#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int a[] = {0, 1, -3, -1, -2};
	int n = sizeof(a)/sizeof(a[0]);
	int min = INT_MAX;

	for (int i = 0; i < n; i++)
	{
    if(a[i] < min)
      min = a[i];
	}

  printf("min is %i\n", min);

	return 0;
}