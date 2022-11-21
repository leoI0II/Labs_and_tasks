// #pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include"Character.hpp"
#include"Weapon.hpp"
#include<map>
#include<vector>
// #include"Item.hpp"
#include<typeinfo>
#include"FieldGrid.hpp"

class FieldGrid;
class Bullet;
class Item;

using Bag_t = std::map<ItemType, std::vector<Item*>>;

class Player : public Character {
public:
    Player(int HP, int dmg, const Point& pos, double sp, int wQuant = 50,
            MoveDir MD = MoveDir::Stay, MoveDir chD = MoveDir::Right);

    ~Player();

    void UseItem(ItemType ittp);

    void AddToBag(Item* newItem);

    Bullet* Fire();
    void SetCheckingDirection(MoveDir mv);
    MoveDir GetPlayerCheckingDirection() const;

    void Update(double time, FieldGrid& grid, const float& chSizeX, const float& chSizeY);

    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) ;

    const Weapon& GetWeapon();

private:

    Weapon weapon;
    Bag_t bag;
    MoveDir checkDir;
};

#endif //PLAYER_HPP