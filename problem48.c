#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <string.h>

int main()
{
	int i;
	char string[10000];
	mpz_t number, result;
	mpz_init(number);
	for(i = 1; i <= 1000; i++)
	{
		mpz_init(result);
		mpz_ui_pow_ui(result, i, i);
		mpz_add(number, number, result);
	} 
	mpz_get_str(string, 10, number);
	printf("%s", string);
	return 0;
}
