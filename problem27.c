#include <stdio.h>
#include <math.h>

int isprime(int number) 
{
    if(number <= 1) return 0;
    for(int i = 2; i <= sqrt(number); i++) 
    {
        if(number % i == 0) return 0;
    }
    return 1;
}

int ma = 10000;
int mb = 10000;

int main()
{
    int wa, wb, record = 0;
    for(int a = -ma + 1; a < ma; a++)
    {
        for(int b = -mb + 1; b < mb; b++)
        {
            int count = 0;
            while(isprime(pow(count, 2) + (count*a) + b))
            {
                count++;
            }
            if(count > record) 
            {
                wa = a;
                wb = b;
                record = count;
                printf("a = %d, b = %d (%d primes)\n", wa, wb, record);
            }
        }
    }
    printf("%d (%d primes)\n", wa*wb, record);
    return 0;
}
