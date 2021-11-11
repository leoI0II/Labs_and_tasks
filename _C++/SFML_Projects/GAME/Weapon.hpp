#ifndef WEAPON_HPP
#define WEAPON_HPP

#include"Entity.hpp"
// #include<stack>
#include"Bullet.hpp"

class Weapon : public Entity {
public:
    Weapon(int initQuantity, const Point& start, double BS = 1) :
        quantity(initQuantity), characterPosition(start), bulletsSpeed(BS) {}
    
    ~Weapon(){}

    Bullet* reduseMagazine(MoveDir direction) {
        if (!quantity) return nullptr;
        quantity--;
        return new Bullet(30, characterPosition, bulletsSpeed, direction);
    }
    void SetPoint(double xx, double yy) override {
        characterPosition.SetX(xx).SetY(yy);
    }
    double GetX() const override {
        return characterPosition.GetX();
    }
    double GetY() const override {
        return characterPosition.GetY();
    }
    void SetX(double newX) override {
        characterPosition.SetX(newX);
    }
    void SetY(double newY) override {
        characterPosition.SetY(newY);
    }

    void SetPoint(const Point& newPos) override {
        characterPosition = newPos;
    }
    Point GetPoint() const override {
        return characterPosition;
    }

    void SetQuantity(int newQ) {
        quantity += newQ;
    }
    int GetQuantity() const { return quantity; }

    void Interact(Entity*) {}

private:
    int quantity;
    Point characterPosition;
    double bulletsSpeed;
    // std::stack<Bullet*> magazine;

};

#endif ///WEAPON_HPP