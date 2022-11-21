#include "Item.hpp"

Item::Item(const Point& point) : position(point) {}
void Item::SetPoint(const Point& point) {
    position = point;
}
Point Item::GetPoint() const {
    return position;
}
void Item::SetPoint(double x, double y) {
    position.SetX(x).SetY(y);
}
double Item::GetX() const {
    return position.GetX();
}
double Item::GetY() const {
    return position.GetY();
}
void Item::SetX(double x) {
    position.SetX(x);
}
void Item::SetY(double y) {
    position.SetY(y);
}

//////////////////////////////////////////////////////////////////////////////

LittleHealthBottle::LittleHealthBottle(const Point& point) : Item(point) {}

void LittleHealthBottle::Interact(Entity* ch) {
    dynamic_cast<ICharacter*>(ch)->SetHP(20);
}

//////////////////////////////////////////////////////////////////////////////

Ammo::Ammo(const Point& point) : Item(point) {}

void Ammo::Interact(Entity* wp) {
    dynamic_cast<Weapon*>(wp)->SetQuantity(30);
}

//////////////////////////////////////////////////////////////////////////////

BigHealthBottle::BigHealthBottle(const Point& point) : Item(point) {}

void BigHealthBottle::Interact(Entity* ch) {
    dynamic_cast<ICharacter*>(ch)->SetHP(50);
}
