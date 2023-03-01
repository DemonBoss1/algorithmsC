#include"sorting.h"

void comparison_pyramid(int* A, int N, int i, int j, int k)
{
	//printf("\ni = %d\tj = %d\tk = %d\n", i, j, k);
	if ((i + j * 2) < N)
	{
		//printf("\n%d\t", A[i - k]);
		if (A[i + j * 2 - k * 2] >= A[i + j * 2 - 1 - k * 2])
		{
			if (A[i - k] < A[i + j * 2 - k * 2]) swap(&A[i - k], &A[i + j * 2 - k * 2]);
			//printf("%d\n", A[i - k]);
			//print_pyramid15(A);
			//printf("i = %d\ti + j * 2 = %d\n", A[i - k], A[i + j * 2 - k * 2]);
			comparison_pyramid(A, N, i + j * 2, j * 2, k * 2);
		}
		if (A[i + j * 2 - k * 2] < A[i + j * 2 - 1 - k * 2])
		{
			if (A[i - k] < A[i + j * 2 - 1 - k * 2]) swap(&A[i - k], &A[i + j * 2 - 1 - k * 2]);
			//printf("%d\n", A[i - k]);
			//print_pyramid15(A);
			//printf("i = %d\ti + j * 2 - 1 = %d\n", A[i - k], A[i + j * 2 - 1 - k * 2]);
			comparison_pyramid(A, N, i + j * 2, j * 2, 1 + k * 2);
		}
		//printf("k = %d\tk + j * 2 = %d\tk + j * 2 - 1 = %d\tmax = %d\n", A[i - k], A[i + j * 2 - k * 2], A[i + j * 2 - 1 - k * 2], A[max]);
	}
	else if ((i + j * 2) - 1 < N)
	{
		//printf("k = %d\tk + j * 2 - 1 = %d\n", A[i - k], A[i + j * 2 - 1 - k * 2]);
		if (A[i - k] < A[i + j * 2 - 1 - k * 2]) swap(&A[i - k], &A[i + j * 2 - 1 - k * 2]);
		//printf("%d\n", A[i - k]);
		//print_pyramid15(A);
		//printf("i = %d\ti + j * 2 - 1 = %d\n", A[i - k], A[i + j * 2 - 1 - k * 2]);
		comparison_pyramid(A, N, i + j * 2, j * 2, 1 + k * 2);
	}
}
void build_pyramid(int* A, int N, int i, int j)
{
	if (i < N)
	{
		i = i + j * 2;
		j *= 2;
		build_pyramid(A, N, i, j);
		int max;
		for (int k = 0; k < j; k++)
		{
			comparison_pyramid(A, N, i, j, k);
		}
	}
}
void pyramid_sorting(int* A, int N)
{
	//print_pyramid15(A);
	int i = 0, j = 1;

	//print_pyramid15(A);
	build_pyramid(A, N, i, j);
	comparison_pyramid(A, N, 0, 1, 0);
	int end = N;
	while (end)
	{
		end--;
		swap(&A[0], &A[end]);
		comparison_pyramid(A, end, 0, 1, 0);
	}
	print_array(A, N);

}
void swap1(int* a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void array_copy(int* a, int* b, int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		b[i] = a[i];
	}
}
void rec_heap_down(int* arr, int size, int k, int* oper) {
	int nmax = k, l = 2 * k + 1, r = 2 * k + 2;			*oper += 7;
	if (l < size && arr[l] > arr[nmax]) { nmax = l;	*oper += 1; }
	if (r < size && arr[r] > arr[nmax]) { nmax = r; 	*oper += 1; }
	if (nmax != k) {
		swap1(arr, k, nmax);							*oper += 6;
		rec_heap_down(arr, size, nmax, oper);		*oper += 3;
	}
}
int rec_heap_sort(int* arr, int size) {
	//clock_t t;
	//t = clock();
	//int oper = 0;//кол-во операций

	int k;
	for (k = size / 2 - 1; k >= 0; k--) {
		oper += 1;
		rec_heap_down(arr, size, k, &oper);			oper += 6;
	}
	oper += 3;

	for (k = size - 1; k >= 0; k--) {
		oper += 1;
		swap1(arr, 0, k);								oper += 6;
		rec_heap_down(arr, k, 0, &oper);			oper += 6;
	}
	oper += 2;
	return oper;
	//t = clock() - t;
	//double time = ((double)t) / CLOCKS_PER_SEC;
	//printf("%lf\n%d\n", time, oper);
}
void non_rec_heap_down(int* arr, int size, int k, int* oper) {
	int nmax = k, l = 2 * k + 1, r = 2 * k + 2;			*oper += 7;
	while (1) {
		if (l < size && arr[l]>arr[nmax]) { nmax = l;	*oper += 1; }
		if (r < size && arr[r]>arr[nmax]) { nmax = r;	*oper += 1; }
		if (nmax != k) {
			swap1(arr, k, nmax);						*oper += 3;
			k = nmax;									*oper += 1;
			nmax = k, l = 2 * k + 1, r = 2 * k + 2;		*oper += 7;
		}
		else break;
	}
}
int non_rec_heap_sort(int* arr, int size) {
	//clock_t t;
	//t = clock();
	//int oper = 0;//кол-во операций

	int k;
	for (k = size / 2 - 1; k >= 0; k--) {
		oper += 1;
		non_rec_heap_down(arr, size, k, &oper);		oper += 6;
	}
	oper += 3;

	for (k = size - 1; k >= 0; k--) {
		oper += 1;
		swap1(arr, 0, k);								oper += 6;
		non_rec_heap_down(arr, k, 0, &oper);		oper += 6;
	}
	oper += 2;
	return oper;
	//t = clock() - t;
	//double time = ((double)t) / CLOCKS_PER_SEC;
	//printf("%lf\n%d\n", time, oper);
}