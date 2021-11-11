#include<iostream>
#include<vector>
#include<functional>
#include<sstream>
#include<fstream>

class function{
public:
    virtual double call(double x) = 0;
};

class f1 : public function{
    double a, b;
public:
    f1(double _a, double _b): a(_a), b(_b){}
    inline double call(double x){
        return a * x + b;
    }
};

class f2 : public function{
    double a, b, c;
public:
    f2(double _a, double _b, double _c) : a(_a), b(_b), c(_c){}
    inline double call(double x){
        return a * x * x + b * x + c;
    }
};

class ResPrinter{
private:
    function* func;
    std::reference_wrapper<std::ostream> out = std::ref(std::cout);

public:
    ResPrinter(function* f, std::ostream& _out) : func(f), out(_out){}
    ~ResPrinter(){}

    void calculate(double x){
        out.get() << func->call(x) << std::endl;
    }
    void calculate(std::vector<double> arr_x){
        for (auto& elem: arr_x)
            out.get() << func->call(elem) << std::endl;
    }

    void set(function* new_func){
        func = new_func;
    }
    void set(std::ostream& new_out){
        out = std::ref(new_out);
    }

};

int main(){

    f1 a(3, 4);

    ResPrinter res(&a, std::cout);

    res.calculate(5);    

    std::ofstream fout("test.txt", std::ofstream::out);

    res.set(std::ref(fout));

    res.calculate(2);

    std::stringstream str;
    
    res.set(str);
    res.calculate(2);

    double x;

    str >> x;

    std::cout << x << std::endl;

    return 0;
}