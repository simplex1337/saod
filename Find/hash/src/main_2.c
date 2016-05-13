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
    double t = wtime(); 
    for (i = 1; i <= 200000; i++) {
        hashtab_add_kp(hashtab_kp, word[i], i);
        if (i % 10000 == 0) {
            double tt = wtime() - t;
            printf("n = %d; time = %.6f\n", i, tt);
            FILE *log = fopen("hash_2.log", "a");
            fprintf(log, "%d\t%.6f\n", i, tt);
            fclose(log);
         }
     
    }
    return 0;
}
