// #pragma once
#ifndef POINT_HPP
#define POINT_HPP

class Point
{
public:
    
    Point(double _x = 0, double _y = 0);

    const double GetX() const;
    const double GetY() const;
    Point& SetX(double _x);
    Point& SetY(double _y);
    Point& SetPosition(double _x, double _y);
    Point& SetPosition(const Point& point);
    bool operator==(const Point& otherP);


private:
    double x;
    double y;
};

#endif //POINT_HPP