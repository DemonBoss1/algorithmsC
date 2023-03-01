#include"ad_list.h"
void way_rec(adjacency_list* ADL, int x, int end, list1* L, int* flag) {
	if (x == end) {
		*flag = 1;
		return;
	}
	int log;
	list1* z;
	adjacency_list* AL = ADL;
	adjacency_list2* l = NULL;
	do {
		if (AL->data == x) {
			l = AL->down;
			break;
		}
		AL = AL->next;
	} while (AL);
	if (!AL) printf("Eror\n");
	if (!l) printf("eror\n");
	do {
		if (l->data)log = search(L, l->data);
		else log = 1;
		if (!log) {
			z = create(l->data);
			insert_after(L, last(L), z);
			way_rec(ADL, l->data, end, L, flag);
			if (*flag)return;
			list1* y = last(L);
			remov(L, y);
			free(y);
		}
		l = l->next;
	} while (l);
}
list1* way(adjacency_list* AL, int begin, int end) {
	list1* L = create(begin);
	int flag = 0;
	int* f = &flag;
	way_rec(AL, begin, end, L, f);
	printf("%5d\n", flag);
	return L;
}
int euler_finish(adjacency_list*AL) {
	adjacency_list2* al = AL->down;
	while (AL) {
		al = AL->down;
		while (al) {
			if (!(al->flag)) return 0;
			al = al->next;
		}
		AL = AL->next;
	}
	return 1;
}
list1* Eulerian_cycle_rec(int x, adjacency_list* AL, list1* L, int* flag, char type) {
	adjacency_list2* l = NULL;
	list1* z;
	adjacency_list2* g = NULL;
	l = down_ad_list(AL, x);
	while (l) {
		if (!(l->flag)) {
			z = create(l->data);
			insert_after(L, last(L), z);
			l->flag = 1;
			if (type) {
				g = down_ad_list(AL, l->data);
				while (g) {
					if (g->data == x) {
						g->flag = 1;
						break;
					}
					g = g->next;
				}
			}
			Eulerian_cycle_rec(l->data, AL, L, flag, type);
			if (*flag)return;
			list1* y = last(L);
			remov(L, y);
			free(y);
			l->flag = 0;
			g->flag = 0;
		}
		l = l->next;
	}
	*flag = euler_finish(AL);
	if (*flag) return;
}
list1* Eulerian_cycle(int a, adjacency_list* AL, char type) {
	list1* L = create(a);
	int x = a;
	int flag = 0;
	int* f = &flag;
	Eulerian_cycle_rec(x, AL, L, f, type);
	printf("%5d\n", flag);
	return L;
}
list1* Eulerian_cycle_rec2(int x, adjacency_list* AL, list1* L, int* flag, char type, int d1, int d2) {
	adjacency_list2* l = NULL;
	list1* z;
	adjacency_list2* g = NULL;
	l = down_ad_list(AL, x);
	while (l) {
		if (!(l->flag)) {
			z = create(l->data);
			insert_after(L, last(L), z);
			l->flag = 1;
			if (type) {
				g = down_ad_list(AL, l->data);
				while (g) {
					if (g->data == x) {
						g->flag = 1;
						break;
					}
					g = g->next;
				}
			}
			if (l->data == d1 || l->data == d2) {
				adjacency_list2* log = down_ad_list(AL, d1);
				char lg = 1;
				while (log) {
					if (!(log->flag)) {
						lg = 0;
						break;
					}
					log = log->next;
					log->data;
				}
				if (lg) {
					log = down_ad_list(AL, d2);
					while (log) {
						if (!(log->flag)) {
							lg = 0;
							break;
						}
						log = log->next;
					}
					if (lg) {
						*flag = 1;
						return;
					}
				}
			}
			Eulerian_cycle_rec2(l->data, AL, L, flag, type, d1, d2);
			if (*flag)return;
			list1* y = last(L);
			remov(L, y);
			free(y);
			l->flag = 0;
			g->flag = 0;
		}
		l = l->next;
	}
	*flag = euler_finish(AL);
	if (*flag) return;
}
list1* Eulerian_cycle2(adjacency_list* AL, char type, int d1, int d2) {
	list1* L = create(d1);
	int x = d1;
	int flag = 0;
	int* f = &flag;
	Eulerian_cycle_rec2(x, AL, L, f, type, d1, d2);
	printf("%5d\n", flag);
	return L;
}
void Hamiltonian_cycle_rec(adjacency_list* ADL, int x, list1* L, int* flag,int*A) {
	int log;
	list1* z;
	adjacency_list* AL = ADL;
	adjacency_list2* l = NULL;
	do {
		if (AL->data == x) {
			l = AL->down;
			break;
		}
		AL = AL->next;
	} while (AL);
	if (!AL) printf("Eror\n");
	if (!l) printf("eror\n");
	do {
		if (l->data)log = search(L, l->data);
		if (!log||(l->data==L->data)) {
			z = create(l->data);
			insert_after(L, last(L), z);
			A[(l->data) - 1] = 1;
			if (L->data == last(L)->data) {
				int i, log = 1;
				for (i = 0; i < SIZE; i++) if (!A[i])log = 0;
				if (log) {
					*flag = 1;
					return;
				}
				list1* y = last(L);
				A[(y->data) - 1] = 0;
				remov(L, y);
				free(y);
				l = l->next;
				continue;
			}
			Hamiltonian_cycle_rec(ADL, l->data, L, flag, A);
			if (*flag)return;
			list1* y = last(L);
			A[(y->data) - 1] = 0;
			remov(L, y);
			free(y);
		}
		l = l->next;
	} while (l);
}
list1* Hamiltonian_cycle(int begin, adjacency_list* AL) {
	list1* L = create(begin);
	int flag = 0;
	int* f = &flag;
	int A[SIZE] = {0};
	Hamiltonian_cycle_rec(AL, begin, L, f,A);
	printf("%5d\n", flag);
	return L;
}
void Hamiltonian_cycle2_finish(adjacency_list* ADL, int x, list1* L, int* flag, int begin) {
	if (x == begin) {
		*flag = 1;
		return;
	}
	int log;
	list1* z;
	adjacency_list* AL = ADL;
	adjacency_list2* l = down_ad_list(AL, x);
	do {
		if (l->data)log = search(L, l->data);
		if (!log || (l->data == begin) && L != prev(L, last(L))) {
			z = create(l->data);
			insert_after(L, last(L), z);
			if (l->data == begin) {
				*flag = 1;
				return;
			}
			Hamiltonian_cycle2_finish(ADL, l->data, L, flag, begin);
			if (*flag)return;
			list1* y = last(L);
			remov(L, y);
			free(y);
		}
		l = l->next;
	} while (l);
}
void Hamiltonian_cycle2_start(adjacency_list* ADL, int x, list1* L, int* flag, int begin, int end) {
	int log;
	list1* z;
	adjacency_list* AL = ADL;
	adjacency_list2* l = down_ad_list(AL, x);
	do {
		if (l->data)log = search(L, l->data);
		if (!log ) {
			z = create(l->data);
			insert_after(L, last(L), z);
			if (l->data == end)Hamiltonian_cycle2_finish(ADL, l->data, L, flag, begin);
			if (*flag)return;
			Hamiltonian_cycle2_start(ADL, l->data, L, flag, begin, end);
			if (*flag)return;
			list1* y = last(L);
			remov(L, y);
			free(y);
		}
		l = l->next;
	} while (l);
}
int Hamiltonian_cycle2(int begin,int end, adjacency_list* AL) {
	list1* L = create(begin);
	int flag = 0;
	int* f = &flag;
	int A[SIZE] = { 0 };
	Hamiltonian_cycle2_start(AL, begin, L, f, begin, end);
	printf("%5d\n", flag);
	return flag;
}
void test_way() {
	int A[10][10] = {
				0,1,1,0,0,0,0,0,0,0,
				1,0,1,1,0,1,0,0,0,0,
				1,1,0,0,1,1,0,0,0,0,
				0,1,0,0,1,1,1,0,0,1,
				0,0,1,1,0,1,0,1,0,1,
				0,1,1,1,1,0,0,0,0,0,
				0,0,0,1,0,0,0,1,1,1,
				0,0,0,0,1,0,1,0,1,1,
				0,0,0,0,0,0,1,1,0,0,
				0,0,0,1,1,0,1,1,0,0 };
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
		for (k = 1; k < 0; k++) printf("     ");
		for (j = 1; j <= 10; j++) {
			printf("%5d", A[i - 1][j - 1]);
		}
		printf("\n");
	}
	printf("\n\n");
	adjacency_list* L5 = matrix_to_list(A);
	adjacency_list2* l;
	adjacency_list* L = L5;
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
	list1* T = way(L5, 10, 8);
	while (T) {
		printf("%5d", T->data);
		T = T->next;
	}
	printf("\n\n");
	//print_ad_list(L5);
	list1* E = Eulerian_cycle(4, L5, 1);
	while (E) {
		printf("%5d", E->data);
		E = E->next;
	}
	printf("\n\n");
	ad_list_flag_clear(L5);
	E = Eulerian_cycle2(L5, 1, 4, 5);
	while (E) {
		printf("%5d", E->data);
		E = E->next;
	}
	printf("\n\n");
	E = Hamiltonian_cycle(4, L5);
	while (E) {
		printf("%5d", E->data);
		E = E->next;
	}
	printf("\n\n");
	E = Hamiltonian_cycle2(1, 9, L5);
	while (E) {
		printf("%5d", E->data);
		E = E->next;
	}

}