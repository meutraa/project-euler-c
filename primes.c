#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isprime(int number) 
{
    if(number <= 1) return 0;
    for(int i = 2; i <= sqrt(number); i++) 
    {
        if(number % i == 0) return 0;
    }
    return 1;
}


#define MAX 1000000L

void fillprimes(unsigned long long **primes, int size)
{
    int n = 1;
    int i = 0;
    while(i < size)
    {
        if(isprime(n))
        {
            (*primes)[i] = n;
            i++;
        }
        n++;
    }
}


struct primepow 
{
    unsigned long long prime;
    unsigned int pow;
};

void primefactors_old(unsigned long long *primes, struct primepow **array, unsigned long long a)
{
    int i;
    unsigned int *powers = calloc(MAX, sizeof(unsigned int));
    
    int cycle = 1;
    while(cycle)
    {
        int i;
        for(i = 0; i < MAX; i++)
        {
            if(a % primes[i] == 0)
            {
                powers[i]++;
                a /= primes[i];
                i = -1;
            }
            if(a == 1)
            {
                cycle = 0;
                break;
            }
            if(i == MAX - 1)
            {
                printf("ERROR: hit %ld\n", MAX - 1);
                return;
            }
        }
    }
    int count = 0;
    for(i = 0; i < MAX; i++)
    {
        if(powers[i] != 0) count++;       
    }
    *array = malloc((count+1)*sizeof(struct primepow));
    ((*array)[0]).pow = count;
    int j = 1;
    for(i = 0; i < MAX; i++)
    {
        if(powers[i] != 0)
        {
            //printf("\nPRIME:%llu-%u\n", primes[i], powers[i]);
            ((*array)[j]).prime = primes[i];
            ((*array)[j]).pow = powers[i];
            j++;
        }
    }
    free(powers);
}

#define ORDER 16

void primefactors(unsigned long long *primes, struct primepow **array, unsigned long long a)
{
    int i = 0, j = 1, k;
    
    *array = (struct primepow*) calloc(ORDER + 1, sizeof(struct primepow));
    while(a != 1 && i < MAX)
    {
        if(a % primes[i] == 0)
        {
            int found = 0;
            for(k = 1; k <= ORDER; k++)
            {
                if(primes[i] == (*array)[k].prime)
                {
                    (*array)[k].pow += 1;
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                (*array)[j].prime = primes[i];
                (*array)[j].pow += 1;
                j++;
                if(j == ORDER)
                {
                    printf("ERROR: hit %d\n", ORDER);
                    return;
                }
            }
            a /= primes[i];
            i = -1;
        }
        if(i == MAX - 1)
        {
            printf("ERROR: hit %ld\n", MAX - 1);
        }
        i++;
    }
    (*array)[0].pow = j - 1;
}
unsigned long long phi(unsigned long long *primes, unsigned long long a)
{
    double phi = 1.0;
    struct primepow *dprimes;
    int i;
    primefactors(primes, &dprimes, a);
    for(i = 1; i <= dprimes[0].pow; i++)
    {
        phi *= (pow((double) dprimes[i].prime, (double) dprimes[i].pow)*(1.0 - (1.0/ ((double) dprimes[i].prime)))); 
    }
    free(dprimes);
    return (unsigned long long) phi;
}
