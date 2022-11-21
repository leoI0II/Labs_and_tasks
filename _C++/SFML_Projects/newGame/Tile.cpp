#include "Tile.hpp"

Tile::Tile(double x, double y) : Point(x, y) {}
Tile::Tile(const Point& point) : Point(point) {}
Tile::Tile(const Point& point, Type tp, Status st) : Point(point), type(tp), status(st) {}
Tile::Tile(double x, double y, Type tp, Status st) : Point(x, y), type(tp), status(st) {}

const Status Tile::GetStatus() const {
    return status;
}
const Type Tile::GetType() const {
    return type;
}

const Tile& Tile::SetType(Type _type) {
    type = _type;
    return *this;
}
const Tile& Tile::SetStatus(Status _status) {
    status = _status;
    return *this;
}

bool Tile::hasItem() const {
    return !items.empty();
}
void Tile::putItem(Item* newItem) {
    items.push_back(newItem);
}
Item* Tile::takeItem() {
    Item* ret = items.back();
    items.pop_back();
    return ret;
}

bool Tile::hasEnemy() const {
    return !enemies.empty();
}
void Tile::putEnemy(Enemy* newEnemy) {
    enemies.push_back(newEnemy);
}
Enemy* Tile::takeEnemy() {
    // auto it = std::find(enemies.begin(), enemies.end(), toDel);
    // Enemy* ret = *it;
    // enemies.remove(*it);
    // return ret;
    Enemy* ret = enemies.back();
    enemies.pop_back();
    return ret;
}

bool Tile::hasPlayer() const {
    return (player ? true : false);
}
void Tile::putPlayer(Player* newPlayer) {
    player = newPlayer;
}
Player* Tile::takePlayer() {
    Player* toret = player;
    player = nullptr;
    return toret;
}