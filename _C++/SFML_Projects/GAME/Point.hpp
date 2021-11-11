#ifndef POINT_HPP
#define POINT_HPP

class Point{
public:
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    const double GetX() const{
        return x;
    }
    
    const double GetY() const{
        return y;
    }
    
    Point& SetX(double _x){
        x = _x;
        return *this;
    }
    
    Point& SetY(double _y){
        y = _y;
        return *this;
    }
    Point& SetPosition(double _x, double _y){
        x = _x; y = _y;
        return *this;
    }
    Point& SetPosition(const Point& point){
        *this = point;
        return *this;
    }
    bool operator==(const Point& otherP){
        return (x == otherP.x && y == otherP.y ? true : false);
    }


private:
    double x;
    double y;
};



#endif ///POINT_HPP