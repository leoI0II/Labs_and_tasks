#include<iostream>
#include<cmath>
#include<exception>

class Vec3D{
public:
    Vec3D(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {}

    Vec3D operator-(){
        return Vec3D(-x, -y, -z);
    }

    Vec3D& operator+(Vec3D vec){
        *this = Vec3D(x+vec.x, y+vec.y, z+vec.z);
        return *this;
    }
    Vec3D& operator-(Vec3D vec){
        *this = operator+(-vec);
        return *this;
    }

    Vec3D& operator+(double someNum){
        *this = Vec3D(x+someNum, y+someNum, z+someNum);
        return *this;
    }

    Vec3D& operator-(double someNum){
        *this = Vec3D(x-someNum, y-someNum, z-someNum);
        return *this;
    }

    double operator()(){
        return std::sqrt(x*x+y*y+z*z);
    }

    double operator[](char ch){
            if (ch == 'x')
                return x;
            else if (ch == 'y')
                return y;
            else if (ch == 'z')
                return z;
            else
                throw std::invalid_argument("Access error");
    }


    friend Vec3D operator*(Vec3D& vec, double num);
    friend double operator*(Vec3D& vec1, Vec3D& vec2);
    friend std::istream& operator>>(std::istream& in, Vec3D& vec);
    friend std::ostream& operator<<(std::ostream& out, Vec3D& vec);
    friend Vec3D operator+(double someNum, Vec3D& vec);
    friend Vec3D operator-(double num, Vec3D& vec);
private:
    double x;
    double y;
    double z;

};

Vec3D operator*(Vec3D& vec, double num){
    return Vec3D(vec.x*num, vec.y*num, vec.z*num);
}



double operator*(Vec3D& vec1, Vec3D& vec2){
    return vec1.x*vec2.x+vec1.y*vec2.y+vec1.z*vec2.z;
}



std::istream& operator>>(std::istream& in, Vec3D& vec){
    in >> vec.x >> vec.y >> vec.z;
    return in;
}

Vec3D operator+(double someNum, Vec3D& vec){
    return Vec3D(someNum+vec.x, someNum+vec.y, someNum+vec.z);
}

Vec3D operator-(double num, Vec3D& vec){
    return Vec3D(num-vec.x, num-vec.y, num-vec.z);
}

std::ostream& operator<<(std::ostream& out, Vec3D& vec){
    out << "{" << vec.x << ", " << vec.y << ", " << vec.z << "}";
    return out;
}

int main(){

    Vec3D vec1(1.2, 2.4, 3.5);

    std::cout << vec1 << std::endl;

    vec1 = -vec1;
    std::cout << vec1 << std::endl;

    Vec3D vec2;
    std::cin >> vec2;
    std::cout << vec2 << std::endl;

    vec2 = vec1-vec2;
    std::cout << vec2 << std::endl;



    double x = vec2['x'];
    std::cout << x << std::endl;


    try{
        double y = vec2['w'];

        std::cout << y << std::endl;
    }
    catch(std::invalid_argument& err){
        err.what();
    }



    return 0;

}



