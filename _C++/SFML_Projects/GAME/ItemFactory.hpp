#ifndef ITEMFACTORY_HPP
#define ITEMFACTORY_HPP

#include"Item.hpp"

class ItemFactory {
public:
    virtual Item* CreateItem(FieldGrid&) = 0;
protected:
    Point randomizer(FieldGrid& grid) {
        int x = 0, y = 0;
        srand(time(NULL));

        while(true){
            x = 1 + rand() % (grid.getWidth() - 1);
            y = 1 + rand() % (grid.getHeight() - 1);
            if (grid.GetTile(y, x).GetType() == Type::Common)
                break;
        }
        return Point(x*int(TileSize::Size), y*int(TileSize::Size));
    }
};
class LittleHealthBottleFactory : public ItemFactory {
public:
    Item* CreateItem(FieldGrid& grid) override {
        Item* tmp = new LittleHealthBottle(randomizer(grid));
        grid.GetTile(tmp->GetY()/int(TileSize::Size), tmp->GetX()/int(TileSize::Size)).putItem(tmp);
        return tmp;
    }
};
class BigHealthBottleFactory : public ItemFactory {
public:
    Item* CreateItem(FieldGrid& grid) override {
        Item* tmp = new BigHealthBottle(randomizer(grid));
        grid.GetTile(tmp->GetY()/int(TileSize::Size), tmp->GetX()/int(TileSize::Size)).putItem(tmp);
        return tmp;
    }
};
class AmmoFactory : public ItemFactory {
public:
    Item* CreateItem(FieldGrid& grid) override {
        Item* tmp = new Ammo(randomizer(grid));
        grid.GetTile(tmp->GetY()/int(TileSize::Size), tmp->GetX()/int(TileSize::Size)).putItem(tmp);
        return tmp;
    }
};


#endif //ITEMFACTORY_HPP