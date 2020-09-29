#include <stdio.h>
#include <math.h>

int main()
{
	int i = 20;
	int j;
	while(1)
	{
		for(j = 3; j <= 20; j++)
		{
			if(i % j != 0)
			{
				break;
			}
			if(j == 20)
			{
				printf("%d", i);
				return 0;
			}
		}
		i += 2;
	}
	return 0;
}
