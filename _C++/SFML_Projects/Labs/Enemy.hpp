#ifndef ENEMY_HPP
#define ENEMY_HPP

#include"Entity.hpp"

class Enemy : public Entity {
public:
    Enemy(int xx, int yy) : Entity(xx, yy, false, 50, 0.5) {}

private:


};


#endif //ENEMY_HPP