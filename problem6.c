#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	int sum_of_squares;
	int square_of_sums;
	for(i = 0; i <= 100; i++)
	{
		sum_of_squares += (int) pow(i, 2);
		square_of_sums += i;
	}
	square_of_sums = (int) pow(square_of_sums, 2);
	printf("%d", square_of_sums - sum_of_squares);
	return 0;
}
