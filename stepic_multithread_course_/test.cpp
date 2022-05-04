#include<iostream>
#include<map>

template<class type>
struct comp{
    inline bool operator()(const type& a, const type& b) const {
        return b < a;
    }
};

int main(){

    std::map<char, int, comp<char>> _map;
    _map['A']++;
    _map['b']++;
    _map['A']++;

    for(auto i = _map.begin(); i != _map.end(); ++i){
        std::cout << i->first << " " << i->second << std::endl;
    }


    return 0;
}