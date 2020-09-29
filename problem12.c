#include <stdio.h>
#include <math.h>

int main()
{
	long i = 7L;
	long number, j;
	int divisors;
	while(1)
	{
		divisors = 0;
		number = 0;
		j = i;
		while(j > 0L)
		{
			number += j;
			j--;
		}
		j = (long) ceil(sqrt(number));
		while(j > 0)
		{
			if(number % j == 0)
			{
				divisors++;
			}
			j--;
		}
		if(divisors*2 > 500)
		{	
			printf("%d", number);
			return 0;
		}
		i++;
	}
	return 0;
}
