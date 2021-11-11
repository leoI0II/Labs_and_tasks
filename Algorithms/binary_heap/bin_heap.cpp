#include<iostream>
#include<vector>

// void siftDown(int iInd, std::vector<int>& arr){
//     while( 2*iInd + 1 < arr.size()){
//         int leftChild = 2 * iInd + 1;
//         int rightChild = 2 * iInd + 2;

//         int jInd = leftChild;
//         if (rightChild < arr.size() && arr[rightChild] < arr[leftChild])
//             jInd = rightChild;

//         if (arr[iInd] < arr[jInd])
//             break;
//         std::swap(arr[iInd], arr[jInd]);
//         iInd = jInd;
//     }
// }

void siftDown(int i, std::vector<int>& arr){
    int maxInd = i;
    int leftCh = 2*i+2;

    if(leftCh < arr.size() && arr[leftCh] < arr[maxInd])
        maxInd = leftCh;

    int rightCh = 2*i+1;

    if (rightCh < arr.size() && arr[rightCh] < arr[maxInd])
        maxInd = rightCh;

    if (i != maxInd){
        std::swap(arr[i], arr[maxInd]);
        siftDown(maxInd, arr);
    }
}

void buildBinHeap(std::vector<int>& arr){
    for (int i = arr.size()/2; i >= 0; --i){
        siftDown(i, arr);
    }
}

int main(){

    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for (auto& elem: A)
        std::cin >> elem;

    buildBinHeap(A);

    for (auto& elem: A)
        std::cout << elem << " ";
    std::cout << std::endl;


    return 0;
}