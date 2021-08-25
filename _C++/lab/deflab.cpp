#include <iostream>
#include <string>
#include<cstdlib>
#include<cmath>
using namespace std;
// class Student
// {
//     int lect;
//     int kr;
//     int labs;

// public:
//     Student(int a , int b, int c) : lect(a), kr(b), labs(c) {;}

//     void evaluate(){
//         int sum = lect + kr + labs;

//         if (sum < 15) std::cout << "Неудовлетворительно" << std::endl;
//         if (sum >= 15 && sum < 28) std::cout << "Удовлетворительно" << std::endl;
//         if (sum >= 28 && sum < 33) std::cout << "Хорошо" << std::endl;
//         if (sum >= 33) std::cout << "Отлично" << std::endl;
//     }
// };

// int main()
// {
//     int a = 4, b = 13, c = 7;
//     Student s(a, b, c);

//     s.evaluate();

// }


// template<typename MyType>
// class Queue
// {
//     MyType *arr;
//     int count;
//     int _size;

// public:

//     Queue(){
//         _size = 5;
//         arr = new MyType[_size];
//         count = 0;
//     }

//     void push(MyType val){
//         if (count == _size){
//             _size += 5;
//             MyType *cpy_arr = new MyType[_size];
//             for (int i = 0; i < count; i++)
//                 cpy_arr[i] = arr[i];
//             delete [] arr;
//             arr = cpy_arr;
//         }
//         arr[count++] = val;
//     }

//     void pop(){
//         if (count == 0)
//             return;
//         for (int i = 0; i < count-1; i++)
//             arr[i] = arr[i+1];
//         --count;
//     }

//     void pr(){
//         if (count == 0){
//             std::cout << "No elem in queue" << std::endl;
//             return;
//         }
//         for (int i = 0; i < count; i++)
//             std::cout << arr[i] << " ";
//         std::cout << std::endl;
//     }

//     MyType front(){
//         if (count == 0){
//             std::cout << "No elem in queue" << std::endl;
//             return 0;
//         }
//         return arr[0];
//     }

//     bool empty(){
//         return count == 0;
//     }

// };


// int main(){

//     Queue<int> q;

//     q.push('1');
//     q.push('f');
//     q.push('g');
//     q.push('b');
//     q.push('c');
//     q.push('v');
//     q.pr();

//     std::cout << q.front() << std::endl;

//     q.pop();
//     q.pop();
//     q.pr();
//     std::cout << q.front() << std::endl;
//     std::cout << q.empty() << std::endl;

//     q.pop();
//     q.pop();
//     q.pop();
//     q.pop();
//     q.pr();
//     std::cout << q.empty() << std::endl;

//     return 0;
// }


template <typename T>
T* my_realloc(T* src, size_t old_size, size_t new_size){
    T* new_src = new T[new_size];

    for (int i = 0; i < old_size; i++)
        new_src[i] = src[i];
    
    delete [] src;
    src = new_src;
    return src;
}

class Cat{
public:
    Cat(string _name, int _age) : name(_name), age(_age){}
    Cat() : name(""), age(0){}
    string name;
    int age;

};

template<typename Type>
class Array{
    Type *data;
    int size;
    int count;

public:
    Array(){
        size = 10;
        count = 0;
        data = new Type[size];
    }

    void push_back(Type& item){
        if (count == size){
            size += 10;
            data = my_realloc<Type>(data, count, size);
        }
        data[count] = item;
        ++count;
    }

    void pop_back(){
        --count;
    }

    Type get(size_t index){
        return data[index];
    }

    int index(Type item){
        int ret = -1;
        for (int i = 0; i < count; i++)
            if (data[i] == item)
                ret = i;
        return ret;
    }

};

template<class TYPE>
TYPE round(TYPE t,int prec)
{
    for(int i=0;i<prec;i++)
        t*=10;
    int n=(int)t;
    if(t-n>=0.5)
       n++;
    t=n;
    for(int i=0;i<prec;i++)
        t/=10;
    return t;
}


struct Point{
    int x, y;
};

class Circle{

    Point centre;
    double radius;
public:
    Circle(int x, int y, double rad){
        centre.x = x;
        centre.y = y;
        radius = rad;
    }

    Circle(){
        centre.x = 0;
        centre.y = 0;
        radius = 10;
    }
    
    double calcDistance(Circle& cir){
        int dx = abs(centre.x - cir.centre.x);
        int dy = abs(centre.y - cir.centre.y);
        double dist = std::sqrt(dx * dx + dy * dy);
        dist = int(dist* 10 + 0.5)/10.0;
        return dist;
    }
};

class Sector : public Circle
{
    int angle;

public:
    Sector() : Circle(){
        angle = 0;
    }
    
    Sector(int x, int y, double rad, int an) : Circle(x, y, rad){
        angle = an;
    }

};



int main(){

    // Circle x(10, 10, 20), xx(20, 20, 20);

    // cout << x.calcDistance(xx) << endl;

    // Sector z(10, 10, 20, 30), zz(30, 30, 20, 30);

    // cout << z.calcDistance(zz) << endl;


    // int *a = new int[20];
    // for (int i = 0; i < 20; i++)
    //     a[i] = i;

    // for (int i = 0; i < 20; i++)
    //     std::cout << a[i] << std::endl;

    // a = my_realloc<int>(a, 20, 40);

    // for (int i = 20; i < 40; i++)
    //     a[i] = i;
    
    // for (int i = 0; i < 40; i++)
    //     std::cout << a[i] << std::endl;

    // Cat v("borsik", 10);
    // cout << v.name << " " << v.age << endl;

    // Cat *aa = new Cat[5];

    // for (int i = 0; i < 5; i++){
    //     cin >> aa[i].name >> aa[i].age;
    // }
    // for (int i = 0; i < 5; i++){
    //     cout << aa[i].name << " " << aa[i].age << endl;
    // }
    // cout << endl;

    // aa = my_realloc<Cat>(aa, 5, 10);

    // for (int i = 5; i < 10; i++){
    //     cin >> aa[i].name >> aa[i].age;
    // }
    // cout << endl;
    // for (int i = 0; i < 10; i++){
    //     cout << aa[i].name << " " << aa[i].age << endl;
    // }

    Array<int> arr;

    for (int i = 0; i < 10; i++)
        arr.push_back(i);
    
    for (int i = 0; i < 10; i++)
        cout << arr.get(i) << endl;

    for (int i = 10; i < 20; i++)
        arr.push_back(i);
    
    for (int i = 0; i < 20; i++)
        cout << arr.get(i) << endl;




    return 0;
}