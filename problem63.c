#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1024];
    long double i = 1L;
    int length = 1;
    int pow_length = 0;
    int count = 0;

    while(1)
    {
        for(int n = 1; pow_length <= length && n <= 9 ; n++)
        {
            i = powl(n, length);
            s[0] = '\0';
            snprintf(s, 1024, "%.0Lf", i);
            pow_length = strlen(s);
            if(pow_length == length)
            {
                printf("%.0Lf = powl(%d, %d) #%d\n", i, n, length, ++count);
            }
        }
        length++;
    }
    return 0;
}
