#if !define AD_LIST_H
#define AD_LIST_H
#include"list.h"
#include"sorting.h"
#define SIZE 10
typedef struct adjacency_list_tag1 {
	struct adjacency_list_tag2* down;
	struct adjacency_list_tag1* prev;
	struct adjacency_list_tag1* next;
	int data;
} adjacency_list;
typedef struct adjacency_list_tag2 {
	struct adjacency_list_tag1* up;
	struct adjacency_list_tag2* prev;
	struct adjacency_list_tag2* next;
	char flag;
	int data;
	int weight;
} adjacency_list2;

void add_top_ad_list(int d, adjacency_list* Lp);
adjacency_list* create_ad_list();
adjacency_list* create_ad_list_top();
void add_ad_list(int d1, int d2, int flag, adjacency_list* AL);
adjacency_list* matrix_to_list(int* A);
int* list_to_matrix(adjacency_list* L);
adjacency_list2* down_ad_list(adjacency_list* AL, int x);
adjacency_list* copy_ad_list(adjacency_list* AL);
void print_ad_list(adjacency_list* L);
void print_matrix(int* A, int N);
void ad_list_flag_clear(adjacency_list* L);

#endif