#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include"Point.hpp"
#include"ICharacter.hpp"
#include"FieldGrid.hpp"

class Character : public ICharacter {
public:
    Character(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Stay) :
        healthPoints(HP),
        damage(dmg),
        position(point),
        speed(sp),
        moveState(ms) {}
    ~Character(){}
    
    void SetPoint(const Point& point) override {
        position = point;
    }
    void SetPoint(double _x, double _y) override {
        position.SetX(_x).SetY(_y);
    }
    Point GetPoint() const override {
        return position;
    }
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

    void SetHP(int plusHP) override {
        // if (plusHP < 0 && healthPoints <= plusHP){           //killing case
        //     //  killing
        // }
        healthPoints += plusHP;
    }
    int GetHP() const override {
        return healthPoints;
    }
    void Interact(Entity* probablyEnemyOfThis) override {
        // probablyEnemyOfThis->SetHP(-GetDamage());
        dynamic_cast<ICharacter*>(probablyEnemyOfThis)->SetHP(-GetDamage());
    }
    int GetDamage() const override{
        return damage;
    }
    void SetSpeed(double newSp) override {
        speed = newSp;
    }
    double GetSpeed() const override {
        return speed;
    }
    void SetDirection(MoveDir newDir) override {
        moveState = newDir;
    }
    MoveDir GetDirection() const override {
        return moveState;
    }

    // void SetState(State st) override { state = st; }
    // State GetState() const override { return state; }

    // void InteractionWithGrid(FieldGrid& grid, double& dx, double& dy) override {
    //     double chX = GetX(), chY = GetY();
    //     int chSize = int(TileSize::Size);
    //     for (int i = chY/chSize; i < (chY + chSize); i++){
    //         for (int j = chY/chSize; j < (chY + chSize); j++){
    //             if (grid.GetTile().GetType() == Type::Wall){
    //                 if (dy > 0){
    //                     position.SetY(i * chSize + chSize);
    //                 }
    //                 if (dy < 0){
    //                     position.SetY(i * chSize + chSize);
    //                 }
    //                 if (dx > 0){
    //                     position.SetX(j * chSize - chSize);
    //                 }
    //                 if (dx < 0){
    //                     position.SetY(j * chSize + chSize);
    //                 }
    //             }
    //         }
    //     }
    // }

private:

    int healthPoints;
    int damage;
    Point position;
    double speed;
    MoveDir moveState;
    // State state;
};


#endif //CHARACTER_HPP