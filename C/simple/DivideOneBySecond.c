#include <stdio.h>
#include <math.h>

//Поделить числа друг на друга. И можно ли?

int main(int argc, char const *argv[])
{
	int a,b;

	printf("Type number 1: \n");
	scanf("%i",&a);
	printf("Type number 2: \n");
	scanf("%i",&b);

	if(a!=0)
	{
		if((b%a)==0)
			printf("%i delitsa na %i\n", b,a);
		else
			printf("%i NE delitsa na %i\n", b,a);
	}
	else
		printf("%i NE elitsa na %i, tak kak a = 0\n", a,b);

	if(b!=0)
	{
		if((a%b)==0)
			printf("%i delitsa na %i\n", a,b);
		else
			printf("%i NE delitsa na %i\n", a,b);
	}
	else
		printf("%i NE elitsa na %i, tak kak b = 0\n", a,b);

	return 0;
}