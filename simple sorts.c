#include "sorting.h"

double getTime() {

	LARGE_INTEGER freq, val;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&val);
	return (double)val.QuadPart / (double)freq.QuadPart;

}
void bubble_sorting(int* A, int N)
{
	int d = 1, i;
	while (d)
	{
		d = 0;
		for (i = 0; i < N - 1; i++)
		{
			if (A[i] > A[i + 1])
			{
				d = A[i];
				A[i] = A[i + 1];
				A[i + 1] = d;
			}
		}
	}
	/*for (i = 0; i < N; i++)
		printf("%5d", A[i]);
		printf("\n");*/
}
void shaker_sorting(int* A, int N)
{
	int max, min, last, i, d;
	min = 0;
	max = N - 1;
	/*for (i = 0; i < N; i++)
		printf("%5d", A[i]);
	printf("\n");*/
	while (min < max)
	{
		//last = -1;
		for (i = min; i < max; i++)
		{
			if (A[i] > A[i + 1])
			{
				d = A[i];
				A[i] = A[i + 1];
				A[i + 1] = d;
				last = i;
			}
		}
		//if (last == -1) break;
		max = last;
		/*for (i = 0; i < N; i++)
			printf("%5d", A[i]);
		printf("\n");*/
		for (i = max; i > min; i--)
		{
			if (A[i] < A[i - 1])
			{
				d = A[i];
				A[i] = A[i - 1];
				A[i - 1] = d;
				last = i;
			}
			
		}
		min = last;
		/*for (i = 0; i < N; i++)
			printf("%5d", A[i]);
		printf("\n");*/
	}
	/*for (i = 0; i < N; i++)
		printf("%5d", A[i]);
	printf("\n");*/
}
void even_odd_sorting(int* A, int N)
{
	int d = 1, i;
	while (d)
	{
		/*for (i = 0; i < N; i++)
			printf("%5d", A[i]);
		printf("\n");*/
		d = 0;
		for (i = 0; i < N - 1; i+=2)
		{
			if (A[i] > A[i + 1])
			{
				d = A[i];
				A[i] = A[i + 1];
				A[i + 1] = d;
			}
		}
		/*for (i = 0; i < N; i ++)
			printf("%5d", A[i]);
		printf("\n");*/
		for (i = 1; i < N - 1; i+=2)
		{
			if (A[i] > A[i + 1])
			{
				d = A[i];
				A[i] = A[i + 1];
				A[i + 1] = d;
			}
		}
	}
	/*for (i = 0; i < N; i++)
		printf("%5d", A[i]);
		printf("\n");*/
}
void dwarven_sorting(int* A, int N)
{
	int i, d, j;
	/*for (i = 0; i < N; i++)
		printf("%5d", A[i]);
	printf("\n");*/
	for (i = 0; i < N - 1; i++)
	{
		if (A[i] > A[i + 1])
		{
			d = A[i];
			A[i] = A[i + 1];
			A[i + 1] = d;
			i -= 2;
			/*for (j = 0; j < N; j++)
				printf("%5d", A[j]);
			printf("\n");*/
		}
	}
	/*for (i = 0; i < N; i++)
		printf("%5d", A[i]);
	printf("\n");*/
}
void random_array(int* A, int N)
{
	int i;
	for (i = 0; i < N; i++)
		A[i] = rand() % 100;
	/*for (i = 0; i < N; i++)
		printf("%5d", A[i]);
	printf("\n");*/
}
/*void copy_array(int* A, int* B, int N)
{
	int i;
	for (i = 0; i < N; i++)
		B[i] = A[i];
}*/
void copy_array(int* A, int* B, int N, int begin)
{
	int i;
	for (i = 0; i < N; i++)
		B[i] = A[i + begin];
	//print_array(B, N);
}
void print_array(int* A, int N)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%5d", A[i]);
	printf("\n");
}

