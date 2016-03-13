#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>
#include <math.h>

void MergeSort(uint32_t a[], int low, int high);
void Merge(uint32_t a[], int l, int m, int r);
double wtime();

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void MergeSort(uint32_t a[], int low, int high)
{
    if (low < high) {
        int mid = floor((low + high) / 2);
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

void Merge(uint32_t a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    uint32_t L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = a[l + i];
    for(j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    } 
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}


int main(int argc, char *argv[]) 
{
    if (argv[1] == NULL) {
		fprintf (stderr, "Please, enter a valid num of elements of arrays or run test_arr.sh for testing.\n");
		exit (EXIT_FAILURE);
    }
	int m = atoi(argv[1]);
    int i;
    uint32_t a[m];
    printf("m = %d\n", m);
    FILE *data = fopen("data.txt", "r");
    if (data == NULL) {
        fprintf(stderr, "Error, no dig.txt. Please, run mkdata.sh once to fix it\n");
        exit (EXIT_FAILURE);
    }
	for (i = 0; i < m; i++)
		fscanf (data, "%d\n", &a[i]);
    fclose(data);
    double t;
    t = wtime();
	MergeSort(a, 0, m);
    t = wtime() - t;
    FILE *log = fopen("merge.log", "a");
	return fprintf(log, "%d  %.6f\n", m, t);
}