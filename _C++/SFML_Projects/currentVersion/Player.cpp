#include "Player.hpp"
#include "Enemy.hpp"
Player::Player(int HP, int dmg, Point& pos, double sp, int wQuant, MoveDir MD, MoveDir chD) :
    Character(HP, dmg, pos, sp, MD), weapon(wQuant, pos), checkDir(chD) {}

Player::~Player() {
    //for (int i = 0; i < 3; i++) {
    //    if (!bag[ItemType(i)].empty())
    //        for (int j = 0; j < bag[ItemType(i)].size(); j++)
    //            delete bag[ItemType(i)][j];
    //}
}

void Player::UseItem(const std::type_index& ind)
{
    if (!bag[ind].empty()) {
        Item* tmp = bag[ind].back();
        bag[ind].pop_back();
        if (ind == typeid(Ammo))
            tmp->Interact(&weapon);
        else
            tmp->Interact(this);
    }
}

void Player::AddToBag(Item* newItem) {
    if (typeid(*newItem) == typeid(LittleHealthBottle)) {
        bag[std::type_index(typeid(*newItem))].push_back(newItem);
        std::cout << "Little health bottle added to player bag" << std::endl;
    }
    else if (typeid(*newItem) == typeid(BigHealthBottle)) {
        bag[std::type_index(typeid(*newItem))].push_back(newItem);
        std::cout << "Big health bottle added to player bag" << std::endl;
    }
    else if (typeid(*newItem) == typeid(Ammo)) {
        bag[std::type_index(typeid(*newItem))].push_back(newItem);
        std::cout << "Ammo added to player bag" << std::endl;
    }
}

Bag_t& Player::GetBag()
{
    return bag;
}

Bullet* Player::Fire() {
    return weapon.reduseMagazine(checkDir);
}
void Player::SetCheckingDirection(MoveDir mv) {
    checkDir = mv;
}
MoveDir Player::GetPlayerCheckingDirection() const {
    return checkDir;
}

void Player::Update(double time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) {
    double dx = 0, dy = 0;
    //MoveDir tmp = GetDirection();
    int i = GetX() / int(TileSize::Size), j = GetY() / int(TileSize::Size);
    grid.GetTile(j, i).takePlayer();

    if (GetDirection() == MoveDir::Left) {
        dx = -GetSpeed();
        SetCheckingDirection(MoveDir::Left);
    }
    if (GetDirection() == MoveDir::Right) {
        dx = GetSpeed();
        SetCheckingDirection(MoveDir::Right);
    }
    if (GetDirection() == MoveDir::Down) {
        dy = GetSpeed();
        SetCheckingDirection(MoveDir::Down);
    }
    if (GetDirection() == MoveDir::Up) {
        dy = -GetSpeed();
        SetCheckingDirection(MoveDir::Up);
    }
    // SetPoint(GetX() + dx * time, GetY() + dy * time);
    SetX(GetX() + dx * time);
    InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY);
    SetY(GetY() + dy * time);
    InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY);

    i = GetX() / int(TileSize::Size); j = GetY() / int(TileSize::Size);
    grid.GetTile(j, i).putPlayer(this);
    if (grid.GetTile(j, i).hasEnemy()) {
        Enemy * enemy = grid.GetTile(j, i).takeEnemy();
        //Enemy3 temp(1, 1, Point(1, 1), 1);
        //Interact(enemy);  //Not Working
        Interact(enemy);
        grid.GetTile(j, i).putEnemy(enemy);
    }
    if (grid.GetTile(j, i).hasItem()) {
        Item* item = grid.GetTile(j, i).takeItem();
        item->SetStateItem(false);
        AddToBag(item);
    }

    SetDirection(MoveDir::Stay);
}

bool Player::InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) {
    int tileS = int(TileSize::Size);
    double chX = GetX(), chY = GetY();

    for (int i = chY / tileS; i < (chY + chSizeY) / tileS; i++) {
        for (int j = chX / tileS; j < (chX + chSizeX) / tileS; j++) {
            if (grid.GetTile(i, j).GetType() == Type::Wall) {
                if (dy > 0) {
                    SetY(static_cast<double>(i * tileS - chSizeY));
                }
                if (dy < 0) {
                    SetY(static_cast<double>(i * tileS + tileS));
                }
                if (dx > 0) {
                    SetX(static_cast<double>(j * tileS - chSizeX));
                }
                if (dx < 0) {
                    SetX(static_cast<double>(j * tileS + tileS));
                }
            }
        }
    }
    return false;

    //std::cout << int(GetY() / int(TileSize::Size)) << " " << int(GetX() / int(TileSize::Size)) << std::endl;
}

const Weapon& Player::GetWeapon() {
    return weapon;
}

void Player::SetFireState(bool state)
{
    fireState = state;
}

bool Player::GetFireState() const
{
    return fireState;
}

void Player::SetIsFire(bool isF)
{
    isFire = isF;
}

bool Player::GetIsFire() const
{
    return isFire;
}
