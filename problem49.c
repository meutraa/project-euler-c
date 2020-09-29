#include <stdio.h>
#include "primes.c"

int is_permutation(char a[5], char b[5])
{
    int chars[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; 
    for(int i = 0; i < 4; i++)
    {
        chars[a[i] - 48] += 1;
        chars[b[i] - 48] -= 1;
    }
    for(int i = 0; i < 10; i++)
    {
        if(chars[i] != 0) return 0;
    }
    return 1;
}

int main ()
{
    for(int i = 1000; i <= 9999; i++)
    {
        if(isprime(i))
        {
            char a[5];
            snprintf(a, 5, "%d", i);
            for(int j = 1; j < ((10000.0 - i)/2.0); j++)
            {
                if(isprime(i + j) && isprime(i + 2*j))
                {
                    char b[5];
                    snprintf(b, 5, "%d", i + j);
                    if(is_permutation(a, b))
                    {
                        char c[5];
                        snprintf(c, 5, "%d", i + (2*j));
                        if(is_permutation(a, c))
                        {
                            printf("%s, %s, %s\n", a, b, c);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
