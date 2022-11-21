// #pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include"Entity.hpp"
#include"Bullet.hpp"

class Bullet;

class Weapon : public Entity
{
public:
    Weapon(int initQuantity, Point& start, double BS = 0.015);

    ~Weapon();

    Bullet* reduseMagazine(MoveDir direction);
    void SetPoint(double xx, double yy) override;
    double GetX() const override;
    double GetY() const override;
    void SetX(double newX) override;
    void SetY(double newY) override;

    void SetPoint(const Point& newPos) override;
    Point GetPoint() const override;

    void SetQuantity(int newQ);
    int GetQuantity() const;

    void Interact(Entity*);

private:
    int quantity;
    Point& characterPosition;
    double bulletsSpeed;
    // std::stack<Bullet*> magazine;

};

#endif //WEAPON_HPP