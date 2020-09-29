#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char buffer[8];
	int i = 10, j, count, super = 0;
	while(i < 200000)
	{
		count = 0;
		sprintf(buffer, "%d", i);
		for(j = 0; j < strlen(buffer); j++)
		{
			count += (int) pow(buffer[j] - '0', 5);
		}
		if(count == i)
		{
			super += i;
			printf("%d\n", super);
		}
		i++;
	}
	return 0;
}
