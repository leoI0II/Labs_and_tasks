#include<iostream>
#include<chrono>
#include<cstdlib>

template<typename type>
int partition(type* arr, int l, int r){
    type value = arr[(l + r) / 2];
    int i = l, j = r;

    while(i <= j){
        while(arr[i] < value) { i++; }
        while(arr[j] > value) { j--; }
        if (i >= j) break;
        std::swap(arr[i++], arr[j--]);
    }
    return j;
}

template<typename type>
void quickSort(type* arr, int l, int r){
    if (l < r){
        int q = partition(arr, l, r);
        quickSort(arr, l, q);
        quickSort(arr, q+1, r);
    }
}

#define COUNT 10

int main(){

    int arr[COUNT];
    srand(time(NULL));
    
    for (int i = 0; i < COUNT; i++){
        arr[i] = rand() % 100 + 1;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "Start quick sort for array." << std::endl;

    auto start = std::chrono::steady_clock::now();
    quickSort(arr, 0, COUNT-1);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed_time = end-start;
    for (int i = 0; i < COUNT; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << "Duration time: " << elapsed_time.count() << std::endl;

    return 0;
}