#ifndef _sorts_h_
#define _sorts_h_

#include <cstring>
#include "arraywork.h"

void bubble_sort(int*, int);
void insertion_sort(int*, int);
void selection_sort(int*, int);
void count_sort(int*, int);
void quickSort_down(int*, int);
void quickSort_up(int*, int);
void merge_up(int*, int, int);
void mergeSort_up(int* ar, int size);
void merge_down(int*, int, int);
void mergeSort_down(int* ar, int size);

#endif
