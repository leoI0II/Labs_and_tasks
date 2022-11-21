// #pragma once
#ifndef TILEBUILDER_HPP
#define TILEBUILDER_HPP

#include"ITileBuilder.hpp"

class Tile;

class ExitTileBuilder : public ITileBuilder
{
public:
    ExitTileBuilder();
    ~ExitTileBuilder();

    // void Reset(){
    //     if (tile) delete tile;
    //     tile = new Tile;
    // }

    Tile GetTile();

    void SetTileType();
    void SetTileStatus();
    void SetPosition(const Point& point);

private:
    // Tile* tile = nullptr;
    std::shared_ptr<Tile> tile;
};

//////////////////////////////////////////////////////////////////////////

class EntryTileBuilder : public ITileBuilder {
public:
    EntryTileBuilder();
    ~EntryTileBuilder();

    // void Reset(){
    //     tile = new Tile;
    // }

    Tile GetTile();

    void SetTileType();
    void SetTileStatus();
    void SetPosition(const Point& point);

private:
    // Tile* tile = nullptr;
    std::shared_ptr<Tile> tile;
};

////////////////////////////////////////////////////////////////////////////

class CommonTileBuilder : public ITileBuilder {
public:
    CommonTileBuilder();
    ~CommonTileBuilder();

    // void Reset(){
    //     tile = new Tile;
    // }

    Tile GetTile();

    void SetTileType();
    void SetTileStatus();
    void SetPosition(const Point& point);

private:
    // Tile* tile = nullptr;
    std::shared_ptr<Tile> tile;
};

/////////////////////////////////////////////////////////////////////////////////////

class WallTileBuilder : public ITileBuilder {
public:
    WallTileBuilder();

    ~WallTileBuilder();

    // void Reset(){
    //     tile = new Tile;
    // }

    Tile GetTile();

    void SetTileType();
    void SetTileStatus();
    void SetPosition(const Point& point);

private:
    // Tile* tile = nullptr;
    std::shared_ptr<Tile> tile;
};

#endif //TILEBUILDER_HPP