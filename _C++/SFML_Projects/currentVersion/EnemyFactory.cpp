#include "EnemyFactory.hpp"

Point EnemyFactory::randomizer(FieldGrid& grid) {
    int x = 0, y = 0;
    //srand(time(NULL));

    while (true) {
        x = rand() % grid.getWidth();
        y = rand() % grid.getHeight();
        if (grid.GetTile(y, x).GetType() == Type::Common)
            break;
    }
    return Point(static_cast<double>(x * int(TileSize::Size)), static_cast<double>(y * int(TileSize::Size)));
}

////////////////////////////////////////////////////////////////////////////////////

Enemy* Enemy1Fact::CreateEnemy(FieldGrid& grid) {
    Enemy* tmp = new Enemy1(300, 30, randomizer(grid), 0.2);
    grid.GetTile(tmp->GetY() / int(TileSize::Size), tmp->GetX() / int(TileSize::Size)).putEnemy(tmp);
    return tmp;
}

////////////////////////////////////////////////////////////////////////////////////

Enemy* Enemy2Fact::CreateEnemy(FieldGrid& grid) {
    Enemy* tmp = new Enemy2(100, 20, randomizer(grid), 0.12);
    grid.GetTile(tmp->GetY() / int(TileSize::Size), tmp->GetX() / int(TileSize::Size)).putEnemy(tmp);
    return tmp;
}

////////////////////////////////////////////////////////////////////////////////////

Enemy* Enemy3Fact::CreateEnemy(FieldGrid& grid) {
    Enemy* tmp = new Enemy3(200, 20, randomizer(grid), 0.16);
    grid.GetTile(tmp->GetY() / int(TileSize::Size), tmp->GetX() / int(TileSize::Size)).putEnemy(tmp);
    return tmp;
}

////////////////////////////////////////////////////////////////////////////////////