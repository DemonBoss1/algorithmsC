#include"sorting.h"
#include"list.h"

typedef struct deque_tag {
	struct lis_tag* last;
	struct lis_tag* first;
} deque;
deque* Deque_Create(list2* list) {
	deque* n = malloc(sizeof(deque));
	n->last = list;
	n->first = list;
	return n;
}
void Deque_Insert_End(deque* a, list2* b) { 
	list2* L = a->first;
	Insert_After(a->last, b);
	a->last = b; 
	//printf("2L%5d%5d\n", L->early->data, L->another->data);
	//printf("2x%5d%5d\n", b->early->data, b->another->data);
	//printf("2D%5d%5d\n", a->first->data, a->last->data);
}
void Deque_Insert_Begin(deque* a, list2* b) { 
	Insert_Before(b, a->first);
	a->first = b;
}
void Deque_Delete_End(deque* a) {
	list2* x = a->last;
	a->last = (a->last)->early;
	list2* b = a->first;
	//a->last->data;
	//(a->last)->early->data;
	//printf("2L%5d%5d\n", b->early->data, b->another->data);
	//printf("2x%5d%5d\n", x->early->data, x->another->data);
	//printf("2D%5d%5d\n", a->first->data, a->last->data);
	Destroy(x);
}
void Deque_Delete_Begin(deque* a) {
	list2* x = a->first;
	a->first = (a->first)->another;
	Destroy(x);
}
void Deque_test() {
	int i;
	list2* L = Create(1);
	deque* D = Deque_Create(L);
	list2* x = Create(2);
	Deque_Insert_End(D, x);
	//printf("1L%5d%5d\n", L->early->data, L->another->data);
	//printf("1x%5d%5d\n", x->early->data, x->another->data);
	//printf("1D%5d%5d\n", D->first->data, D->last->data);
	for (i = 2; i <= 5; i++) {
		list2* a = Create(i * 2 - 1);
		Deque_Insert_End(D, a);
		printf("%5d%5d\n", D->first->data, D->last->data);
		list2* b = Create(i * 2);
		Deque_Insert_End(D, b);
		printf("%5d%5d\n", D->first->data, D->last->data);
	}
	list2* stop = L;
	list2* counter = L;
	do {
		printf("%5d", counter->data);
		counter = counter->another;
	} while (counter != stop);
	printf("\n");
	while (D->first != D->last) {
		Deque_Delete_Begin(D);
		printf("%5d%5d\n", D->first->data, D->last->data);
	}
}