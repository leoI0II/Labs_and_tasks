#ifndef BUILDDIRECTOR_HPP
#define BUILDDIRECTOR_HPP

#include"TileBuilder.hpp"

class BuildDirector{
public:
    BuildDirector(){}

    // void SetBuilder(ITileBuilder* newBuilder){
    //     builder = newBuilder;
    // }
    void SetBuilder(const std::shared_ptr<ITileBuilder>& newBuilder){
        builder = newBuilder;
    }
    void BuildTile(const Point& point){
        builder->SetPosition(point);
        builder->SetTileStatus();
        builder->SetTileType();
    }
    // std::shared_ptr<Tile> GetTile(){
    //     return builder->GetTile();
    // }

    ~BuildDirector(){}

private:
    std::shared_ptr<ITileBuilder> builder = nullptr;

};


#endif ///BUILDDIRECTOR_HPP