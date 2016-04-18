#include "bstree.h"
#include <time.h>
#include <sys/time.h>
//постфикс _r означает, что действия происходит с разбросанными словами
char word_r[200000][40];
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
    FILE *data = fopen("lol.txt", "r");
    FILE *data_r = fopen("base.txt", "r");
    FILE *log = fopen("bstree_5.log", "a");
    int i;
    for (i = 0; i < 200000; i++) {
        fscanf(data_r, "%s\n", word_r[i]);
        fscanf(data, "%s\n", word[i]);
    }
    struct bstree *tree;
    struct bstree *tree_r;
    tree = bstree_create(word[0], 0);
    tree_r = bstree_create(word_r[0], 0);
    for (i = 2; i <= 200000; i++) {
        bstree_add(tree, word[i - 1], i - 1);
        bstree_add(tree_r, word_r[i - 1], i - 1);
        if (i % 10000 == 0) {
            fprintf(log, "%d\t", i);
            char *w = word[i-1];
            char *w_r = word_r[i-1];
            printf("%s\n", w);
            double t = wtime();
            struct bstree *node = bstree_lookup(tree, w);
            t = wtime() - t;
            printf("%s\n", node->key);
            printf("worst case: n = %d; time = %.6f\n", i, t);
            fprintf(log, "%.6f\t", t);
            printf("%s\n", w_r);
            t = wtime();
            struct bstree *node_r = bstree_lookup(tree_r, w_r);
            t = wtime() - t;
            printf("%s\n", node_r->key);
            printf("avrg case: n = %d; time = %.6f\n", i, t);
            fprintf(log, "%.6f\n", t);
        }
    }
    return 0;
}