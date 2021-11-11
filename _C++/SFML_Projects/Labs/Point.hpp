#ifndef POINT_HPP
#define POINT_HPP

struct Point{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}

    Point& operator+(const Point& _p){
        x += _p.x;
        y += _p.y;
        return *this;
    }
    Point& operator-(const Point& _p){
        
    }
};


#endif  //POINT_HPP