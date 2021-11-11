#include"FieldGrid.hpp"

FieldGrid::FieldGrid() : grid(nullptr), width(0), height(0) {}

//FIXED
FieldGrid::FieldGrid(const FieldGrid& otherField) 
    : width(otherField.width), height(otherField.height), grid(new tileArr_t[height]) {
    
    startPosition = otherField.startPosition;
    // grid = new Tile*[height];
    // for (int i = 0; i < height; i++){
    //     grid[i] = new Tile[width];
    //     for (int j = 0; j < width; j++)
    //         grid[i][j] = otherField.grid[i][j];
    // }

    // grid = std::make_shared<tileArr_t[]>(height);


    for (int i = 0; i < height; i++){
        grid[i] = std::shared_ptr<Tile[]>(new Tile[width]);
        for (int j = 0; j < width; j++)
            grid[i][j] = otherField.grid[i][j];
    }
}

FieldGrid::FieldGrid(FieldGrid&& otherField) : FieldGrid() {
    std::swap(grid, otherField.grid);
    std::swap(height, otherField.height);
    std::swap(width, otherField.width);
    std::swap(startPosition, otherField.startPosition);
}

FieldGrid::FieldGrid(GridCreator& creator) : FieldGrid() {
    height = creator.GetHeight(); width = creator.GetWidth();
    grid.swap(creator.GetGrid());
    std::swap(startPosition, creator.GetStartPos());
    
}

FieldGrid& FieldGrid::operator=(const FieldGrid& otherField) {
    if (this == &otherField)
        return *this;
    if (grid){                                         //delete if smth
        for (int i = 0; i < height; i++){
            // for (int j = 0; j < width; j++){
            //     grid[i][j].reset();
            // }
            grid[i].reset();
        }
        grid.reset();
    }
    width = otherField.width; height = otherField.height;
    startPosition = otherField.startPosition;
    
    // grid = new Tile*[height];
    // for (int i = 0; i < height; i++){
    //     grid[i] = new Tile[width];
    //     for (int j = 0; j < width; j++)
    //         grid[i][j] = otherField.grid[i][j];
    // }

    // grid = std::make_shared<tileArr_t[]>(height);
    grid = std::shared_ptr<tileArr_t[]>(new tileArr_t[height]);
    for (int i = 0; i < height; i++){
        // grid[i] = std::make_shared<Tile[]>(width);
        grid[i] = std::shared_ptr<Tile[]>(new Tile[width]);
        for (int j = 0; j < width; j++)
            grid[i][j] = otherField.grid[i][j];
    }

    return *this;
}

FieldGrid& FieldGrid::operator=(FieldGrid&& otherField) {
    if (this != &otherField){
        std::swap(grid, otherField.grid);
        std::swap(height, otherField.height);
        std::swap(width, otherField.width);
        std::swap(startPosition, otherField.startPosition);
    }
    return *this;
}

Tile& FieldGrid::GetTile(int i, int j) {
    return grid[i][j];
}

FieldGrid::iterator FieldGrid::GetIterTile(int i, int j){
    return iterator(*this, i, j);
}

const int FieldGrid::getHeight() {
    return height;
}

FieldGrid& FieldGrid::setHeight(int newH) { height = newH; return *this; }

const int FieldGrid::getWidth() {
    return width;
}

FieldGrid& FieldGrid::setWidth(int newW) { width = newW; return *this; }

FieldGrid::iterator FieldGrid::begin(){
    return FieldGrid::iterator(*this, 0, 0);
}

FieldGrid::iterator FieldGrid::end(){
    return FieldGrid::iterator(*this, height, width);
}