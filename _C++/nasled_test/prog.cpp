#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<valarray>
#include<cstdlib>
#include<ctime>
using namespace std;

// class TableTennisPlayer{
// private:
//     string first_name;
//     string last_name;
//     bool on_table;
// public:
//     TableTennisPlayer(const string& fn = "none", const string& ln = "none", bool o_t = false) : 
//         first_name(fn), last_name(ln), on_table(o_t) {}

//     void Name() const{
//         cout << first_name << ", " << last_name;
//     }
//     bool HasTable() const { return on_table; }
//     void ResetTable(bool v) { on_table = v; }
// };

// class RatedPlayer : public TableTennisPlayer
// {
// private:
//     uint32_t rating;
// public:
//     RatedPlayer(uint r = 0, const string& fname = "none", const string& ln = "none", bool o_t = false) :
//         TableTennisPlayer(fname, ln, o_t), rating(r) {}
//     RatedPlayer(uint r, const TableTennisPlayer& tp) : TableTennisPlayer(tp) {
//         rating = r;
//     }
//     uint Rating() const { return rating; }
//     void ResetRating(uint r = 0) { rating = r; }
// };

class Brass{
private:
    string name;
    int number_acc;
    int balance;
public:
    Brass(const string& _name = "no name", int num = 0, double _balance = 0)
        : name(_name), number_acc(num), balance(_balance){;}

    void deposit(double amt);
    virtual void withdraw(double amt);
    double Balance() const;
    virtual void viewAcc() const;
    virtual ~Brass(){;}
};

class BrassPlus : public Brass{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const string& _name = "no name", int _num_acc = 0, double _balance = 0.0, double ml = 500, double r = 0.11125);
    BrassPlus(const Brass& refBras, double ml = 500, double r = 0.11125);

    virtual void viewAcc() const;
    virtual void withdraw(double amt);
    void resetMax(double m){ maxLoan = m; }
    void resetRate(double r) { rate = r; }
    void resetOwes() { owesBank = 0; }
};

typedef ios_base::fmtflags format;
typedef streamsize precis;
format setFormat();
void restore(format f, precis p);

void Brass::deposit(double amt){
    if (amt < 0)
        cout << "Error: negative deposit is not allowed!" << endl;
    else
        balance += amt;
}
void Brass::withdraw(double amt){
    format initialState = setFormat();
    precis prec = cout.precision(2);
    if(amt < 0)
        cout << "Error: withdrawal amount must be positive" << endl;
    else if(amt <= balance)
        balance -= amt;
    else
        cout << "Withdrawal amount of $ " << amt << " exceeds your balance!" << endl;
    restore(initialState, prec);
}

double Brass::Balance()const{
    return balance;
}

void Brass::viewAcc() const{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << name << endl;
    cout << "Account number: " << number_acc << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}

BrassPlus::BrassPlus(const string& _name, int _num_acc, double _balance, double ml, double r)
    : Brass(_name, _num_acc, _balance), maxLoan(ml), rate(r) { owesBank = 0;}

BrassPlus::BrassPlus(const Brass& s, double ml, double r) : Brass(s), maxLoan(ml), rate(r) {owesBank = 0;}

void BrassPlus::viewAcc() const{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    Brass::viewAcc();

    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan rate: " << 100 * rate << "%\n";

    restore(initialState, prec);
}

void BrassPlus::withdraw(double amt){
    format initialState = setFormat();
    precis prec = cout.precision(2);
    double bal = Balance();

    if(amt <= bal)
        Brass::withdraw(amt);
    else if(amt <= bal + maxLoan - owesBank){
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        deposit(advance);
        Brass::withdraw(amt);
    }
    else
        cout << "Credit limit exceeded. Transaction cancellled!" << endl;
    restore(initialState, prec);
}

format setFormat(){
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p){
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}


// struct test1{

//     virtual void show() const{
//         cout << "Hello" << endl;
//     }
// };
// struct test2 : public test1{
//     void show() const {
//         cout << " WOrld!" << endl;
//     }
// };


// class som1{
// public:
//     virtual void lol(){
//         cout << "lol" << endl;
//     }
// };
// class som2 : public som1{
// public:
//     void lol(){
//         cout << "LLLOOL" << endl;
//     }
// };
// class som3 : public som2{
// public:
//     void lol(){
//         cout << "WOW" << endl;
//     }
// };

class Fruit{
    int mass;
    int cost;
public:
    Fruit(int _m = 0, int _cost = 0);
    virtual ~Fruit(){;}
    int getMass() const { return mass; }
    int getCost() const { return cost; }
    virtual const string& getID() const = 0;
    virtual void ShowInfo() const = 0;
    friend ostream& operator<<(ostream& os, const Fruit& a);
    friend ostream& operator<<(ostream& os, const Fruit* a);
};

ostream& operator<<(ostream& os, const Fruit& a){
    os << "Mass: " << a.mass << endl;
    os << "Cost: " << a.cost << endl;
    return os;
}
ostream& operator<<(ostream& os, const Fruit* a){
    os << "Mass: " << a->mass << endl;
    os << "Cost: " << a->cost << endl;
    return os;
}

class Banana : public Fruit{
private:
    string ID;
public:
    Banana(int _m = 0, int _cost = 0, const string& _ID = "just a banana");
    virtual ~Banana(){}
    const string& getID() const;
    friend ostream& operator<<(ostream& os, const Banana& a);
    friend ostream& operator<<(ostream& os, const Banana* a);
    void ShowInfo() const{
        // cout << ID << endl;
        // cout << (const Fruit*)this;
        // Fruit::operator<<(cout, *this);
        cout << this;
        // cout << "Bananas are helpful!" << endl << endl;
    }
};

ostream& operator<<(ostream& os, const Banana& a){
    os << a.ID << endl;
    os << (const Fruit&)a;
    // Fruit::operator<<(cout, this);
    os << "Bananas are helpful" << endl;
    return os;
}
ostream& operator<<(ostream& os, const Banana* a){
    os << a->ID << endl;
    os << (const Fruit*)a;
    os << "Bananas are helpful" << endl;
    return os;
}

class sapple: public Fruit{
    string index;
public:
    sapple(int _m = 0, int _cost = 0, const string& _ind = "just an apple");
    virtual ~sapple(){;}
    const string& getID() const;
    friend ostream& operator<<(ostream& os, const sapple& a);
    friend ostream& operator<<(ostream& os, const sapple* a);
    void ShowInfo() const{
        // cout << index << endl;
        // cout << (const Fruit*)this;
        // Fruit::operator<<(cout, this);
        cout << this;
        // cout << "i dont like apple!" << endl << endl;
    }
};

ostream& operator<<(ostream& os, const sapple& a){
    os << a.index << endl;
    os << (const Fruit&)a;
    os << "Apples are good, but not enough like bananas!" << endl;
    return os;
}
ostream& operator<<(ostream& os, const sapple* a){
    os << a->index << endl;
    os << (const Fruit*) a;
    os << "Apples are good, but not enough like bananas!" << endl;
    return os;
}

Fruit::Fruit(int _m, int _cost) : mass(_m), cost(_cost){;}

Banana::Banana(int _m, int _cost, const string& _ID) : Fruit(_m, _cost), ID(_ID){}

const string& Banana::getID() const{ return ID; }

sapple::sapple(int _m, int _cost, const string& _ind) : Fruit(_m, _cost), index(_ind){}
const string& sapple::getID() const { return index; }

void cleanBuffer(){
    while(cin.get() != '\n'){}
}


//runtimme error
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> res(2);
//         nums.sort();
//         int i = 0;
//         int ost = 0;
//         for (i; nums[i] < target; i++);
//         for (int j = 0, k = i-1; ; j++, k--){
//             ost = target - nums[k];
//             if (nums[j] == ost){
//                 res[0] = j;
//                 res[1] = k;
//             }
//         }

//         return res;
//     }
// };


class test{
    int data;
public:
    explicit test(int _d = 0) : data(_d){}
    void show_data(){
        cout << data << endl;
    }
};


class cd{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    cd (const char* s1, const char* s2, int _sel, double _play){
        strcpy(performers, s1);
        strcpy(label, s2);
        selections = _sel;
        playtime = _play;
    }
    cd (const cd & a){
        strcpy(performers, a.performers);
        strcpy(label, a.label);
        selections = a.selections;
        playtime = a.playtime;
    }
    cd (){
        strcpy(performers, "default");
        strcpy(label, "default");
        selections = 0;
        playtime = 0;
    }
    ~cd(){}
    virtual void report() const{
        cout << "Performers: " << performers << endl;
        cout << "Label: " << label << endl;
        cout << "Selections: " << selections << endl;
        cout << "Playtime: " << playtime << endl;
    }
    cd & operator=(const cd& d){
        if (this == &d)
            return *this;
        strcpy(performers, d.performers);
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
        return *this;
    }
};

class Classic: public cd {
private:
    char* main_song;
public:
    Classic(const char* s1, const char* s2, const char* s3, int _sel, double _play) 
        : cd(s1, s2, _sel, _play){
            main_song = new char[strlen(s3) + 1];
            strcpy(main_song, s3);
        }
    Classic(const Classic& a) : cd(a){
        main_song = new char[strlen(a.main_song) + 1];
        strcpy(main_song, a.main_song);
        // cd::cd(a);
    }
    Classic() : cd(){
        main_song = new char[strlen("default")+1];
        strcpy(main_song, "default");
    }
    void report() const{
        cout << "Main song: " << main_song << endl;
        cd::report();
    }
    Classic& operator=(const Classic& s){
        if (this == &s)
            return *this;
        delete [] main_song;
        main_song = new char[strlen(s.main_song) + 1];
        strcpy(main_song, s.main_song);
        cd::operator=(s);
        return *this;
    }

};

void Bravo(const cd& disk){
    disk.report();
}

class Port{
private:
    char* brand;
    char style[20];
    int bottles;
public:
    Port(const char* br = "none", const char* st = "none", int b = 0){
        brand = new char[strlen(br)+1];
        strcpy(brand, br);
        strcpy(style, st);
        bottles = b;
    }
    Port(const Port& p){
        brand = new char[strlen(p.brand)+1];
        strcpy(brand, p.brand);
        strcpy(style, p.style);
        bottles = p.bottles;
    }
    virtual ~Port(){
        delete [] brand;
    }
    Port& operator=(const Port& p){
        if(this == &p)
            return *this;
        delete [] brand;
        brand = new char[strlen(p.brand)+1];
        strcpy(brand, p.brand);
        strcpy(style, p.style);
        bottles = p.bottles;
        return *this;
    }
    Port& operator+=(int b){
        bottles += b;
        return *this;
    }
    Port& operator-=(int b){
        // bottles < b ? continue : bottles -= b;
        if (bottles < b){
            cout << "Nope!" << endl;
            return *this;
        }else
            bottles -= b;
        return *this;
    }
    int BottleCount() const {
        return bottles;
    }
    virtual void Show() const{
        cout << "Brand: " << brand << endl;
        cout << "Kind: " << style << endl;
        cout << "Bottles: " << bottles << endl;
    }
    friend ostream& operator<<(ostream& os, const Port& p);
};

ostream& operator<<(ostream& os, const Port& p){
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

class VintagePort: public Port{
private:
    char* nickname;
    int year;
public:
    VintagePort() : Port("none", "vintage"){
        nickname = new char[strlen("none")+1];
        strcpy(nickname, "none");
        year = 0;
    }
    VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "vintage", b){
        nickname = new char[strlen(nn)+1];
        strcpy(nickname, nn);
        year = y;
    }
    VintagePort(const VintagePort& vp) : Port(vp){
        nickname = new char[strlen(vp.nickname)+1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
    }
    ~VintagePort(){
        delete [] nickname;
    }
    VintagePort& operator=(const VintagePort& vp){
        if(this == &vp)
            return *this;
        Port::operator=(vp);
        delete [] nickname;
        nickname = new char[strlen(vp.nickname)+1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
    }
    void Show() const{
        cout << "Nickname: " << nickname << endl;
        Port::Show();
        cout << "Year: " << year << endl << endl;
    }
    friend ostream& operator<<(ostream& os, VintagePort& vp);
};
ostream& operator<<(ostream& os, VintagePort& vp){
    os << vp.nickname << ", ";
    operator<<(os, (const Port&)vp);
    cout << ", " << vp.year;
    return os;
}


// class Student{
// private:
//     typedef valarray<double> ArrD;
//     string name;
//     ArrD scores;
//     ostream& arr_out(ostream& os) const{
//         int i ;
//         int lim = scores.size();
//         if(lim){
//             for (int i = 0; i < scores.size(); i++){
//                 os << scores[i] << " ";
//                 if (i % 5 == 4)
//                     os << endl;
//             }
//             if (i % 5 != 0)
//                 os << endl;
//         }
//         else
//             os << " empty array" << endl;
//         return os;
//     }
// public:
//     Student(): name("Null Student"), scores(){}
//     explicit Student(const string& _name) : name(_name), scores(){}
//     explicit Student(int n) : name("Nully"), scores(n){}
//     Student(const string& _name, int n) : name(_name), scores(n){}
//     Student(const string& _name, const ArrD& _scores) : name(_name), scores(_scores){}
//     Student(const string& _name, const double* arr, int n) : name(_name), scores(arr, n){}
//     ~Student(){}
//     double Average() const {
//         if (scores.size())
//             return scores.sum()/scores.size();
//         else
//             return 0;
//     }
//     const string& Name() const{
//         return name;
//     }
//     double& operator=(int i){
//         return scores[i];
//     }
//     double operator[](int i) const{
//         return scores[i];
//     }
//     double& operator[](int i){
//         return scores[i];
//     }
    // friend istream& operator>>(istream& is, Student& st);
    // friend istream& getline(istream& is, Student& st);
    // friend  ostream& operator<<(ostream& os, Student& st);
// };
// ostream& operator<<(ostream& os, Student& st){
//     os << "Scores for " << st.name << ":" << endl << "    ";
//     st.arr_out(os);
//     return os;
// }
// istream& operator>>(istream& is, Student& st){
//     is >> st.name;
//     return is;
// }
// istream& getline(istream& is, Student& st){
//     getline(is, st.name);
//     return is;
// }


class Student: private string, private valarray<double>{
    typedef valarray<double> ArrD;
    std::ostream& arr_out(ostream& os) const{
        int i;
        int lim = ArrD::size();
        if(lim){
            for (int i = 0; i < lim; i++){
                os << ArrD::operator[](i) << " ";
                if (i % 5 == 4)
                    os << endl;
            }
            if (i % 5 == 0)
                os << endl;
        }
        else
            os << " empty array";
        return os;
    }
public:
    Student(): string("Nully"), ArrD(){}
    explicit Student(const char* _n): string(_n), ArrD(){}
    explicit Student(int n): string("Nully"), ArrD(n){}
    Student(const char* _n, int n): string(_n), ArrD(n){}
    Student(const string& a, ArrD& b) : string(a), ArrD(b){}
    Student(const string& a, int n): string(a), ArrD(n){}
    Student(const char* _n, const double* pd, int n): string(_n), ArrD(pd, n){}
    ~Student(){}
    using std::string::size;

    double Average() const{
        if (ArrD::size() > 0)
            return ArrD::sum()/ArrD::size();
        else
            return 0;
    }
    double operator[](int i) const{
        return ArrD::operator[](i);
    }
    double& operator[](int i){
        return ArrD::operator[](i);
    }
    const string& Name() const{
        return (const string&) *this;
    }
    friend istream& operator>>(istream& is, Student& st);
    friend istream& getline(istream& is, Student& st);
    friend ostream& operator<<(ostream& os, Student& st);
};
ostream& operator<<(ostream& os, Student& st){
    os << "Scores for " << (const string&) st << ":" << endl;
    st.arr_out(os);
    return os;
}
istream& getline(istream& is, Student& st){
    getline(is, (string&)st);
    return is;
}
istream& operator>>(istream& is, Student& st){
    is >> (string&)st;
    return is;
}


void set(Student& st, int n){
    cout << "Enter the Students name: ";
    getline(cin, st);
    cout << "Please, enter " << n << " quiz scores: " << endl;
    for (int i = 0; i < n; i++)
        cin >> st[i];
    while(cin.get() != '\n')
        continue;
}
const int pupils = 3;
const int quizzes = 5;


class worker{
private:
    string full_name;
    long id;
protected:
    virtual void data() const;
    virtual void get();
public:
    worker() : full_name("no name"), id(0L){}
    worker(const string& s, long n) : full_name(s), id(n){}
    virtual ~worker() = 0;
    virtual void set() = 0;
    virtual void show() const = 0;
};
void worker::data() const{
    cout << "Name: " << full_name << endl;
    cout << "Employee ID: " << id << endl;
}
void worker::get(){
    // cout << "Enter workers name: ";
    getline(cin, full_name);
    cout << "Enter workers id: ";
    cin >>id;
    while(cin.get() != '\n') continue;
}

worker::~worker(){}

// void worker::set(){
//     cout << "Workers name: ";
//     getline(cin, full_name);
//     cout << "Enter workers ID: ";
//     cin >> id;
//     while (cin.get() != '\n') continue;
// }
// void worker::show() const {
//     cout << "Name: " << full_name << endl;
//     cout << "Employee ID: " << id << endl << endl;
// }

class waiter: virtual public worker{
private:
    int panache;
protected:
    void data() const;
    void get();
public:
    waiter(): worker(), panache(0){}
    waiter(const string& s, long n, int p = 0): worker(s, n), panache(p){}
    waiter(const worker& wk, int p = 0) : worker(wk), panache(p){}
    void set();
    void show() const;
};

void waiter::set(){
    // worker::set();
    cout << "Enter waiters name: ";
    worker::get();
    get();
    // cout << "Enter waiters panache rating: ";
    // cin >> panache;
    // while (cin.get() != '\n') continue;
}
void waiter::show() const {
    cout << "Category: waiter" << endl;
    worker::data();
    // cout << "Panache rainting: " << panache << endl << endl;
    data();
}
void waiter::data()const{
    cout << "Panache rainting: " << panache << endl;
}
void waiter::get(){
    cout << "Enter waiter panache rating: ";
    cin >> panache;
    while(cin.get() != '\n') continue;
}

class singer: virtual public worker{
protected:
    enum{other, alto, contralto, soprano, bass, baritone, tenor};
    enum{Vtypes = 7};
    void data() const;
    void get();
private:
    static char* pv[Vtypes];
    int voice;
public:
    singer(): worker(), voice(other){}
    singer(const string& s, long n, int v = other): worker(s, n), voice(v){}
    singer(const worker& wk, int v = other): worker(wk), voice(v){}
    void set();
    void show() const;
};

char* singer::pv[singer::Vtypes] = {"other" , "alto", "contralto", "soprano", "bass", "baritone", "tenor"};
void singer::get(){
    cout << "Enter number for singers vocal range: " << endl;
    int i = 0;
    for (i; i < Vtypes; i++){
        cout << i << ": " << pv[i] << " ";
        if (i % 4 == 3)
            cout << endl;
    }
    if(i %4 == 0)
        cout << endl;
    while((cin >> voice) && (voice < 0 || voice >= Vtypes))
        cout << "Please, enter a value >= 0 and <" << Vtypes << endl;
    while(cin.get() != '\n') continue;
}
void singer::set(){
    cout << "Enter singers name: ";
    worker::get();
    get();
}
void singer::show() const{
    cout << "Category: singer" << endl;
    worker::data();
    // cout << "Vocal range: " << pv[voice] << endl << endl;
    data();
}
void singer::data() const{
    cout << "Vocal range: " << pv[voice] << endl;
}

class singing_waiter: public singer, public waiter{
protected:
    void data() const;
    void get();
public:
    singing_waiter(){}
    singing_waiter(const string& s, long n, int p = 0, int v = other):
        worker(s, n), waiter(s, n, p), singer(s, n, v){}
    singing_waiter(const worker& wk, int p = 0, int v = other):
        worker(wk), waiter(wk, p), singer(wk, v){}
    singing_waiter(const waiter& wt, int v = other): worker(wt), waiter(wt), singer(wt, v){}
    singing_waiter(const singer& ws, int p = 0): worker(ws), waiter(ws, p), singer(ws){}
    void set();
    void show() const;
};

void singing_waiter::data() const{
    singer::data();
    waiter::data();
}
void singing_waiter::get(){
    waiter::get();
    singer::get();
}
void singing_waiter::set(){
    cout << "Enter singing waiters name: ";
    worker::get();
    get();
}
void singing_waiter::show() const{
    cout << "Category: singing waiter" << endl;
    worker::data();
    data();
}



class sss{
    int data;
public:
    sss(int _d = 0): data(_d){}
    int& get_data(){
        return data;
    }
    void set_data(){
        cout << "Enter data: ";
        cin >> this->get_data();
        while(cin.get() != '\n') continue;
    }
};

// const int SIZE = 5;


template<class Type>
class stack{
private:
    enum{SIZE = 10};
    int stack_size;
    Type* items;
    int top;
public:
    explicit stack(int ss = SIZE);
    stack(const stack& st);
    ~stack(){ delete [] items; }
    bool isempty() { return top == 0; }
    bool isfull() { return top == stack_size; }
    bool push(const Type& item);
    bool pop(Type& item);
    stack& operator=(const stack& st);
};

template<class Type>
stack<Type>::stack(int ss): stack_size(ss), items(new Type[stack_size]), top(0) {}

template<class Type>
stack<Type>::stack(const stack& st){
    stack_size = st.stack_size;
    items = new Type[stack_size];
    for (int i = 0; i < stack_size; i++)
        items[i] = st.items[i];
    top = st.top;
}

template<class Type>
stack<Type>& stack<Type>::operator=(const stack& st){
    if(this == &st)
        return *this;
    delete [] items;
    stack_size = st.stack_size;
    items = new Type[stack_size];
    top = st.top;
    for (int i = 0; i < stack_size; i++)
        items[i] = st.items[i];
    return *this;
}

template<class Type>
bool stack<Type>::push(const Type& item){
    if(top < stack_size){
        items[top++] = item;
        return true;
    }else
        return false;
}

template<class Type>
bool stack<Type>::pop(Type& item){
    if(top > 0){
        item = items[--top];
        return true;
    }else
        return false;
}


template<class T, int n>
class array_tp{
private:
    T arr[n];
public:
    array_tp(){};
    explicit array_tp(const T& v);
    virtual T& operator[](int i);
    virtual T operator[](int i) const;
};
template<class T, int n>
array_tp<T, n>::array_tp(const T& v){
    for (int i = 0; i < n; i++)
        arr[i] = v;
}
template<class T, int n>
T& array_tp<T, n>::operator[](int i){
    if(i < 0 && i >= n){
        cerr << "Error in array limits: " << i << " is out of range!" << endl;
        exit(EXIT_FAILURE);
    }
    return arr[i];
}
template<class T, int n>
T array_tp<T, n>::operator[](int i) const {
    if(i < 0 && i >= n){
        cerr << "Error in array limits: " << i << " is out of range!" << endl;
        exit(EXIT_FAILURE);
    }
    return arr[i];
}


template<class T1, class T2>
class Pair{
    T1 a;
    T2 b;
public:
    Pair(int s = 0): a(s), b(s){}
    Pair(const T1& a_val, const T2& b_val) : a(a_val), b(b_val){}
    T1& first(){
        return a;
    }
    T2& second(){
        return b;
    }
    T1 first() const{
        return a;
    }
    T2 second() const{
        return b;
    }
};


template<class T>
class dd{
    static int ct;
    T item;
public:
    dd(T _item): item(_item){ ct++; }
    ~dd(){ ct--; }
    friend void count();
    friend void report(dd<T> & d);

};
template<class T>
int dd<T>::ct = 0;

void count(){
    cout << "Counts: int " << dd<int>::ct << " double " << dd<double>::ct << endl;
}

// template<class T>
void report(dd<int> & d){
    cout << "Report int: " << d.item << endl;
}

void report(dd<double> & d){
    cout << "Report int: " << d.item << endl;
}


// template<class T, int n>
// class ww<T, T, n>{
//     T a;
//     T b;
//     double nn;
// public:
//     ww(const T& _a, const T& _b): a(_a), b(_b), nn(n){}
//     void show() const{
//         cout << a << " " << b << " " << n << endl;
//     }
// };

// class Frabjous{
//     char fab[20];
// public:
//     Frabjous(const char* s = "C++"): fab(s){}
//     virtual void tell(){ cout << fab << endl; }
// };
// class Gloam{
//     int glip;
//     Frabjous fb;
// public:
//     Gloam(int g = 0, const char* s = "C++") : glip(g), fb(s){}
//     Gloam(int g, const Frabjous& f): glip(g), fb(f){}
//     void tell(){
//         cout << glip << endl;
//         fb.tell();
//     }
// };

class Wine{
private:
    string name;
    int count;
    Pair<valarray<int>, valarray<int>> datas;
public:
    Wine(const char* l, int y, const int yr[], const int bot[]): name(l), count(y), datas(valarray<int>(yr, y), valarray<int>(bot, y)){}
    Wine(const char* l = "no name", int y = 0): name(l), count(y), datas(y){}
    const string& Label() const{
        return name;
    }
    int sum() const{
        return datas.second().sum();
    }

    void Show() const{
        cout << "Wine name:\t" << name << endl;
        cout << "\tYears\t\tBottles" << endl;
        for(int i = 0; i < count; i++)
            cout << "\t" << datas.first()[i] << "\t\t" << datas.second()[i] << endl;
    }

    void GetBottles(){
        cout << "Enter " << name << " data for " << count << " year(s): ";
        for (int i = 0; i < count; i++){
            cout << "Enter year: ";
            cin >> datas.first()[i];
            cout << "Enter bottles for that year: ";
            cin >> datas.second()[i];
        }
    }
};





int main()
{

    {

    }




    {
        // cout << "Enter the name of the wine: ";
        // char lab[50];
        // cin.getline(lab, 50);

        // cout << "Enter number of years: ";
        // int years;
        // cin >> years;

        // Wine holding(lab, years);

        // holding.GetBottles();
        // holding.Show();

        // const int YRS = 3;

        // int y[YRS] = {1993, 1995, 1998};
        // int b[YRS] = {48, 60, 72};

        // Wine more("Gushing Grape Red", YRS, y, b);
        // more.Show();
        // cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;
        // cout << "BYE!" << endl;


        // int b[] = {20, 21 ,43, 41};
        // int y[] = {1923, 1945, 1978, 1983};
        // Wine a("Lamber Mamber", 4, y, b);
        // a.Show();
        // cout << a.sum() << endl;

        // int * aa = new int[5];
        // for (int i = 0; i < 5; i++)
        //     aa[i] = i;
        // valarray<int> a(aa, 5);
        // cout << a.sum() << endl;

        // char d[20] = "Hello";
        // cout << d << endl;
    }

    {
        // dd<int> s1(20);
        // dd<double> s2(32.5);
        // dd<int> s3(321);

        // count();
        // report(s1);
        // report(s2);
    }
    {
        // Pair<string, int> ratings[4] = {
        //     Pair<string, int>("The purpled duck", 5),
        //     Pair<string, int>("Jacke fresco", 7),
        //     Pair<string, int>("Cafe shuffle", 4),
        //     Pair<string, int>("Bertiees eats", 3)
        // };

        // int joints = sizeof(ratings) / sizeof(pair<string, int>);

        // cout << "Ratins:\tEatery\n";
        // for(int i = 0; i < joints; i++){
        //     cout << ratings[i].second() << ":\t" << ratings[i].first() << endl;
        // }

        // cout << "OOPS, revised rating" << endl;
        // ratings[3].first() = "Berties Fat Eat";
        // ratings[3].second() = 6;
        // cout << ratings[3].second() << ":\t" << ratings[3].first() << endl;
    }


    {
        // srand(time(0));
        // cout << "Please, enter stack size: ";
        // int ss;
        // cin >> ss;

        // stack<const char*> st(ss);

        // const char* in[10] = {
        //     " 1: Bill Gates", " 2: Steve Jobs", " 3: Elon Musk", " 4: Jeff Bezos",
        //     " 5: Steven Prata", " 6: Gerberdt Shieldt", " 7: Steve Voznyak",
        //     " 8: Richard Hendrics", " 9: Erlich Bachman", " 10: Dinesh Chucktai"
        // };

        // const char* out[10];
        // int processed = 0;
        // int nextin = 0;
        // while (processed < 10){
        //     if (st.isempty())
        //         st.push(in[nextin++]);
        //     else if (st.isfull())
        //         st.pop(out[processed++]);
        //     else if (rand() % 2 && nextin < 10)
        //         st.push(in[nextin++]);
        //     else
        //         st.pop(out[processed++]);
        // }
        // for (int i = 0; i < 10; i++)
        //     cout << out[i] << endl;
        // cout << "BUE" << endl;
        // return 0;
    }



    {
        // stack<string> st;
        // char ch;
        // string po;

        // cout << "Please enter A to add a purchase order, " << endl << "P to process a PO, or Q to quit." << endl;
        // while(cin >> ch && toupper(ch) != 'Q'){
        //     while(cin.get() != '\n') continue;
        //     if(!isalpha(ch)){
        //         cout << '\a';
        //         continue;
        //     }
        //     switch(ch){
        //         case 'A':
        //         case 'a':
        //             {
        //                 cout << "Enter a PO number to add: ";
        //                 cin >> po;
        //                 if(st.isfull())
        //                     cout << "stack already full." << endl;
        //                 else
        //                     st.push(po);
        //             }break;
        //         case 'P':
        //         case 'p':
        //             {
        //                 if (st.isempty())
        //                     cout << "Stack already empty" << endl;
        //                 else{
        //                     st.pop(po);
        //                     cout << "PO #" << po << " popped!" << endl;
        //                 }
        //             }break;
        //     }
        //     cout << "Please enter A to add a purchase order, " << endl << "P to process a PO, or Q to quit." << endl;
        // }
        // cout << "BYE!" << endl;
        // return 0;
    }
    {
        // worker * lolas[SIZE];
        // int ct;
        // for (ct = 0; ct < SIZE; ct++){
        //     char choice;
        //     cout << "Enter the employee category: " << endl << "w: waiter" << endl <<
        //         "s: singer" << endl << "t: singing waiter" << endl << "q: quit" << endl;
        //     cin >> choice;
        //     while (strchr("wstq", choice) == NULL){
        //         cout << "Please enter a w, s, t, or q for quit: ";
        //         cin >> choice;
        //     }
        //     if (choice == 'q')
        //         break;
        //     switch(choice){
        //         case 'w':
        //             lolas[ct] = new waiter;
        //             break;
        //         case 's':
        //             lolas[ct] = new singer;
        //             break;
        //         case 't':
        //             lolas[ct] = new singing_waiter;
        //             break;
        //     }
        //     cin.get();
        //     lolas[ct]->set();
        // }
        // cout << endl << "Here is ur staff:" << endl;
        // int i = 0;
        // for (i; i < ct; i++){
        //     cout << endl;
        //     lolas[i]->show();
        // }
        // for (i = 0; i < ct; i++){
        //     delete lolas[i];
        // }
        // cout << "BYE)" << endl;
        // return 0;
    }

    // sss a(10);
    // cout << a.get_data() << endl;
    // a.set_data();
    // cout << a.get_data() << endl;

    {
        // waiter bob("Bob Apple", 314, 5);
        // singer bev("Beverly Hills", 522, 3);
        // waiter w_temp;
        // singer s_temp;
        // worker* pw[4] = {&bob, &bev, &w_temp, &s_temp};
        // int i = 0;
        // for (i = 2; i < 4; i++){
        //     pw[i]->set();
        // }
        // for (i = 0; i < 4; i++){
        //     pw[i]->show();
        //     cout << endl;
        // }
    }


    {
        // Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
        // int i;
        // for (i = 0; i < pupils; i++)
        //     set(ada[i], quizzes);

        // cout << endl << "Students List: " << endl;
        // for (i = 0; i < pupils; i++)
        //     cout << ada[i].Name() << endl;
        // cout << endl << "Results: " << endl;
        // for (i = 0; i < pupils; i++)
        //     cout << ada[i] << "average: " << ada[i].Average() << endl << endl;
        // cout << "Done." << endl;
        // return 0;
    }

    // int d[5] = {1, 2, 3, 4, 5};
    // valarray<int> dd(d, 3);
    // cout << dd.size() << endl << dd.max() << endl << dd.min() << endl << dd.sum() << endl;

    // done
    {
        // cd c1("Beatles", "Capitol", 14, 35.5);
        // Classic c2 = Classic("Piano sonata in B flat, Fantasia in C", "Alfred Blendel", "Philips", 2, 57.17);
        // cd* pcd = &c1;

        // cout << "Using object directly: " << endl;
        // c1.report();
        // c2.report();

        // cout << "Using type cd* pointer to object: " << endl;
        // pcd->report();
        // pcd = &c2;
        // pcd->report();

        // cout << "Calling a function with a cd reference argument: " << endl;
        // Bravo(c1);
        // Bravo(c2);

        // cout << "Testing assignment: " << endl;
        // Classic copy;
        // copy = c2;
        // copy.report();
    }


    // test a(40);
    // a.show_data();
    // a = test(3.8);
    // a.show_data();

    // sync_with_stdio()

    {
        // int kind;
        // string a;
        // Fruit* fr[3];
        // for (int i = 0; i < 3; i++){
        //     cout << "Enter Banana - 1, Apple - 2: ";
        //     cin >> kind;
        //     cleanBuffer();
        //     cout << "Enter name of fruit: ";
        //     getline(cin, a);
        //     // cleanBuffer();
        //     switch(kind){
        //         case 1:
        //             fr[i] = new Banana(100, 100, a);
        //             break;
        //         case 2:
        //             fr[i] = new sapple(84, 34, a);
        //     }
        // }
        // for (int i = 0; i < 3; i++)
        //     fr[i]->ShowInfo();
        //     // cout << fr[i];
        // for(int i = 0; i < 3; i++)
        //     delete fr[i];
    }

    // som2 a;
    // som3 d;
    // som1* b = &a;
    // som2& c = d;
    // b->lol();
    // c.lol();


    {
        // BrassPlus ddd("Luci mornin", 323828, 12344, 500, 12.12);
        // Brass * hdn = &ddd;
        // Brass &edhe = ddd;
        // hdn->viewAcc();
        // edhe.viewAcc();
    }

    {
        // Brass* clients_mass[4];
        // string temp;

        // long tempNum;
        // double tempBal;
        // char kind;
        // for (int i = 0; i < 4; i++){
        //     cout << "Enter clients name: ";
        //     getline(cin, temp);
        //     cout << "Enter clinets account number: ";
        //     cin >> tempNum;
        //     cout << "Enter opening balance: ";
        //     cin >> tempBal;
        //     while(cin.get() != '\n')
        //         continue;
        //     cout << "Enter 1 for classic Brass account, or 2 for BrassPlus account: ";
        //     while((cin >> kind) && (kind != '1' && kind != '2'))
        //         cout << "You have to enter 1 or 2" << endl << "Try again!" << endl;
        //     if (kind == '1')
        //         clients_mass[i] = new Brass(temp, tempNum, tempBal);
        //     else{
        //         double tmax, trate;
        //         cout << "Enter the overdraft limit: $";
        //         cin >> tmax;
        //         cout << "Enter the interest rate: ";
        //         cin >> trate;
        //         clients_mass[i] = new BrassPlus(temp, tempNum, tempBal, tmax, trate);
        //     }
        //     while (cin.get() != '\n')
        //         continue;
        //     }
        // cout << endl;

        // for (int i = 0; i < 4; i++){
        //     clients_mass[i]->viewAcc();
        //     cout << endl;
        // }

        // for (int i = 0; i < 4; i++)
        //     delete clients_mass[i];
        // cout << "Done!" << endl;
    }

    {
        // TableTennisPlayer player1("Chuck", "Norris", true);
        // TableTennisPlayer player2("Arnie", "Schvarz", false);
        // player1.Name();
        // if(player1.HasTable())
        //     cout << ": has a table." << endl;
        // else
        //     cout << ": has not a table." << endl;
        // player2.Name();
        // if(player2.HasTable())
        //     cout << ": has a table." << endl;
        // else
        //     cout << ": has not a table." << endl;
    }

    {
        // TableTennisPlayer pl1("Tara", "Bombeck", false);
        // RatedPlayer r_pl1(1140, "Mallory", "Duck", true);

        // r_pl1.Name();
        // if(r_pl1.HasTable())
        //     cout << ": has a table." << endl;
        // else
        //     cout << ": has not a table." << endl;

        // pl1.Name();
        // if(pl1.HasTable())
        //     cout << ": has a table." << endl;
        // else
        //     cout << ": has not a table." << endl;

        // cout << "Name: ";
        // r_pl1.Name();
        // cout << "; Rating: " << r_pl1.Rating() << endl;

        // RatedPlayer r_pl2(1212, pl1);
        // cout << "Name: ";
        // r_pl2.Name();
        // cout << "; Rating: " << r_pl2.Rating() << endl;
    }

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


