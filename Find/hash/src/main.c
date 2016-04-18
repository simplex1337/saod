#include "hash.h"
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

char word[200000][40];

int getrand(int min, int max)
{
    srand(time(NULL));
    return (rand() / (RAND_MAX + 1.0) * (max - min) + min);
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
    int i, n;
    for (i = 0; i < 200000; i++)
        fscanf(data, "%s\n", word[i]);
    fclose(data);
    hashtab_init(hashtab_kp);
    hashtab_add_kp(hashtab_kp, word[0], 0);  
    for (i = 1; i <= 200000; i++) {
        hashtab_add_kp(hashtab_kp, word[i], i);
        if (i % 10000 == 0) 
            for (n = 0; n < 100; n++) {
                sleep(1);
                char *w = word[getrand(0, i)];
                printf("%s\n", w);
                double t = wtime();
                struct listnode *find = hashtab_lookup(hashtab_kp, w);
                t = wtime() - t;
                printf("%s\n", find->key);
                printf("n = %d; time = %.6f\n", i, t);
                FILE *log = fopen("hash_1.log", "a");
                fprintf(log, "%d\t%.6f\n", i, t);
                fclose(log);
        }
    }
    return 0;
}