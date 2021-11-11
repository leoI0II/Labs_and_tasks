#ifndef HEROWEAPON_HPP
#define HEROWEAPON_HPP

#include"Ammo.hpp"

class HeroWeapon {
public:
    HeroWeapon(int damg = 50, int initAmount = 50) : damage(damg), amountAmmo(initAmount) {}

    void addAmmo(Ammo& newAmmo){
        amountAmmo += newAmmo.addToWeapon();
    }

    void weaponsDamage(int newDmg) { damage = newDmg; }
    const int Damage() const { return damage; }

private:
    int damage;
    // int distance;
    int amountAmmo;
};


#endif  //HEROWEAPON_HPP