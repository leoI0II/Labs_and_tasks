#ifndef FIELD_HPP
#define FIELD_HPP

#include"FieldCage.hpp"
#include"CreateField.hpp"
#include<memory>

using cageArr_t = std::shared_ptr<FieldCage[]>;
using field_t = std::shared_ptr<cageArr_t[]>;


class CreateField;

class Field {
public:

    class iterator;

    Field();
    Field(CreateField creator);
    Field(const Field& otherField);
    Field(Field&& otherField);
    ~Field();

    Field& operator=(const Field& otherField);
    Field& operator=(Field&& otherField);

    Field::iterator Cage(int i = 0, int j = 0);

    iterator begin();
    iterator end();
    const int getHeight();
    const int getWidth();
    Field& setHeight(int newHeight);
    Field& setWidth(int newWidth);

    // friend CreateField::CreateField(const char* fp);

    class iterator{
    public:
        iterator(Field& _field, int i = 0, int j = 0) : field(_field) {
            i_pos = i; j_pos = j;
        }
        // iterator(iterator& cpy) : field(cpy.field), i_pos(cpy.i_pos), j_pos(cpy.j_pos){}
        iterator& operator=(iterator& other){
            field = other.field;
            i_pos = other.i_pos; j_pos = other.j_pos;
            return *this;
        }
        iterator(const iterator& it) : field(it.field), i_pos(it.i_pos), j_pos(it.j_pos){}
        iterator& operator=(iterator it){
            field = it.field;
            std::swap(i_pos, it.i_pos);
            std::swap(j_pos, it.j_pos);
            return *this;
        }
        ~iterator(){ /*std::cout << "DESTRUCTOR" << std::endl;*/}

        FieldCage& operator*(){
            return field.getCage(i_pos, j_pos);
        }

        iterator& operator++(){
            change_positios();
            return *this;
        }
        iterator operator++(int){
            iterator tmp(*this);
            change_positios();
            return tmp;
        }

        bool operator==(const iterator& end) const{
            return i_pos == end.i_pos;
        }

        bool operator!=(const iterator& end) const{
            return !(*this == end);
        }

        // void show(){
        //     std::cout << i_pos << " " << j_pos << std::endl;
        // }

    private:
        int i_pos;
        int j_pos;
        Field& field;
        
        void change_positios(){
            j_pos++;
            if (j_pos == field.getWidth()){
                i_pos++; j_pos = 0; return;
            }
        }

    };

private:
    // FieldCage** cageArray;
    int width;   //1200 = 20 * 60
    int height;  //900 = 15 * 60
    field_t cageArray;

    int x_startPos;
    int y_startPos;

    FieldCage& getCage(int i = 0, int j = 0);
};

#endif //FIELD_HPP