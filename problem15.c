#include <stdio.h>
#include <stdlib.h>

#define size 20
long double n[size][size];

int main()
{
    n[0][0] = 1;

    for(int i = 1; i <= size; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == j)
            {
                n[i][j] = n[i][j - 1] * 2;
            }
            else
            {
                n[i][j] = n[i - 1][j];
                if(j != 0)
                {
                    n[i][j] += n[i][j - 1];   
                }
            }
            if(i == j)
            {
                printf("%d = %Lf\n", i, (long double) n[i][i]);
            }
        }
    }
    return 0;
}
