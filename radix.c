#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void radix_sort(int *a, int n) {
	int i, b[15], m = 0, exp = 1;
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
int main() {
	int a[15];
	int i, m = 15; 
	srand(time(NULL));
	for (i = 0; i < m; i++)
		a[i] = (rand());
	radix_sort(a, m);
	printf("\n\nSORTED  : ");
	for (i = 0; i < m; i++)
	  printf("%d\t", a[i]);
	return 0;
}
