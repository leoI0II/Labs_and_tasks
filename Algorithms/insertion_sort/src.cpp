#include<iostream>
#include<cstdlib>
#include<chrono>


template<typename type>
void insertionSort(type* arr, size_t size){
    int j;
    for (int i = 1; i < size; i++){
        j = i-1;
        while( j >= 0 && arr[j] > arr[j+1]){
            std::swap(arr[j], arr[j+1]);
            j--;
        }
    }
}

int main(){

    srand(time(NULL));

    int arr[20];
    for(int i = 0; i < 20; i++){
        arr[i] = rand() % 100 + 1;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "Insertion sort begin." << std::endl;

    auto start = std::chrono::steady_clock::now();
    insertionSort(arr, 20);
    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double, std::milli> dur = end - start;

    for(int i = 0; i < 20; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "Duration time: " << dur.count() << "s" << std::endl;;


    return 0;
}