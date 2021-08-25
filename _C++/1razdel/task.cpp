#include<iostream>
#include<stack>
#include<cstring>
struct T
{
    int x, y;
};

class test
{
    public:
        test(int x, int y)
        {
            var.x = x;
            var.y = y;
        }
        test & showX(){
            std::cout << var.x << std::endl;
            return *this;
        }
        test & showY()
        {
            std::cout << var.y << std::endl;
            return *this;                                   //lol, this work
        }
    private:
        T var;
};


// swap for int
void swap(int& a, int& b){
    int tmp = b;
    b = a;
    a = tmp;
}

// swap for char*
void swap(char*& a, char*& b){
    char tmp[20];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}

int main()
{
    using namespace std;

    // int a = 5, b = 10;
    // cout << a << " " << b << endl;
    // swap(a, b);
    // cout << a << " " << b << endl;

    char a[20], b[20];
    cin.getline(a, 20);
    cin.getline(b, 20);

    cout << endl << a << endl;
    cout << b << endl;

    swap(a, b);
    
    cout << endl << a << endl;
    cout << b << endl;



    // char ch;
    // while ((ch = cin.get()) != '.')
    // {
    //     if (ch == '\n')
    //         cout << ch;
    //     else
    //         cout << (ch +=1);
    // }

    // char* str = new char [80];
    // cin.getline(str, 80);

    // cout << "Complete line: " << str;
    // delete [] str;
    

    // int d, c, v;
    // if (cin >> d >> c)
    //     cout << d << c << endl;
    // cin >> v;
    // cout << v;


    // test ff(4, 5);
    // ff.showX().showY();


    // int x =5, y =8;
    // std::cout.operator<<(x).operator<<(" ").operator<<(y);
    // std::cout << x << " " << y << std::endl;



    return 0;
}
