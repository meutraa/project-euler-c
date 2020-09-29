#include <stdio.h>
#include <math.h>

int main()
{
	int current_three = 3;
	int current_five = 5;
	int total = 0;
	while(current_three < 1000)
	{
		total += current_three;
		current_three += 3;
	}
	while(current_five < 1000)
	{
		if(current_five % 3 != 0)
		{
			total += current_five;
		}
		current_five += 5;
	}
	printf("%d", total);
	return 0;
}
