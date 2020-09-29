#include <stdio.h>
#include <stdlib.h>
#include "problem22-names.txt"
#include <string.h>

int comp(const void* a, const void* b)
{
    return strcmp(* (char * const *) a, * (char * const *) b);
}

int score(char* name, int pos)
{
    int score = 0;
    for(int i = 0; i < strlen(name); i++)
    {
        score += (name[i] - 64);
    }
    return score * pos;
}

int main()
{
    int size = sizeof(names)/sizeof(*names);
    qsort(names, size, sizeof(*names), comp);
    int total = 0;

    for(int i = 0; i < size; i++)
    {
        total += score(names[i], i + 1);
    }
    printf("%d\n", total);
    return 0;
}
