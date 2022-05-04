#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<iterator>
#include<thread>
#include<exception>
#include<execution>
#include<sstream>
#include<unordered_map>

void hello(){
    std::cout << "Hello concurrent world!:)" << std::endl;
}
void hay(){
    using namespace std::chrono_literals;
    hello();
    std::this_thread::sleep_for(3s);
    std::cout << "How you doin?:)" << std::endl;
}

// template<class type, int __size>
// class Vector{
//     public:
//         static_assert(__size > 5, "Error: size have to be bigger than 5!");
// };

struct check{
    int a;
    check(int _a) : a(_a){}
    void operator()() const {
        std::cout << "Hello from operator() " << a << std::endl;
    }
};

void my_terminate_handler(){
    std::cout << "Error, terminate program!" << std::endl;
}

void my_f1(){
    // std::set_terminate(my_terminate_handler);
    throw std::logic_error("error of logic...");
}


// void my_func(){
//     std::cout << "In my func! Throwing..." << std::endl;
//     std::exception_ptr p;
//     try{
//         my_f1();
//     }
//     catch(std::logic_error& err){
//         std::cout << err.what() << std::endl;
//         p = std::current_exception();
//     }
//     std::rethrow_exception(p);
// }


class obj
{
public:
    void hello (const std::string& s, const std::string& s_){
        std::cout << "Hello " << s << " " << s_ << std::endl;
    }
};


int main(){

    


    // std::ostream_iterator<int> s(std::cout, ", ");
    // std::istream_iterator<int> in(std::cin);
    // std::copy(in, std::istream_iterator<int>(), s);


    // std::string str;
    // while (std::getline(std::cin, str) && !str.empty())
    //     std::cout << str << std::endl;

    //  #2
    // std::string word;
    // std::unordered_map<std::string, size_t> map;
    // // ctrl+D for EOF
    // while (std::cin >> word){
    //     std::transform(word.begin(), word.end(), word.begin(),
    //                     [](uint8_t ch) {return std::tolower(ch);});
    //     ++map[word];
    //     std::cout << word << std::endl;
    // }

    // std::vector<std::pair<std::string, size_t>> words_vec(map.begin(), map.end());
    // std::sort(words_vec.begin(), words_vec.end(), [](const std::pair<std::string, size_t>& a,
    //                                                  const std::pair<std::string, size_t>& b)
    //                                                  { return a.second > b.second; });
    
    // for (const auto& word: words_vec)
    //     std::cout << word.first << " " << word.second << std::endl;

    //  #1
    // std::string str;    
    // std::getline(std::cin, str);
    // std::transform(str.begin(), str.end(), str.begin(), [](uint8_t el) -> uint8_t { return std::tolower(el);});
    // std::stringstream ss(str);

    // std::unordered_map<std::string, size_t> map;
    // str.clear();
    // while (std::getline(ss, str, ' ')){
    //     map[str]++;
    // }

    // for(auto it = map.begin(); it != map.end(); ++it){
    //     std::cout << it->first << " " << it->second << std::endl;
    // }

    // std::vector<std::pair<std::string, size_t>> pairs(map.begin(), map.end());
    // for (std::cout << std::endl; auto& el: pairs)
    //     std::cout << el.first << " " << el.second << std::endl;
    
    // std::sort(pairs.begin(), pairs.end(), [](const std::pair<std::string, size_t>& a,
    //                                          const std::pair<std::string, size_t>& b) -> bool {
    //                                             return a.second > b.second;
    //                                         });
    // for (std::cout << std::endl; auto& el: pairs)
    //     std::cout << el.first << " " << el.second << std::endl;




    // std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    // std::for_each(vec.begin(), vec.end(), [](int& x){ std::cout << x << " "; });
    // std::cout << std::endl;
    // std::for_each(std::execution::par, vec.begin(), vec.end(), [](int& x){ x *= 2; });
    // std::for_each(vec.begin(), vec.end(), [](int& x){ std::cout << x << " "; });
    // std::cout << std::endl;

    // std::thread t(hay);
    // t.detach();
    // using namespace std::chrono_literals;
    // std::cout << std::this_thread::get_id() << std::endl;
    // auto st = std::chrono::high_resolution_clock::now();
    // std::this_thread::sleep_for(5000ms);
    // auto end = std::chrono::high_resolution_clock::now();
    // std::cout << "Dur. sleep time: " << (static_cast<std::chrono::duration<double, std::milli>>(end-st)).count() << std::endl;

    // auto f = std::bind(&obj::hello, obj(), std::placeholders::_1, std::placeholders::_2);
    // f("Mark", "David");

    // std::set_terminate([](void)->void{ std::cout << "Error from lambda..." << std::endl; });
    // std::terminate();

    // std::set_terminate(my_terminate_handler);

    // check ch(33);

    // std::thread t(hello);
    // t.join();

    std::cout << "Hello world!" << std::endl;
    
    // std::terminate();

    // try{
    //     my_func();
    // }
    // catch(std::logic_error& err){
    //     std::cout << err.what() << std::endl;
    //     std::cout << "Throwing from catch current..." << std::endl;
    //     // throw std::current_exception();
    // }


    // auto a = static_cast<std::function<void(int)>>([](int a = 10){ std::cout << "HElloo world! and " << a << std::endl; });
    // a(10);

    // std::vector<int> vec {1, 2, 3, 4, 5, 6, 7};
    // std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));



    return 0;
}