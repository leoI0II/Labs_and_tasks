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

int main() {


	Game game;
	game.HaveFun();

	// Enemy* a = new Enemy2(100, 20, Point(10, 10), 0.12, MoveDir::Down);
	// std::cout << a->GetDamage() << std::endl;


	return 0;
}