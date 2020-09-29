#include <stdio.h>
#include <math.h>

int main()
{
	int i, j;
	double total = 5.0;
	for(i = 5; i < 2000000; i++)
	{
		int prime = 1;
		j = (int) ceil(sqrt(i));
		while(j >= 2)
		{
			if(i % j == 0)
			{
				prime = 0;
				break;
			}
			j--;
		}
		if(prime == 1)
		{
			total += i;
		}
	}
	printf("%f", total);
	return 0;
}
