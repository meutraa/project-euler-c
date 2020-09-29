#include <stdio.h>
#include <gmp.h>
#include "problem99-data.c"

int main()
{
    int line = 0;
    mpz_t a;
    mpz_t record;
    mpz_init(a);
    mpz_init(record);
    for(int i = 0; i < 2000; i += 2)
    {
        mpz_ui_pow_ui(a, n[i], n[i + 1]);
        if(mpz_cmp(a, record) >= 1)
        {
            mpz_set(record, a);
            line = (i >> 1);
        }
    }
    printf("%d\n", line + 1);
    return 0;
}
