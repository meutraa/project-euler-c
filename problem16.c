#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <string.h>

int main()
{
	char string[10000];
	mpz_t number;
	mpz_init(number);
	mpz_setbit(number, 1000);
	mpz_get_str(string, 10, number);
	
	int i;
	int total = 0;
	for(i = 0; i < strlen(string); i++)
	{
		total += (string[i] - '0');
	}
	printf("%d", total);
	return 0;
}
