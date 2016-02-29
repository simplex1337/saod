#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

double wtime();

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void radix_sort(int *a, int n) 
{
	int i, b[n], m = 0, exp = 1;
	for (i = 0; i < n; i++) {
        if (a[i] > m)
		   m = a[i];
	}
	while (m / exp > 0) {
        int box[10] = {
			0
		}
		;
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
	int n = atoi(argv[1]);
    int i, a[n];
    printf("n = %d\n", n);
	FILE *data = fopen("dig.txt", "r");
	for (i = 0; i < n; i++)
		fscanf (data, "%d\n", &a[i]);
    fclose(data);
    double t;
    t = wtime();
	radix_sort(a, n);
    t = wtime() - t;
    FILE *log = fopen("radix.log", "a");
	return fprintf(log, "%d  %.6f\n", n, t);
}
