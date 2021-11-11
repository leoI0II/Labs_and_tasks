// #include<iostream>
#include<iostream>
#include<fstream>
// #include<cstdio>
#include<vector>
#include<initializer_list>

struct point{
public:
	double x;
	double y;
	point(const double _x, const double _y) : x(_x), y(_y) {}
	// point(const double& _x, const double& _y): x(_x), y(_y){}
	// point(double& _x, double& _y): x(_x), y(_y){}
	// void setX(double _x){ x = _x; }
	// void setY(double _y){ y = _y; }
	friend std::ostream& operator<<(std::ostream& out, point& a){
		out << a.x << " " << a.y;
		return out;
	}
};

class decart_coords{
	std::vector<point> coords_arr;
	int count;
public:
	decart_coords(){
		count = 0;
	}
	decart_coords& push_coords(point some_c){
		coords_arr.push_back(some_c);
		return *this;
	}
	decart_coords(decart_coords& cp){
		coords_arr = cp.coords_arr;
		count = cp.count;
	}
	decart_coords(const char* path){
		std::ifstream in(path);

		if (!in.is_open()) exit(EXIT_FAILURE);

		double x, y;

		while(!in.eof()){
			in >> x >> y;
			coords_arr.push_back(point(x, y));
		}

		coords_arr.pop_back();
		count = coords_arr.size();

		in.close();
	}
	~decart_coords(){}
	int size(){
		return coords_arr.size();
	}
	point& operator[](int i){
		return coords_arr[i];
	}
	const point& operator[](int i) const{
		return coords_arr[i];
	}
	friend std::ostream& operator<<(std::ostream& out, decart_coords& a){
		for (auto& elem: a.coords_arr){
			out << elem << " ";
		}
	}
	// void push_back(point& coords){
	// 	coords_arr.push_back(coords);
	// }
};

class delete_same_coords{			// private наследование также возможно
private:
	// decart_coords a;
	// decart_coords b;
	std::vector<decart_coords> coords;
	int count;
public:
	// delete_same_coords(decart_coords& first, decart_coords& second, ...){
	// 	a = first;
	// 	b = second;
	// }

	//----------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------

	delete_same_coords(const std::initializer_list<decart_coords>& list){
		count = list.size();
		// int i = 0;
		for (auto& element: list)
			coords.push_back(element);
	}

	void print(){
		// for (const auto& element: coords){
		// 	std::cout << element << " ";
		// }
		// std::cout << std::endl;
		for (int i = 0; i < count; i++)
			std::cout << coords[i] << " ";
	}

	//----------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------

	decart_coords return_diff_coords(){
		decart_coords ans;
		if (a.size() == b.size()){
			for (int i = 0; i < a.size() || i < b.size(); i++){
				if (a[i].x == b[i].x && a[i].y == b[i].y)
					continue;
				else{
					ans.push_coords(point(a[i].x, a[i].y));
					ans.push_coords(point(b[i].x, b[i].y));
				}
			}
		}
		else if (a.size() > b.size()){
			int i = 0;
			for (i; i < b.size(); i++){
				if (a[i].x == b[i].x && a[i].y == b[i].y)
					continue;
				else{
					ans.push_coords(point(a[i].x, a[i].y));
					ans.push_coords(point(b[i].x, b[i].y));
				}
			}
			for (i; i < a.size(); i++)
				ans.push_coords(point(a[i].x, a[i].y));
		}
		else{
			int i = 0;
			for (i; i < a.size(); i++){
				if (a[i].x == b[i].x && a[i].y == b[i].y)
					continue;
				else{
					ans.push_coords(point(a[i].x, a[i].y));
					ans.push_coords(point(b[i].x, b[i].y));
				}
			}
			for (i; i < b.size(); i++)
				ans.push_coords(point(b[i].x, b[i].y));
		}
		return ans;
	}
};

// class test{
// 	std::vector<int> arr;
// public:
// 	test(){ }

// 	void print(){
// 		for (auto elem: arr)
// 			std::cout << elem << " ";
// 		std::cout << std::endl;
// 	}
// 	friend void std::vector<int>::push_back(int&& value);
// };

int main(){
	using namespace std;

	vector<vector<int>> a{{1, 2, 3,4}, {122, 34 ,233, 64, 5234}};


	// a.push_back(vector<int>{1, 2, 3, 4, 5});
	// a.push_back(vector<int>{12, 23, 45, 67, 445, 32331});

	// a.push_back(vector<int>(3));
	// a.push_back(vector<int>(3));
	// a.push_back(vector<int>(3));
	// for (int i = 0; i < 3; i++)
	// 	for (int j = 0; j < 3; j++)
	// 		a[i][j] = i+j;

	for (auto& _elem: a){
		for (auto& elem: _elem){
			cout << elem << " ";
		}
		cout << endl;
	}

	// for (auto& elem: a)
	// 	cout << elem << endl;
	// for (int i = 0; i < a.size(); i++)
	// 	cout << a[i] << " ";

	return 0;
}
