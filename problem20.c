#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <string.h>

int main()
{
	int i;
	long sum = 0;
	char string[10000];
	mpz_t j;
	mpz_init_set_ui(j, 1);
	
	for(i = 1000000; i > 1; i--)
	{
		mpz_mul_ui(j, j, i);
	}
	mpz_get_str(string, 10, j);
	for(i = 0; i < strlen(string); i++)
	{
		sum += string[i] - '0';
	}
	printf("%d", sum);
	return 0;
}
