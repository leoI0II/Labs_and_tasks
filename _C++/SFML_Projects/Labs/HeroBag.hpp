#ifndef HEROBAG_HPP
#define HEROBAG_HPP

#include"Object.hpp"
#include<list>
#include<vector>
#include<unordered_map>
#include<memory>

using Bag_t = std::unordered_map<Item, std::vector<std::unique_ptr<Object>>>;

class HeroBag : private Bag_t {
public:
    HeroBag() : Bag_t(3) {
    }
    
    using Bag_t::insert;
    using Bag_t::operator[];
    using Bag_t::size;
    using Bag_t::begin;
    using Bag_t::end;
    using Bag_t::iterator;


    // void insert(std::pair<Item, std::vector<std::unique_ptr<Object>>> p){
    //     bag.insert(p);
    // }

    // std::vector<std::unique_ptr<Object>> at(const Item& i){
    //     return bag[i];
    // }

    
private:
    // std::list<std::unique_ptr<Object>> bag;
    // std::map<ObjType, std::vector<std::unique_ptr<Object>>> bag;
    // Bag_t bag;
};



#endif  ///HEROBAG_HPP