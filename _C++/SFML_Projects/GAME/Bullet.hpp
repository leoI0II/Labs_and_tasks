#ifndef BULLET_HPP
#define BULLET_HPP

#include"Character.hpp"

class Bullet : public Entity{
public:
    Bullet(int dmg, const Point& bulletPos, double speed, MoveDir MD) : 
        damage(dmg),
        position(bulletPos),
        bulletSpeed(speed),
        flyingDirection(MD) {}

    void SetPoint(const Point& point) override { position = point; }
    void SetPoint(double xx, double yy) override {
        position.SetX(xx).SetY(yy);
    }
    Point GetPoint() const override { return position; }
    double GetX() const override {
        return position.GetX();
    }
    double GetY() const override {
        return position.GetY();
    }
    void SetX(double newX) override {
        position.SetX(newX);
    }
    void SetY(double newY) override {
        position.SetY(newY);
    }

    void SetDamage(int newDmg) { damage = newDmg; }
    int GetDamage() const { return damage; }

    void Interact(Entity* enemyMaybe){
        // Character* stillEnemy = dynamic_cast<Character*>(enemyMaybe);
        // stillEnemy->SetHP(-GetDamage());
        dynamic_cast<Character*>(enemyMaybe)->SetHP(-GetDamage());
    }
    void SetBulletSpeed(double newSpeed){
        bulletSpeed = newSpeed;
    }
    double GetBulletSpeed() const { return bulletSpeed; }

    bool Update(double time, FieldGrid& grid){
        double dx = 0, dy = 0;
        if (flyingDirection == MoveDir::Right){
            dx = bulletSpeed;
        }
        else if (flyingDirection == MoveDir::Left){
            dx = -bulletSpeed;
        }
        else if (flyingDirection == MoveDir::Up){
            dy = -bulletSpeed;
        }
        else if (flyingDirection == MoveDir::Down){
            dy = bulletSpeed;
        }
        position.SetX(GetX()+dx*time);
        if (!InteractionWithGrid(grid, dx, dy)) return false;
        position.SetY(GetY()+dy*time);
        if (!InteractionWithGrid(grid, dx, dy)) return false;
        return true;
    }

    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy) {

        for (int i = GetY(); i < (GetY() + 1); i++){
            for (int j = GetX(); j < (GetX() + 1); j++){
                if (grid.GetTile(i, j).GetType() == Type::Wall){
                    return false;
                }
                if (grid.GetTile(i, j).hasEnemy()){
                    Enemy* enemy = grid.GetTile(i, j).takeEnemy();
                    Interact(enemy);
                    grid.GetTile(i, j).putEnemy(enemy);
                }
            }
        }
        return true;
    }

private:
    int damage;
    Point position;
    double bulletSpeed;
    MoveDir flyingDirection;
};


#endif //BULLET_HPP
