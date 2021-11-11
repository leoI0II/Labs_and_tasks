#include<iostream>
#include<cstdlib>
#include<vector>
#include<chrono>
#include<algorithm>

int partition(std::vector<int>& arr, int l, int r){
    int value = arr[(l + r) / 2];
    int i = l, j = r;

    while(i <= j){
        while(arr[i] < value) { i++; }
        while(arr[j] > value) { j--; }
        if (i >= j) break;
        std::swap(arr[i++], arr[j--]);
    }
    return j;
}

void quickSort(std::vector<int>& arr, int l, int r){
    if (l < r){
        int q = partition(arr, l, r);
        quickSort(arr, l, q);
        quickSort(arr, q+1, r);
    }
}

void CountingSort(std::vector<int>& arr){
    
    int max = *(std::max_element(arr.begin(), arr.end()));
    std::vector<int> tmp (max+1);

    for (int i = 0 ; i < arr.size(); i++){
        ++tmp[arr[i]];
    }

    int pos = 0;

    for (int i = 0; i < max+1; ++i) {
        for (int j = 0; j < tmp[i]; ++j){
            arr[pos++] = i;
        }
    }

}

int main()
{
    srand(time(NULL));

    std::vector<int> arr(500);
    for (int i = 0; i < arr.size(); i++)
        arr[i] = rand() % 1000;

    std::cout << "Original vector: ";
    
    for (int& elem: arr)
        std::cout << elem << " ";
    std::cout << std::endl << std::endl;

    std::vector<int> arr2 = arr;

    auto start1 = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size()-1);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
    
    std::cout << "Vector after quick sort: ";
    for (int& elem : arr){
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    CountingSort(arr2);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
    
    std::cout << "Vector after counting sort: ";
    for (int& elem : arr2){
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl << "Quick sort time " << elapsed1.count() << " microseconds";
    std::cout << std::endl << "Counting sort time " << elapsed2.count() << " microseconds";
    std::cout << std::endl << "Difference in time " << double(elapsed1.count())/elapsed2.count() << std::endl;

    return 0;
}