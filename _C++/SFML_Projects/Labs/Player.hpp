#ifndef PLAYER_HPP
#define PLAYER_HPP

// #include"HeroBag.hpp"
#include<unordered_map>
#include<vector>
#include<memory>
#include"Item.hpp"
#include"HeroWeapon.hpp"
#include"GranadeItem.hpp"
#include"healthItem.hpp"
#include"Entity.hpp"

using Bag_t = std::unordered_map<ItemType, std::vector<std::shared_ptr<Item>>>;


class Player : public Entity {
public:
    Player(int xx = 5, int yy = 5) :
        Entity(xx, yy, true, 100, 1), bag(3), weapon() {}

    void addToBag(std::shared_ptr<Item>& ptrToItem) {
        bag[ptrToItem->getItemType()].push_back(ptrToItem);
    }

    // bool use(ItemType tp) {                 //По нажатию забинженной кнопки, передается какой тип и идет проверка с действием....
    //     if (bag[tp].empty())
    //         return false;
    //     else{
    //         if (tp == ItemType::Ammo){
    //             std::shared_ptr<Ammo> tmpPtr = std::shared_ptr<Ammo>(dynamic_cast<Ammo*>(bag[tp].back().get()));
    //             weapon.addAmmo(*tmpPtr);
    //         }
    //         else if (tp == ItemType::Granade){
    //             std::shared_ptr<Granade> tmpPtr = std::shared_ptr<Granade>(dynamic_cast<Granade*>(bag[tp].back().get()));
    //             ///....///
                
    //         }
    //         else if (tp == ItemType::HealthBottle){
    //             std::shared_ptr<HealthItem> tmpPtr = std::shared_ptr<HealthItem>(dynamic_cast<HealthItem*>(bag[tp].back().get()));
    //             // health += tmpPtr->addHealth();
    //             addEntityHealth(tmpPtr->addHealth());
    //         }
    //         bag[tp].pop_back();
    //     }
    //     return true;
    // }

    //ТУДУ:
    //Логика движения
    //Логика кол-ва пуль
    //Логика здоровья

private:

    Bag_t bag;
    HeroWeapon weapon;
    // HeroBag bag;

};


#endif