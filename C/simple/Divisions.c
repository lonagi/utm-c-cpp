#include <stdio.h>
#include <math.h>

//Сколько чисел от 1к до 10к делится на то, а на другое не делится.

int main(int argc, char const *argv[])
{
	int count = 0;

	for (int i = 1000; i < 10000; ++i)
	{
		if( i % 77 == 0 && i % 3 != 0 && i % 5 != 0)
			count++;
	}

	printf("%i\n",count);


	return 0;
}