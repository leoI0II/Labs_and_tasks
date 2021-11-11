#include"FieldView.hpp"
#include<iostream>
// #include"PlayerView.hpp"
#include"Player.hpp"
using namespace sf;

FieldView::FieldView(Field& _field, OutMode md) : mode(md), field(_field) {}

void FieldView::Mode(OutMode md) { mode = md; }

void FieldView::setField(Field& _field){
    field = std::ref(_field);
}

void FieldView::draw() {
    if (mode == OutMode::GUI) {
        sf::RenderWindow window(sf::VideoMode(field.getWidth()*(int)CageSize::Size, 
            field.getHeight()*(int)CageSize::Size), "Game");

        Player p;
        sf::Clock clock;
        while (window.isOpen()) {

            double time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;

            sf::Event event;

            while (window.pollEvent(event)) {

                switch (event.type) {
                    case sf::Event::Closed:
                    {
                        window.close();
                        break;
                    }
                }

            }

            sf::Texture herotext;
            herotext.loadFromFile("/home/leo/Projects/Obi-Wan/obi.png");
            Sprite heroSprite;
            heroSprite.setTexture(herotext);

            if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
                p.setMovement(MoveDirect::Left); p.setEntitySpeed(1);//dir =1 - направление вверх, speed =0.1 - скорость движения. Заметьте - время мы уже здесь ни на что не умножаем и нигде не используем каждый раз
                // CurrentFrame += 0.005*time;
                // if (CurrentFrame > 3) CurrentFrame -= 3; 
                // p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
            }
    
            if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
                // p.dir = 0; p.speed = 0.1;//направление вправо, см выше
                // CurrentFrame += 0.005*time;
                // if (CurrentFrame > 3) CurrentFrame -= 3; 
                // p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 192, 96, 96));  //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
                p.setMovement(MoveDirect::Right); p.setEntitySpeed(1);
            }
    
            if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) { 
                // p.dir = 3; p.speed = 0.1;//направление вниз, см выше
                // CurrentFrame += 0.005*time;
                // if (CurrentFrame > 3) CurrentFrame -= 3;
                // p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 288, 96, 96));  //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
                p.setMovement(MoveDirect::Up); p.setEntitySpeed(1);
            }
    
            if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква А
                // p.dir = 2; p.speed = 0.1;//направление вверх, см выше
                // CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
                // if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
                // p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
                p.setMovement(MoveDirect::Down); p.setEntitySpeed(1);
            }

            p.update(time, heroSprite);

            window.clear();

            sf::Texture texture;
            sf::Sprite sprite;

            // for (int i = 0; i < field.get().getHeight(); i++) {
            //     for (int j = 0; j < field.get().getWidth(); j++) {
            //         texture.loadFromFile(filePaths[field.get().getCage(i, j).getType()]);
            //         sprite.setTexture(texture);
            //         sprite.setTextureRect(sf::IntRect(0, 0, int(CageSize::Size), int(CageSize::Size)));
            //         sprite.setPosition(int(field.get().getCage(i, j).getX()), int(field.get().getCage(i, j).getY()));
            //         window.draw(sprite);
            //     }
            // }
            // std::cout << "HERE3" << std::endl;
            Field::iterator it = field.begin();
            for (it; it != field.end(); ++it){
                texture.loadFromFile(filePaths[(*it).getType()]);
                sprite.setTexture(texture);
                sprite.setTextureRect(sf::IntRect(0, 0, int(CageSize::Size), int(CageSize::Size)));
                sprite.setPosition(int((*it).getX()), int((*it).getY()));
                window.draw(sprite);
            }
		
            window.draw(heroSprite);

            window.display();
        }
    }
    else if (mode == OutMode::CLI) {
        // std::cout << "HERE5" << std::endl;
        Field::iterator it = field.begin();
        // for (int i = 0; i < field.get().getHeight(); i++) {
        //     for (int j = 0; j < field.get().getWidth(); j++) {
        //         std::cout << static_cast<int>(field.get().getCage(i, j).getType()) << " ";
        //     }
        //     std::cout << std::endl;
        // }
        int i = 0;
        // field.end().show();
        for (; it != field.end(); ++it){
            // it.show();
            std::cout << static_cast<int>((*it).getType()) << " ";
            i++;
            if (i == field.getWidth()){
                std::cout << std::endl;
                i = 0;
            }
        }
        // std::cout << "HERE6" << std::endl;
    }
    // std::cout << "HERE7" << std::endl;
}

void FieldView::loadPictures(std::initializer_list<std::string> fpList) {
    std::initializer_list<std::string>::iterator it;

    int i = 0;
    for (it = fpList.begin(); it != fpList.end(); it++)
        filePaths.insert(std::pair<Type, std::string>(static_cast<Type>(i++), *it));
}