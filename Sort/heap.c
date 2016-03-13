#include <inttypes.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

double wtime();
void heap();

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
	heap(a, n);	
	t = wtime() - t;
	printf("time %.6f sec.\n", t);
    return 0;
}

void heap(uint32_t a[], int n)
{

	int  i, j, c, min, temp;
	for (i = 1; i < n; i++){      
		c = i;
		do{
			min = (c - 1) / 2;
			if (a[min] < a[c]){
				temp = a[min];
				a[min] = a[c];
				a[c] = temp;
			}
			c = min;
		}
		while (c != 0);
	}
	for (j = n - 1; j >= 0; j--){ 
		temp = a[0];
		a[0] = a[j];
		a[j] = temp;
		min = 0;
		do{
			c = min + 1;
			if ((a[c] < a[c + 1]) && c < j-1)
				c++;
			if (a[min]<a[c] && c<j){
				temp = a[min];
				a[min] = a[c];
				a[c] = temp;
			}
			min = c;
		}
		while (c < j);
	}
}

