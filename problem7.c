#include <stdio.h>
#include <math.h>

int main()
{
	int count = 6;
	int i = 14;
	int j;
	int value;
	while(count != 10001)
	{
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
			count++;
			value = i;
		}
		i++;
	}
	printf("%d", value);
	return 0;
}
