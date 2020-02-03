#include <stdio.h>
#include <math.h>

//Сумма чётных цифр в чисел.

int main(int argc, char const *argv[])
{
	int n = 872;
	int sum = 0;

	for ( ; n > 0; n /= 10)
	{
		if( ((n % 10) % 2) == 0)
		{
			sum += n % 10;
		}
	}
	printf("%i\n", sum);


	return 0;
}