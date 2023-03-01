#include"sorting.h"
#include"list.h"
int number_edges(int* A, int SIZE) {
	int number = 0, i, j;
	for (i = 0; i < SIZE; i++)
		for (j = i; j < SIZE; j++)
			if (A[i + j * SIZE] != 0)
				number++;
	return number;
}
int number_degrees(int* A, int SIZE, int elem) {
	int number = 0, i;
	for (i = 0; i < SIZE; i++)
		if (A[elem * SIZE + i] != 0)
			number++;
	return number;
}
void passage_depth_rec(int* A, int SIZE, int j, list1* L) {
	int i;
	int log;
	list1* x;
	for (i = 0; i < SIZE; i++) {
		if (A[j * SIZE + i]) {
			log = search(L, i);
			if (!log) {
				x = create(i);
				insert_after(L, last(L), x);
				passage_depth_rec(A, SIZE, i, L);
			}
		}
	}
}
list1* passage_depth(int* A, int SIZE) {
	int i;
	list1* x;
	list1* L = create(0);
	for (i = 0; i < SIZE; i++) {
		if (A[0 * SIZE + i]) {
			x = create(i);
			insert_after(L, last(L), x);
			passage_depth_rec(A, SIZE, i, L);
			break;
		}
	}
	passage_depth_rec(A, SIZE, 0, L);
	return L;
}
void width_traversal_1(int* A, int SIZE, int j, list1* L, list1* N) {
	int i, d, log;
	list1* x;
	for (i = 0; i < SIZE; i++)
	{
		d = i;
		if (A[j * SIZE + d]){
			log = search(L, d);
			if (!log) {
				x = create(d);
				insert_after(L, last(L), x);
			}
		}
	}
	list1* next = N->next;
	if (next == NULL)return 0;
	width_traversal_1(A, SIZE, next->data, L, next);
}
list1* width_traversal(int* A, int SIZE) {
	int i;
	list1* L = create(0);
	list1* x;
	for (i = 0; i < SIZE; i++)
		if (A[0 * SIZE + i]) {
			x = create(i);
			insert_after(L, last(L), x);
		}
	list1* next = L->next;
	width_traversal_1(A, SIZE, next->data, L, next);
	return L;
}
void graph_test() {
	int A[10][10] = { 0, 0, 1, 0, 1, 1, 0, 0, 1, 1,
					0, 1, 0, 1, 1, 0, 0, 0, 1, 1,
					1, 0, 0, 1, 0, 1, 1, 0, 1, 0,
					0, 1, 1, 0, 1, 1, 1, 1, 0, 0,
					1, 1, 0, 1, 1, 0, 0, 0, 0, 1,
					1, 0, 1, 1, 0, 1, 1, 0, 0, 1,
					0, 0, 1, 1, 0, 1, 0, 1, 0, 1,
					0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
					1, 1, 1, 0, 0, 0, 0, 1, 1, 1,
					1, 1, 0, 0, 1, 1, 1, 1, 1, 1 };
	//printf("%5d\n",A[0][0]);
	int i, j, x, k;
	for (i = -1; i < 10; i++) {
		printf("%5d", i);
	}
	printf("\n");
	for (i = 0; i < 11; i++) {
		printf("_____", i);
	}
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("%4d|", i);
		for (j = 0; j < 10; j++) {
			printf("%5d", A[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	printf("%d\n", number_edges(A, 10));
	printf("%d\n", number_degrees(A,10,1));
	list1* D = passage_depth(A, 10);
	while(D){
		printf("%5d", D->data);
		D = D->next;
	}
	printf("\n");
	list1* T = width_traversal(A,10);
	while (T) {
		printf("%5d", T->data);
		T = T->next;
	}
}