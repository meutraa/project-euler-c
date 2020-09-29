#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max 1000000

char* itoa(char *dest, size_t size, int a, int base) {
      static char buffer[sizeof a * CHAR_BIT + 1 + 1];
        static const char digits[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

            char* p = &buffer[sizeof(buffer) - 1];
              *p = '\0';

                int an = a < 0 ? a : -a;  

                  // Works with negative `int`
                  do {
                          *(--p) = digits[-(an % base)];
                              an /= base;
                                } while (an);

                    if (a < 0) {
                            *(--p) = '-';
                              }

                    size_t size_used = &buffer[sizeof(buffer)] - p;
                      if (size_used > size) {
                              fprintf(stderr, "Scant buffer %zu > %zu", size_used , size);
                                  return NULL;
                                    }
                        return memcpy(dest, p, size_used);
}

int ispalidrome(char *str)
{
    int end = strlen(str) - 1;
    for(int j = 0; j < ceil((strlen(str) - 1)/2.0); j++)
    {
        if(str[j] != str[end])
        {
            return 0;
        }
        end--;
    }
    return 1;
}

int main()
{
    int sum = 0;
    char ten[8];
    char two[24];

    for(int i = 1; i < max; i++)
    {
        ten[0] = '\0';
        itoa(ten, sizeof(int)*8, i, 10);
        if(ispalidrome(ten))
        {            
            two[0] = '\0';
            itoa(two, sizeof(int)*24, i, 2);
            if(ispalidrome(two)) sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
