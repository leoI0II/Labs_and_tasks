#include<iostream>
#include<SFML/Graphics.hpp>
#include"FieldCage.hpp"


class Character{

};

class Hero : public Character{

};

class Enemy : public Character{

};

// class FieldCage{
// public:
//     enum class STATUS {NOT_AVAILABLE, AVAILABLE};
//     enum class ITEM {Empty, Hero, Enemy, Item1, Item2, Item3};
//     STATUS Status() const;
//     ITEM item() const;
// private:
//     STATUS fieldStatus;
//     ITEM itemOnField;
// };

class Field{

};



// class test{
// public:
//     enum class yr{jan, feb, mars, june, aug, sept};
//     void setY(yr _year){
//         year = _year;
//     }
//     yr getY(){
//         return year;
//     }
//     void size() const{
//         std::cout << sizeof(yr) << std::endl;
//     }
//     void www(){
//         std::cout << static_cast<int>(year) << std::endl;
//     }
// private:
//     // enum yr{jan, feb, mars, june, aug, sept};
//     yr year;

// };

class test{
private:
    int data;
protected:
    int pr_data;
public:
    test(int a = 5, int b = 6) : data(a), pr_data(b){}
    virtual void check(){
        std::cout << "Hello" << std::endl;
    }
    void c(){
        std::cout << data << " " << pr_data << std::endl;
    }
    virtual int& ch(){
        std::cout << "in test" << std::endl;
        return data;
    }
};
class test2: public test{
private:
    int date;
protected:
public:
    test2(int a, int b, int c): test(a, b), date(c){}
    // void check(){
    //     std::cout << date << " " << test::pr_data << std::endl;
    // }
    void check(){
        std::cout << "world" << std::endl;
    }
    int& ch(){
        std::cout << "in test2" << std::endl;
        return test::ch();
    }
};


int main(){

    test *a = new test;
    *a = test(10,20);
    a->c();

    // using namespace sf;
    // RenderWindow window(VideoMode(1200, 900), "SFML Works!");
    //     // sf::Texture texture;

    //     // texture.loadFromFile("pics/PNG/_land_6.jpg");
    //     // sf::Sprite sprite(texture, IntRect(0, 0, 360, 60));
    //     // sprite.setTexture(texture);
	// // Главный цикл приложения. Выполняется, пока открыто окно
	// while (window.isOpen())
	// {
	// 	// Обрабатываем очередь событий в цикле
	// 	Event event;
	// 	while (window.pollEvent(event))
	// 	{
	// 		// Пользователь нажал на «крестик» и хочет закрыть окно?
	// 		if (event.type == Event::Closed)
	// 			// тогда закрываем его
	// 			window.close();
	// 	}
    //     // sprite.move(300, 300);
    //     Texture texture;
 
	//    // Подгружаем нашу текстуру из файла texture.png
	//    texture.loadFromFile("pics/PNG/_land_6.jpg");
 
	// 	// Создаем спрайт и устанавливаем ему нашу текстуру
	// 	Sprite sprite(texture);
	// 	sprite.move(350, 350);

    //     window.draw(sprite);
	// // Отрисовка окна	
	//     window.display();
	// }

    // enum STATUS {NOT_AVAILABLE, AVAILABLE};
    // enum yr{jan, feb, mars, june, aug, sept};
    // STATUS st = AVAILABLE;

    // std::cout << st << std::endl;

    // test a;
    // a.setY(test::yr::mars);
    // switch(a.getY()){
    //     case test::yr::aug:
    //         std::cout << "Aug" << std::endl;
    //         break;
    //     case test::yr::mars:
    //         std::cout << "YEEE mars" << std::endl;
    //         break;
    // }
    // a.size();
    // a.www();
    
    // sf::RenderWindow window(sf::VideoMode(1280, 1024), "APPKA");
    // // window.clear(sf::Color(0, 0, 0));

    // while(window.isOpen()){

    //     sf::Event event;

    //     while(window.pollEvent(event)){
            
    //         switch(event.type){
    //             case sf::Event::Closed:
    //                 window.close();
    //                 break;
    //         }
    //     }

    //     window.display();
    // }

    return 0;
}