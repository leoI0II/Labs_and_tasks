// #pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include"ICharacter.hpp"
#include"Observable.hpp"

class Character : public ICharacter, public Observable
{
public:
    Character(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Stay);
    ~Character();

    void SetPoint(const Point& point) override;
    void SetPoint(double _x, double _y) override;
    Point GetPoint() const override;
    double GetX() const override;
    double GetY() const override;
    void SetX(double newX) override;
    void SetY(double newY) override;

    void SetHP(int plusHP) override;
    int GetHP() const override;
    void Interact(Entity* probablyEnemyOfThis) override;
    int GetDamage() const override;
    void SetSpeed(double newSp) override;
    double GetSpeed() const override;
    void SetDirection(MoveDir newDir) override;
    MoveDir GetDirection() const override;

private:

    int healthPoints;
    int damage;
    Point position;
    double speed;
    MoveDir moveState;
    // State state;
};

#endif //CHARACTER_HPP