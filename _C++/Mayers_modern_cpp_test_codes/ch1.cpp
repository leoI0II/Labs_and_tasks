#include<iostream>
#include<initializer_list>
#include<vector>
#include<typeinfo>
#include<boost/type_index.hpp>

template<class Container, class Index>
decltype(auto) takeValue(Container&& _cont, Index _index)
{
    return std::forward<Container>(_cont)[_index];                  // std::forward from C++14
}

template<typename T>
void CheckType(const T& _object)
{
    using namespace std;
    using boost::typeindex::type_id_with_cvr;

    cout << "T = " << type_id_with_cvr<T>().pretty_name() << endl;
    cout << "Object = " << type_id_with_cvr<decltype(_object)>().pretty_name()  << endl;
}

bool func(const int& par)
{
    std::cout << par;
    return par;
}

// template<typename T> TD;

int main()
{
    




    // auto lam = func;
    // auto lam = [](const int& par) -> bool { std::cout << par; return par; };
    // std::cout << boost::typeindex::type_id_with_cvr<decltype(lam)>().pretty_name() << std::endl;


    // struct test
    // {
    //     test(){}
    //     int a, b;
    // };

    // CheckType(4);
    // CheckType(test());


    // const int Ans = 42;
    // auto x = Ans;
    // auto y = &Ans;

    // std::cout << typeid(x).name() << " " << typeid(y).name() << std::endl;
    // TD<decltype(x)> xType;
    // TD<decltype(y)> yType;


    // std::vector<int> _vec = {1, 2, 3, 4, 5};
    // auto _val = takeValue(_vec, 2);
    // // doesn't return a ref
    // std::cout << _val << " " << typeid(decltype(_val)).name() << std::endl;
    // _val = 5;
    // // doesn't change
    // std::cout << _val << " " << _vec[2] << std::endl;


    // not_working
    // auto _init_list_val = {1, 2, 3, 4, 5}[2];
    // std::cout << _init_list_val << std::endl;

    return 0;
}