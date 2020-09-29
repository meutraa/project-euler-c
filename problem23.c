#include <stdio.h>

int main()
{
    int count = 0;
    int abundant[7000];
    unsigned long long total = 0L;
    for(int i = 12; i < 28123; i++)
    {
        int sum = 1;
        for(int j = 2; j <= (i >> 1); j++)
        {
            if(i % j == 0)
            {
                sum += j;
            }
        }
        if(sum > i)
        {
            abundant[count++] = i;
        }
    }

    for(int i = 1; i <= 28123; i++)
    {
        // prove i cannot be a sum of any two abundant numbers.
        for(int j = 0; j < count; j++)
        {
            if(abundant[j] < i)
            {
                for(int k = 0; k < count; k++)
                {
                    int value = abundant[j] + abundant[k];
                    if(value > i)
                    {
                        break;
                    }
                    else if(value == i)
                    {
                        j = count;
                        break;
                    }
                }
            }
            else
            {
                printf("%d cannot be a sum of two abundant numbers.\n", i);
                total += i;
                break;
            }
        }
    }
    printf("The sum of all positive integers which cannot be written as the sum of two abundant numbers is %llu.\n", total);
    return 0;
}
