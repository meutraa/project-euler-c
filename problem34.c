#include <stdio.h>
#include <string.h>

int main()
{
    double sum = 0.0;
    char buf[33]; 
    for(unsigned long long i = 3; i < 10000000000L; i++)
    {
        snprintf(buf, 32, "%llu", i);
        int len = strlen(buf) - 1;
        unsigned long long total = 0;
        while(len >= 0)
        {
            unsigned long long p = 1;
            while(buf[len] >= 50)
            {
                p *= (buf[len] - 48);
                buf[len] -= 1;
            }
            total += p;
            len--;
        }
        if(total == i)
        {
            printf("%llu\n", i);
            sum += i;
        }
    }

    return 0;
}
