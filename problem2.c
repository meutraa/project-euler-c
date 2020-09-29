#include <stdio.h>
#include <math.h>

int main()
{
	int temp = 0;
	int last = 1;
	int current = 1;
	int total = 0;
	while(current < 4000000)
	{
		if((current & 1) == 0)
		{
			total += current;
		}
		temp = current;
		current += last;
		last = temp;
	}
	
	printf("%d", total);
	return 0;
}
