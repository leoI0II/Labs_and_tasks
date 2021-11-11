#ifndef TILE_HPP
#define TILE_HPP

#include"Point.hpp"
#include"Player.hpp"
#include"Item.hpp"


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

    bool HasPlayer(){
        return (player ? true : false);
    }
    void putPlayer(Player* pl){
        player = pl;
    }
    void takePlayer() { player = nullptr; }

    void SetItem(Item* newIt){
        items.push_back(newIt);
    }
    Item* takeItem(){
        Item* tmp = items.back();
        items.pop_back();
        return tmp;
    }

private:
    Type type;
    Status status;

    Player* player;
    std::vector<Item*> items;

};




#endif ///TILE_HPP