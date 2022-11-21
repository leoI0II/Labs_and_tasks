// #pragma once
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include<SFML/Graphics.hpp>
#include"Player.hpp"

class Controller
{
public:
	Controller(Player& _view);

	void Control();

private:

	// EntityView& view;
	Player& player;
};

#endif //CONTROLLER_HPP