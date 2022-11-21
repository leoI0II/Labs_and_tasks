// #pragma once
#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include"Entity.hpp"
#include"FieldGrid.hpp"

class FieldGrid;

class ICharacter : public Entity
{
public:
    virtual ~ICharacter() {}
    virtual void SetHP(int) = 0;
    virtual int GetHP() const = 0;
    virtual void SetSpeed(double) = 0;
    virtual double GetSpeed() const = 0;
    virtual int GetDamage() const = 0;
    //------------------------------------
    virtual void UseItem(ItemType) = 0;
    //------------------------------------
    virtual void SetDirection(MoveDir) = 0;
    virtual MoveDir GetDirection() const = 0;
    // virtual void SetState(State) = 0;
    // virtual State GetState() const = 0;
    //------------------------------------
    virtual void Update(double, FieldGrid&, const float&, const float&) = 0;
    //------------------------------------
    virtual bool InteractionWithGrid(FieldGrid&, double&, double&, const float&, const float&) = 0;
};

#endif //ICHARACTER_HPP