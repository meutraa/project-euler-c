#include <stdio.h>

#include "primes.c"

#define max 1000

int main()
{
    int size = 100000;
    unsigned long long primes[size];
    fillprimes(primes, size);

    int record = 21;

    for(int length = 21; length < 1000; length++)
    {
        for(int i = 0; i < size - length; i++)
        {
            int sum = 0;
            for(int j = i; j < length + i; j++)
            {
                sum += primes[j];
            }
            if(sum >= max)
            {
                break;
            }
            else if(isprime(sum))
            {
                record = length;
                printf("%d has %d consecutive primes.\n", sum, record);
                break;
            }
        }
    }
    return 0;
}
