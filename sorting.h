#if !define SORTING_H
#define SORTING_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

unsigned int SWAPS;
unsigned int COMPS;
unsigned int oper;
unsigned int sr, per;
double getTime ();
void swap(int* a, int* b);
void bubble_sorting(int* A, int N);
void shaker_sorting(int* A, int N);
void even_odd_sorting(int* A, int N);
void dwarven_sorting(int* A, int N);
void random_array(int* A, int N);
void print_array(int* A, int N);
//void copy_array(int* A, int* B, int N);
void copy_array(int* A, int* B, int N, int begin);
void comb_sort(int* A, int N, double l);
void shell_sort(int* A, int N, int l);
void merge_sorting(int* A, int N);
void quick_sorting(int* A, int N, int m);
void comparison_pyramid(int* A, int N, int i, int j, int k);
void build_pyramid(int* A, int N, int i, int j);
void pyramid_sorting(int* A, int N);
void pyramid_sorting_nrec(int* A, int N);
void rec_heap_down(int* arr, int size, int k, int* oper);
int rec_heap_sort(int* arr, int size);
void non_rec_heap_down(int* arr, int size, int k, int* oper);
int non_rec_heap_sort(int* arr, int size);
void array_copy(int* a, int* b, int size);
void shell_sorts(int* A, int N, int elemsize, int flag, int alpha);
void shell_sor(int* A, int N, double shrink);
void comb_sor(int* A, int N, double distance);
void combsort(int* array, int size, float l);

#endif