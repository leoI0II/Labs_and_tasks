#include<SFML/Graphics.hpp>
#include<iostream>


int main(){

    sf::RenderWindow window(sf::VideoMode(500, 500), "SSSSS");

    while(window.isOpen()){

        sf::Event ev;

        while(window.pollEvent(ev)){
            if (ev.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        sf::Texture text;
        text.loadFromFile("P.png");
        sf::Sprite spr;
        spr.setTexture(text);
        spr.setPosition(250, 250);

        std::cout << text.getSize().x << " " << text.getSize().y << std::endl;

        window.draw(spr);

        window.display();


    }
}