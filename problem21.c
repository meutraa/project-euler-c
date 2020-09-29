#include <stdio.h>

#define max 10000

int sumofdiv(int i)
{
    int total = 0;
    for(int j = 1; j < (i/2) + 1; j++)
    {
        if(i % j == 0) total += j;
    }
    return total;
}

int main()
{
    int sum = 0;
    for(int i = 1; i < max; i++)
    {
        int a = sumofdiv(i);
        if(a != i && sumofdiv(a) == i) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
