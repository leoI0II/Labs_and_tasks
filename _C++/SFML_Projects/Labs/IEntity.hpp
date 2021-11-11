#ifndef IENTITY_HPP
#define IENTITY_HPP
#include<SFML/Graphics.hpp>

class IEntity {
public:
    virtual void reduceEntityHealth(int) = 0;
    virtual void addEntityHealth(int) = 0;
    virtual void giveArmor() = 0;
    virtual bool HasArmor() const = 0;
    virtual void setEntitySpeed(double newSpeed) = 0;
    virtual double getEntitySpeed() const = 0;

    virtual const double getX() = 0;
    virtual const double getY() = 0;
    virtual void setX(double) = 0;
    virtual void setY(double) = 0;

    // virtual void update(double time, sf::Sprite) = 0;

};



#endif ///IENTITY_HPP