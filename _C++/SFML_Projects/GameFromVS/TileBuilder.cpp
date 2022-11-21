#include "TileBuilder.hpp"

ExitTileBuilder::ExitTileBuilder() {
    tile.reset(new Tile);
}
ExitTileBuilder::~ExitTileBuilder() { tile.reset(); }

// void Reset(){
//     if (tile) delete tile;
//     tile = new Tile;
// }

Tile ExitTileBuilder::GetTile() {
    Tile res = *tile;
    tile.reset(new Tile);
    return res;
}

void ExitTileBuilder::SetTileType() {
    tile->SetType(Type::Exit);
}
void ExitTileBuilder::SetTileStatus() {
    tile->SetStatus(Status::Available);
}
void ExitTileBuilder::SetPosition(const Point& point) {
    tile->SetPosition(point);
}

///////////////////////////////////////////////////////////////

EntryTileBuilder::EntryTileBuilder() {
    tile.reset(new Tile);
}
EntryTileBuilder::~EntryTileBuilder() { tile.reset(); }

// void Reset(){
//     tile = new Tile;
// }

Tile EntryTileBuilder::GetTile() {
    Tile res = *tile;
    tile.reset(new Tile);
    return res;
}

void EntryTileBuilder::SetTileType() {
    tile->SetType(Type::Entry);
}
void EntryTileBuilder::SetTileStatus() {
    tile->SetStatus(Status::Available);
}
void EntryTileBuilder::SetPosition(const Point& point) {
    tile->SetPosition(point);
}

////////////////////////////////////////////////////////////////////////

CommonTileBuilder::CommonTileBuilder() {
    tile.reset(new Tile);
}
CommonTileBuilder::~CommonTileBuilder() { tile.reset(); }

// void Reset(){
//     tile = new Tile;
// }

Tile CommonTileBuilder::GetTile() {
    Tile res = *tile;
    tile.reset(new Tile);
    return res;
}

void CommonTileBuilder::SetTileType() {
    tile->SetType(Type::Common);
}
void CommonTileBuilder::SetTileStatus() {
    tile->SetStatus(Status::Available);
}
void CommonTileBuilder::SetPosition(const Point& point) {
    tile->SetPosition(point);
}

//////////////////////////////////////////////////////////////////////////

WallTileBuilder::WallTileBuilder() {
    tile.reset(new Tile);
}

WallTileBuilder::~WallTileBuilder() { tile.reset(); }

// void Reset(){
//     tile = new Tile;
// }

Tile WallTileBuilder::GetTile() {
    Tile res = *tile;
    tile.reset(new Tile);
    return res;
}

void WallTileBuilder::SetTileType() {
    tile->SetType(Type::Wall);
}
void WallTileBuilder::SetTileStatus() {
    tile->SetStatus(Status::NotAvailable);
}
void WallTileBuilder::SetPosition(const Point& point) {
    tile->SetPosition(point);
}