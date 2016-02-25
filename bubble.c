#include <inttypes.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

void bubble();
int main(int argc, char * argv[])
{
	double wtime()
	{
	    struct timeval t;
	    gettimeofday(&t, NULL);
	    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
	}

	int n;
	if (argc < 2){
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
	for (int i = 0; i < n; i++) {
		a[i] =  (double) rand() / (RAND_MAX + 1.0) * 100001;
	}
	bubble(&a, n);
	double t = wtime();
	
	t = wtime() - t;
	printf("%d %.6f\n",n,t);
}

void bubble(uint32_t *a, int n)
{
     for (int i = 0; i < n-1; i++) {
         for (int j = 0; j < n-i-1; j++) {
             if (a[j] > a[j+1]) {
                 int b = a[j]; 
                 a[j] = a[j+1];
                 a[j+1] = b;
             }
         }
     }
 }
