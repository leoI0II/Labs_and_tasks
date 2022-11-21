#ifndef ENEMY_HPP
#define ENEMY_HPP

#include"Character.hpp"
#include<cstdlib>
#include<ctime>

enum class EnemyType {enemy1, enemy2, enemy3};

class Enemy : public Character {
public:
    Enemy(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Stay, EnemyType tp = EnemyType::enemy1)
        : Character(HP, dmg, point, sp, ms), type(tp) {}

    ~Enemy(){}

    void UseItem(ItemType) {}

    EnemyType GetType() const {
        return type;
    }
    void SetType(EnemyType tp){
        type = tp;
    }

private:
    EnemyType type;
};


class Enemy1 : public Enemy {
public:
    Enemy1(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Right)
        : Enemy(HP, dmg, point, sp, ms, EnemyType::enemy1) {}

    void Update(double time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) override {
        double dx = 0, dy = 0;
        MoveDir tmp = GetDirection();
        if (tmp == MoveDir::Left){
            dx = -GetSpeed();
        }
        else if (tmp == MoveDir::Right){
            dx = GetSpeed();
        }
        else if (tmp == MoveDir::Down){
            dy = GetSpeed();
        }
        else if (tmp == MoveDir::Up){
            dy = -GetSpeed();
        }
        SetPoint(GetX() + dx * time, GetY() + dy * time);
        if (InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY)){
            if (tmp == MoveDir::Left){
                SetDirection(MoveDir::Right);
            }
            if (tmp == MoveDir::Right){
                SetDirection(MoveDir::Left);
            }
        }

    }


    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) override {
        double chX = GetX(), chY = GetY();
        int tileS = int(TileSize::Size);
        for (int i = chY/tileS; i < (chY + chSizeY)/tileS; i++){
            for (int j = chY/tileS; j < (chY + chSizeX)/tileS; j++){
                if (grid.GetTile().GetType() == Type::Wall){
                    if (dy > 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * tileS - chSizeY);
                        return true;
                    }
                    if (dy < 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * tileS + tileS);
                        return true;
                    }
                    if (dx > 0){
                        // position.SetX(j * chSize - chSize);
                        SetX(j * tileS - chSizeX);
                        return true;
                    }
                    if (dx < 0){
                        // position.SetY(j * chSize + chSize);
                        SetX(j * tileS + tileS);
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:

};


class Enemy2 : public Enemy {
public:
    Enemy2(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Up)
        : Enemy(HP, dmg, point, sp, ms, EnemyType::enemy1) {}
    

    void Update(double time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) override {
        double dx = 0, dy = 0;
        MoveDir tmp = GetDirection();
        if (tmp == MoveDir::Left){
            dx = -GetSpeed();
        }
        else if (tmp == MoveDir::Right){
            dx = GetSpeed();
        }
        else if (tmp == MoveDir::Down){
            dy = GetSpeed();
        }
        else if (tmp == MoveDir::Up){
            dy = -GetSpeed();
        }
        SetPoint(GetX() + dx * time, GetY() + dy * time);
        if (InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY)){
            if (tmp == MoveDir::Up){
                SetDirection(MoveDir::Down);
            }
            if (tmp == MoveDir::Down){
                SetDirection(MoveDir::Up);
            }
        }
    }

    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) override {
        double chX = GetX(), chY = GetY();
        int tileS = int(TileSize::Size);
        for (int i = chY/tileS; i < (chY + chSizeY)/tileS; i++){
            for (int j = chY/tileS; j < (chY + chSizeX)/tileS; j++){
                if (grid.GetTile().GetType() == Type::Wall){
                    if (dy > 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * tileS - chSizeY);
                        return true;
                    }
                    if (dy < 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * tileS + tileS);
                        return true;
                    }
                    if (dx > 0){
                        // position.SetX(j * chSize - chSize);
                        SetX(j * tileS - chSizeX);
                        return true;
                    }
                    if (dx < 0){
                        // position.SetY(j * chSize + chSize);
                        SetX(j * tileS + tileS);
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:

};


class Enemy3 : public Enemy {
public:
    Enemy3(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Up)
        : Enemy(HP, dmg, point, sp, ms, EnemyType::enemy1) {}

    
    void Update(double _time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) override {
        double dx = 0, dy = 0;
        MoveDir tmp = GetDirection();
        if (tmp == MoveDir::Left){
            dx = -GetSpeed();
        }
        else if (tmp == MoveDir::Right){
            dx = GetSpeed();
        }
        else if (tmp == MoveDir::Down){
            dy = GetSpeed();
        }
        else if (tmp == MoveDir::Up){
            dy = -GetSpeed();
        }
        SetPoint(GetX() + dx * _time, GetY() + dy * _time);
        if (InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY)) {
            srand(time(NULL));
            MoveDir tmp1 = tmp;
            while(tmp1 == tmp){
                tmp1 = static_cast<MoveDir>((rand() % 5));
                if (tmp1 == MoveDir::Stay)
                    tmp1 = tmp;
            }
            SetDirection(tmp1);
        }
        
    }

    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) override {
        double chX = GetX(), chY = GetY();
        int tileS = int(TileSize::Size);
        for (int i = chY/tileS; i < (chY + chSizeY)/tileS; i++){
            for (int j = chY/tileS; j < (chY + chSizeX)/tileS; j++){
                if (grid.GetTile().GetType() == Type::Wall){
                    if (dy > 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * tileS - chSizeY);
                        return true;
                    }
                    if (dy < 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * tileS + tileS);
                        return true;
                    }
                    if (dx > 0){
                        // position.SetX(j * chSize - chSize);
                        SetX(j * tileS - chSizeX);
                        return true;
                    }
                    if (dx < 0){
                        // position.SetY(j * chSize + chSize);
                        SetX(j * tileS + tileS);
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:

};


#endif //ENEMY_HPP