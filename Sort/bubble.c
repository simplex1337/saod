#include <inttypes.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

double wtime();
void bubble();

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double) t.tv_sec + (double) t.tv_usec * 1E-6;
}

int main(int argc, char *argv[])
{
    int n;
    if (argc < 2) {
        fprintf(stderr, "error\n");
        exit(EXIT_FAILURE);
    }
    n = atoi(argv[1]);
    uint32_t *a;
    a = malloc(sizeof(uint32_t) * n);
    if (a == NULL) {
        fprintf(stderr, "count; No enough memory\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++)
        a[i] = (double) rand() / (RAND_MAX + 1.0) * 100001;
    double t = wtime();
    bubble(a, n);
    t = wtime() - t;
    printf("time %.6f sec.\n", t);
    return 0;
}

void bubble(uint32_t a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
        }
    }
}
