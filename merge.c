#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

void MergeSort(int a[], int l, int h);
void Merge(int a[], int l, int m, int h);
double wtime();

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void MergeSort(int a[], int low, int high)
{
    if (low < high) {
        int mid = floor((low + high) / 2);
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

void Merge(int a[], int low, int mid, int high)
{
    int i, b[i];
    for (i = low; low <= high; low++)
        b[i] = a[i];
    int l = low, r = mid + 1;
    i = low;
    while ((l <= mid) && (r <= high)) {
        if (b[l] <= b[r]){
            a[i] = b[l];
            l = l + 1;
        }
        else {
            a[i] = b[r];
            r = r + 1;
        }
        i = i + 1;
    }
    while (l <= mid) {
        a[i] = b[l];
        l = l + 1;
        i = i + 1;
    }
    while (r <= high) {
        a[i] = b[r];
        r = r + 1;
        i = i + 1;
    } 

}

int main(int argc, char *argv[]) 
{
	int m = atoi(argv[1]);
    int i, a[m];
    printf("m = %d\n", m);
    FILE *data = fopen("dig.txt", "r");
	for (i = 0; i < m; i++)
		fscanf (data, "%d\n", &a[i]);
    fclose(data);
    double t;
    t = wtime();
	MergeSort(a, 0, m);
    t = wtime() - t;
    for (i = 0; i < m; i++)
        printf("%d  ", a[i]);
    FILE *log = fopen("merge.log", "a");
	return fprintf(log, "%d  %.6f\n", m, t);
}