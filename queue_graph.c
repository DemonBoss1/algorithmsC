#include"sorting.h"
#include"list.h"

/*typedef struct queue_graph_tag {
	struct list_tag_priority* input;
	struct list_tag_priority* output;
} queue_graph;*/

typedef struct queue_tree_tag {
	int data;
	struct queue_tree_tag* top;
	struct queue_tree_tag* left;
	struct queue_tree_tag* right;
	int priority;
} queue_tree;

queue_tree* Create_tree_queue(int data, int priority) {
	printf("%5d", data);
	queue_tree* Q = malloc(sizeof(queue_tree));
	Q->top = NULL;
	Q->left = NULL;
	Q->right = NULL;
	Q->data = data;
	Q->priority = priority;
}
queue_tree* Queue_Tree_First(queue_tree* Q) {
	while (Q->top != NULL)
	{
		Q = Q->top;
	}
	return Q;
}
queue_tree* Queue_Tree_Last(queue_tree* Q) {
	while (Q->left != NULL)
	{
		Q = Q->left;
	}
	return Q;
}
void Queue_Insert_tree(queue_tree* Q, int data, int prior) {
	//printf("%5d", data);
	queue_tree* b = Create_tree_queue(data, prior);
	Q = Queue_Tree_First(Q);
	if (prior > Q->priority) {
		Q->top = b;
		b->right = Q;
	}
	else if (prior == Q->priority){
		if (Q->left == NULL) {
			Q->left = b;
			b->top = Q;
			return 0;
		}
		while(1){
			Q = Q->left;
			/*if (Q->right == NULL) {
				Q->right = b;
				b->top = Q;
				Q->right->data;
				return 0;
			}*/
			if (Q->left == NULL) {
				Q->left = b;
				b->top = Q;
				Q->left->data;
				return 0;
			}
		}
	}
	else if (prior < Q->priority) {
		while (prior < Q->priority) Q->right;
		if (prior == Q->priority) {
			if (Q->left == NULL) Q->left = b;
			while (1) {
				Q = Q->left;
				/*if (Q->right == NULL) {
					Q->right = b;
					b->top = Q;
				}*/
				if (Q->left == NULL) {
					Q->left = b;
					b->top = Q;
				}
			}

		}
		if (prior > Q->priority) {
			queue_tree* c = Q->top;
			c->right = b;
			b->top = c;
			b->right = Q;
			Q->top = b;
		}
	}
}
void Queue_Delete_tree(queue_tree* Q) {
	Q = Queue_Tree_First(Q);
	//printf("%5d\n", Q->data);
	while (Q->right != NULL) {
		Q = Q->right;
	}
	queue_tree* a = Q;
	if (Q->top != NULL) {
		Q = Q->top;
		Q->right = a->left;
		if (a->left != NULL)a->left->top = Q;
	}
	else if (Q->left!=NULL) {
		Q = Q->left;
		Q->top = a->top;
	}
	printf("%5d", a->data);
	free(a);
}
void Print_tree(queue_tree* Q) {
	printf("%5d", Q->data);
	if (Q->left != NULL)Print_tree(Q->left);
	if (Q->right != NULL)Print_tree(Q->right);
}
void Queue_tree_test() {
	int i;
	queue_tree* Q = Create_tree_queue(1, 1);
	Queue_Insert_tree(Q, 2, 2);
	for (i = 2; i <= 5; i++) {
		Queue_Insert_tree(Q, i * 2 - 1, 2);
		Queue_Insert_tree(Q, i * 2, 2);
	}
	printf("\n");
	//while (Q){ 
	//Q = Queue_Tree_First(Q);
	//Print_tree(Q);
	Q = Queue_Tree_First(Q);
	//printf("%5d\n", Q->data);
	printf("\n");
	Q = Queue_Tree_Last(Q);
	for (i = 0; i < 10; i++) {
		Queue_Delete_tree(Q);
		//printf("%5d%5d\n", Q->output->data, Q->input->data);
		/*do {
			printf("%5d", counter->data);
			counter = counter->another;
		} while (counter != stop);
		printf("%5d\n", counter->data);*/
	}
}


