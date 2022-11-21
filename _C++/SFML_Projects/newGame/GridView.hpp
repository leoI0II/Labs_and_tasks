// #pragma once
#ifndef GRIDVIEW_HPP
#define GRIDVIEW_HPP

#include"FieldGrid.hpp"
#include<map>
#include<string>
#include<initializer_list>
#include<SFML/Graphics.hpp>

class GridView
{
public:
    GridView(FieldGrid& _grid);
    ~GridView() {}

    void loadPictures(std::initializer_list<std::string> fpList);
    void loadPicsFromFile();
    void draw(sf::RenderWindow& window);

private:

    FieldGrid& grid;
    std::map<Type, std::string> filePaths;
};

#endif //GRIDVIEW_HPP