#include <stdio.h>
#include <math.h>

#define min 3
#define max 10

int main()
{
    int sum = 0;
    for(int a = max; a <= max; a++)
    {
        int r_max = 0;
        for(int n = 0; n < 100; n++)
        {
            long double r = powl(a - 1, n) + powl(a + 1, n);
            printf("%f\n", fmod(r, pow(a, 2))); 
        }
    }
    return 0;
}
