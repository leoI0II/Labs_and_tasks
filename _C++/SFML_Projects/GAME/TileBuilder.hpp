#ifndef TILEBUILDER_HPP
#define TILEBUILDER_HPP

#include"ITileBuilder.hpp"

class ExitTileBuilder : public ITileBuilder{
public:
    ExitTileBuilder(){
        tile.reset(new Tile);
    }
    ~ExitTileBuilder(){ tile.reset(); }

    // void Reset(){
    //     if (tile) delete tile;
    //     tile = new Tile;
    // }

    Tile GetTile(){
        Tile res = *tile;
        tile.reset(new Tile);
        return res;
    }

    void SetTileType(){
        tile->SetType(Type::Exit);
    }
    void SetTileStatus(){
        tile->SetStatus(Status::Available);
    }
    void SetPosition(const Point& point){
        tile->SetPosition(point);
    }

private:
    // Tile* tile = nullptr;
    std::shared_ptr<Tile> tile;
};


class EntryTileBuilder : public ITileBuilder{
public:
    EntryTileBuilder(){
        tile.reset(new Tile);
    }
    ~EntryTileBuilder(){ tile.reset();}

    // void Reset(){
    //     tile = new Tile;
    // }

    Tile GetTile(){
        Tile res = *tile;
        tile.reset(new Tile);
        return res;
    }

    void SetTileType(){
        tile->SetType(Type::Entry);
    }
    void SetTileStatus(){
        tile->SetStatus(Status::Available);
    }
    void SetPosition(const Point& point){
        tile->SetPosition(point);
    }

private:
    // Tile* tile = nullptr;
    std::shared_ptr<Tile> tile;
};

class CommonTileBuilder : public ITileBuilder{
public:
    CommonTileBuilder(){
        tile.reset(new Tile);
    }
    ~CommonTileBuilder(){ tile.reset();}

    // void Reset(){
    //     tile = new Tile;
    // }

    Tile GetTile(){
        Tile res = *tile;
        tile.reset(new Tile);
        return res;
    }

    void SetTileType(){
        tile->SetType(Type::Common);
    }
    void SetTileStatus(){
        tile->SetStatus(Status::Available);
    }
    void SetPosition(const Point& point){
        tile->SetPosition(point);
    }

private:
    // Tile* tile = nullptr;
    std::shared_ptr<Tile> tile;
};

class WallTileBuilder : public ITileBuilder{
public:
    WallTileBuilder(){
        tile.reset(new Tile);
    }

    ~WallTileBuilder(){ tile.reset();}

    // void Reset(){
    //     tile = new Tile;
    // }

    Tile GetTile(){
        Tile res = *tile;
        tile.reset(new Tile);
        return res;
    }

    void SetTileType(){
        tile->SetType(Type::Wall);
    }
    void SetTileStatus(){
        tile->SetStatus(Status::NotAvailable);
    }
    void SetPosition(const Point& point){
        tile->SetPosition(point);
    }

private:
    // Tile* tile = nullptr;
    std::shared_ptr<Tile> tile;
};

#endif