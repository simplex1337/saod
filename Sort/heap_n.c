#include <inttypes.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

double wtime();
void downheap();
void heapsort();

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(int argc, char * argv[])
{
	int n;
	if (argc < 2) {
		fprintf (stderr, "error\n");
		exit (EXIT_FAILURE);
	}
	n = atoi (argv[1]);
	uint32_t *a;
	a = malloc (sizeof (uint32_t) *  n);
	if (a == NULL) {
		fprintf (stderr, "count; No enough memory\n");
		exit (EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++)
		a[i] =  (double) rand() / (RAND_MAX + 1.0) * 100001;
	double t = wtime();
	heapsort(a, n);	
	t = wtime() - t;
	printf("time %.6f sec.\n", t);
	free(a);
	return 0;
}

int  max (uint32_t *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[j] > a[m]) {
        m = j;
    }
    if (k < n && a[k] > a[m]) {
        m = k;
    }
    return m;
}
 
void downheap (uint32_t *a, int n, int i) {
    while (1) {
        int j = max(a, n, i, 2 * i + 1, 2 * i + 2);
        if (j == i) {
            break;
        }
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i = j;
    }
}
 
void heapsort (uint32_t *a, int n) {
    int i;
    for (i = (n - 2) / 2; i >= 0; i--) {
        downheap(a, n, i);
    }
    for (i = 0; i < n; i++) {
        int t = a[n - i - 1];
        a[n - i - 1] = a[0];
        a[0] = t;
        downheap(a, n - i - 1, 0);
    }
}


