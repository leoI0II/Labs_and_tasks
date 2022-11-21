#include "ItemFactory.hpp"

Point ItemFactory::randomizer(FieldGrid& grid) {
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

///////////////////////////////////////////////////////////////////////////////////

Item* LittleHealthBottleFactory::CreateItem(FieldGrid& grid) {
    Item* tmp = new LittleHealthBottle(randomizer(grid));
    grid.GetTile(tmp->GetY() / int(TileSize::Size), tmp->GetX() / int(TileSize::Size)).putItem(tmp);
    return tmp;
}

///////////////////////////////////////////////////////////////////////////////////

Item* BigHealthBottleFactory::CreateItem(FieldGrid& grid) {
    Item* tmp = new BigHealthBottle(randomizer(grid));
    grid.GetTile(tmp->GetY() / int(TileSize::Size), tmp->GetX() / int(TileSize::Size)).putItem(tmp);
    return tmp;
}

///////////////////////////////////////////////////////////////////////////////////

Item* AmmoFactory::CreateItem(FieldGrid& grid) {
    Item* tmp = new Ammo(randomizer(grid));
    grid.GetTile(tmp->GetY() / int(TileSize::Size), tmp->GetX() / int(TileSize::Size)).putItem(tmp);
    return tmp;
}

///////////////////////////////////////////////////////////////////////////////////