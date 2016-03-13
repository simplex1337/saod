#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double) t.tv_sec + (double) t.tv_usec * 1E-6;
}

void selectionSort(int a[], int size)
{
    int i, j;
    int min, temp;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}


int main(int argc, char *argv[])
{
    int m = atoi(argv[1]);
    int i, a[m];
    printf("m = %d\n", m);
    FILE *data = fopen("dig.txt", "r");
    for (i = 0; i < m; i++) {
        fscanf(data, "%d\n", a[i]);
        printf("file readed\n");
    }
    fclose(data);
    double t;
    t = wtime();
    selectionSort(a, m);
    t = wtime() - t;
    return printf("Elapsed time: %.6f sec.\n", t);
}
