#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	int j;
	int largest = 0;
	char number[6];
	for(i = 999; i > 500; i--)
	{
		for(j = 999; j > 500; j--)
		{
			sprintf(number, "%d", i*j);
			if(number[0] == number[5] && number[1] == number[4] && number[2] == number[3])
			{
							printf("%s, ", number);

				if((i*j) > largest)
				{
					largest = i*j;
					break;
				}
			}
		}
	}
	printf("%d", largest);
	return 0;
}
