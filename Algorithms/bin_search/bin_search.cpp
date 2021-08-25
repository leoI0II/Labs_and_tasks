#include<iostream>
#include<mine>

int main(){

    int arr[] = {1, 23, 34, 56, 122, 323};

    // int *arr = new int[6];

    // for (int i = 0; i < 6; i++)
    //     arr[i] = i*2;

    std::cout << mine::binary_search(arr, 6, 122) << std::endl;

    return 0;
}