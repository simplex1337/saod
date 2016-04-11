#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

void odd_even_sort(uint32_t a[], int n);
double wtime();

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double) t.tv_sec + (double) t.tv_usec * 1E-6;
}

void odd_even_sort(uint32_t a[], int n)
{
    for (int i = 0; i < n; i++) {
        if (i & 1)
            for (int j = 2; j < n; j += 2) {
                if (a[j] < a[j - 1]) {
                    int temp;
                    temp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = temp;
                }
        } else
            for (int j = 1; j < n; j += 2) {
                if (a[j] < a[j - 1]) {
                    int temp;
                    temp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = temp;
                }
            }
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
    odd_even_sort(a, m);
    t = wtime() - t;
    FILE *log = fopen("odd.log", "a");
    return fprintf(log, "%d  %.6f\n", m, t);
}
