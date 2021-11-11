#ifndef AMMO_HPP
#define AMMO_HPP

#include"Item.hpp"

class Ammo : public Item {
public:
    Ammo(int xx, int yy, bool st, int _amountAmmo):
        Item(ItemType::Ammo, xx, yy, st), amount(_amountAmmo) {}

    int addToWeapon(){
        return amount;
    }

private:
    int amount;
};



#endif  ////AMMO_HPP