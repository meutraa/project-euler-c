#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <string.h>

int main()
{
	int i = 3;
	char string[10000];
	mpz_t last, temp, current;
	mpz_init_set_str(last, "1", 10);
	mpz_init_set_str(current, "1", 10);
	while(1)
	{
		mpz_set(temp, current);
		mpz_add(current, current, last);
		mpz_set(last, temp);
		mpz_get_str(string, 10, current);
		if(strlen(string) == 1000)
		{
			printf("%d", i);
			break;
		}
		i++;
	}
	return 0;
}
