// #pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include"Point.hpp"
enum class MoveDir { Stay, Up, Down, Right, Left };
enum class ItemType { LittleHealthBottle, BigHealthBottle, Ammo };

class Entity
{
public:
    virtual ~Entity() {}
    virtual void SetPoint(const Point&) = 0;
    virtual void SetPoint(double, double) = 0;
    virtual Point GetPoint() const = 0;
    virtual double GetX() const = 0;
    virtual void SetX(double) = 0;
    virtual double GetY() const = 0;
    virtual void SetY(double) = 0;
    virtual void Interact(Entity*) = 0;
};

#endif //ENTITY_HPP