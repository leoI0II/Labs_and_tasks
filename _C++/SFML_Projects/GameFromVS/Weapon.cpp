#include "Weapon.hpp"

Weapon::Weapon(int initQuantity, Point& start, double BS) :
    quantity(initQuantity), characterPosition(start), bulletsSpeed(BS) {}

Weapon::~Weapon() {}

Bullet* Weapon::reduseMagazine(MoveDir direction) {
    if (!quantity) return nullptr;
    quantity--;
    return new Bullet(30, characterPosition, bulletsSpeed, direction);
}
void Weapon::SetPoint(double xx, double yy) {
    characterPosition.SetX(xx).SetY(yy);
}
double Weapon::GetX() const {
    return characterPosition.GetX();
}
double Weapon::GetY() const {
    return characterPosition.GetY();
}
void Weapon::SetX(double newX) {
    characterPosition.SetX(newX);
}
void Weapon::SetY(double newY) {
    characterPosition.SetY(newY);
}

void Weapon::SetPoint(const Point& newPos) {
    characterPosition = newPos;
}
Point Weapon::GetPoint() const {
    return characterPosition;
}

void Weapon::SetQuantity(int newQ) {
    quantity += newQ;
}
int Weapon::GetQuantity() const { return quantity; }

void Weapon::Interact(Entity*) {}