#include"sorting.h"
#include"list.h"

list1* first(list1* L) { return L; }
list1* next(list1* now) { return now->next; }
list1* prev(list1* L, list1* now) {
	L = first(L);
	while (L->next != now) L = L->next;
	return L;
}
list1* last(list1* L) {
	while (L->next) L = L->next;
	return L;
}void insert_after(list1* L, list1* p, list1* n) {
	n->next = p->next;
	p->next = n;
}void insert_before(list1* L, list1* p, list1* n) {
	insert_after(L, p, n);
	int tmp = p->data; 
	p->data = n->data;
	n->data = tmp;
}list1* remov(list1* L, list1* n) {
	if (n->next) {
		list1* r = n->next;
		int data = r->data; r->data = n->data; n->data = data;
		n->next = r->next; r->next = NULL;
		//return r;
	}
	else {
		list1* r = prev(L, n);
		r->next = NULL;
	}
}int search(list1* L, int key) {
	int data;
	data = L->data;
	if (data == key) 
		return 1;
	while (L->next){
		L = L->next;
		data = L->data;
		if (data == key) 
			return 1;
		//if (L == NULL)return 0;
	} 
	return 0;
}list1* create(int data) {
	list1* n = malloc(sizeof(list1));
	n->next = 0;
	n->data = data;
	return n;
}list1* destroy(list1* L) {
	while (L != NULL) {
		list1* n = L->next;
		free(L);
		L = n;
	}
	return 0;
}