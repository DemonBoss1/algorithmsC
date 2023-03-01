#include"sorting.h"
#include"list.h"

typedef struct queue_tag {
	struct list_tag_priority* input;
	struct list_tag_priority* output;
} queue;

typedef struct list_tag_priority {
	int data;
	struct list_tag_priority* another;
	struct list_tag_priority* early;
	int priority;
} list_prior;

void Insert_After_Preority(list_prior* a, list_prior* b) {
	list_prior* c = a->another;
	b->another = a->another;
	a->another = b;
	b->early = a;
	c->early = b;
}
void Insert_Before_Preority(list_prior* a, list_prior* b) {
	list_prior* c = a->early;
	b->early = a->early;
	a->early = b;
	b->another = a;
	c->another = b;
}
list_prior* Create_priority(int data, int priority) {
	list_prior* list = malloc(sizeof(list_prior));
	list->another = list;
	list->early = list;
	list->data = data;
	list->priority = priority;
}
queue* Queue_Create(int data, int priority) {
	queue* n = malloc(sizeof(queue));
	list_prior* list = Create_priority(data, priority);
	n->input = list;
	n->output = list;
	return n;
}
void Queue_Insert(queue* Q, int data, int prior) {
	list_prior* b = Create_priority(data, prior);
	int l, r;
	l = prior - (Q->output->priority);
	r = (Q->input->priority) - prior;
	list_prior* i;
	if (l > r) {
		i = Q->input;
		while (i->priority > prior) i = i->early;
		if (i == Q->input) Q->input = b;
		Insert_After_Preority(i, b);
	}
	if (l < r) {
		i = Q->output;
		while (i->priority <= prior) i = i->early;
		if (i == Q->output) Q->output = b;
		Insert_Before_Preority(i, b);
	}
}
void Queue_Delete(queue* a) {
	list_prior* x = a->output;
	a->output = (a->output)->another;
	a->output->early = a->input;
	a->input->another = a->output;
//	printf("1%5d%5d%5d\n", a->output->early->data, a->output->data,a->output->another->data);
	//free(x);
	//x = NULL;
}
void Queue_test() {
	int i;
	queue* Q = Queue_Create(1, 1);
	Queue_Insert(Q, 2, 2);
	//Deque_Insert_End(D, x);
	//printf("1L%5d%5d\n", L->early->data, L->another->data);
	//printf("1x%5d%5d\n", x->early->data, x->another->data);
	//printf("1D%5d%5d\n", D->first->data, D->last->data);
	for (i = 2; i <= 5; i++) {
		//list2* a = Queue_Create(i * 2 - 1, 1);
		Queue_Insert(Q, i * 2 - 1, 2);
		//Deque_Insert_End(D, a);
		//printf("%5d%5d\n", D->first->data, D->last->data);
		//list2* b = Queue_Create(i * 2, 1);
		Queue_Insert(Q, i * 2, 2);
		//Deque_Insert_End(D, b);
		//printf("%5d%5d\n", D->first->data, D->last->data);
	}
	list_prior* stop = Q->input;
	list_prior* counter = Q->output;
	do {
		printf("%5d", counter->data);
		counter = counter->another;
	} while (counter != stop);
	printf("%5d", counter->data);
	printf("\n");
	while (Q->input!=Q->output) {
		Queue_Delete(Q);
		printf("%5d%5d\n", Q->output->data, Q->input->data);
		/*do {
			printf("%5d", counter->data);
			counter = counter->another;
		} while (counter != stop);
		printf("%5d\n", counter->data);*/
	}
}

