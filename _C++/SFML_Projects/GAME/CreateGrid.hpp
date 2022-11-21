#ifndef CREATEGRID_HPP
#define CREATEGRID_HPP

#include"Point.hpp"
#include<string>
#include<fstream>
#include<sstream>
#include"Exceptions.hpp"
#include<iostream>
#include"BuildDirector.hpp"
#include"Player.hpp"
#include"Enemy.hpp"
#include"Item.hpp"
#include<list>
#include<cstdlib>

using tileArr_t = std::shared_ptr<Tile[]>;
using grid_t = std::shared_ptr<tileArr_t[]>;


class GridCreator{

public:
    GridCreator();

    grid_t& GetGrid();
    int GetHeight();
    int GetWidth();
    Point& GetStartPos();
    Point& GetEndPos();

    ~GridCreator(){
        if (tiles){
            for (int i = 0; i < gridHeight; i++)
                tiles[i].reset();
            tiles.reset();
        }
    }

private:
    grid_t tiles;
    int gridHeight;
    int gridWidth;
    Point startPosition;
    Point endPosition;

    const std::string TakeFile();

    void FindParams(std::ifstream& file);

    // Item* randomPosItem(ItemType type){
    //     int x = 0, y = 0;
    //     srand(time(NULL));

    //     while(true){
    //         x = 1 + rand() % (gridWidth - 1);
    //         y = 1 + rand() % (gridHeight - 1);
    //         if (tiles[y][x].GetType() == Type::Common)
    //             break;
    //     }
    //     if (type == ItemType::Ammo)
    //         return new Ammo(Point(y, x));
    //     else if (type == ItemType::BigHealthBottle)
    //         return new BigHealthBottle(Point(y, x));
    //     else if (type == ItemType::LittleHealthBottle)
    //         return new LittleHealthBottle(Point(y, x));
    // }
    // Enemy* randomPosEnemy(EnemyType tp){
    //     int x = 0, y = 0;
    //     srand(time(NULL));

    //     while(true){
    //         x = 1 + rand() % (gridWidth - 1);
    //         y = 1 + rand() % (gridHeight - 1);
    //         if (tiles[y][x].GetType() == Type::Common)
    //             break;
    //     }
    //     if (tp == EnemyType::enemy1)
    //         return new Enemy1(100, 20, Point(y, x), 0.5);
    //     else if (tp == EnemyType::enemy2)
    //         return new Enemy2(100, 10, Point(y, x), 0.3);
    //     else if (tp == EnemyType::enemy3)
    //         return new Enemy3(100, 40, Point(y, x), 0.8);
    // }
    // Player* randomPosPlayer(){
    //     int x = 0, y = 0;
    //     srand(time(NULL));

    //     while(true){
    //         x = 1 + rand() % (gridWidth - 1);
    //         y = 1 + rand() % (gridHeight - 1);
    //         if (tiles[y][x].GetType() == Type::Common)
    //             break;
    //     }
    //     return new Player(100, 50, startPosition, 1);
    // }

};


#endif ///CREATEGRID_HPP