#include <stdio.h>
#include <math.h>

#include "primes.c"

#define nprimes 10000 

int main()
{
    unsigned long long primes[nprimes];
    fillprimes(primes, nprimes);

    int i = 9;
    while(1)
    {
        /* If this is a composite number. */
        if(isprime(i) == 0)
        {
            int found = 0;
            for(int j = 1; j < ceil(sqrt(i)); j++)
            {
                int k = 0;
                while(primes[k] < i)
                {
                    if(i == (primes[k] + (2*pow(j, 2))))
                    {
                        found = 1;
                        break;
                    }
                    k++;
                }
                if(found) break;
            }
            if(found == 0)
            {
                printf("%d is not true\n", i);
            }
        }
        i += 2;
    }
    return 0;
}
