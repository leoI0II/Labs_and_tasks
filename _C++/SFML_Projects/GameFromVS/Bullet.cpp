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

bool Bullet::Update(double time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) {
    double dx = 0, dy = 0;
    //MoveDir tmp = GetDirection();

    if (flyingDirection == MoveDir::Left) {
        dx = -GetBulletSpeed();
    }
    if (flyingDirection == MoveDir::Right) {
        dx = GetBulletSpeed();
    }
    if (flyingDirection == MoveDir::Down) {
        dy = GetBulletSpeed();
    }
    if (flyingDirection == MoveDir::Up) {
        dy = -GetBulletSpeed();
    }
    SetX(GetX() + dx * time);
    InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY);
    SetY(GetY() + dy * time);
    InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY);

    int i = GetX() / int(TileSize::Size), j = GetY() / int(TileSize::Size);
    //grid.GetTile(j, i).putPlayer(this);
    if (grid.GetTile(j, i).hasEnemy()) {
        Enemy* enemy = grid.GetTile(j, i).takeEnemy();
        //Enemy3 temp(1, 1, Point(1, 1), 1);
        //Interact(enemy);  //Not Working
        Interact((Entity*)enemy);
        grid.GetTile(j, i).putEnemy(enemy);
        SetLifeBulletState(false);
    }
    return true;
}

bool Bullet::InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) {

    //for (int i = GetY(); i < (GetY() + 1); i++) {
    //    for (int j = GetX(); j < (GetX() + 1); j++) {
    //        if (grid.GetTile(i, j).GetType() == Type::Wall) {
    //            return false;
    //        }
    //        // if (grid.GetTile(i, j).hasEnemy()) {
    //        //     Enemy* enemy = grid.GetTile(i, j).takeEnemy();
    //        //     Interact(enemy);
    //        //     grid.GetTile(i, j).putEnemy(enemy);
    //        // }
    //    }
    //}
    //return true;
    double chX = GetX(), chY = GetY();
    int tileS = int(TileSize::Size);
    //std::cout << "ChX " << chX << " ChY " << chY << " chSizeX " << chSizeX << " chSizeY " <<
    //    chSizeY << " tilesS " << tileS << " chY/tileS " << chY/tileS << 
    //        " chX/tileS " << chX/tileS << " (chY + chSizeY)/tileS " << (chY + chSizeY) / tileS <<
    //        " (chX + chSizeX)/tileS " << (chY + chSizeY) / tileS << std::endl;
    for (int i = chY / tileS; i < (chY + chSizeY) / tileS; i++) {
        for (int j = chX / tileS; j < (chX + chSizeX) / tileS; j++) {
            if (grid.GetTile(i, j).GetType() == Type::Wall) {
                if (dy > 0) {
                    // position.SetY(i * chSize + chSize);
                    SetY(static_cast<double>(i * tileS - chSizeY));
                    SetLifeBulletState(false);
                    // return true;
                }
                if (dy < 0) {
                    // position.SetY(i * chSize + chSize);
                    SetY(static_cast<double>(i * tileS + tileS));
                    SetLifeBulletState(false);
                    // return true;
                }
                if (dx > 0) {
                    // position.SetX(j * chSize - chSize);
                    SetX(static_cast<double>(j * tileS - chSizeX));
                    SetLifeBulletState(false);
                    // return true;
                }
                if (dx < 0) {
                    // position.SetY(j * chSize + chSize);
                    SetX(static_cast<double>(j * tileS + tileS));
                    SetLifeBulletState(false);
                    // return true;
                }
            }
        }
    }
    return false;
}

bool Bullet::GetLifeBulletState() const
{
    return lifeState;
}

void Bullet::SetLifeBulletState(bool st)
{
    lifeState = st;
}
