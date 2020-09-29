#include <stdio.h>
#include <math.h>

int main()
{
	int i, length, longest_length = 0, winner;
	long value;
	for(i = 10; i < 1000000; i++)
	{
		length = 1;
		value = i;
		while(value != 1)
		{
			value = value & 1 ? (value * 3) + 1 : value >> 1;
			length++;
		}
		if(length > longest_length)
		{
			longest_length = length;
			winner = i;
			printf("%d, with a length of %d\n", winner, longest_length);
		}
	}
	printf("%d, with a length of %d\n", winner, longest_length);
	return 0;
}
