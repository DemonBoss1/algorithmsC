#include "sorting.h"
#include "list.h"

int compare(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}
void simple_sorts(){
	time_t start, end;
	double timeInMilliseconds, d0;
	FILE* file = fopen("text.txt", "w");

	srand(time(NULL));
	int A[10000], i;
	int N = 10000;
	int B[10000];
	random_array(B, N);
	copy_array(B, A, N, 0);

	/*for (N = 100; N < 10001; N += 100)
	{
		copy_array(B, A, N);

		d0 = getTime();

		bubble_sorting(A, N);

		timeInMilliseconds = 1000 * (getTime() - d0);
		fprintf(file, "%f\n", timeInMilliseconds);
	}
	/*fprintf(file, "\n");

	copy_array(B, A, N);
	/*
	//printf("1\n");
	for (N = 100; N < 10001; N += 100)
	{
		copy_array(B, A, N);

		d0 = getTime();

		shaker_sorting(A, N);

		timeInMilliseconds = 1000 * (getTime() - d0);
		fprintf(file, "%f\n", timeInMilliseconds);
		//printf("1\n");
	}
	/*
	fprintf(file, "\n");

	copy_array(B, A, N);
	/*
	for (N = 100; N < 10001; N += 100)
	{
		copy_array(B, A, N);

		d0 = getTime();

		even_odd_sorting(A, N);

		timeInMilliseconds = 1000 * (getTime() - d0);
		fprintf(file, "%f\n", timeInMilliseconds);
	}
	/*
	fprintf(file, "\n");

	copy_array(B, A, N);
	
	for (N = 100; N < 10001; N += 100)
	{
		copy_array(B, A, N);

		d0 = getTime();

		dwarven_sorting(A, N);

		timeInMilliseconds = 1000 * (getTime() - d0);
		fprintf(file, "%f\n", timeInMilliseconds);
	}*/
	fclose(file);
	
}
void variable_step_sorting(){
	time_t start, end;
	double timeInMilliseconds, d0;
	FILE* file = fopen("text.txt", "w");

	srand(time(NULL));
	int A[32768], i;
	int N = 32768;
	int B[32768];

	random_array(B, N);
	copy_array(B, A, N, 0);
	printf("0\n");

	for (double distance = 1.1; distance <= 5; distance += 0.1)
	{
		//copy_array(B, A, N, 0);
		timeInMilliseconds = 0;

		for (i = 0; i < 100; i++) {
			random_array(A, N);
			d0 = getTime();

			//comb_sort(A, N, distance);
			//shell_sort(A, N, distance);
			//shell_sorts(A, N, sizeof(int), 1, distance);
			//shell_sor(A, N, distance);
			comb_sor(A, N, distance);
			//ShellSort(N, A);
			//combsort(A, N, distance);

			timeInMilliseconds += 1000 * (getTime() - d0);
		}
		//printf("%d\t%f\n", distance, timeInMilliseconds);
		fprintf(file, "%f\n", timeInMilliseconds/100);
		//fprintf(file, "%d\n%d\n", sr, per);

		//print_array(A, N);
		printf("%f\n", distance);

	}

	
}
void lab5(){
	FILE* file = fopen("text.txt", "w");
	//int SWAPS, COMPS;
	int A[1000], i, j;
	int N = 1000;
	int B[1000];
	random_array(B, N);
	if(0)
	{
		for (N = 100; N < 1001; N += 100)
		{
			fprintf(file, "%d\n", N);
			//copy_array(B, A, N);
			SWAPS = 0, COMPS = 0;
			for (j = 0; j < 101; j++)
			{
				random_array(A, N);
				merge_sorting(A, N);
			}
			fprintf(file, "%d\n%d\n", SWAPS / 100, COMPS / 100);
			for (i = 0; i < 3; i++)
			{
				//copy_array(B, A, N);
				SWAPS = 0, COMPS = 0;
				for (j = 0; j < 101; j++)
				{
					random_array(A, N);
					quick_sorting(A, N, i);
				}
				fprintf(file, "%d\n%d\n", SWAPS / 100, COMPS / 100);
			}
			fprintf(file, "\n");
			printf("%d\n", N);
		}

	}
	if (1)
	{
		time_t start, end;
		double timeInMilliseconds, d0; 
		
		for (N = 100; N < 1001; N += 100)
		{
			fprintf(file, "%d\n", N);
			copy_array(B, A, N, 0);
			d0 = getTime();
			qsort(A, N, sizeof(int), compare);
			timeInMilliseconds = 1000 * (getTime() - d0);
			fprintf(file, "%f\n", timeInMilliseconds);

			copy_array(B, A, N, 0);
			d0 = getTime();
			quick_sorting(A, N, 1);
			timeInMilliseconds = 1000 * (getTime() - d0);
			fprintf(file, "%f\n", timeInMilliseconds);
			fprintf(file, "\n");
		}
	}
	fclose(file);

}
void lab6(){
	int A[10], B[10];
	int N = 10;
	random_array(B, N);
	copy_array(B, A, N, 0);

}
void man_1() {
	//setlocale(0, "rus");
	//srand(time(NULL));

	time_t start, end;
	double timeInMilliseconds, d0;
	FILE* file = fopen("text.txt", "w");

	int size = 1000, i;
	int a[10000], b[10000];
	int oper;
	/*for (i = 0; i < ; i++) {
		a[i] = rand() % 100 + 1;
	}*/
	random_array(a, 10000);
	for (size; size < 10001; size += 1000)
	{
		printf("%d\n", size);
		//print_array(a, size);
		array_copy(a, b, size);
		oper = 0;
		d0 = getTime();
		oper = rec_heap_sort(b, size);
		timeInMilliseconds = 1000 * (getTime() - d0);
		fprintf(file, "%f\n%d\n", timeInMilliseconds, oper);
		//print_array(a, size);
		//printf("\n");
		array_copy(a, b, size);
		//print_array(a, size);
		oper = 0;
		d0 = getTime();
		oper = non_rec_heap_sort(b, size);
		timeInMilliseconds = 1000 * (getTime() - d0);
		fprintf(file, "%f\n%d\n", timeInMilliseconds, oper);
		//print_array(a, size);
		printf("\n");
	}
	fclose(file);

}
void list_1() {
	//list1 a, b, c, d, e, f, g, x, y, z;
	int i;
	list1* L = create(1);
	list1* x = create(2);
	insert_after(L, L, x);
	for (i = 2; i <= 5; i++) {
		list1* a = create(i * 2 - 1);
		insert_after(L, last(L), a);
		list1* b = create(i * 2);
		insert_after(L, a, b);
	}
	list1* j = L;
	do {
		printf("%5d", j->data);
		j = j->next;
	} while (j);
	printf("\n");
	j = last(L);
	do {
		printf("%5d", j->data);
		j = prev(L, j);
		if (j == L) printf("%5d", j->data);
	} while (j!=L);
	list1* z = search(L, 5);
	printf("\n%5d", z->data);
	printf("\n");
	do {
		printf("%5d", j->data);
		j = j->next;
	} while (j);
	do {
		remov(L, prev(L,last(L)));
		printf("\n");
		j = first(L);
		do {
			printf("%5d", j->data);
			j = j->next;
		} while (j);
	} while (j != L->next);
}
void list_2() {
	int i;
	list2* L = Create(1);
	list2* x = Create(2);
	Insert_After(L, x);
	for (i = 2; i <= 5; i++) {
		list2* a = Create(i * 2 - 1);
		Insert_After(Last(L), a);
		list2* b = Create(i * 2);
		Insert_After(a, b);
	}
	list2* stop = L;
	list2* counter = L;
	do {
		printf("%5d", counter->data);
		counter = counter->another;
	} while (counter != stop);
	printf("\n");
	counter = Last(L);
	do {
		printf("%5d", counter->data);
		counter = Prev(counter);
	 } while (counter != Last(L));
	 list2* z = Search(L, 5);
	 printf("\n%5d", z->data);
	 printf("\n");
	 counter = L;
	 do {
		 printf("%5d", counter->data);
		 counter = counter->another;
	 } while (counter != L);
	 do {
		 Destroy(Last(L));
		 Remove(Last(L));
		 printf("\n");
		 counter = First(L);
		 do {
			 printf("%5d", counter->data);
			 counter = counter->another;
		 } while (counter != L);
	 } while (Last(L) != L);
}