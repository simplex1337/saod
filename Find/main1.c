#include "hash.h"
#include <sys/time.h>

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double) t.tv_sec + (double) t.tv_usec * 1E-6;
}

int main()
{
    struct listnode *hashtab[200000];
    FILE *data = fopen("base.txt", "r");
    int i; char word[200000][40];
    for (i = 0; i < 200000; i++);
        fscanf(data, "%s\n", word[i]);
    struct listnode *node;
    hashtab_init(hashtab);  
    for (i = 0; i <= 200000; i++) {
        hashtab_add(hashtab, word[i - 1], i - 1);
        if (i % 10000 == 0) {
            char w = word[getrand(0, i - 1)];
            printf("%s\n", w);
            double t = wtime();
            struct listnode *find = hashtab_lookup(hashtab, w);
            t = wtime() - t;
            printf("%s\n", find->key);
            printf("n = %d; time = %.6f", i -1, t);
        }
    }
    return 0;
}