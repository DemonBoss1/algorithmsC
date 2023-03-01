#include "sorting.h"

void swap(int* a, int* b)
{
	int t;
	t = *b;
	*b = *a;
	*a = t;
}
void comb_sort(int* A, int N, double l)
{
	int i, d, j;
	int distance;
	//printf("%d\n",N);
	distance = N / l;
	//printf("%d\n", distance);
	while (distance > 0)
	{
		for (i = 0; i < N; i++)
		{
			if (i + distance >= N) break;
			if (A[i] > A[i + distance])
			{
				d = A[i];
				A[i] = A[i + distance];
				A[i + distance] = d;
			}
		}
		if (distance == 1)
			if (d != -1) distance *= l;
			else break;
		d = -1;
		distance /= l;
		if (distance < 1) distance = 1;
	}
}
void shell_sort_comparison(int* A, int N, int i, int distance, int* d)
{
	printf("%5d%5d\n", i, distance);

	if (i + distance >= N || i + distance == 0) return 0;
	if (A[i] > A[i + distance])
	{
		printf("%5d%5d\n", A[i], A[i + distance]);
		swap(&A[i], &A[i + distance]);
		*d = 1;
		shell_sort_comparison(A, N, i - distance, distance, d);

	}
}
void shell_sort(int* A, int N, int l)
{
	int i, d, j;
	int distance = N / l;
	while (1)
	{
		for (i = 0; i < N; i+=distance)
		{
			shell_sort_comparison(A, N, i, distance, &d);
		}
		if (distance <= 1)
		{
			if (d = -1) break;
			if (distance == 0) distance = 1;
			distance *= l;
		}
		d = -1;
		distance /= l;
	}
}
int comp(void* a, void* b) {
	if (*((int*)a) < *((int*)b)) return -1;
	else if (*((int*)a) > * ((int*)b)) return 1;
	return 0;
}
void shell_sorts(int* A, int N, int elemsize, int flag, int alpha) {
	int x = 0;
	int h;
	int* i;
	int* j;
	for (h = N / alpha; h > 0; h /= alpha) {
		for (i = A + h; i < (A + N); i++) {
			x = *i;
			for (j = i; j >= (void*)((char*)A + h * elemsize) && comp((void*)((char*)j - h * elemsize), x) == flag; j = (void*)((char*)j - h * elemsize)) {
				*j = *(j - h);
			}
			*j = x;
		}
	}
	free(x);
}
void shell_sor(int* A, int N, double shrink)
{
	int i, j, h, x; //
	sr = 0, per = 0;
	int k = 1;
	for (h = N / shrink; h > 0; h /= shrink) {
		for (i = h; i < N; i++) {
			sr++;
			x = A[i];
			for (j = i; j >= h && x < A[j - h]; j -= h) {
				A[j] = A[j - h];
				k = 0;
				per++;
			}
			A[j] = x;
			per++;
			sr++;
		}
		
	}
	//printf("shell sort: sravneniya = %d, peressilki = %d\n", sr, per);
}
void comb_sor(int* A, int N, double distance)
{
	int i, k, j; //
	sr = 0, per = 0;
	int l;
	l = N - 1;
	while (1)
	{
		for (i = 0; i < N; i++)
		{
			if (i + l >= N) break;
			if (A[i] > A[i + l])
			{
				k = A[i];
				A[i] = A[i + l];
				A[i + l] = k;
				per++;
			}
			sr++;
		}
		//if (l == 0) l = 1;
		if (l == 1)
			if (k != -1) {
				l *= distance;

			}
			else break;
		k = -1;
		l /= distance;
		if (l < 1) l = 1;
	}
	//printf("comb sort: sravneniya = %d, peressilki = %d\n", sr, per);
}
void combsort(int* array, int size, float l)
{
	if (array && size)
	{
		int jump = size, i;
		int swapped = 1;
		while (jump > 1 || swapped)
		{
			if (jump > 1)
				jump /= l;
			swapped = 0;
			for (i = 0; i + jump < size; ++i)
				if (array[i + jump] > array[i])
				{
					int tmp;
					tmp = array[i];
					array[i] = array[i + jump];
					array[i + jump] = tmp;
					//std::swap(array[i], array[i + jump]);
					swapped = 1;
				}
		}
	}
}