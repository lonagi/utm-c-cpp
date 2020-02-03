#include <stdio.h>
#include <math.h>

//Перемножить каждую цифру в числе.

int main(int argc, char const *argv[])
{
	int n = 423;
	int pr = 1;

	for ( ; n > 0; n /= 10)
	{
		pr *= n % 10;
	}
	printf("%i\n", pr);


	return 0;
}