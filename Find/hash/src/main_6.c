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
    //struct listnode *hashtab_kp[HASHTAB_SIZE]; //хеш-таблица, создаваемая по алгоритму Кернигана и Пайка
    //struct listnode *hashtab_djb[HASHTAB_SIZE];//хеш-таблица, создаваемая по алгоритму djb
    FILE *data = fopen("base.txt", "r");
    int i, n, table_kp[HASHTAB_SIZE] = {0}, table_djb[HASHTAB_SIZE] = {0};
    for (i = 0; i < 200000; i++)
        fscanf(data, "%s\n", word[i]);
    fclose(data);
    hashtab_init(hashtab_kp);
    hashtab_init(hashtab_djb);  
    for (i = 1; i <= 200000; i++) {
        hashtab_add_kp(hashtab_kp, word[i - 1], i - 1);
        hashtab_add_djb(hashtab_djb, word[i - 1], i - 1);
        table_kp[hashtab_hash(word[i - 1])] += 1;
        table_djb[djb_hash(word[i - 1])] += 1;
        if (i % 10000 == 0) {
            FILE *log = fopen("hash_6.log", "a");
            fprintf(log, "%d\t", i);
            char *w = word[getrand(0, i - 1)];
            printf("%s\n", w);
            double t = wtime();
            struct listnode *find = hashtab_lookup(hashtab_kp, w);
            t = wtime() - t;
            printf("%s\n", find->key);
            int collision_kp = 0, collision_djb = 0;
            for (n = 0; n < HASHTAB_SIZE; n++)
                if (table_kp[n] > 0)
                    collision_kp++;
            printf("kp, n = %d; time = %.6f; collision = %d\n", i, t, collision_kp);
            fprintf(log, "%.6f\t%d\t", t, collision_kp);
            t = wtime();
            find = hashtab_lookup_djb(hashtab_djb, w);
            t = wtime() - t;
            printf("%s\n", find->key);
            for (n = 0; n < HASHTAB_SIZE; n++)
                if (table_djb[n] > 0)
                    collision_djb++;
            printf("djb, n = %d; time = %.6f; collision = %d\n", i, t, collision_djb);
            fprintf(log, "%.6f\t%d\n", t, collision_djb);
            fclose(log);
        }
    }
    return 0;
}
