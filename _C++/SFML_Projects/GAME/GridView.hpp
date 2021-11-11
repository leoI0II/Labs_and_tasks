#ifndef GRIDVIEW_HPP
#define GRIDVIEW_HPP

#include"FieldGrid.hpp"
#include<map>
#include<string>
#include<initializer_list>
#include<SFML/Graphics.hpp>

enum class OutMode { CLI, GUI };

class GridView{

public:
    GridView(FieldGrid& _grid, OutMode md = OutMode::CLI);
    ~GridView(){}

    void Mode(OutMode _mode);
    void loadPictures(std::initializer_list<std::string> fpList);
    void loadPicsFromFile();
    void draw();

private:
    
    FieldGrid& grid;
    OutMode mode;
    std::map<Type, std::string> filePaths;
};


#endif ///GRIDVIEW_HPP