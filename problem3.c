#include <stdio.h>
#include <math.h>

int main()
{
	int root = (int) floor(sqrt(600851475143));
	int largest = 1;
	int i = 1;
	int j;
	while(i < root)
	{
		if(600851475143 % i == 0)
		{
			// is i prime?
			int prime = 1;
			j = (int) floor(sqrt(i));
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
				largest = i;
			}
		}
		i++;
	}
	printf("%d", largest);
	return 0;
}
