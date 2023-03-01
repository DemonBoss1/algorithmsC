#include"ad_list.h"
void Dijkstra_algorithm_rec(adjacency_list* L, int* A, int now, int way, int* B) {
	if (B[now-1]) return;
	B[now-1] = 1;
	adjacency_list2* l = down_ad_list(L, now);
	adjacency_list2* l2 = l;
	int control;
	while (l2) {
		if ((A[l2->data-1] > way + l2->weight) || (A[l2->data-1] == 0)) {
			A[l2->data-1] = way + l2->weight;
			control = A[l2->data-1];
		}
		l2 = l2->next;
	}
	while (l) {
		Dijkstra_algorithm_rec(L, A, l->data, A[l->data-1], B);
		l = l->next;
	}
}
int Dijkstra_algorithm(adjacency_list* L,int start,int*A) {
	//int A[SIZE] = {0};
	int B[SIZE] = { 0 };
	Dijkstra_algorithm_rec(L, A, start, 0, B);
	A[start - 1] = 0;
	/*print_array(A, SIZE);*/
	//return A;
}
void all_shortcut(adjacency_list* L,int* A) {
	int i;
	int* B;
	for (i = 0; i < SIZE; i++) {
		B = A + i * SIZE;
		Dijkstra_algorithm(L, i+1, B);
	}
}
void test_shortcut() {
	int A[10][10];
	int i;
	for (i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) A[i][j] = rand() % 10;
	adjacency_list * L = matrix_to_list(A);
	print_ad_list(L);
	int B[SIZE*SIZE] = {0};
	//int* B = calloc(10, sizeof(int));
	//print_array(B, 10);
	all_shortcut(L, B);
	print_matrix(B, SIZE);
}