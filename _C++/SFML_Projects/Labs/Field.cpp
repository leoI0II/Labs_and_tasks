#include"Field.hpp"
#include"CreateField.hpp"
#include<utility>


Field::Field() : cageArray(nullptr), width(0), height(0) {}

Field::~Field() {
    // if (cageArray){
    //     for (int i = 0; i < height; i++)
    //         delete[] cageArray[i];
    //     delete[] cageArray;
    // }
}

//FIXED
Field::Field(const Field& otherField) 
    : width(otherField.width), height(otherField.height), cageArray(new cageArr_t[height]) {
    
    x_startPos = otherField.x_startPos;
    y_startPos = otherField.y_startPos;
    // cageArray = new FieldCage*[height];
    // for (int i = 0; i < height; i++){
    //     cageArray[i] = new FieldCage[width];
    //     for (int j = 0; j < width; j++)
    //         cageArray[i][j] = otherField.cageArray[i][j];
    // }

    // cageArray = std::make_shared<cageArr_t[]>(height);


    for (int i = 0; i < height; i++){
        cageArray[i] = std::shared_ptr<FieldCage[]>(new FieldCage[width]);
        for (int j = 0; j < width; j++)
            cageArray[i][j] = otherField.cageArray[i][j];
    }
}

Field::Field(Field&& otherField) : Field() {
    std::swap(cageArray, otherField.cageArray);
    std::swap(height, otherField.height);
    std::swap(width, otherField.width);
    std::swap(x_startPos, otherField.x_startPos);
    std::swap(y_startPos, otherField.y_startPos);
}

Field::Field(CreateField creator)
    : cageArray(nullptr), width(creator.fieldW), height(creator.fieldH) {
    
    // std::swap(cageArray, creator.cages);
    cageArray.swap(creator.cages);          //or .release
    x_startPos = creator.x_start;
    y_startPos = creator.y_start;
}

Field& Field::operator=(const Field& otherField) {
    if (this == &otherField)
        return *this;
    if (cageArray){                                         //delete if smth
        for (int i = 0; i < height; i++)
            cageArray[i].reset();
        cageArray.reset();
    }
    width = otherField.width; height = otherField.height;
    x_startPos = otherField.x_startPos; y_startPos = otherField.y_startPos;
    
    // cageArray = new FieldCage*[height];
    // for (int i = 0; i < height; i++){
    //     cageArray[i] = new FieldCage[width];
    //     for (int j = 0; j < width; j++)
    //         cageArray[i][j] = otherField.cageArray[i][j];
    // }

    // cageArray = std::make_shared<cageArr_t[]>(height);
    cageArray = std::shared_ptr<cageArr_t[]>(new cageArr_t[height]);
    for (int i = 0; i < height; i++){
        // cageArray[i] = std::make_shared<FieldCage[]>(width);
        cageArray[i] = std::shared_ptr<FieldCage[]>(new FieldCage[width]);
        for (int j = 0; j < width; j++)
            cageArray[i][j] = otherField.cageArray[i][j];
    }

    return *this;
}

Field& Field::operator=(Field&& otherField) {
    if (this != &otherField){
        std::swap(cageArray, otherField.cageArray);
        std::swap(height, otherField.height);
        std::swap(width, otherField.width);
        std::swap(x_startPos, otherField.x_startPos);
        std::swap(y_startPos, otherField.y_startPos);
    }
    return *this;
}

FieldCage& Field::getCage(int i, int j) {
    return cageArray[i][j];
}

Field::iterator Field::Cage(int i, int j){
    return iterator(*this, i, j);
}

//FIXED
const int Field::getHeight() {
    return height;
}

Field& Field::setHeight(int newH) { height = newH; return *this; }

const int Field::getWidth() {
    return width;
}

Field& Field::setWidth(int newW) { width = newW; return *this; }

Field::iterator Field::begin(){
    return Field::iterator(*this, 0, 0);
}

Field::iterator Field::end(){
    return Field::iterator(*this, height, width);
}


