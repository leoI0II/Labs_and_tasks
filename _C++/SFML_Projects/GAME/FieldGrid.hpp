#ifndef FIELDGRID_HPP
#define FIELDGRID_HPP

#include"Tile.hpp"
#include<memory>
#include"CreateGrid.hpp"
#include"Player.hpp"
#include"Enemy.hpp"
#include"Item.hpp"
#include<list>
#include<cstdlib>

using tileArr_t = std::shared_ptr<Tile[]>;
using grid_t = std::shared_ptr<tileArr_t[]>;


class FieldGrid{
public:
    class iterator;

    FieldGrid();
    FieldGrid(GridCreator& creator);
    FieldGrid(const FieldGrid& otherField);
    FieldGrid(FieldGrid&& otherField);
    ~FieldGrid(){}

    FieldGrid& operator=(const FieldGrid& otherField);
    FieldGrid& operator=(FieldGrid&& otherField);

    FieldGrid::iterator GetIterTile(int i = 0, int j = 0);
    Tile& GetTile(int i = 0, int j = 0);

    iterator begin();
    iterator end();
    const int getHeight();
    const int getWidth();
    FieldGrid& setHeight(int newHeight);
    FieldGrid& setWidth(int newWidth);

    const Point& GetStartPosition() const;
    const Point& GetEndPosition() const;

    class iterator{
    public:
        iterator(FieldGrid& _field, int i = 0, int j = 0) : field(_field) {
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

        Tile& operator*(){
            return field.GetTile(i_pos, j_pos);
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

    private:
        int i_pos;
        int j_pos;
        FieldGrid& field;
        
        void change_positios(){
            j_pos++;
            if (j_pos == field.getWidth()){
                i_pos++; j_pos = 0; return;
            }
        }

    };



private:
    int width;
    int height;

    grid_t grid;
    Point startPosition;
    Point endPosition;
};





#endif ///FIELDGRID_HPP