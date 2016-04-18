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
    struct listnode *hashtab_kp[200000]; //хеш-таблица, создаваемая по алгоритму Кернигана и Пайка
    struct listnode *hashtab_xor[200000];//хеш-таблица, создаваемая по алгоритму xor
    FILE *data = fopen("base.txt", "r");
    FILE *log = fopen("hash_6.log", "a");
    int i, n, table_kp[200000] = {0}, table_xor[200000] = {0};
    for (i = 0; i < 200000; i++)
        fscanf(data, "%s\n", word[i]);
    hashtab_init(hashtab_kp);
    hashtab_init(hashtab_xor);  
    for (i = 0; i <= 200000; i++) {
        hashtab_add_kp(hashtab_kp, word[i], i);
        hashtab_add_xor(hashtab_xor, word[i], i);
        table_kp[hashtab_hash(word[i])] += 1;
        table_xor[xor_hash(word[i])] += 1;
        if (i % 10000 == 0) {
            fprintf(log, "%d\t", i);
            char *w = word[getrand(0, i - 1)];
            printf("%s\n", w);
            double t = wtime();
            struct listnode *find = hashtab_lookup(hashtab_kp, w);
            t = wtime() - t;
            printf("%s\n", find->key);
            int collision_kp = 0, collision_xor = 0;
            for (n = 0; n < i; n++)
                if (table_kp[n] > 1)
                    collision_kp++;
            printf("kp, n = %d; time = %.6f; collision = %d\n", i, t, collision_kp);
            fprintf(log, "%.25lf\t%d\t", t, collision_kp);
            t = wtime();
            find = hashtab_lookup_xor(hashtab_xor, w);
            t = wtime() - t;
            printf("%s\n", find->key);
            for (n = 0; n < i; n++)
                if (table_xor[n] > 0)
                    collision_xor++;
            printf("xor, n = %d; time = %.6f; collision = %d\n", i, t, collision_xor);
            fprintf(log, "%.6f\t%d\n", t, collision_xor);
        }
    }
    return 0;
}