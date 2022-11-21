#include "Enemy.hpp"

Enemy::Enemy(int HP, int dmg, const Point& point, double sp, MoveDir ms, EnemyType tp)
    : Character(HP, dmg, point, sp, ms), type(tp) {}

Enemy::~Enemy() {}

void Enemy::UseItem(ItemType) {}

EnemyType Enemy::GetType() const {
    return type;
}
void Enemy::SetType(EnemyType tp) {
    type = tp;
}

////////////////////////////////////////////////////////////////

Enemy1::Enemy1(int HP, int dmg, const Point& point, double sp, MoveDir ms)
    : Enemy(HP, dmg, point, sp, ms, EnemyType::enemy1) {}

void Enemy1::Update(double time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) {
    double dx = 0, dy = 0;
    //MoveDir tmp = GetDirection();

    int i = GetX() / int(TileSize::Size), j = GetY() / int(TileSize::Size);
    grid.GetTile(j, i).takeEnemy();

    if (GetDirection() == MoveDir::Left) {
        dx = -GetSpeed();
    }
    else if (GetDirection() == MoveDir::Right) {
        dx = GetSpeed();
    }
    else if (GetDirection() == MoveDir::Down) {
        dy = GetSpeed();
    }
    else if (GetDirection() == MoveDir::Up) {
        dy = -GetSpeed();
    }
    //SetPoint(GetX() + dx * time, GetY() + dy * time);
    SetX(GetX() + dx * time);
    InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY);
    SetY(GetY() + dy * time);
    InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY);

    i = GetX() / int(TileSize::Size);  j = GetY() / int(TileSize::Size);
    grid.GetTile(j, i).putEnemy(this);

    if (grid.GetTile(j, i).hasPlayer()) {
        Player* tmpP = grid.GetTile(j, i).takePlayer();
        Interact((Entity*)tmpP);
        grid.GetTile(j, i).putPlayer(tmpP);
    }
}

bool Enemy1::InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) {
    double chX = GetX(), chY = GetY();
    int tileS = int(TileSize::Size);
    for (int i = chY / tileS; i < (chY + chSizeY) / tileS; i++) {
        for (int j = chX / tileS; j < (chX + chSizeX) / tileS; j++) {
            if (grid.GetTile(i, j).GetType() == Type::Wall) {
                if (dy > 0) {
                    // position.SetY(i * chSize + chSize);
                    SetY(static_cast<double>(i * tileS - chSizeY));
                    SetDirection(MoveDir::Up);
                    // return true;
                }
                if (dy < 0) {
                    // position.SetY(i * chSize + chSize);
                    SetY(static_cast<double>(i * tileS + tileS));
                    SetDirection(MoveDir::Down);
                    // return true;
                }
                if (dx > 0) {
                    // position.SetX(j * chSize - chSize);
                    SetX(static_cast<double>(j * tileS - chSizeX));
                    SetDirection(MoveDir::Left);
                    // return true;
                }
                if (dx < 0) {
                    // position.SetY(j * chSize + chSize);
                    SetX(static_cast<double>(j * tileS + tileS));
                    SetDirection(MoveDir::Right);
                    // return true;
                }
            }
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////

Enemy2::Enemy2(int HP, int dmg, const Point& point, double sp, MoveDir ms)
    : Enemy(HP, dmg, point, sp, ms, EnemyType::enemy1) {}


void Enemy2::Update(double time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) {
    double dx = 0, dy = 0;
    
    int i = GetX() / int(TileSize::Size), j = GetY() / int(TileSize::Size);
    grid.GetTile(j, i).takeEnemy();
    
    //MoveDir tmp = GetDirection();
    if (GetDirection() == MoveDir::Left) {
        dx = -GetSpeed();
    }
    else if (GetDirection() == MoveDir::Right) {
        dx = GetSpeed();
    }
    else if (GetDirection() == MoveDir::Down) {
        dy = GetSpeed();
    }
    else if (GetDirection() == MoveDir::Up) {
        dy = -GetSpeed();
    }
    //SetPoint(GetX() + dx * time, GetY() + dy * time);
    SetX(GetX() + dx * time);
    InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY);
    SetY(GetY() + dy * time);
    InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY);
    
    i = GetX() / int(TileSize::Size);  j = GetY() / int(TileSize::Size);
    grid.GetTile(j, i).putEnemy(this);

    if (grid.GetTile(j, i).hasPlayer()) {
        Player* tmpP = grid.GetTile(j, i).takePlayer();
        Interact((Entity*)tmpP);
        grid.GetTile(j, i).putPlayer(tmpP);
    }
}

bool Enemy2::InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) {
    double chX = GetX(), chY = GetY();
    int tileS = int(TileSize::Size);
    for (int i = chY / tileS; i < (chY + chSizeY) / tileS; i++) {
        for (int j = chX / tileS; j < (chX + chSizeX) / tileS; j++) {
            if (grid.GetTile(i, j).GetType() == Type::Wall) {
                if (dy > 0) {
                    // position.SetY(i * chSize + chSize);
                    SetY(static_cast<double>(i * tileS - chSizeY));
                    SetDirection(MoveDir::Up);
                    // return true;
                }
                if (dy < 0) {
                    // position.SetY(i * chSize + chSize);
                    SetY(static_cast<double>(i * tileS + tileS));
                    SetDirection(MoveDir::Down);
                    // return true;
                }
                if (dx > 0) {
                    // position.SetX(j * chSize - chSize);
                    SetX(static_cast<double>(j * tileS - chSizeX));
                    SetDirection(MoveDir::Left);
                    // return true;
                }
                if (dx < 0) {
                    // position.SetY(j * chSize + chSize);
                    SetX(static_cast<double>(j * tileS + tileS));
                    SetDirection(MoveDir::Right);
                    // return true;
                }
            }
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////

Enemy3::Enemy3(int HP, int dmg, const Point& point, double sp, MoveDir ms)
    : Enemy(HP, dmg, point, sp, ms, EnemyType::enemy1) {}


void Enemy3::Update(double _time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) {
    double dx = 0, dy = 0;

    int i = GetX() / int(TileSize::Size), j = GetY() / int(TileSize::Size);
    grid.GetTile(j, i).takeEnemy();

    //MoveDir tmp = GetDirection();
    if (GetDirection() == MoveDir::Left) {
        dx = -GetSpeed();
    }
    if (GetDirection() == MoveDir::Right) {
        dx = GetSpeed();
    }
    if (GetDirection() == MoveDir::Down) {
        dy = GetSpeed();
    }
    if (GetDirection() == MoveDir::Up) {
        dy = -GetSpeed();
    }

    SetX(GetX() + dx * _time);
    InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY);
    SetY(GetY() + dy * _time);
    InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY);

    i = GetX() / int(TileSize::Size);  j = GetY() / int(TileSize::Size);
    grid.GetTile(j, i).putEnemy(this);
    
    if (grid.GetTile(j, i).hasPlayer()) {
        Player* tmpP = grid.GetTile(j, i).takePlayer();
        Interact((Entity*)tmpP);
        grid.GetTile(j, i).putPlayer(tmpP);
    }

}

bool Enemy3::InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) {
    double chX = GetX(), chY = GetY();
    int tileS = int(TileSize::Size);
    srand(time(0));
    for (int i = chY / tileS; i < (chY + chSizeY) / tileS; i++) {
        for (int j = chX / tileS; j < (chX + chSizeX) / tileS; j++) {
            if (grid.GetTile(i, j).GetType() == Type::Wall) {
                if (dy > 0) {
                    // position.SetY(i * chSize + chSize);
                    SetY(static_cast<double>(i * tileS - chSizeY));
                    MoveDir tmp1 = GetDirection();
                    while (tmp1 == GetDirection()) {
                        tmp1 = static_cast<MoveDir>((rand() % 5));
                        if (tmp1 == MoveDir::Stay)
                            tmp1 = GetDirection();
                    }
                    SetDirection(tmp1);
                    // return true;
                }
                if (dy < 0) {
                    // position.SetY(i * chSize + chSize);
                    SetY(static_cast<double>(i * tileS + tileS));
                    MoveDir tmp1 = GetDirection();
                    while (tmp1 == GetDirection()) {
                        tmp1 = static_cast<MoveDir>((rand() % 5));
                        if (tmp1 == MoveDir::Stay)
                            tmp1 = GetDirection();
                    }
                    SetDirection(tmp1);
                    // return true;
                }
                if (dx > 0) {
                    // position.SetX(j * chSize - chSize);
                    SetX(static_cast<double>(j * tileS - chSizeX));
                    MoveDir tmp1 = GetDirection();
                    while (tmp1 == GetDirection()) {
                        tmp1 = static_cast<MoveDir>((rand() % 5));
                        if (tmp1 == MoveDir::Stay)
                            tmp1 = GetDirection();
                    }
                    SetDirection(tmp1);
                    // return true;
                }
                if (dx < 0) {
                    // position.SetY(j * chSize + chSize);
                    SetX(static_cast<double>(j * tileS + tileS));
                    MoveDir tmp1 = GetDirection();
                    while (tmp1 == GetDirection()) {
                        tmp1 = static_cast<MoveDir>((rand() % 5));
                        if (tmp1 == MoveDir::Stay)
                            tmp1 = GetDirection();
                    }
                    SetDirection(tmp1);
                    // return true;
                }
            }
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////