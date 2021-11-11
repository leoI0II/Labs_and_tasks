#ifndef IITEM_HPP
#define IITEM_HPP

// #include"IObject.hpp"
enum class ItemType {HealthBottle, Ammo, Granade};

class IItem {
public:
    virtual ItemType getItemType() const = 0;
    virtual void setItemType(ItemType tp) = 0;
    
    virtual const int getX() = 0;
    virtual const int getY() = 0;
    virtual void setX(int) = 0;
    virtual void setY(int) = 0;

    virtual void setStatusItem(bool st) = 0;
    virtual bool getStatusItem() const = 0;
};

#endif