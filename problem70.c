#include <stdio.h>
#include "gcd.c"
#include "primes.c"
#include <pthread.h>

pthread_mutex_t lock;

#define MIN 10
#define MAXN 10000000

unsigned long long lint(const unsigned long long n) 
{
    return (n < 10) ? 1 : 1 + lint(n / 10);
}

unsigned int p(int c, int a, int b)
{
    return (b == 1) ? c : p(c*a, a, --b);
}

int isperm(unsigned long long a, unsigned long long b)
{
    const int lena = lint(a);
    int i, j;
    if(lena != lint(b)) return 0;
    
    int aa[lena];
    for(i = 0; i < lena; ++i, a /= 10)
    {
        aa[i] = a % 10;
    }
    for(i = 0; i < lena; ++i, b /= 10)
    {
        int c = b % 10;
        int found = 0;
        for(j = 0; j < lena; j++)
        {
            if(c == aa[j])
            {
                aa[j] = -1;
                found = 1;
            }
        }
        if(found == 0) return 0;
    }
    return 1;
}

#define nthreads 8
unsigned long long *primes;
int current_n = MIN;
double max_ratio = 10000000.0;

void *loop(void *argv)
{
    pthread_mutex_lock(&lock);
    int n = current_n++;
    pthread_mutex_unlock(&lock);
    do
    {
        n += nthreads;

        unsigned long long p = phi(primes, (unsigned long long) n);
        
        if(isperm(n, p))
        {
            double ratio = ((double) n)/((double) p);
            pthread_mutex_lock(&lock);
            if(ratio < max_ratio)
            {
                printf("phi(%d) = %llu\n", n, p);
                max_ratio = ratio;
            }
            pthread_mutex_unlock(&lock);
        }
    } while(n < MAXN);
    return NULL;
}

int main()
{
    int i;
    primes = malloc(MAX*sizeof(unsigned long long));
    fillprimes(&primes, MAX);
    pthread_mutex_init(&lock, NULL);
    pthread_t pid[nthreads];
    for(int i = 0; i < nthreads; i++) pthread_create((&pid[i]), NULL, &loop, NULL);
    for(int i = 0; i < nthreads; i++) pthread_join(pid[i], NULL);
    pthread_mutex_destroy(&lock);
    return 1;
}
