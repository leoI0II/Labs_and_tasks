#include "ItemFactory.hpp"

Point ItemFactory::randomizer(FieldGrid& grid) {
    int x = 0, y = 0;
    //srand(time(0));

    while (true) {
        x = rand() % grid.getWidth();
        y = rand() % grid.getHeight();
        if (grid.GetTile(y, x).GetType() == Type::Common)
            break;
    }
    return Point(static_cast<double>(x * int(TileSize::Size)), static_cast<double>(y * int(TileSize::Size)));
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