#include "sorts.h"

void swap(int& a, int& b){
    int c = a;
    a = b;
    b = c;
}
    
void bubble_sort(int *ar, int size){
    for (int j = 1; j < size; j++){
        for(int i = 0; i < size - j; i++){
            if (ar[i] > ar[i + 1])
                swap(ar[i], ar[i + 1]);
        }   
    }   
}
        
void selection_sort(int* ar, int size){
    int min_ind;
    for (int i = 0; i < size; i++){
        min_ind = i;
        for (int j = i; j < size; j++){
            if (ar[j] < ar[min_ind])
                min_ind = j;
        }
        swap(ar[min_ind], ar[i]);
    }
}       
    
void insertion_sort(int *ar, int size){
    int key, k;
    for (int i = 1; i < size; i++){
        key = ar[i];
        k = i;
        for (int j = i - 1; ar[j] > key && j >= 0; j--, k--){
            ar[k] = ar[j];
        }
        ar[k] = key;
    }   
}           

void count_sort(int *ar, int size){
    int min = get_min(ar, size);
    int max = get_max(ar, size);
    int null_ar[max-min];
    for (int i = 0; i <= max-min; i++){ 
        null_ar[i] = 0;
    }
    
    for (int i = 0; i < size; i++){
        null_ar[ar[i]-min]++;
    }
    
    for (int i = 0, k = 0; i < size; k++) {
        while(null_ar[k]--){
            ar[i++] = k+min;
        }
    }
}

    
void quickSort(int* ar, int size) {
    int left = 0;
    int right = size - 1;
    int pivot = ar[size >> 1];
        
    while(left <= right) {
        while(ar[left] < pivot) {
            left++;
        }

        while (ar[right] > pivot) {
            right--;
        }

        if (left <= right) {
            swap(ar[right], ar[left]);
            right--;
            left++;
        }
    }
    if (right > 0) {
        quickSort(&ar[0], right + 1);
    }

    if (left < size) {
        quickSort(&ar[left], size - left);
    }
}

void merge(int* ar, int size, int central) {
    int left = 0;
    int right = central;
    int* arTemp = new int [size];
    int indexTemp = 0;

    while (left < central && right < size) {
        while(ar[left] <= ar[right] && left < central) {
            arTemp[indexTemp++] = ar[left++];
//            left++;
//            indexTemp++;
        }
        while(ar[left] > ar[right] && right < size) {
            arTemp[indexTemp] = ar[right];
            indexTemp++;
            right++;
        }
    }

    while (left < central) {
        arTemp[indexTemp++] = ar[left++];
    }
    while (right < size) {
        arTemp[indexTemp++] = ar[right++];
    }

    memcpy(ar, arTemp, size * sizeof(int));

    delete [] arTemp;
}

void mergeSort(int* ar, int size) {
    if (size <= 1) {
        return;
    }
    mergeSort(&ar[0], size >> 1);
    mergeSort(&ar[size >> 1], size - (size >> 1));

    merge(ar, size, size >> 1);
}
                                                                                                            
