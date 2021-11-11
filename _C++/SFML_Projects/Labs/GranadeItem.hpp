#ifndef GRANADEITEM_HPP
#define GRANADEITEM_HPP

#include"Item.hpp"

class Granade : public Item {
public:
    Granade(int x, int y, bool st, int whatsDamage):
        Item(ItemType::Granade, x, y, st), granadeDamage(whatsDamage) {}

private:
    int granadeDamage;       // how much heal
};


#endif //GRANADEITEM_HPP