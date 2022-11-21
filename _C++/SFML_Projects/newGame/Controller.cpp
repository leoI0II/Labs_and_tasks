#include "Controller.hpp"

Controller::Controller(Player& _view) : player(_view) {}

void Controller::Control() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player.SetDirection(MoveDir::Left);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.SetDirection(MoveDir::Right);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player.SetDirection(MoveDir::Up);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player.SetDirection(MoveDir::Down);
	}
}