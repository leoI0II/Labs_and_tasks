#include<stdio.h>
#include<iostream>
using namespace std;
#include<cmath>
#include<cstring>

// class test
// {
//     private:
//         int data;
//     public:
//         void setData(int d){
//             data = d;
//         }
//         void showData(){
//             printf("Data = %d\n", data);
//         }
//         int getData(){
//             return data;
//         }
//         void lol();
// };

// void test::lol(){
//     printf("LOLOLOLOLOLOLOL WORK!");
// }

// int main()
// {
//     test t1, t2;
//     t1.setData(10);
//     t2.setData(t1.getData());
//     t1.showData();
//     t2.showData();
//     t1.lol();
    
//     return 0;
// }




// class foo{
//     private:
//         static int count;
//     public:
//         foo(){
//             count++;
//         }
//         int getcount(){
//             return count;
//         }
// };

// // int foo::count = 0;

// int main(){
//     foo f1, f2;
//     printf("%d\n", f1.getcount());
// }




// class Foo
// {
// private:
//     int x;
//     int y;
// public:
//     Foo() : x(0), y(0) {}
//     Foo(int x, int y) : x(x), y(y) {}
//     void setCoord(){
//         cout << "VVedite znachenia coord: ";
//         // scanf("%d%d", &this->x, &this->y);                  //и так работает
//         // scanf("%d%d", &x, &y);
//         cin >> x >> y;
//     }
//     void showInfo(){
//         printf("ur coord are: %d %d\n", x, y);
//     }
//     void operPlus(Foo& c){
//         x += c.x;
//         y += c.y;
//     }
//     float getDistToCent(){
//         return sqrt(x*x + y*y);
//     }
// };

// int main()
// {
//     Foo c1(5, 4);
//     Foo c2 = c1;
//     Foo c3; c3.setCoord();

//     c1.showInfo();
//     c2.showInfo();
//     c3.showInfo();

//     c2.operPlus(c3);

//     c1.showInfo();
//     c2.showInfo();
//     c3.showInfo();

//     cout << c1.getDistToCent() << endl;
//     return 0;
// }

#include<string>


class Student
{
private:
    char* lName;
    char* fName;
    char dospeh[20];
    string hey;
public:
    void setName(){
        // scanf("%s%s", lName, fName);
        // cin >> lName >> fName;
        lName = (char*) malloc(30 * sizeof(char));
        fName = (char*) malloc(30 * sizeof(char));
        scanf("%s%s", lName, fName);
    }
    void getName(){
        // printf("%s %s\n", lName, fName);
        cout << lName << " " << fName << endl;
    }
    string getHey(){
        return hey;
    }
    Student(){
        // dospeh[] = "drakoniy dospeg";
        strcpy(dospeh, "Draconiy dospeh");
        hey = "HEello";
    }
    void getDospeh(){
        cout << dospeh << endl;
    }
};


int main()
{
    // Student obj1, ob2;
    // obj1.setName();
    // ob2.setName();

    // obj1.getName();
    // ob2.getName();

    // Student arrObj[2];
    // for (int i = 0; i < 2; i++)
    //     arrObj[i].setName();

    // for (int i = 0; i < 2; i++)
    //     arrObj[i].getName();


    Student l;
    l.setName();
    l.getName();
    l.getDospeh();
    cout << l.getHey().size() << endl;
    // cout << typeid(l).name() << endl;
    


    return 0;
}