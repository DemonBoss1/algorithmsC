#include "sorting.h"

void quick_sorting_rek(int* A, int N, int L, int R, int m)
{
	if (L < R)
	{
		int l = L, r = R;
		int med;
		/*if (m == 0) med = A[L];
		else if (m == 1)*/ med = A[(L + R) / 2];
		//else if (m == 2) med = A[R];


		//printf("%d\n", med);
		while (l <= r) /*|| (l < med) || (med < r)*/
		{
			//l = L; r = R;
			COMPS++;
			while (A[l] < med)
			{
				l++;
				COMPS++;
			}
			COMPS++;
			while (A[r] > med)
			{
				r--;
				COMPS++;
			}
			if (l <= r)
			{
				if (A[l] > A[r])
				{
					COMPS++;
					swap(&A[l], &A[r]);
					SWAPS++;
				}
				l++; r--;
			}
			//print_array(A, N);
			//printf("%5d%5d\n", l-1, r+1);

		}
		//printf("1\n");
		//printf("%5d%5d\n", L, r);
		//printf("%10d%10d\n", SWAPS, COMPS);
		if (L < r) 	quick_sorting_rek(A, N, L, r, m);

		//printf("%5d%5d\n", l, R);
		if (l < R)	quick_sorting_rek(A, N, l, R, m);
	}
	return;
}
void quick_sorting(int* A, int N, int m)
{
	int L = 0, R = N - 1;
	quick_sorting_rek(A, N, L, R, m);
}
void merge_sorting(int* A, int N)
{
	if (N != 1)
	{
		int B[10000];
		copy_array(A, B, N / 2, 0);
		merge_sorting(B, N / 2);
		int C[10000];
		//int begin = N / 2 + 1;
		//printf("\n%d\n", begin);
		copy_array(A, C, N - N / 2, N / 2);
		merge_sorting(C, N - N / 2);
		int i = 0, j = 0, k = 0;
		//printf("\ni=%5d j=%5d\n N=%5d\n", N / 2, N - N / 2, N);
		//for (int z = 0; z < N; z++) A[z] = -1;
		//printf("1%5d%5d\n", SWAPS, COMPS);
		while (k < N)
		{
			if (i > N / 2 - 1)
			{
				while (j <= N / 2)
				{
					COMPS++;
					A[k] = C[j];
					j++; k++;
					SWAPS++;
					//printf("1");
				}
				//printf("\n");
				//print_array(A, N);
				return;
			}
			if (j > N - N / 2 - 1)
			{
				while (i <= N / 2)
				{
					COMPS++;
					A[k] = B[i];
					i++; k++;
					SWAPS++;
					//printf("2");
				}
				printf("\n");
				//print_array(A, N);
				return;
			}
			if (B[i] <= C[j])
			{
				COMPS++;
				A[k] = B[i];
				//printf("\n%7d%7d\n", i, j);
				//printf("\n%7d%7d\n", B[i], C[j]);
				k++; i++;
				SWAPS++;
				//printf("3");
			}
			if (B[i] > C[j])
			{
				COMPS++;
				A[k] = C[j];
				//printf("\n%7d%7d\n", i, j);
				//printf("\n%7d%7d\n", B[i], C[j]);
				k++; j++;
				SWAPS++;
				//printf("4");
			}
			//printf("\nk=%d\n", k);
		}
		//print_array(A, N);
	}
	//printf("2%5d%5d\n", SWAPS, COMPS);
	return;
}