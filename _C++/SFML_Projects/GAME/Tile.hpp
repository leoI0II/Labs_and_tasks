#ifndef TILE_HPP
#define TILE_HPP

#include"Point.hpp"
#include"Player.hpp"
#include"Item.hpp"
#include"Enemy.hpp"
#include<list>
#include<algorithm>

enum class Status {NotAvailable, Available};
enum class Type {Exit, Common, Entry, Wall};
enum class TileSize {Size = 60};

class Tile : private Point {
public:
    Tile(double x = 0, double y = 0) : Point(x, y) {}
    Tile(const Point& point) : Point(point) {}
    Tile(const Point& point, Type tp, Status st = Status::NotAvailable) : Point(point), type(tp), status(st) {}
    Tile(double x, double y, Type tp, Status st = Status::NotAvailable) : Point(x, y), type(tp), status(st) {}

    using Point::GetX;
    using Point::GetY;
    using Point::SetX;
    using Point::SetY;
    using Point::SetPosition;

    const Status GetStatus() const{
        return status;
    }
    const Type GetType() const{
        return type;
    }

    const Tile& SetType(Type _type){
        type = _type;
        return *this;
    }
    const Tile& SetStatus(Status _status){
        status = _status;
        return *this;
    }

    bool hasItem() const {
        return !items.empty();
    }
    void putItem(Item* newItem){
        items.push_back(newItem);
    }
    Item* takeItem(){
        Item* ret = items.back();
        items.pop_back();
        return ret;
    }

    bool hasEnemy() const {
        return !enemies.empty();
    }
    void putEnemy(Enemy* newEnemy){
        enemies.push_back(newEnemy);
    }
    Enemy* takeEnemy(){
        // auto it = std::find(enemies.begin(), enemies.end(), toDel);
        // Enemy* ret = *it;
        // enemies.remove(*it);
        // return ret;
        Enemy* ret = enemies.back();
        enemies.pop_back();
        return ret;
    }

    bool hasPlayer() const {
        return (player ? true : false);
    }
    void putPlayer(Player* newPlayer){
        player = newPlayer;
    }
    Player* takePlayer(){
        Player* toret = player;
        player = nullptr;
        return toret;
    }

private:
    Type type;
    Status status;

    Player* player;
    std::list<Item*> items;
    std::list<Enemy*> enemies;

};




#endif ///TILE_HPP