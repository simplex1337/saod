#include "hash.h"
#include <time.h>
#include <sys/time.h>

char word[200000][40];

int getrand(int min, int max)
{
    srand(time(NULL));
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
    struct listnode *hashtab_kp[200000];
    FILE *data = fopen("base.txt", "r");
    FILE *log = fopen("hash_1.log", "a");
    int i;
    for (i = 0; i < 200000; i++)
        fscanf(data, "%s\n", word[i]);
    hashtab_init(hashtab_kp);  
    for (i = 0; i <= 200000; i++) {
        hashtab_add_kp(hashtab_kp, word[i], i);
        if (i % 10000 == 0) {
            char *w = word[getrand(0, i - 1)];
            printf("%s\n", w);
            double t = wtime();
            struct listnode *find = hashtab_lookup(hashtab_kp, w);
            t = wtime() - t;
            printf("%s\n", find->key);
            printf("n = %d; time = %.6f\n", i, t);
            fprintf(log, "%d\t%.6f\n", i, t);
        }
    }
    return 0;
}