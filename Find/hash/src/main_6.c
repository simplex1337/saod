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
    FILE *data = fopen("base.txt", "r");
    int i, n, table_kp[HASHTAB_SIZE] = {0}, table_xor[HASHTAB_SIZE] = {0};
    for (i = 0; i < 200000; i++)
        fscanf(data, "%s\n", word[i]);
    fclose(data);
    hashtab_init(hashtab_kp);
    hashtab_init(hashtab_xor);  
    for (i = 1; i <= 200000; i++) {
        hashtab_add_kp(hashtab_kp, word[i - 1], i - 1);
        hashtab_add_xor(hashtab_xor, word[i - 1], i - 1);
        table_kp[hashtab_hash(word[i - 1])] += 1;
        table_xor[xor_hash(word[i - 1])] += 1;
        if (i % 10000 == 0) {
            FILE *log = fopen("hash_6.log", "a");
            fprintf(log, "%d\t", i);
            char *w = word[getrand(0, i - 1)];
            printf("%s\n", w);
            double t = wtime();
            struct listnode *find = hashtab_lookup(hashtab_kp, w);
            t = wtime() - t;
            printf("%s\n", find->key);
            int collision_kp = 0, collision_xor = 0;
            for (n = 0; n < HASHTAB_SIZE; n++)
                if (table_kp[n] > n)
                    collision_kp++;
            printf("kp, n = %d; time = %.6f; collision = %d\n", i, t, collision_kp);
            fprintf(log, "%.6f\t%d\t", t, collision_kp);
            t = wtime();
            find = hashtab_lookup_xor(hashtab_xor, w);
            t = wtime() - t;
            printf("%s\n", find->key);
            for (n = 0; n < HASHTAB_SIZE; n++)
                if (table_xor[n] > n)
                    collision_xor++;
            printf("xor, n = %d; time = %.6f; collision = %d\n", i, t, collision_xor);
            fprintf(log, "%.6f\t%d\n", t, collision_xor);
            fclose(log);
        }
    }
    return 0;
}
