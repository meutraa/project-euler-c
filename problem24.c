#include <stdio.h>

int main()
{
    int seq[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i = 1; i < 1000000; i++)
    {
        int j = 9;
        while(j > 0 && seq[j - 1] >= seq[j])
        {
            j--;
        }
        if(j > 0)
        {
            int k = 9;
            while(seq[k] <= seq[j - 1])
            {
                k--;
            }
            int buf = seq[j - 1];
            seq[j - 1] = seq[k];
            seq[k] = buf;

            k = 9;
            while(j < k)
            {
                buf = seq[j];
                seq[j] = seq[k];
                seq[k] = buf;
                j++;
                k--;
            }
        }
    }
    for(int i = 0; i < 10; i ++)
    {
        printf("%d", seq[i]);
    }
    printf("\n");
    return 0;
}
