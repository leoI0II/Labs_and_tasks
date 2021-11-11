#include<iostream>
#include<vector>
using namespace std;

class point{
    double x, y;
public:
    point(double _x = 0, double _y = 0): x(_x), y(_y){}
    point(const vector<double>& init){
        x = init[0]; y = init[1];
    }
    void setX(double _x){
        x = _x;
    }
    void setY(double _y){
        y = _y;
    }
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    friend ostream& operator<<(ostream& out, point& p){
        out << p.getX() << " " << p.getY();
        return out;
    }
    void operator=(const vector<double>& init){
        x = init[0]; y = init[1];
    }
};

class figure{
private:
    point* figure_points;
    int count_points;
public:
    figure(int points_count_figure){
        figure_points = new point[points_count_figure];
        count_points = points_count_figure;
    }
    const int& point_counts(){
        return count_points;
    };
    virtual ~figure(){
        delete [] figure_points;
    };
    point& get_i_point(int i){
        return figure_points[i];
    }
    virtual void check() = 0;
};


class Scalable{
public:
    virtual void scale(int new_size) = 0;
};
class Movable{
public:
    virtual void move(int move_count) = 0;
};

class Triangle: public figure, public Scalable, public Movable{
private:
    point find_center(){
        // point center;
        int x_sum = 0, y_sum = 0;
        for (int i = 0; i < 3; i++){
            x_sum += get_i_point(i).getX();
            y_sum += get_i_point(i).getY();
        }
        return {x_sum, y_sum};
    }
public:
    Triangle(const vector<point>& arr_points): figure(3){
        for (int i = 0; i < 3; i++){
            get_i_point(i) = arr_points[i];
        }
    }

    ~Triangle(){}
    void check(){
        for (int i = 0; i < 3; i++)
            cout << get_i_point(i) << endl;
    }
    void scale(int new_size){
        point center = find_center();
        for (int i = 0; i < 3; i++){
            get_i_point(i) = {get_i_point(i).getX() - center.getX(), get_i_point(i).getY() - center.getY()};
            get_i_point(i) = {get_i_point(i).getX() + new_size, get_i_point(i).getX() + new_size };
            get_i_point(i) = {get_i_point(i).getX() + center.getX(), get_i_point(i).getX() + center.getY()};
        }
    }
    void move(int move_count){
        for (int i = 0; i < 3; i++){
            get_i_point(i) = {get_i_point(i).getX() + move_count, get_i_point(i).getY() + move_count};
        }
    }
};

class Rect: public figure, public Scalable, public Movable{
private:
    point find_center(){
        point center;
        center.setX((get_i_point(1).getX() + get_i_point(0).getX())/2.0);
        center.setY((get_i_point(0).getY() + get_i_point(2).getY())/2.0);
        return center;
    }
public:
    Rect(const vector<point>& arr_points): figure(4){
        for (int i = 0; i < 4; i++)
            get_i_point(i) = arr_points[i];
    }
    ~Rect(){}
    void check(){
        for (int i = 0; i < 4; i++)
            cout << get_i_point(i) << endl;
    }
    void scale(int new_size){
        point center = find_center();
        // point tmp;
        for (int i = 0; i < 4; i++){
            get_i_point(i) = {get_i_point(i).getX() - center.getX(), get_i_point(i).getY() - center.getY()};
            // get_i_point(i).setX(get_i_point(i).getX() + new_size);
            // get_i_point(i).setY(get_i_point(i).getY() + new_size);
            get_i_point(i) = {get_i_point(i).getX() + new_size, get_i_point(i).getY() + new_size};
            get_i_point(i) = {get_i_point(i).getX() + center.getX(), get_i_point(i).getY() + center.getY()};
            // get_i_point(i).setX(get_i_point(i).getX() + center.getX());
            // get_i_point(i).setY(get_i_point(i).getY() + center.getY());
        }
    }
    void move(int move_count){
        for (int i = 0; i < 4; i++){
            get_i_point(i) = {get_i_point(i).getX() + move_count, get_i_point(i).getY() + move_count};
        }
    }
};


int main(){

    
    // tr.check();


    return 0;
}