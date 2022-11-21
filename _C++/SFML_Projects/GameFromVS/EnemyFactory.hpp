// #pragma once
#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP

#include"Enemy.hpp"

class EnemyFactory
{
public:
    virtual Enemy* CreateEnemy(FieldGrid&) = 0;
protected:
    Point randomizer(FieldGrid& grid);
};

////////////////////////////////////////////////////////////////////////////////////

class Enemy1Fact : public EnemyFactory {
public:
    Enemy* CreateEnemy(FieldGrid& grid) override;
};

////////////////////////////////////////////////////////////////////////////////////

class Enemy2Fact : public EnemyFactory {
public:
    Enemy* CreateEnemy(FieldGrid& grid) override;
};

////////////////////////////////////////////////////////////////////////////////////

class Enemy3Fact : public EnemyFactory {
public:
    Enemy* CreateEnemy(FieldGrid& grid) override;
};

////////////////////////////////////////////////////////////////////////////////////
#endif //ENEMYFACTORY_HPP