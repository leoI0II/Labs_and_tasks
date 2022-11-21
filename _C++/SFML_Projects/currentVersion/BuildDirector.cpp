#include "BuildDirector.hpp"

BuildDirector::BuildDirector() {}

// void SetBuilder(ITileBuilder* newBuilder){
//     builder = newBuilder;
// }
void BuildDirector::SetBuilder(const std::shared_ptr<ITileBuilder>& newBuilder) {
    builder = newBuilder;
}
void BuildDirector::BuildTile(const Point& point) {
    builder->SetPosition(point);
    builder->SetTileStatus();
    builder->SetTileType();
}
// std::shared_ptr<Tile> GetTile(){
//     return builder->GetTile();
// }

BuildDirector::~BuildDirector() {}