#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define max 1000000
pthread_mutex_t lock;


int gcd(int a, int b)
{
    int c;
    while(a != 0)
    {
        c = a;
        a = b%a;
        b = c;
    }
    return b;
}

double record_pn = 2;
int current_n = 30000;

void *loop(void *argv)
{
    int n;
    do
    {
        int phi = 1;
        pthread_mutex_lock(&lock);
        n = current_n++;
        pthread_mutex_unlock(&lock);

        for(int i = 2; i < n; i++)
        {
            if(gcd(n, i) == 1) phi++;
        }
        double pn = (double)n / (double)phi;
        pthread_mutex_lock(&lock);
        if(pn > record_pn)
        {
            record_pn = pn;
            printf("%d has %d coprimes, and phi(n) = %f\n", n, phi, pn);
        }
        pthread_mutex_unlock(&lock);
        if((n % 50000) == 0)
        {
            pthread_mutex_lock(&lock);
            printf("%d\n", n);
            pthread_mutex_unlock(&lock);
        }
    } while(n < max);
    return NULL;
}

int main()
{
    pthread_mutex_init(&lock, NULL);
    pthread_t pid[8];
    for(int i = 0; i < 8; i++) pthread_create((&pid[i]), NULL, &loop, NULL);
    for(int i = 0; i < 8; i++) pthread_join(pid[i], NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}
