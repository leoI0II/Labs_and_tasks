#include<iostream>
#include<cstdlib>
#include<chrono>

template<typename type>
void insertionSort(type* arr, size_t size){
    int j;
    for (int i = 1; i < size; i++){
        j = i;
        while( j > 0 && (arr[j] < arr[j-1])){
            std::swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

#define COUNT 20

int main(){

    srand(time(NULL));

    char arr[COUNT];
    for(int i = 0; i < COUNT; i++){
        arr[i] = rand() % 60 + 65;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "Insertion sort begin." << std::endl;

    auto start = std::chrono::steady_clock::now();
    insertionSort(arr, COUNT);
    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double, std::milli> dur = end - start;

    for(int i = 0; i < COUNT; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "Duration time: " << dur.count() << "s" << std::endl;;


    return 0;
}