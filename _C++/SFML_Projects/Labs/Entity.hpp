#ifndef ENTITY_HPP
#define ENTITY_HPP

#include"IEntity.hpp"
#include<SFML/Graphics.hpp>

enum class MoveDirect {Left, Right, Up, Down, Stay};

class Entity : public IEntity {
public:

    Entity(int xx, int yy, bool entHasArm, int entHealth, double entSpeed = 0):
        x(xx), y(yy), health(entHealth), armor(entHasArm), speed(entSpeed) {}

    virtual const double getX(){
        return x;
    }
    virtual const double getY(){
        return y;
    }
    virtual void setX(double xx){
        x = xx;
    }
    virtual void setY(double yy){
        y = yy;
    }

    void reduceEntityHealth(int dmg) {
        if (health <= dmg) health = 0;
            else health -= dmg;
    }

    void addEntityHealth(int dH) {
        health += dH;
    }

    void giveArmor() {
        armor = true;
    }

    bool HasArmor() const {
        return armor;
    }

    void setEntitySpeed(double newSpeed) {
        speed = newSpeed;
    }

    double getEntitySpeed() const {
        return speed;
    }
    void update(double time, sf::Sprite& spr){
        if (dir == MoveDirect::Left){
            dx = -speed; dy = 0;
        }
        else if (dir == MoveDirect::Right){
            dx = speed; dy = 0;
        }
        else if (dir == MoveDirect::Up){
            dy = -speed; dx = 0;
        }
        else if (dir == MoveDirect::Down){
            dy = speed; dx = 0;
        }

        x += dx*time;
        y += dy*time;

        speed = 0;
        spr.setPosition(x, y);
    }

    void setMovement(MoveDirect move){
        dir = move;
    }

private:
    double x;
    double y;

    int health;
    bool armor;
    double speed;
    double dx = 0;
    double dy = 0;

    MoveDirect dir = MoveDirect::Stay;

};



#endif ///ENTITY_HPP