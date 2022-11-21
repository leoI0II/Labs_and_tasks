// #pragma once
#ifndef TILE_HPP
#define TILE_HPP

#include"Point.hpp"
// #include"Player.hpp"
#include"Item.hpp"
// #include"Enemy.hpp"
#include<list>
#include<algorithm>

class Player;
class Enemy;
class Item;

enum class Status { NotAvailable, Available };
enum class Type { Exit, Common, Entry, Wall };
enum class TileSize { Size = 60 };

class Tile : Point
{
public:
    Tile(double x = 0, double y = 0);
    Tile(const Point& point);
    Tile(const Point& point, Type tp, Status st = Status::NotAvailable);
    Tile(double x, double y, Type tp, Status st = Status::NotAvailable);

    using Point::GetX;
    using Point::GetY;
    using Point::SetX;
    using Point::SetY;
    using Point::SetPosition;

    const Status GetStatus() const;
    const Type GetType() const;

    const Tile& SetType(Type _type);
    const Tile& SetStatus(Status _status);

    bool hasItem() const;
    void putItem(Item* newItem);
    Item* takeItem();

    bool hasEnemy() const;
    void putEnemy(Enemy* newEnemy);
    Enemy* takeEnemy();

    bool hasPlayer() const;
    void putPlayer(Player* newPlayer);
    Player* takePlayer();

private:
    Type type;
    Status status;

    Player* player;
    std::list<Item*> items;
    std::list<Enemy*> enemies;

};

#endif //TILE_HPP