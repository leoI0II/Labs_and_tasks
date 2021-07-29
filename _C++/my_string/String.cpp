#include <iostream>
#include<string>
#include<cstring>
#include<ostream>
#include<istream>
#include<cmath>
// #include<cstdlib>
// #include<boost/filesystem/string_file.hpp>
using namespace std;


class String{
private:
	char* str = nullptr;
	int size = 0;
	int capasity = 0;

public:
	//constructors
	String() : size(0), capasity(0){
		str = NULL;
		// cout << endl << "Created an empty object" << endl;
	}
	String(const char* _str){
		capasity = size = strlen(_str);
		str = new char[size + 1];
		strcpy(str, _str);
		// cout << endl << "Object created! " << str << endl;
	}

	String(const String& cpy){
		capasity = size = cpy.size;
		str = new char[size + 1];
		strcpy(str, cpy.str);
		// cout << endl << "Object created!! " << str << endl;
	}

	//destructor
	~String(){
		// cout << "Deleting " << str << endl;
		if (str)
			delete [] str;
	}

	//operators =
	String& operator=(const String& cpy){
		if(this == &cpy){
			return *this;
		}
		if (str)
			delete [] str;
		capasity = size = cpy.size;
		str = new char[size + 1];
		strcpy(str, cpy.str);
		// cout << "Object created!!!" << str << endl;
		return *this;
	}

	void operator=(const char* lit){
		// cout << endl << "Here!" << endl;

		delete [] str;
		size = capasity = strlen(lit);
		str = new char[size + 1];
		strcpy(str, lit);
	}

	//operators +
	friend const String operator+(const String& a, const String& b);
	friend const String operator+(const char* a, const String& b);
	friend const String operator+(const String& a, const char* b);
	// String operator+(String& b){
	// 	char* tmp = new char[size + b.size + 1];
	// 	if (str == NULL){
	// 		if (b.str == NULL){
	// 			tmp[0] = 0;
	// 		} else {
	// 			strcpy(tmp, b.str);
	// 		}
	// 	} else {
	// 		strcpy(tmp, str);
	// 		strcat(tmp, b.str);
	// 	}
	// 	// String a(tmp);
	// 	return String(tmp);
	// }

	String operator+=(const String& a){
		size = capasity = a.size + size;
		char* tmp = new char[size + 1];
		if (!str){
			if (!a.str){
				tmp[0] = 0;
			}
			else{
				strcpy(tmp, a.str);
			}
		}
		else{
			strcpy(tmp, str);
			strcat(tmp, a.str);
		}
		delete [] str;
		str = new char[size + 1];
		strcpy(str, tmp);
		delete [] tmp;
		return *this;
	}
	String operator+=(const char *a){
		size = capasity = strlen(a) + size;
		char* tmp = new char[size + 1];
		if (!str)
			strcpy(tmp, a);
		else{
			strcpy(tmp, str);
			strcat(tmp, a);
		}
		delete [] str;
		str = new char[size + 1];
		strcpy(str, tmp);
		delete [] tmp;
		return *this;
	}


	friend bool operator==(const String& a, const String& b);
	friend bool operator<(const String& a, const String& b);
	friend bool operator>(const String& a, const String& b);


	int _size(){
		return size;
	}

	char& operator[](int i){
		return str[i];
	}




	bool is_digit(){
		if (this->str[0] == '-'){
			for (int i = 1; i < this->size; i++)
				if (!isdigit(this->str[i]))
					return false;
			return true;
		}
		else{
			for (int i = 0; i < this->size; i++)
				if (!isdigit(this->str[i]))
					return false;
			return true;
		}
	}
	operator int(){
		int a = 0;
		for (int i = 0; i < size; i++){
			a += (int(str[i])-48)*pow(10, size-1-i);
		}
		return a;
	}
	int count_sym(char sym);
	void stringup();
	void stringlow();


	//Enter/output
	friend istream& operator>>(istream& in, String& a);
	friend ostream& operator<<(ostream& out, String& a);


};////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

bool operator==(const String& a, const String& b){
	return strcmp(a.str, b.str) == 0;
}

bool operator<(const String& a, const String& b){
	return strcmp(a.str, b.str) < 0;
}

bool operator>(const String& a, const String& b){
	return strcmp(a.str, b.str) > 0;
}

const String operator+(const char* a, const String& b){
	char* tmp = new char[strlen(a) + b.size + 1];
	strcpy(tmp, a);
	strcat(tmp, b.str);
	return tmp;
}

const String operator+(const String& a, const char* b){
	char* tmp = new char[strlen(b) + a.size + 1];
	strcpy(tmp, a.str);
	strcat(tmp, b);
	return tmp;
}

const String operator+(const String& a, const String& b){
	char* tmp = new char[a.size + b.size + 1];
	if (a.str == NULL){
		if (b.str == NULL){
			tmp[0] = 0;
		} else {
			strcpy(tmp, b.str);
		}
	} else {
		strcpy(tmp, a.str);
		strcat(tmp, b.str);
	}
	// String a(tmp);
	return String(tmp);
}

istream& operator>>(istream& in, String& a){
	char *tmp = new char[1024];
	// getline(in, 1024);
	in.getline(tmp, 1024);
	a.size = a.capasity = strlen(tmp);
	a.str = new char[a.size];
	strcpy(a.str, tmp);
	delete [] tmp;
	return in;
}

ostream& operator<<(ostream& out, String& a){
	out << a.str;
	return out;
}

void String::stringlow(){
	for (int i = 0; i < size; i++)
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
}
void String::stringup(){
	for (int i = 0; i < size; i++)
		if(islower(str[i]))
			str[i] = toupper(str[i]);
}

int String::count_sym(char sym){
	int count = 0;
	for (int i = 0; i < size; i++)
		if (str[i] == sym)
			count++;
	return count;
}


int main(){



	{
		// String s1(" and I am a C++ student.");
		// String s2 = "Please enter your name: "; // ввод имени
		// String s3;
		// cout << s2; // перегруженная операция <<
		// cin >> s3; // перегруженная операция >>
		// s2 = "My name is " + s3; // перегруженные операции =, +
		// cout << s2 << " . \n";
		// s2 = s2 + s1;
		// s2.stringup (); // преобразование строки в верхний регистр
		// cout << "The string\n" << s2 << "\ncontains " << s2.count_sym('A') << " 'A' characters in it.\n";
		// s1 = "red"; // String(const char *) ,
		// // тогда String & operator= (const Strings)
		// String rgb[3] = { String (s1), String("green"), String("blue")} ;
		// cout << "Enter the name of a primary color for mixing light: " ; // ввод цвета
		// String ans;
		// bool success = false;
		// while (cin >> ans)
		// {
		// 	ans.stringlow(); // преобразование строки в нижний регистр
		// 	for (int i = 0; i < 3; i++ )
		// 	{
		// 		if (ans == rgb[i]) // перегруженная операция ==
		// 		{
		// 			cout << "That's right!\n";
		// 			success = true;
		// 			break;
		// 		}
		// 	}
		// 	if (success)
		// 		break;
		// 	else
		// 		cout << "Try again! \n";
		// }
		// cout << "Bye\n";
	}

	{
		// String a("Hello "), b = "World!";
		// String c;
		// c = a + b;
		// cout << c << endl;

		// String x;
		// x = "HEHEHEHE" + b + "Shalom";
		// cout << x << endl;
	}

	{
		// String a("lol");
		// if (a == "lol")
		// 	cout << "Yep" << endl;
	}

	{
		// String a("Hekko ");
		// String b("Motto ");
		// cout << a << endl << b << endl;
		// a += b;
		// cout << a << endl << b << endl;

		// b += a + "Hello";
		// cout << a << endl << b << endl;

		// String c("Hello ");
		// c += "World!";
		// cout << c << endl;

		// String v;
		// v += c + "Shalov";
		// cout << v << endl;
	}

	{
		// String a;
		// cin >> a;
		// cout << a;
	}

	{
		// char* a = new char[22];
		// char* b = new char[22];
		// cin.get(a, 22).get(b, 22);		//оставляет перевод строки в потоке ввода, в б загоняется только перевод строки
		// cout << a << endl;
		// cout << b << endl;
	}

	return 0;
}
