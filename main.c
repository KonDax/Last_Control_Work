#include "sorts.h"
#include <chrono>
#include <iostream>

void (*sortF[6])(int*, int) = {bubble_sort, insertion_sort, selection_sort, count_sort, quickSort, mergeSort};

double get_Time(void (*sort)(int*, int), int size){
	int* ar = new int[size];
	random_Fill_ar(ar, size);

	auto start = std::chrono::high_resolution_clock::now();
	sort(ar, size);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;

	delete [] ar;
	return diff.count();
}

int main(){
	double time;
	int ar_steps[7] = {100, 250, 1000, 5000, 10000, 100000, 1000000};
	int ar_fronts[8] = {100, 500, 1000, 10000, 100000, 200000, 1000000, 10000000};
	bool func_ar[6] = {false, false, false, false, false, false};
	std::cout << "\tbubble_sort\tinsertion_sort\tselection_sort\tcount_sort\tquickSort\tmergeSort\n" << std::endl;

	for (int i = 0; i < 8; i++){
		for (int size = ar_fronts[i]; size < ar_fronts[i+1]; size+=ar_steps[i]){
			std::cout << size << "\t";
			for (int j = 0; j < 6; j++){

				if (func_ar[j]){
					std::cout << "-\t";
					continue;
				}

				time = get_Time(sortF[j], size);

				if (time > 60){
					func_ar[j] = true;
				}

				std::cout << time << "\t";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}
