//#include <SFML/Graphics.hpp>
//
//using namespace sf;
//
//int main()
//{
//	// ������, �������, ����������, �������� ������� ����� ����������
//	RenderWindow window(VideoMode(200, 200), "SFML Works!");
//
//	// ������� ���� ����������. �����������, ���� ������� ����
//	while (window.isOpen())
//	{
//		// ������������ ������� ������� � �����
//		Event event;
//		while (window.pollEvent(event))
//		{
//			// ������������ ����� �� �������� � ����� ������� ����?
//			if (event.type == Event::Closed)
//				// ����� ��������� ���
//				window.close();
//		}
//
//		window.clear(Color(250, 220, 100, 0));
//		// ��������� ����	
//		window.display();
//	}
//
//	return 0;
//}


#include"Game.hpp"
#include<SFML/Graphics.hpp>

class test {
public:
	virtual void print() {
		std::cout << "In test" << std::endl;
	}
};
class testChild : public test {
public:
	void print() {
		std::cout << "In testChild" << std::endl;
	}
};

class SomeTest {

};

class ttt : public SomeTest {

};


int main() {

	//SomeTest st;
	//ttt t;

	//SomeTest* reft = &t;

	//std::cout << typeid(st).name() << std::endl;
	//std::cout << typeid(t).name() << std::endl;
	//std::cout << typeid(*reft).name() << std::endl;

	//std::string str(typeid(SomeTest).name());
	//size_t n = str.find(" ");

	//std::cout << str.c_str()+n+1 << std::endl;


	/*test t;
	t.print();

	testChild ch;
	ch.print();

	test& refT = ch;
	refT.print();

	if (typeid(refT) == typeid(test)) {
		std::cout << "YEs, refs work" << std::endl;
	}*/

	//std::string str = "HP = " + std::to_string(12);
	//std::cout << str << std::endl;

	Game game;
	game.HaveFun();


	//sf::RenderWindow win(sf::VideoMode(1200, 900), "APP");
	//srand(time(NULL));
	//sf::Font font;
	//if (!font.loadFromFile("Freedom-10eM.ttf")) {
	//	std::cerr << "Error" << std::endl;
	//	exit(EXIT_FAILURE);
	//}

	//sf::Text text;
	//text.setFont(font);
	//text.setFillColor(sf::Color::Red);
	//text.setString("HP");
	//text.setCharacterSize(40);
	//text.setStyle(sf::Text::Bold);

	//while (win.isOpen()) {
	//	sf::Event event;

	//	while (win.pollEvent(event)) {

	//		if (event.type == sf::Event::Closed) {
	//			win.close();
	//			return 0;
	//		}

	//		win.clear();

	//		sf::Texture txt;
	//		txt.loadFromFile("bullet3.png");

	//		sf::Sprite spr;
	//		spr.setTexture(txt);

	//		int x = rand() % 1000;
	//		int y = rand() % 800;

	//		text.setPosition(x, y);

	//		win.draw(spr);
	//		win.draw(text);

	//		win.display();

	//		/*if (event.type == sf::Event::KeyReleased) {
	//			if (event.key.code == sf::Keyboard::Space) {
	//				std::cout << "the space key was pressed" << std::endl;
	//				std::cout << "control:" << event.key.control << std::endl;
	//				std::cout << "alt:" << event.key.alt << std::endl;
	//				std::cout << "shift:" << event.key.shift << std::endl;
	//				std::cout << "system:" << event.key.system << std::endl;
	//			}
	//		}*/
	//	}
	//}


	// Enemy* a = new Enemy2(100, 20, Point(10, 10), 0.12, MoveDir::Down);
	// std::cout << a->GetDamage() << std::endl;


	return 0;
}