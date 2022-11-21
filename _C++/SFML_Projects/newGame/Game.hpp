// #pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include"EntityView.hpp"
#include"Player.hpp"
#include"EnemyFactory.hpp"
#include"ItemFactory.hpp"
#include<list>
#include"GridView.hpp"
#include"Controller.hpp"

using pairEnemy = std::pair<Enemy*, EntityView*>;
using pairItem = std::pair<Item*, EntityView*>;

class Game
{
public:
    Game();

    void HaveFun();

private:

    Player* player;
    EntityView* playerView;

    // std::list<Enemy*>& enemies;
    std::list<pairEnemy> enemies;

    // std::list<Item*>& items;
    // std::list<std::pair<Item*, EntityView*>> items;
    std::list<pairItem> items;

    FieldGrid* grid;
    GridView* gridView;

    Controller* pControl;
};

#endif //GAME_HPP