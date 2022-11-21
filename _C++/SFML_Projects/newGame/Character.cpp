#include "Character.hpp"

Character::Character(int HP, int dmg, const Point& point, double sp, MoveDir ms) :
    healthPoints(HP),
    damage(dmg),
    position(point),
    speed(sp),
    moveState(ms) {}

Character::~Character() {}

void Character::SetPoint(const Point& point) {
    position = point;
}
void Character::SetPoint(double _x, double _y) {
    position.SetX(_x).SetY(_y);
}
Point Character::GetPoint() const {
    return position;
}
double Character::GetX() const {
    return position.GetX();
}
double Character::GetY() const {
    return position.GetY();
}
void Character::SetX(double newX) {
    position.SetX(newX);
}
void Character::SetY(double newY) {
    position.SetY(newY);
}

void Character::SetHP(int plusHP) {
    // if (plusHP < 0 && healthPoints <= plusHP){           //killing case
    //     //  killing
    // }
    healthPoints += plusHP;
}
int Character::GetHP() const {
    return healthPoints;
}
void Character::Interact(Entity* probablyEnemyOfThis) {
    // probablyEnemyOfThis->SetHP(-GetDamage());
    dynamic_cast<ICharacter*>(probablyEnemyOfThis)->SetHP(-GetDamage());
}
int Character::GetDamage() const {
    return damage;
}
void Character::SetSpeed(double newSp) {
    speed = newSp;
}
double Character::GetSpeed() const {
    return speed;
}
void Character::SetDirection(MoveDir newDir) {
    moveState = newDir;
}
MoveDir Character::GetDirection() const {
    return moveState;
}