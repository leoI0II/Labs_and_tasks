#include"FieldCage.hpp"
// #include<iostream>

FieldCage::FieldCage(int x, int y, Type tp, Status st)
    : x_coord(x), y_coord(y), type(tp), status(st) {}

Status FieldCage::getStatus() {
    return status;
}

Type FieldCage::getType() {
    return type;
}

FieldCage& FieldCage::setStatus(Status st) { status = st; return *this; }
FieldCage& FieldCage::setType(Type _type) { type = _type; return *this; }

int FieldCage::getX() const {
    return x_coord;
}

// FieldCage& FieldCage::setX(int x) {
//     x_coord = x;
//     return *this;
// }

int FieldCage::getY() const {
    return y_coord;
}

// FieldCage& FieldCage::setY(int y) {
//     y_coord = y;
//     return *this;
// }