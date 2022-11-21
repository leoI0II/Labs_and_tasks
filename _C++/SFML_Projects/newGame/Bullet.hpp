// #pragma once
#ifndef BULLET_HPP
#define BULLET_HPP

#include"Entity.hpp"
#include"Character.hpp"
#include"FieldGrid.hpp"
// #include"Enemy.hpp"

class FieldGrid;

class Bullet : public Entity {
public:
    Bullet(int dmg, const Point& bulletPos, double speed, MoveDir MD);

    void SetPoint(const Point& point) override;
    void SetPoint(double xx, double yy) override;
    Point GetPoint() const override;
    double GetX() const override;
    double GetY() const override;
    void SetX(double newX) override;
    void SetY(double newY) override;

    void SetDamage(int newDmg);
    int GetDamage() const;

    void Interact(Entity* enemyMaybe);
    void SetBulletSpeed(double newSpeed);
    double GetBulletSpeed() const;

    bool Update(double time, FieldGrid& grid);

    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy);

private:
    int damage;
    Point position;
    double bulletSpeed;
    MoveDir flyingDirection;
};

#endif //BULLET_HPP