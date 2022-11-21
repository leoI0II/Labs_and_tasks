#ifndef ITEM_HPP
#define ITEM_HPP

#include"Entity.hpp"
#include"Weapon.hpp"

class Item : public Entity{
public:
    Item(const Point& point) : position(point) {}
    void SetPoint(const Point& point) override {
        position = point;
    }
    Point GetPoint() const override{
        return position;
    }
    void SetPoint(double x, double y){
        position.SetX(x).SetY(y);
    }
    double GetX() const {
        return position.GetX();
    }
    double GetY() const {
        position.GetY();
    }
    void SetX(double x){
        position.SetX(x);
    }
    void SetY(double y){
        position.SetY(y);
    }

private:
    Point position;
};

class LittleHealthBottle : public Item{
public:
    LittleHealthBottle(const Point& point) : Item(point) {}
    void Interact(Entity* ch) override {
        dynamic_cast<Player*>(ch)->SetHP(20);
    }
private:

};

class Ammo : public Item{
public:
    Ammo(const Point& point) : Item(point) {}
    void Interact(Entity* wp) override {
        dynamic_cast<Weapon*>(wp)->SetQuantity(30);
    }

private:
};

class BigHealthBottle : public Item{
public:
    BigHealthBottle(const Point& point) : Item(point) {}
    void Interact(Entity* ch) override {
        dynamic_cast<Player*>(ch)->SetHP(50);
    }
    
private:

};


#endif ///ITEM_HPP