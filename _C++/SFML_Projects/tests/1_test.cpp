#include<iostream>
#include<SFML/Graphics.hpp>

using namespace sf;

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
//     window.clear(sf::Color(255, 255, 255, 0));
//     window.setPosition(sf::Vector2i(300, 200));

//     sf::CircleShape shape(0);
//     shape.setFillColor(sf::Color::Magenta);
//     shape.setPosition(250, 250);
//     // shape.setRotation(90);
//     // shape.setPointCount(20);
//     shape.move(0, 0);
//     int i = 0;

//     window.setKeyRepeatEnabled(false);
//     while(window.isOpen())
//     {
//         sf::Event event;
        
//         while(window.pollEvent(event))
//         {
//             // if (event.type == sf::Event::Closed)
//             //     window.close();
            
//             // sf::String str;                      //DO NOT WORK!
//             // std::getline(std::cin, str);         //
//             // std::cin >> str;                     //
//             // std::cout << str << std::endl;       //

//             switch(event.type){
//                 case sf::Event::Closed:
//                     window.close();
//                     break;
//                 case sf::Event::KeyPressed:
//                     std::cout << "Hello from console" << std::endl;
//                     break;
//                 case sf::Event::Resized:
//                 {
//                     std::cout << "New width " << event.size.width << std::endl;
//                     std::cout << "New heigth " << event.size.height << std::endl;
//                     break;
//                 }
//                 case sf::Event::LostFocus:
//                 {
//                     std::cout << "LOST FOCUS" << std::endl;
//                     break;
//                 }
//                 case sf::Event::GainedFocus:
//                 {
//                     std::cout << "YEAH!! We are on the game!" << std::endl;
//                     break;
//                 }
//                 default:
//                     break;
//             }
//             if (event.type == sf::Event::KeyPressed)
//             {
//                 if (event.key.code == sf::Keyboard::Escape)
//                 {
//                     std::cout << "the escape key was pressed" << std::endl;
//                     std::cout << "control:" << event.key.control << std::endl;
//                     std::cout << "alt:" << event.key.alt << std::endl;
//                     std::cout << "shift:" << event.key.shift << std::endl;
//                     std::cout << "system:" << event.key.system << std::endl;
//                 }
//             }

//             if (event.type == sf::Event::MouseWheelScrolled)
//             {
//                 if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
//                     std::cout << "wheel type: vertical" << std::endl;
//                 else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
//                     std::cout << "wheel type: horizontal" << std::endl;
//                 else
//                     std::cout << "wheel type: unknown" << std::endl;
//                 std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
//                 std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
//                 std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
//             }

//             if (event.type == sf::Event::MouseButtonPressed)        //OR sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)
//             {
//                 if (event.mouseButton.button == sf::Mouse::Right)
//                 {
//                     std::cout << "the right button was pressed" << std::endl;
//                     std::cout << "mouse x: " << event.mouseButton.x << std::endl;
//                     std::cout << "mouse y: " << event.mouseButton.y << std::endl;
//                 }
//             }
//             if (event.type == sf::Event::MouseMoved)
//             {
//                 std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
//                 std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
//             }
//         }
//         if(i == 250) i = 0;
//         i++;
//         window.clear(sf::Color(255, 255, 255, 0));
//         shape.setRadius(i);
//         window.draw(shape);
//         window.display();
//     }

//     return 0;
// }


int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(700, 700), "SFML Works!");
 
	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем события в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		// Установка цвета фона - белый
		window.clear(Color::White);
 
		// Создаем переменную текстуры
		Texture texture;
 
	   // Подгружаем нашу текстуру из файла texture.png
	   texture.loadFromFile("puff.png", IntRect(300, 300, 100, 100));
 
		// Создаем спрайт и устанавливаем ему нашу текстуру
		Sprite sprite(texture);
		sprite.move(350, 350);
		// Отрисовка спрайта	 
		window.draw(sprite);
 
		// Отрисовка окна
		window.display();
	}
 
	return 0;
}