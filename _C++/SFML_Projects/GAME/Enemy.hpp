#ifndef ENEMY_HPP
#define ENEMY_HPP

#include"Character.hpp"
#include<cstdlib>

class Enemy : public Character {
public:
    Enemy(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Stay)
        : Character(HP, dmg, point, sp, ms) {}

    ~Enemy(){}

private:

};


class Enemy1 : public Enemy {
public:
    Enemy1(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Right)
        : Enemy(HP, dmg, point, sp, ms) {}

    void Update(double time, FieldGrid& grid) override {
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
        if (InteractionWithGrid(grid, dx, dy)){
            if (tmp == MoveDir::Left){
                SetDirection(MoveDir::Right);
            }
            if (tmp == MoveDir::Right){
                SetDirection(MoveDir::Left);
            }
        }

    }


    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy) override {
        double chX = GetX(), chY = GetY();
        int chSize = int(TileSize::Size);
        for (int i = chY/chSize; i < (chY + chSize); i++){
            for (int j = chY/chSize; j < (chY + chSize); j++){
                if (grid.GetTile().GetType() == Type::Wall){
                    if (dy > 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * chSize + chSize);
                        return true;
                    }
                    if (dy < 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * chSize + chSize);
                        return true;
                    }
                    if (dx > 0){
                        // position.SetX(j * chSize - chSize);
                        SetX(j * chSize - chSize);
                        return true;
                    }
                    if (dx < 0){
                        // position.SetY(j * chSize + chSize);
                        SetX(j * chSize + chSize);
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
        : Enemy(HP, dmg, point, sp, ms) {}
    

    void Update(double time, FieldGrid& grid) override {
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
        if (InteractionWithGrid(grid, dx, dy)){
            if (tmp == MoveDir::Up){
                SetDirection(MoveDir::Down);
            }
            if (tmp == MoveDir::Down){
                SetDirection(MoveDir::Up);
            }
        }
    }

    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy) override {
        double chX = GetX(), chY = GetY();
        int chSize = int(TileSize::Size);
        for (int i = chY/chSize; i < (chY + chSize); i++){
            for (int j = chY/chSize; j < (chY + chSize); j++){
                if (grid.GetTile().GetType() == Type::Wall){
                    if (dy > 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * chSize + chSize);
                        return true;
                    }
                    if (dy < 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * chSize + chSize);
                        return true;
                    }
                    if (dx > 0){
                        // position.SetX(j * chSize - chSize);
                        SetX(j * chSize - chSize);
                        return true;
                    }
                    if (dx < 0){
                        // position.SetY(j * chSize + chSize);
                        SetX(j * chSize + chSize);
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
        : Enemy(HP, dmg, point, sp, ms) {}

    
    void Update(double _time, FieldGrid& grid) override {
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
        if (InteractionWithGrid(grid, dx, dy)) {
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

    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy) override {
        double chX = GetX(), chY = GetY();
        int chSize = int(TileSize::Size);
        for (int i = chY/chSize; i < (chY + chSize); i++){
            for (int j = chY/chSize; j < (chY + chSize); j++){
                if (grid.GetTile().GetType() == Type::Wall){
                    if (dy > 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * chSize + chSize);
                        return true;
                    }
                    if (dy < 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * chSize + chSize);
                        return true;
                    }
                    if (dx > 0){
                        // position.SetX(j * chSize - chSize);
                        SetX(j * chSize - chSize);
                        return true;
                    }
                    if (dx < 0){
                        // position.SetY(j * chSize + chSize);
                        SetX(j * chSize + chSize);
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