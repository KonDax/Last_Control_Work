#include "arraywork.h"

//вообще эта функция не имеет никакого отношение к массивам... потому что она может менять значения и обычных переменных
void swap(int& a, int& b){
    int c = a;
    a = b;
    b = c;
}

void random_Fill_ar(int* ar, int size, int min, int max){
    srand(time(nullptr));
    for (int i = 0; i < size; i++){
        ar[i] = min + rand() % (max - min + 1);	это я где-то видел!!!... зачем из max вычитать min???
    }
}

void show_ar(int* ar, int size, char element){ element это скорее всего delimeter
    for (int i = 0; i < size; i++){
        std::cout << ar[i] << element;
    }
    std::cout << std::endl;
}

