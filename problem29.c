#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min 2
#define max 100

const int n = max - min + 1;
int size = n*n;

int comp(const void * a, const void * b)
{
    if( *(double*)a < *(double*)b) return -1;
    if( *(double*)a == *(double*)b) return 0;
    if( *(double*)a > *(double*)b) return 1;
    return 0;
}

int main()
{
    double *array = malloc(size * sizeof(double));
    for(int i = 0; i <= max - min; i++)
    {
        for(int j = 0; j <= max - min; j++)
        {
            array[(i*n) + j] = powl(i + min, j + min);
        }
    }
    qsort(array, size, sizeof(array[0]), comp);
    
    int count = 0;
    for(int i = 0; i < size - 1; i++)
    {
        if(array[i + 1] > array[i])
        {
            count++;
        }
    }
    for(int i = 0; i < size; i++) printf("%e\n", array[i]);
    printf("%d\n", ++count);
    
    return 0;
}
