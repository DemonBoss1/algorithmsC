#if !define LIST_H
#define LIST_H

typedef struct list_tag {
	int data;
	struct list_tag* next;
} list1;
typedef struct lis_tag {
	int data;
	struct lis_tag* another;
	struct lis_tag* early;
} list2;


list1* first(list1* L);
list1* next(list1* now);
list1* prev(list1* L, list1* now);
list1* last(list1* L);
void insert_after(list1* L, list1* p, list1* n);
void insert_before(list1* L, list1* p, list1* n);
list1* remov(list1* L, list1* n);
int search(list1* L, int key);
list1* create(int data);
list1* destroy(list1* L);

list2* First(list2* L);
list2* Next(list2* now);
list2* Prev(list2* now);
list2* Last(list2* L);
void Insert_After(list2* a, list2* b);
void Insert_Before(list2* a, list2* b);
list2* Remove(list2* a);
list2* Search(list2* L, int key);
list2* Create(int data);
list2* Destroy(list2* L);

void list_1();
void list_2();
#endif