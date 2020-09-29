#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, k;
	for(i = 998; i > 333; i--)
	{
		for(j = 1; j < 1000 - i; j++)
		{
			k = 1000 - i - j;
			if((pow(i, 2) + pow(j, 2)) == pow(k, 2))
			{
				printf("%d", i*j*k);
				return 0;
			}
		}
	}
	return 0;
}
