#include "bstree.h"
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
    int i;
    for (i = 0; i < 200000; i++)
        fscanf(data, "%s\n", word[i]);
    struct bstree *tree;
    tree = bstree_create(word[0], 0);  
    for (i = 2; i <= 200000; i++) {
        bstree_add(tree, word[i - 1], i - 1);
        if (i % 10000 == 0) {
            char *w = word[getrand(0, i - 1)];
            printf("%s\n", w);
            double t = wtime();
            struct bstree *node = bstree_lookup(tree, w);
            t = wtime() - t;
            printf("%s\n", node->key);
            printf("n = %d; time = %.6f\n", i, t);
        }
    }
    return 0;
}