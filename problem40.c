#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int pos = 0;
    int total = 1;
    char a[16];
    int mark = 10;
    for(int i = 1; mark < 1000001; i++)
    {
        snprintf(a, 15, "%d", i);
        int len = strlen(a);
        pos += len;
        if(pos >= mark)
        {
            printf("%c, for mark %d\n", a[len - (pos - mark) - 1], mark);
            total *= (a[len - (pos - mark) - 1] - 48);
            mark *= 10;
        }
    }
    printf("%d\n", total);
    return 0;
}
