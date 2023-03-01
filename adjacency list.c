#include"ad_list.h"
void add_top_ad_list(int d, adjacency_list* Lp) {
	adjacency_list* L = calloc(1, sizeof(adjacency_list));
	adjacency_list2* L2 = calloc(1, sizeof(adjacency_list2));
	L->down = L2; L2->up = L;
	L->next = NULL; L->prev = Lp; Lp->next = L;
	L2->next = NULL; L2->prev = NULL;
	L->data = d; L2->data = NULL;
}
adjacency_list* create_ad_list() {
	adjacency_list* L = calloc(1, sizeof(adjacency_list));
	adjacency_list2* L2 = calloc(1, sizeof(adjacency_list2));
	L->down = L2; L2->up = L;
	L->next = NULL; L->prev = NULL;
	L2->next = NULL; L2->prev = NULL;
	L->data = 0; L2->data = NULL;
	/*adjacency_list* Lp = L;
	int i;
	for (i = 2; i <= N; i++) {
		add_top_ad_list(i, Lp);
		if (i-2)Lp = Lp->next;
	}*/
	return L;
}
adjacency_list* create_ad_list_top() {
	adjacency_list* L = calloc(1, sizeof(adjacency_list));
	adjacency_list2* L2 = calloc(1, sizeof(adjacency_list2));
	L->down = L2; L2->up = L;
	L->next = NULL; L->prev = NULL;
	L2->next = NULL; L2->prev = NULL;
	L->data = 1; L2->data = 0;
	int i;
	adjacency_list* L1 = L;
	for (i = 2; i <= SIZE; i++) {
		adjacency_list* L3 = calloc(1, sizeof(adjacency_list));
		adjacency_list2* L4 = calloc(1, sizeof(adjacency_list2));
		L3->down = L4; L4->up = L3;
		L3->next = NULL; L3->prev = L1; L1->next = L3;
		L4->next = NULL; L4->prev = NULL;
		L3->data = i; L4->data = 0;
		L1 = L3;
	}
	return L;
}
adjacency_list* create_ad_list_add(int d1, int d2, int flag, adjacency_list* L, int weight) {
	adjacency_list2* L2 = calloc(1, sizeof(adjacency_list2));
	L->down = L2; L2->up = L;
	L2->next = NULL; L2->prev = NULL;
	L->data = d1; L2->data = d2;
	L2->weight = weight;
	if (flag && (d1 != d2)) {
		adjacency_list* L1 = calloc(1, sizeof(adjacency_list));
		adjacency_list2* L21 = calloc(1, sizeof(adjacency_list2));
		L1->down = L21; L21->up = L1;
		L1->next = NULL; L1->prev = L; L->next = L1;
		L21->next = NULL; L21->prev = NULL;
		L1->data = d2; L21->data = d1;
		L21->weight = weight;
	}
}
void add_ad_list(int d1, int d2, int flag, adjacency_list* AL, int weight) {
	while (AL->prev)AL->prev;
	if (AL->data == NULL) {
		create_ad_list_add(d1, d2, flag, AL, weight);
		return;
	}
	adjacency_list* L = AL;
	adjacency_list2* l = NULL;
	do {
		if (L->data == d1) {
			l = L->down;
			break;
		}
		if (L->next == NULL) {
			adjacency_list* L1 = calloc(1, sizeof(adjacency_list));
			adjacency_list2* L2 = calloc(1, sizeof(adjacency_list2));
			L1->down = L2; L2->up = L1;
			L1->next = NULL; L1->prev = L; L->next = L1;
			L2->next = NULL; L2->prev = NULL;
			L1->data = d1; L2->data = d2;
			L2->weight = weight;
			if (flag && (d1 != d2)) add_ad_list(d2, d1, 0, AL,weight);
			return;
		}
		L = L->next;
	} while (L);
	if (!L) printf("Eror\n");
	if (!l->data) {
		l->up = L;
		l->data = d2;
		l->weight = weight;
		if (flag && (d1 != d2)) add_ad_list(d2, d1, 0, AL, weight);
		return;
	}
	do {
		if (l->data == d2) {
			break;
		}
		if (l->next == NULL) {
			adjacency_list2* L2 = calloc(1, sizeof(adjacency_list2));
			L2->up = l->up;
			L2->next = NULL; L2->prev = l; l->next = L2;
			L2->data = d2;
			L2->weight = weight;
			if (flag && (d1 != d2)) add_ad_list(d2, d1, 0, AL, weight);
			return;
		}
		l = l->next;
	} while (l);
	if (!l) printf("Eror\n");
	if (flag && (d1 != d2)) add_ad_list(d2, d1, 0, AL, weight);
}
adjacency_list* matrix_to_list(int* A) {
	adjacency_list* L = create_ad_list();
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (A[i * SIZE + j])add_ad_list(i + 1, j + 1, 0, L, A[i * SIZE + j]);
		}
	}
	return L;
}
int* list_to_matrix(adjacency_list* L) {
	int* A = calloc(SIZE * SIZE, sizeof(int));
	adjacency_list2* l = NULL;
	while (L) {
		l = L->down;
		while (l)
		{
			A[(L->data - 1) * SIZE + l->data - 1] = 1;
			l = l->next;
		}
		L = L->next;
	}
	return A;
}
int number_of_degrees_ad_list(adjacency_list* L, int d) {
	adjacency_list2* l = NULL;
	while (L){
		if (L->data == d) {
			l = L->down;
			break;
		}
		L = L->next;
	}
	if (!L) return -1;
	int count = 0;
	while (l) {
		count++;
		l = l->next;
	}
	return count;
}
int number_of_top_ad_list(adjacency_list* L) {
	int count = 0;
	while (L) {
		count++;
		L = L->next;
	}
	return count;
}
int number_of_edges_ad_list(adjacency_list* L) {
	adjacency_list2* l = NULL;
	int count = 0;
	while (L) {
		l = L->down;
		while (l) {
			count++;
			l = l->next;
		}
		L = L->next;
	}
	return count;
}
adjacency_list2* down_ad_list(adjacency_list* AL, int x) {
	while (AL->prev)AL->prev;
	adjacency_list* L = AL;
	adjacency_list2* l = NULL;
	do {
		if (L->data == x) {
			l = L->down;
			break;
		}
		L = L->next;
	} while (L);
	if (!L) printf("Eror\n");
	return l;
}
adjacency_list* copy_ad_list(adjacency_list* AL) {
	adjacency_list* L = calloc(1, sizeof(adjacency_list));
	adjacency_list2* l = calloc(1, sizeof(adjacency_list2));
	L->data = AL->data;
	adjacency_list2* al = AL->down;
	l->data = al->data;
	L->down = l; l->up = L;
	adjacency_list* L1 = L;
	while (AL) {
		al = AL->down;
		while (al) {
			add_ad_list(AL->data, al->data, 0, L,al->weight);
			al = al->next;
		}
		AL = AL->next;
	}
	return L1;
}
void print_ad_list(adjacency_list* L) {
	adjacency_list2* l;
	while (L) {
		l = L->down;
		while (l)
		{
			printf("%5d,%d - %d", L->data, l->data, l->weight);
			l = l->next;
		}
		printf("\n");
		L = L->next;
	}
	printf("\n\n");
}
void print_matrix(int* A, int N) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%5d", A[i * N + j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
void ad_list_flag_clear(adjacency_list* L) {
	adjacency_list2* l;
	while (L) {
		l = L->down;
		while (l)
		{
			l->flag = 0;
			l = l->next;
		}
		L = L->next;
	}
}
void test_ad_list() {
	/*int A[SIZE][SIZE] = { 0, 0, 1, 0, 1, 1, 0, 0, 1, 1,
					0, 1, 0, 1, 1, 0, 0, 0, 1, 1,
					1, 0, 0, 1, 0, 1, 1, 0, 1, 0,
					0, 1, 1, 0, 1, 1, 1, 1, 0, 0,
					1, 1, 0, 1, 1, 0, 0, 0, 0, 1,
					1, 0, 1, 1, 0, 1, 1, 0, 0, 1,
					0, 0, 1, 1, 0, 1, 0, 1, 0, 1,
					0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
					1, 1, 1, 0, 0, 0, 0, 1, 1, 1,
					1, 1, 0, 0, 1, 1, 1, 1, 1, 1 };
	*/
	//int C[SIZE] = { 0,1,2,3,4,5,6,7,8,9 };
	adjacency_list* L = create_ad_list(SIZE);
	//adjacency_list* L = matrix_to_list(A);
	//srand(time(NULL));
	int i, j, x, k;
	for (i = 0; i < 11; i++) {
		printf("%5d", i);
	}
	printf("\n"); 
	for (i = 0; i < 11; i++) {
		printf("_____", i);
	}
	printf("\n");
	for (i = 1; i <= 10; i++) {
		printf("%4d|", i);
		for (k = 1; k < i; k++) printf("     ");
		for (j = i; j <= 10; j++) {
			x = rand() % 2;
			printf("%5d", x);
			//printf("%5d", A[i][j]);
			if (x)add_ad_list(i, j, 1, L,x);
		}
		printf("\n");
	}
	printf("\n\n");
	adjacency_list2* l;
	adjacency_list* AL = L;
	while (L) {
		l = L->down;
		while (l)
		{
			printf("%5d,%d", L->data, l->data);
			l = l->next;
		}
		printf("\n");
		L = L->next;
	}
	printf("\n\n");
	int* B = list_to_matrix(AL);
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%5d", B[i * SIZE + j]);
		}
		printf("\n");
	}
	printf("\n%5d\n", number_of_degrees_ad_list(AL, 1));
	printf("\n%5d\n", number_of_top_ad_list(AL));
	printf("\n%5d\n", number_of_edges_ad_list(AL));
	print_ad_list(AL);
}