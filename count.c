#include <inttypes.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

void counting_sort();
double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(int argc, char * argv[])
{
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
	for (int i = 0; i < n; i++)
		a[i] =  (double) rand() / (RAND_MAX + 1.0) * 100001;
   	double t = wtime();
	counting_sort(a, n);	
	t = wtime() - t;
	printf("time %.6f sec.\n", t);
    return 0;
}

	void counting_sort(uint32_t *a, int n){

	int i, j, idx = 0;
	int min = a[0];
	int max = a[0];
	
	for(i = 1; i < n; i++){
		if(a[i] < min)
			min = a[i];
		if(a[i] > max)
			max = a[i];
		}
	int k = max - min + 1;
	int b[k];
	for(i = 0; i < k; i++)
		b[i] = 0;
	
	for(i = 0; i < n; i++)
		b[a[i] - min]++;
	for(i = min; i <= max; i++)
	for(j = 0; j < b[i - min]; j++)
		a[idx++] = i;
}
