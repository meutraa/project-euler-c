#include <stdio.h>

#define n 1001

int main()
{
    int turn = 0;
    long long d = 2L;
    long long i;
    long long total = 0L;
    
    for(i = 1L; i <= n*n; i += d)
    {
        if(turn % 4 == 0)
        {
            d += 2L;
        }
        turn++;
        printf("%lld\n", i);
        total += i;
    }


    printf("%lld\n", total);

    return 0;
}
