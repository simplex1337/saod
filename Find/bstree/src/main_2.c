#include "bstree.h"
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
    FILE *data = fopen("base.txt", "r");
    int i, n;
    for (i = 0; i < 200000; i++)
        fscanf(data, "%s\n", word[i]);
    fclose(data);
    struct bstree *tree;
    tree = bstree_create(word[0], 0);
    double t = wtime();  
    for (i = 2; i <= 200000; i++) {
        bstree_add(tree, word[i - 1], i - 1);
        if (i % 10000 == 0) {
			double tt = wtime() - t;
			printf("n = %d; time = %.6f\n", i, tt);
			FILE *log = fopen("bstree_1.log", "a");
			fprintf(log, "%d\t%.6f\n", i, tt);
			fclose(log);
		}
    }
    return 0;
}