// #pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

//#include"Character.hpp"
#include"Weapon.hpp"
#include<map>
#include<vector>
// #include"Item.hpp"
#include<typeinfo>
#include"FieldGrid.hpp"
#include<typeindex>

class FieldGrid;
class Bullet;
class Item;

using Bag_t = std::map<std::type_index, std::vector<Item*>>;

class Player : public Character {
public:
    Player(int HP, int dmg, Point& pos, double sp, int wQuant = 50,
            MoveDir MD = MoveDir::Stay, MoveDir chD = MoveDir::Right);

    ~Player();

    void UseItem(const std::type_index& ind);

    void AddToBag(Item* newItem);
    Bag_t& GetBag();

    Bullet* Fire();
    void SetCheckingDirection(MoveDir mv);
    MoveDir GetPlayerCheckingDirection() const;

    void Update(double time, FieldGrid& grid, const float& chSizeX, const float& chSizeY);

    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) ;

    const Weapon& GetWeapon();

    void SetFireState(bool state);
    bool GetFireState() const;

    void SetIsFire(bool isF);
    bool GetIsFire() const;

private:

    Weapon weapon;
    Bag_t bag;
    MoveDir checkDir;
    bool fireState = false;
    bool isFire = false;
};

#endif //PLAYER_HPP

//template<class item>
//void Player::UseItem(item) {
//    if (!bag[std::type_index(typeid(item)].empty()) {
//        Item* tmp = bag[std::type_index(typeid(item)].back();
//        bag[std::type_index(typeid(item)].pop_back();
//        if (typeid(item) == typeid(Ammo))
//            tmp->Interact(&weapon);
//        else
//            tmp->Interact(this);
//    }
//}