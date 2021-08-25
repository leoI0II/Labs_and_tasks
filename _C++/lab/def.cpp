#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>

// template<typename T>
// T* my_realloc(T* src, size_t old_size, size_t new_size){
//     // if (old_size <= 0){
//     //     T* new_src = new T[new_size];
//     //     src = new_src;
//     //     return src;
//     // }

//     // T* new_src = new T[new_size];

//     // for (int i = 0; i < old_size; i++)
//     //     new_src[i] = src[i];

//     // delete [] src;
//     // src = new_src;
//     // return src;

//     T* new_src = new T[new_size];
//     delete [] src;
//     src = new_src;
//     return src;
// }

// class Cat{
//     std::string name;
//     int age;
// public:

//     Cat(std::string _name, int _age) : name(_name), age(_age) {}
//     Cat() : name(""), age(0) {}

// };

// template<class T>
// class Array{
//     T* arr;
//     int count;
//     int size;
    
// public:
//     Array(){
//         size = 10;
//         count = 0;
//         arr = new T[size];
//     }
//     Array(int _size){
//         size = _size;
//         count = 0;
//         arr = new T[size];
//     }

//     void push_back(T& item){
//         if (count == size){
//             size += 10;
//             arr = my_realloc<T>(arr, count, size);
//         }
//         arr[count] = item;
//         ++count;
//     }
//     void pop_back(){
//         --count;
//     }
//     T get(size_t index){
//         return arr[index];
//     }
//     int index(T item){
//         for (int i = 0; i < count; i++)
//             if (arr[i] == item)
//                 return i;
//         return -1;
//     }

// };

struct Point {
	int x;
	int y;
};

class Circle{
    Point centre;
    double radius;

public:
    Circle(Point& a, double rad){
        centre.x = a.x;
        centre.y = a.y;
        radius = rad;
    }

    void calcDistance(Circle &cir){
        // int dx = abs(centre.x - cir.centre.x);
        // int dy = abs(centre.y - cir.centre.y);
        // double dist = std::sqrt(dx * dx + dy * dy);
        // dist = int(dist*10 + 0.5)/10.0;
        // return dist;

        std::cout << "Hello world bro" << std::endl;
    }
};

class Sector : Circle{
    int angle;

public:

    Sector(Point& a, double rad, int ag) : Circle(a, rad){
        angle = ag;
    }

    void calcDistance(Sector &sek){
        std::cout << "Hello" << std::endl;
    }

};


int main(){
    Point aa = {10, 10}, bb = {20, 20};

    Circle a(aa, 10), b(bb, 10);

    // std::cout << a.calcDistance(b) << std::endl;
    a.calcDistance(b);

    Sector aaa(aa, 10, 30), bbb(bb, 10, 30);

    // std::cout << aaa.calcDistance(bbb) << std::endl;
    aaa.calcDistance(bbb);
    
    
    


    return 0;
}



