#include "sorts.h"
#include <chrono>
#include <iostream>

void (*sortF[6])(int*, int) = {bubble_sort, insertion_sort, selection_sort, count_sort, quickSort, mergeSort};

double get_Time(void (*sort)(int*, int), int size){
	int* ar = new int[size];
	random_Fill_ar(ar, size);

		
				//std::chrono::time_point<std::chrono::high_resolution_clock> start;
				auto start = std::chrono::high_resolution_clock::now();
	
				sort(ar, size);
	
				//std::chrono::time::time_point<std::chrono::high_resolution_clock> end;
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
		for (int s = ar_fronts[i]; s < ar_fronts[i+1]; s+=ar_steps[i]){
			std::cout << s << "\t";
			for (int i = 0; i < 6; i++){
				if (func_ar[i]){
					std::cout << "----\t";
					continue;
				}
				time = get_Time(sortF[i], s);
				if (time > 60)
					func_ar[i] = true;

				std::cout << time << "\t";
			}
		std::cout << std::endl;
		}
	}


	return 0;
}
