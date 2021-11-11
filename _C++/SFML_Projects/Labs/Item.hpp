#ifndef ITEM_HPP
#define ITEM_HPP

#include"IItem.hpp"

class Item : public IItem {
public:
    Item(ItemType it, int xx, int yy, bool st) :
        item(it), x(xx), y(yy), status(st) {}

    virtual const int getX(){
        return x;
    }
    virtual const int getY(){
        return y;
    }
    virtual void setX(int xx){
        x = xx;
    }
    virtual void setY(int yy){
        y = yy;
    }

    ItemType getItemType() const{
        return item;
    }
    void setItemType(ItemType tp){
        item = tp;
    }

    virtual void setStatusItem(bool whatsStatus){
        status = whatsStatus;
    }
    virtual bool getStatusItem() const{
        return status;
    }



private:
    ItemType item;
    int x;
    int y;
    bool status;            //true - on the field, false - in the player bag
};


#endif