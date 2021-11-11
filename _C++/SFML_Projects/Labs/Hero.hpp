#ifndef HERO_HPP
#define HERO_HPP

#include"Entity.hpp"

class Hero : public Entity{
public:
    Hero(int xx, int yy, ObjType tp = ObjType::Hero, int health = 100):
        Entity(xx, yy, tp, health) {}
    
    bool haveArmor() { return armor; }
    void giveArmor() { armor = true; }

private:
    bool armor = false;

};



#endif ////HERO_HPP