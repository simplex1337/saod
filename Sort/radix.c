#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

double wtime();

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double) t.tv_sec + (double) t.tv_usec * 1E-6;
}

void radix_sort(uint32_t a[], int n)
{
    int i, m = 0, exp = 1;
    uint32_t b[n];
    for (i = 0; i < n; i++)
        if (a[i] > m)
            m = a[i];
    while (m / exp > 0) {
        int box[10] = { 0 };
        for (i = 0; i < n; i++)
            box[a[i] / exp % 10]++;
        for (i = 1; i < 10; i++)
            box[i] += box[i - 1];
        for (i = n - 1; i >= 0; i--)
            b[--box[a[i] / exp % 10]] = a[i];
        for (i = 0; i < n; i++)
            a[i] = b[i];
        exp *= 10;
    }
}

int main(int argc, char *argv[])
{
    if (argv[1] == NULL) {
        fprintf(stderr,
                "Please, enter a valid num of elements of arrays or run test_arr.sh for testing.\n");
        exit(EXIT_FAILURE);
    }
    int m = atoi(argv[1]);
    int i;
    uint32_t a[m];
    printf("m = %d\n", m);
    FILE *data = fopen("data.txt", "r");
    if (data == NULL) {
        fprintf(stderr,
                "Error, no dig.txt. Please, run mkdata.sh once to fix it\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < m; i++)
        fscanf(data, "%d\n", &a[i]);
    fclose(data);
    double t;
    t = wtime();
    radix_sort(a, m);
    t = wtime() - t;
    FILE *log = fopen("radix.log", "a");
    return fprintf(log, "%d  %.6f\n", m, t);
}
