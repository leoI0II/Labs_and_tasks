#ifndef HEALTHITEM_HPP
#define HEALTHITEM_HPP

#include"Item.hpp"

class HealthItem : public Item {
public:
    HealthItem(int x, int y, bool st, int whatsHealSt):
        Item(ItemType::HealthBottle, x, y, st), healthStatus(whatsHealSt) {}
    
    int addHealth(){
        return healthStatus;
    }

private:
    int healthStatus;       // how much heal
};


#endif //HEALTHITEM_HPP