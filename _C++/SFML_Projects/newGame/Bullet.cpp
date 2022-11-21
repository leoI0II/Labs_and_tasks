#include "Bullet.hpp"

Bullet::Bullet(int dmg, const Point& bulletPos, double speed, MoveDir MD) :
    damage(dmg),
    position(bulletPos),
    bulletSpeed(speed),
    flyingDirection(MD) {}

void Bullet::SetPoint(const Point& point) { position = point; }
void Bullet::SetPoint(double xx, double yy) {
    position.SetX(xx).SetY(yy);
}
Point Bullet::GetPoint() const { return position; }
double Bullet::GetX() const {
    return position.GetX();
}
double Bullet::GetY() const {
    return position.GetY();
}
void Bullet::SetX(double newX) {
    position.SetX(newX);
}
void Bullet::SetY(double newY) {
    position.SetY(newY);
}

void Bullet::SetDamage(int newDmg) { damage = newDmg; }
int Bullet::GetDamage() const { return damage; }

void Bullet::Interact(Entity* enemyMaybe) {
    // Character* stillEnemy = dynamic_cast<Character*>(enemyMaybe);
    // stillEnemy->SetHP(-GetDamage());
    dynamic_cast<Character*>(enemyMaybe)->SetHP(-GetDamage());
}
void Bullet::SetBulletSpeed(double newSpeed) {
    bulletSpeed = newSpeed;
}
double Bullet::GetBulletSpeed() const { return bulletSpeed; }

bool Bullet::Update(double time, FieldGrid& grid) {
    double dx = 0, dy = 0;
    if (flyingDirection == MoveDir::Right) {
        dx = bulletSpeed;
    }
    else if (flyingDirection == MoveDir::Left) {
        dx = -bulletSpeed;
    }
    else if (flyingDirection == MoveDir::Up) {
        dy = -bulletSpeed;
    }
    else if (flyingDirection == MoveDir::Down) {
        dy = bulletSpeed;
    }
    position.SetX(GetX() + dx * time);
    if (!InteractionWithGrid(grid, dx, dy)) return false;
    position.SetY(GetY() + dy * time);
    if (!InteractionWithGrid(grid, dx, dy)) return false;
    return true;
}

bool Bullet::InteractionWithGrid(FieldGrid& grid, double& dx, double& dy) {

    for (int i = GetY(); i < (GetY() + 1); i++) {
        for (int j = GetX(); j < (GetX() + 1); j++) {
            if (grid.GetTile(i, j).GetType() == Type::Wall) {
                return false;
            }
            // if (grid.GetTile(i, j).hasEnemy()) {
            //     Enemy* enemy = grid.GetTile(i, j).takeEnemy();
            //     Interact(enemy);
            //     grid.GetTile(i, j).putEnemy(enemy);
            // }
        }
    }
    return true;
}