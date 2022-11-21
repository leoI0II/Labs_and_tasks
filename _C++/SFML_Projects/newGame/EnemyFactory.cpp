#include "EnemyFactory.hpp"

Point EnemyFactory::randomizer(FieldGrid& grid) {
    int x = 0, y = 0;
    srand(time(NULL));

    while (true) {
        x = 1 + rand() % (grid.getWidth() - 1);
        y = 1 + rand() % (grid.getHeight() - 1);
        if (grid.GetTile(y, x).GetType() == Type::Common)
            break;
    }
    return Point(x * int(TileSize::Size), y * int(TileSize::Size));
}

////////////////////////////////////////////////////////////////////////////////////

Enemy* Enemy1Fact::CreateEnemy(FieldGrid& grid) {
    Enemy* tmp = new Enemy1(100, 20, randomizer(grid), 0.15);
    grid.GetTile(tmp->GetY() / int(TileSize::Size), tmp->GetX() / int(TileSize::Size)).putEnemy(tmp);
    return tmp;
}

////////////////////////////////////////////////////////////////////////////////////

Enemy* Enemy2Fact::CreateEnemy(FieldGrid& grid) {
    Enemy* tmp = new Enemy2(100, 40, randomizer(grid), 0.13);
    grid.GetTile(tmp->GetY() / int(TileSize::Size), tmp->GetX() / int(TileSize::Size)).putEnemy(tmp);
    return tmp;
}

////////////////////////////////////////////////////////////////////////////////////

Enemy* Enemy3Fact::CreateEnemy(FieldGrid& grid) {
    Enemy* tmp = new Enemy3(100, 30, randomizer(grid), 0.14);
    grid.GetTile(tmp->GetY() / int(TileSize::Size), tmp->GetX() / int(TileSize::Size)).putEnemy(tmp);
    return tmp;
}

////////////////////////////////////////////////////////////////////////////////////