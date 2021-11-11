#ifndef FIELDCAGE_HPP
#define FIELDCAGE_HPP

#include<iostream>
#include<memory>
#include"Item.hpp"
#include"Player.hpp"

enum class Status { NOT_AVAILABLE, AVAILABLE };
enum class Type { Exit, Common, Entry, Wall };
enum class CageSize {Size = 60};

class FieldCage {
public:
    FieldCage(int x = 0, int y = 0, Type tp = Type::Common, Status st = Status::NOT_AVAILABLE);
    ~FieldCage() {}

    Status getStatus();
    Type getType();

    FieldCage& setType(Type _type);
    FieldCage& setStatus(Status st);

    int getX() const;
    // FieldCage& setX(int x);

    int getY() const;
    // FieldCage& setY(int y);


    // friend std::ostream& operator<<(std::ostream& out, FieldCage& cage){
    //     out << static_cast<int>(cage.cageType());
    //     return out;
    // }
    // friend std::ostream& operator<<(std::ostream& out, FieldCage* cage){
    //     out << static_cast<int>(cage->cageType());
    //     return out;
    // }

private:
    int x_coord;
    int y_coord;

    Type type;
    Status status;

};


#endif //FIELDCAGE_HPP