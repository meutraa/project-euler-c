#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "primes.c"

#define max 1000000
#define length 8

int main()
{
    int count = 0;
    char a[length + 1];
    for(int i = 2; i < max; i++)
    {
        if(isprime(i))
        {
            snprintf(a, length, "%d", i);
            int circular = 1;
            for(int j = 0; j < strlen(a); j++)
            {
                char buf = a[0];
                int len = strlen(a);
                for(int k = 0; k < len - 1; k++)
                {
                    a[k] = a[k + 1];
                }
                a[len - 1] = buf;
                if(!isprime(atoi(a)))
                {
                    circular = 0;
                    break;
                }
            }
            if(circular)
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
