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

int ma = 10;
int mb = 10000;
int mc = 10000;

int main()
{
    int wa, wb, wc, record = 0;
    for(int a = -ma + 1; a < ma; a++)
    {
        for(int b = -mb + 1; b < mb; b++)
        {
            for(int c = -mc + 1; c < mc; c++)
            {
                int count = 0;
                while(isprime(a*pow(count, 2) + (count*b) + c))
                {
                    count++;
                }
                if(count > record) 
                {
                    wa = a;
                    wb = b;
                    wc = c;
                    record = count;
                    printf("a = %d, b = %d, c = %d (%d primes)\n", wa, wb, wc, record);
                }
            }
        }
    }
    return 0;
}
