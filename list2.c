#include"sorting.h"
#include"list.h"

list2* First(list2* L) { return L; }
list2* Next(list2* now) { return now->another; }
list2* Prev(list2* now) { return now->early; }
list2* Last(list2* L) {
	L = First(L);
	return L->early;
}
void Insert_After(list2* a, list2* b) {
	list2* c = a->another;
	b->another = a->another;
	a->another = b;
	b->early = a;
	c->early = b;
	//printf("3L%5d%5d%5d\n", a->early->data, a->another->data, a->data);
	//printf("3x%5d%5d%5d\n", b->early->data, b->another->data, b->data);
}
void Insert_Before(list2* a, list2* b) {
	list2* c = a->early;
	b->early = a->early;
	a->early = b;
	b->another = a;
	c->another = b;
}
list2* Remove(list2* a) {
	list2* b = a->early;
	list2* c = a->another;
	b->another = c;
	c->early = b;
	a->another = a;
	a->early = a;
	return a;
}
list2* Search(list2* L, int key) {
	list2* stop = L;
	do {
		if (L->data == key) return L;
		L = L->another;
	} while (L != stop);
	return 0;
}
list2* Create(int data) {
	list2* n = malloc(sizeof(list2));
	n->another = n;
	n->early = n;
	n->data = data;
	return n;
}
list2* Destroy(list2 *L) {
	while (L != L) {
		list2* n = L->another;
		Remove(L);
		free(L);
		L = n;
	}
	return 0;
}