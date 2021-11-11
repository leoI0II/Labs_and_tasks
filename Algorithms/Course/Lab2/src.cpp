#include<iostream>
#include<vector>
using matrixIndexSum = std::pair<int, int>;
#include<cassert>

void Merge(std::vector<matrixIndexSum>& arr, int left, int mid, int right){
    int indL = 0; int indR = 0;

    std::vector<matrixIndexSum> res(right - left);

    while( left + indL < mid && mid + indR < right){
        if (arr[left+indL].second <= arr[mid+indR].second){
            res[indL+indR] = arr[left+indL];
            indL++;
        }
        else{
            res[indL+indR] = arr[mid+indR];
            indR++;
        }
    }

    while(left+indL < mid){
        res[indL+indR] = arr[left+indL];
        indL++;
    }
    while (mid + indR < right){
        res[indL+indR] = arr[mid+indR];
        indR++;
    }

    for (int i = 0; i < indL+indR; i++){
        arr[left+i] = res[i];
    }

}

void MergeSort(std::vector<matrixIndexSum>& arr, int left, int right){

    if (left + 1 >= right)
        return;

    int mid = (left + right) / 2;

    MergeSort(arr, left, mid);
    MergeSort(arr, mid, right);
    Merge(arr, left, mid, right);

    // for (int i = left; i < right; i++){
    //     std::cout << arr[i].first << " ";
    // }
    // std::cout << std::endl;

}


void TESTS(){
    using test = std::vector<matrixIndexSum>;
    using correct = std::vector<matrixIndexSum>;
    
    int testC = 1;
    std::cout << "Test#" << testC++ << ": ";
    test t1 = {{0, 12}, {1, 2}, {2, 5}, {3, 1}, {4, 7}};
    correct c1 = {{3, 1}, {1, 2}, {2, 5}, {4, 7}, {0, 12}};
    MergeSort(t1, 0, t1.size());
    assert(t1 == c1 && "incorrect!");
    std::cout << "correct" << std::endl;
    
    std::cout << "Test#" << testC++ << ": ";
    test t2 = {{0, 1}, {1, 2}, {2, 10}, {3, 2}};
    correct c2 = {{0, 1}, {1, 2}, {3, 2}, {2, 10}};
    MergeSort(t2, 0, t2.size());
    assert(t2 == c2 && "incorrect!");
    std::cout << "correct" << std::endl;

    std::cout << "Test#" << testC++ << ": ";
    test t3 = {{0, 1}};
    correct c3 = {{0, 1}};
    MergeSort(t3, 0, t3.size());
    assert(t3 == c3 && "incorrect!");
    std::cout << "correct" << std::endl;    

    std::cout << "Test#" << testC++ << ": ";
    test t4 = {{0, -10}, {1, 10}, {2, -200}, {3, 15}, {4, 0}, {5, 17}};
    correct c4 = {{2, -200}, {0, -10}, {4, 0}, {1, 10}, {3, 15}, {5, 17}};
    MergeSort(t4, 0, t4.size());
    assert(t4 == c4 && "incorrect!");
    std::cout << "correct" << std::endl;

}



int main(){

    // int matrixCount;
    // std::cin >> matrixCount;

    // std::vector<matrixIndexSum> matrixArray(matrixCount);

    // for (int matrC = 0; matrC < matrixCount; matrC++){

    //     int matrixDimension;
    //     std::cin >> matrixDimension;
    //     int diagonalSum = 0, tmpMatrEl;
        
    //     for (int matrixRow = 0; matrixRow < matrixDimension; matrixRow++){
    //         for (int matrixColoumn = 0; matrixColoumn < matrixDimension; matrixColoumn++){
    //             std::cin >> tmpMatrEl;
                
    //             if (matrixRow == matrixColoumn){
    //                 diagonalSum += tmpMatrEl;
    //             }

    //         }
    //     }
    //     matrixArray[matrC] = std::make_pair(matrC, diagonalSum);
    // }

    // MergeSort(matrixArray, 0, matrixArray.size());

    // for (int i = 0; i < matrixArray.size(); i++){
    //     std::cout << matrixArray[i].first << " ";
    // }
    // std::cout << std::endl;

    TESTS();

    return 0;
}