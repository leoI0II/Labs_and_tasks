// #pragma once
#ifndef BUILDDIRECTOR_HPP
#define BUILDDIRECTOR_HPP

#include"TileBuilder.hpp"

class ITileBuilder;

class BuildDirector
{
public:
    BuildDirector();

    // void SetBuilder(ITileBuilder* newBuilder){
    //     builder = newBuilder;
    // }
    void SetBuilder(const std::shared_ptr<ITileBuilder>& newBuilder);
    void BuildTile(const Point& point);
    // std::shared_ptr<Tile> GetTile(){
    //     return builder->GetTile();
    // }

    ~BuildDirector();

private:
    std::shared_ptr<ITileBuilder> builder = nullptr;
};

#endif//BUILDDIRECTOR_HPP