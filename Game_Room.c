#include "sorting.h"
#include "list.h"

void create_rooms(int* rooms) {
	int counterRoom = 0;
	for (int i = 0; i < 10; i++) {
		for (int l = 0; l < i; l++)
			if (rooms[i * 10 + l] == 1)
				counterRoom++;
		for (int j = i; j < 10; j++) {
			if (counterRoom == 4)
				break;
			if (i == j)continue;
			rooms[10 * i + j] = rand() % 2;
			if (rooms[i * 10 + j] == 1) {
				counterRoom++;
				rooms[j * 10 + i] = 1;
			}
		}
		counterRoom = 0;
	}
}
void check_way_rec(int* rooms, int* A, int a) {
	for (int i = 0; i < 10; i++) {
		if (A[a * 10 + i] == 1) {
			A[i] = 1;
			check_way_rec(rooms, A, a);
		}
	}
}
int check_way(int* rooms) {
	int A[10] = { 0 };
	check_way_rec(rooms, A, 0);
	for (int i = 0; i < 10; i++)
		if (A[i] == 0)
			return 0;
	return 1;
}
void cleer_rooms(int* rooms) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			rooms[i * 10 + j] = 0;
}

void create_levelRoom() {
	srand(time(NULL));
	int rooms[10][10] = { 0 };
	create_rooms(rooms);
	while (check_way(rooms)) {
		cleer_rooms(rooms);
		create_rooms(rooms);
	}
		printf("\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", rooms[i][j]);
		}
		printf("\n");
	}
}
