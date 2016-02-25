#include <inttypes.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

void count();
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
	printf("call count\n");
	count(&a, n);
	double t = wtime();
	
	t = wtime() - t;
	printf("%d %.6f\n",n,t);
}

void count(uint32_t *a, int n)
{
	int i, min = a[0], max = a[0];

    for (i = 1; i < n; i++){
        if (a[i] < min)
            min = a[i];
        else
        if (a[i] > max)
            max = a[i];
    }
	uint32_t *c = (uint32_t*)malloc(sizeof(uint32_t)*(max-min+1));
	uint32_t *b = (uint32_t*)malloc(sizeof(uint32_t)*n);
	
	printf("variables init\n");
	for (i = 1; i < max-min + 1; i++)
		c[i] = 0;
	printf("zeroes created\n");
	for (i = 1; i < n; i++)
		c[a[i]-min]++;
	printf("c is full\n");
	for (i = 1; i < max-min + 1; i++)
		c[i] = c[i] + c[i-1];
	printf("hz \n");
	for (i = n - 1; i<=0; i++) {
		c[a[i]] = c[a[i]] - 1;
		b[c[a[i]]] = a[i];
	}
	printf("count end\n");
	for (i = 1; i < n; i++)
		printf("%d ",b[i]);
	free (b);
	free (c);
}
