#include<iostream>
#include<vector>
#include<limits>
#include<string>
#include<exception>
#include<algorithm>

template<class El_t>
class MinBinHeap{
public:

    MinBinHeap() : size(0){}
    MinBinHeap(const std::vector<El_t>& _heap) : heap(_heap), size(heap.size()) {
        BuildMinHeap(heap);
    }

    int Parent(int i) const { return (i-1) / 2 ; }
    int LeftChild(int i) const { return 2 * i + 1 ; }
    int RightChild(int i) const { return 2 * i + 2 ; }

    void SiftDown(int i) {
        int minInd = i;

        int l = LeftChild(i);
        if (l < size && heap[l] < heap[minInd])
            minInd = l;

        int r = RightChild(i);
        if (r < size && heap[r] < heap[minInd])
            minInd = r;

        if (minInd != i){
            std::swap(heap[i], heap[minInd]);
            SiftDown(minInd);
        }
    }

    void SiftUp(int i) {
        while ( heap[i] < heap[Parent(i)] ){
            std::swap(heap[i], heap[Parent(i)]);
            i = Parent(i);
        }
    }

    void ChangePriority(int i, El_t newP) {
        if (!size)
            throw std::out_of_range("Heap is empty.");
        El_t oldP = heap[i];
        heap[i] = newP;

        if (oldP > newP)
            SiftDown(i);
        else if (oldP == newP)
            return;
        else
            SiftUp(i);
    }

    El_t ExtractMin() {
        if (!size)
            throw std::out_of_range("Heap is empty!");
        El_t min = heap[0];
        heap[0] = heap[--size];
        SiftDown(0);
        return min;
    }

    void Insert(El_t newP) {
        if (size == 0)
            heap.resize(10);
        if (size == heap.capacity()) {
            heap.resize(size * 2);
        }
        ++size;
        heap[size - 1] = newP; SiftUp(size - 1);
    }

    void Remove(int i) {
        if (!size)
            throw std::out_of_range("Heap is empty.");
        heap[i] = std::numeric_limits<El_t>::min();
        SiftUp(i) ; ExtractMin();
    }


    void BuildMinHeap(std::vector<El_t>& newHeap){
        for (int i = newHeap.size()/2; i >= 0; --i)
            SiftDown(i);
    }

    void showHeap(){
        if (! size)
            throw std::out_of_range("Heap is empty!");
        std::cout << "Heap: ";
        for (int i = 0; i < size; i++)
            std::cout << " " << heap[i];
        std::cout << std::endl;
    }

private:

    std::vector<El_t> heap;
    int size;

};


template<class T>
class MaxBinHeap {
public:

    MaxBinHeap() : size(0){}
    MaxBinHeap(const std::vector<T>& _heap) : heap(_heap), size(heap.size()) {
        BuildHeap();
    }
    int Parent(int i) const { return (i-1) / 2 ; }
    int LeftChild(int i) const { return 2 * i + 1 ; }
    int RightChild(int i) const { return 2 * i + 2 ; }

    void BuildHeap(){
        for (int i = size/2; i >= 0; --i){
            SiftDown(i);
        }    
    }
    void SiftDown(int i) {
        int maxInd = i;

        int l = LeftChild(i);
        if (l < size && heap[l] > heap[maxInd])
            maxInd = l;

        int r = RightChild(i);
        if (r < size && heap[r] > heap[maxInd])
            maxInd = r;

        if (maxInd != i){
            std::swap(heap[i], heap[maxInd]);
            SiftDown(maxInd);
        }
    }

    void SiftUp(int i) {
        while ( heap[i] > heap[Parent(i)] ){
            std::swap(heap[i], heap[Parent(i)]);
            i = Parent(i);
        }
    }
    void Insert(T newP) {
        if (size == 0)
            heap.resize(10);
        if (size == heap.capacity())
            heap.resize(size*2);
        ++size;
        heap[size-1] = newP;
        SiftUp(size-1);
    }
    T ExtractMax() {
        if (!size)
            throw std::out_of_range("Heap is empty.");
        T max = heap[0];
        heap[0] = heap[--size];
        SiftDown(0);
        return max;
    }
    void Remove(int i) {
        if (!size)
            throw std::out_of_range("Heap is empty.");
        heap[i] = std::numeric_limits<T>::max();
        SiftUp(i);
        ExtractMax();
    }
    void ChangePriority(int i, T newP) {
        if (!size)
            throw std::out_of_range("Heap is empty.");
        T oldP = heap[i];
        heap[i] = newP;
        if (oldP > newP)
            SiftDown(i);
        else
            SiftUp(i);
    }
    void showHeap() const {
        if (!size)
            throw std::out_of_range("Heap is empty.");

        std::cout << "Heap: ";
        for (int i = 0; i < size; ++i)
            std::cout << " " << heap[i];
        std::cout << std::endl;
    }


private:

    std::vector<T> heap;
    int size;
};

void check(){
    int arg1, arg2, add, sub, mul, quo, rem ;

    printf( "Enter two integer numbers : " );
    scanf( "%d%d", &arg1, &arg2 );

    /* Perform Addition, Subtraction, Multiplication & Division */
    // __asm__ ( "addl %%ebx, %%eax" : "=a" (add) : "a" (arg1) , "b" (arg2) );
    // __asm__ ( "subl %%ebx, %%eax" : "=a" (sub) : "a" (arg1) , "b" (arg2) );
    // __asm__ ( "imull %%ebx, %%eax" : "=a" (mul) : "a" (arg1) , "b" (arg2) );

    // __asm__ ( "movl $0x0, %%edx"
    //           "movl %2, %%eax"
    //           "movl %3, %%ebx"
    //            "idivl %%ebx" : "=a" (quo), "=d" (rem) : "g" (arg1), "g" (arg2) );

    printf( "%d + %d = %d\n", arg1, arg2, add );
    printf( "%d - %d = %d\n", arg1, arg2, sub );
    printf( "%d * %d = %d\n", arg1, arg2, mul );
    printf( "%d / %d = %d\n", arg1, arg2, quo );
    printf( "%d %% %d = %d\n", arg1, arg2, rem );
    
}



// struct Computers{
//     Computers(const std::string& _company = "", int DS = 0, int M = 0, double _HZ = 0) : 
//         company(_company), disk_size(DS), memory(M), HZ(_HZ) {}

//     std::string company;
//     int disk_size;
//     int memory;
//     double HZ;
// };

// void Info(const Computers& comp) {
//     std::cout << "\tCompany:\t" << comp.company << std::endl;
//     std::cout << "\tDisk size:\t" << comp.disk_size << std::endl;
//     std::cout << "\tMemory:\t\t" << comp.memory << std::endl;
//     std::cout << "\tHZ:\t\t" << comp.HZ << std::endl;
// }

// class CheckSize{
// public:
//     void operator()(const Computers* comp){
//         if (comp->disk_size > 500)
//             Info(*comp);
//     }
// } checker;

int main(){
    

    // std::vector<Computers*> CompVec;

    // Computers* c1 = new Computers("Micro", 512, 4, 2.4);
    // CompVec.push_back(c1);

    // Computers* c2 = new Computers("Cinema23", 1024, 8, 3.2);
    // CompVec.push_back(c2);

    // Computers* c3 = new Computers("DNW", 1024, 16, 3.2);
    // CompVec.push_back(c3);

    // Computers* c4 = new Computers("SAMSON", 256, 8, 3.2);
    // CompVec.push_back(c4);

    // for (auto& comp : CompVec){
    //     if (comp->company == "DNW")
    //         Info(*comp);
    // }
    // std::cout << std::endl;

    // std::for_each(CompVec.begin(), CompVec.end(), checker);

    return 0;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


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

// void siftDown(int i, std::vector<int>& arr){
//     int maxInd = i;
//     int leftCh = 2*i+1;

//     if(leftCh < arr.size() && arr[leftCh] < arr[maxInd])
//         maxInd = leftCh;

//     int rightCh = 2*i+2;

//     if (rightCh < arr.size() && arr[rightCh] < arr[maxInd])
//         maxInd = rightCh;

//     if (i != maxInd){
//         std::swap(arr[i], arr[maxInd]);
//         siftDown(maxInd, arr);
//     }
// }

// void buildBinHeap(std::vector<int>& arr){
//     for (int i = arr.size()/2; i >= 0; --i){
//         siftDown(i, arr);
//     }
// }