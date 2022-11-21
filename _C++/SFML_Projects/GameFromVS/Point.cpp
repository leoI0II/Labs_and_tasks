#include "Point.hpp"

Point::Point(double _x, double _y) : x(_x), y(_y) {}

bool Point::operator==(const Point& otherP) {
    return (x == otherP.x && y == otherP.y ? true : false);
}

Point& Point::SetPosition(const Point& point) {
    *this = point;
    return *this;
}
Point& Point::SetPosition(double _x, double _y) {
    x = _x; y = _y;
    return *this;
}
Point& Point::SetY(double _y) {
    y = _y;
    return *this;
}
Point& Point::SetX(double _x) {
    x = _x;
    return *this;
}
const double Point::GetY() const {
    return y;
}
const double Point::GetX() const {
    return x;
}