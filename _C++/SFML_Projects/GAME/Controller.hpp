#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

// #include"EntityView.hpp"
#include<SFML/Graphics.hpp>
#include"Player.hpp"

class PlayerController {
public:
    PlayerController(Player& _view) : player(_view) {}

    void Control() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.SetDirection(MoveDir::Left);
		}
 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.SetDirection(MoveDir::Right);
		}
 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			player.SetDirection(MoveDir::Up);
		}
 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			player.SetDirection(MoveDir::Down);
		}
    }

private:

    // EntityView& view;
    Player& player;

};



#endif //CONTROLLER_HPP