#include<iostream>
#include<string>

class my_cl
{
    std::string name;
    std::string lname;

public:
    my_cl(const std::string &_name, const std::string &_lname) : name(_name), lname(_lname) {;}
    void Name()
    {
        std::cout << name << " " << lname << std::endl;
    }
    my_cl(){
        name = "no name";
        lname = "no lname";
    }
    // ~my_cl();
};

class my_cl_child : public my_cl
{
    bool status;

public:
    my_cl_child(const std::string &_name, const std::string &_lname, bool st) : my_cl(_name, _lname)
    {
        status = true;
    }
    void show()
    {
        Name();
        std::cout << "status: " << status << std::endl;
    }
};


int main()
{

    my_cl b;
    my_cl a("john", "travolta");

    a.Name();
    b.Name();

    my_cl_child aa("dom", "toretto", true);
    aa.show();

    my_cl dd(aa);
    dd.Name();               //вызов конструктора неявного копирования


    return 0;
}


// class stack
// {
//     int *mData;
//     int _top;
//     int capacity;
 
// public:
//     stack(int size);
//     ~stack();
 
//     void push(int);
//     void pop();
//     int top();
 
//     size_t size();
//     bool empty();
//     void extend(int);
// };
 
// stack::stack(int size)
// {
//     mData = new int[size];
//     capacity = size;
//     _top = 0;
// }
 
// stack::~stack() {
//     delete[] mData;
// }

// void stack::push(int x)
// {
//     if (_top == capacity)
//         extend(5);
 
//     mData[_top++] = x;
//     std::cout << "Ok" << std::endl;
// }
 
// void stack::pop()
// {
//     std::cout << top() << std::endl;
//     --_top;
// }
 
// int stack::top()
// {
//     return mData[_top-1];
// }
 
// size_t stack::size() {
//     return _top;
// }
 
// bool stack::empty() {
//     return _top == 0;
// }

// void stack::extend(int n) {
//     capacity += n;
//     int *cpy = new int[capacity];
//     for (int i = 0; i < size(); i++)
//         cpy[i] = mData[i];
//     delete [] mData;
//     mData = cpy;
// }


