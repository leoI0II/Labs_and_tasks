#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

//1) own int class DONE
// class Int
// {
// private:
//     int data;
// public:
//     Int() : data(0){}
//     Int(int num) : data(num) {}

//     // friend Int operator+(Int& left, Int& right);
//     // friend void operator+=(Int& left, Int& right);
//     // friend void operator++(Int& obj);
    
//     friend Int operator+(Int& left, Int& right){
//         return Int(left.data + right.data);
//     }

//     friend void operator+=(Int& left, Int& right){
//         left.data += right.data;
//         // return left;
//     }

//     friend void operator++(Int& obj){
//         obj.data++;
//         // return obj;
//     }

//     void printData(){
//         cout << data << endl;}
    
//     int getData();

//     Int& operator=(int numd){
//         data = numd;
//         return *this;
//     }

//     // void printThis(){
//     //     cout << this << endl;
//     // }
// };

// int Int::getData(){
//     return data;
// }


// int main()
// {
//     Int a;
//     Int b(5);
//     Int c(12);
//     Int s = b;
//     Int v = b+c;
//     a.printData();
//     b.printData();
//     c.printData();
//     s.printData();
//     v.printData();

//     v += c;
//     v.printData();
    
//     ++b;
//     b.printData();

//     // b++;
//     // b.printData();

//     cout << endl << b.getData() << endl;
//     // cout << b+c << endl;

//     Int d;
//     d = 22;
//     d.printData();



//     // b.printThis();
//     return 0;
// }





// Симулятор турникета для машин на платной автостраде
// class tollBooth
// {
// private:
//     unsigned int countCar;
//     double summaryMoney;

// public:
//     tollBooth() : countCar(0), summaryMoney(0) {}
//     ~tollBooth(){
//         cout << "Destruct" << endl;
//     }

//     void payingCar(){
//         this->countCar++;
//         this->summaryMoney += 0.50;
//         cout << "Added" << endl;
//     }

//     void nopayCar(){
//         this->countCar++;
//         cout << "Pidor" << endl;
//     }

//     void display() const {
//         cout << "total cars passed: " << countCar << "\tmoney paid: " << summaryMoney << "$" << endl;
//     }
// };

// int main(){

//     tollBooth tur;
//     char c;

//     cout << "Нажмите на клавиатуре \"0\" для машины без оплаты,\n" <<
//         "\"1\" для машины с оплатой,\n" <<
//         "или \"Esc\" для выхода из программы и вывода данных!\n" << endl;

//     // while ((int)(c = getchar()) != 27)
//     // {
//     //     switch((int)c){
//     //         case 48:
//     //             tur.nopayCar();
//     //             break;
//     //         case 49:
//     //             tur.payingCar();
//     //             break;
//     //         case 27:
//     //             tur.display();
//     //             exit(0);
//     //     }
//     // }

//     while ((int)(c = getchar()) != 27)
//     {

//         if ((int)c == 49)
//             tur.payingCar();
//         if ((int)c == 48)
//             tur.nopayCar();
//     }

//     tur.display();

//     return 0;
// }


// SUM OF TIMES DONE
// class Time
// {
// private:
//     int sec;
//     int min;
//     int hr;

// public:
//     Time(): sec(0), min(0), hr(0){}
//     Time(int x, int y, int z) : hr(x), min(y), sec(z) {}

//     void displayTime();
//     friend void addTime(const Time& t1, const Time& t2);
//     void _addTime(const Time& t1, const Time& t2);
//     ~Time(){ cout << "Destructor called" << endl;}
// };

// void Time::displayTime()
// {
//     cout << this->hr << ":" << this->min << ":" << this->sec << endl;
// }

// void addTime(const Time& t1, const Time& t2)
// {
//     Time temp;
//     temp.sec += t1.sec + t2.sec;
//     if (temp.sec > 59){
//         temp.sec -= 60;
//         temp.min++;
//     }
//     temp.min += t1.min + t2.min;
//     if (temp.min > 59){
//         temp.min -= 60;
//         temp.hr++;
//     }
//     temp.hr += t1.hr + t2.hr;
//     if (temp.hr > 23)
//         temp.hr -= 24;

//     cout << "Sum of times is " << temp.hr << ":" << temp.min << ":" << temp.sec << endl;
// }

// void Time::_addTime(const Time& t1, const Time& t2)
// {
//     // Time temp;
//     sec = t1.sec + t2.sec;
//     if (sec > 59){
//         sec -= 60;
//         min++;
//     }
//     min += t1.min + t2.min;
//     if (min > 59){
//         min -= 60;
//         hr++;
//     }
//     hr += t1.hr + t2.hr;
//     if (hr > 23)
//         hr -= 24;
    
//     // return temp;
// }


// int main()
// {
//     Time t1(10, 59, 34);
//     Time t2(12, 45, 23);

//     t1.displayTime();
//     t2.displayTime();

//     Time t3;
//     addTime(t1, t2);
//     t3._addTime(t1, t2);
//     t3.displayTime();

//     return 0;
// }




int main()
{

    int arr[5];
    int i =0;
    cout << "arr1: ";
    while (i < 5 && cin >> arr[i]){
        if (++i < 5)
            cout << "arr" << i+1 << " : ";
    }
    for (int j = 0; j < i; j++)
        cout << arr[j] << " ";
    cout << endl;

    return 0;
}