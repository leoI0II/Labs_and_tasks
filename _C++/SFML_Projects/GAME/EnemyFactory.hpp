#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP

#include"Enemy.hpp"

class EnemyFactory {
public:
    virtual Enemy* CreateEnemy(FieldGrid&) = 0;
protected:
    Point randomizer(FieldGrid& grid){
        int x = 0, y = 0;
        srand(time(NULL));

        while(true){
            x = 1 + rand() % (grid.getWidth() - 1);
            y = 1 + rand() % (grid.getHeight() - 1);
            if (grid.GetTile(y, x).GetType() == Type::Common)
                break;
        }
        return Point(x*int(TileSize::Size), y*int(TileSize::Size));
    }
};

class Enemy1Fact : public EnemyFactory{
public:
    Enemy* CreateEnemy(FieldGrid& grid) override {
        Enemy* tmp = new Enemy1(100, 20, randomizer(grid), 0.5);
        grid.GetTile(tmp->GetY()/int(TileSize::Size), tmp->GetX()/int(TileSize::Size)).putEnemy(tmp);
        return tmp;
    }
};
class Enemy2Fact : public EnemyFactory{
public:
    Enemy* CreateEnemy(FieldGrid& grid) override {
        Enemy* tmp = new Enemy2(100, 40, randomizer(grid), 0.3);
        grid.GetTile(tmp->GetY()/int(TileSize::Size), tmp->GetX()/int(TileSize::Size)).putEnemy(tmp);
        return tmp;
    }
};
class Enemy3Fact : public EnemyFactory{
public:
    Enemy* CreateEnemy(FieldGrid& grid) override {
        Enemy* tmp = new Enemy3(100, 30, randomizer(grid), 0.4);
        grid.GetTile(tmp->GetY()/int(TileSize::Size), tmp->GetX()/int(TileSize::Size)).putEnemy(tmp);
        return tmp;
    }
};


#endif ///ENEMYFACTORY_HPP