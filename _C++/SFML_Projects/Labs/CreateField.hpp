#ifndef CREATE_FIELD_HPP
#define CREATE_FIELD_HPP

#include"FieldCage.hpp"
#include"Field.hpp"
#include<memory>

using cageArr_t = std::shared_ptr<FieldCage[]>;
using field_t = std::shared_ptr<cageArr_t[]>;

class Field;

class CreateField {
    field_t cages;
    int fieldH;
    int fieldW;
    void findParams(const char* fp);

    int x_start, y_start;

public:
    CreateField(const char* filePath);
    ~CreateField();

    // const FieldCage** getCages();
    // int fieldHeight();
    // int fieldWidth();
    friend class Field;         //???? friend class Field::Field(CreateField&);
};

#endif //CREATE_FIELD_HPP