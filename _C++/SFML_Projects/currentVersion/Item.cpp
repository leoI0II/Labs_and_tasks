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

void Item::SetStateItem(bool st)
{
    state = st;
}

bool Item::GetStateItem() const
{
    return state;
}

//////////////////////////////////////////////////////////////////////////////

LittleHealthBottle::LittleHealthBottle(const Point& point) : Item(point) {}

void LittleHealthBottle::Interact(Entity* ch) {
    ICharacter* tmp = dynamic_cast<ICharacter*>(ch);
    std::cout << "Player health point before: " << tmp->GetHP() << std::endl;
    //dynamic_cast<ICharacter*>(ch)->SetHP(20);
    tmp->SetHP(20);
    std::cout << "Player health point after: " << tmp->GetHP() << std::endl;
}

//////////////////////////////////////////////////////////////////////////////

Ammo::Ammo(const Point& point) : Item(point) {}

void Ammo::Interact(Entity* wp) {
    Weapon* tmp = dynamic_cast<Weapon*>(wp);
    std::cout << "Weapon ammo quantity before: " << tmp->GetQuantity() << std::endl;
    //dynamic_cast<Weapon*>(wp)->SetQuantity(30);
    tmp->SetQuantity(30);
    std::cout << "Weapon ammo quantity after: " << tmp->GetQuantity() << std::endl;
}

//////////////////////////////////////////////////////////////////////////////

BigHealthBottle::BigHealthBottle(const Point& point) : Item(point) {}

void BigHealthBottle::Interact(Entity* ch) {
    ICharacter* tmp = dynamic_cast<ICharacter*>(ch);
    std::cout << "Player health point before: " << tmp->GetHP() << std::endl;
    //dynamic_cast<ICharacter*>(ch)->SetHP(50);
    tmp->SetHP(50);
    std::cout << "Player health point after: " << tmp->GetHP() << std::endl;
}
