#ifndef PLAYERSBAG_HPP
#define PLAYERSBAG_HPP

#include"Player.hpp"
#include<SFML/Graphics.hpp>

using Bag_t = std::map<ItemType, std::vector<Item*>>;

class PlayersBagView
{
public:
	PlayersBagView(Bag_t& _bag, FieldGrid& grid);
	
	void UpdateView(sf::RenderWindow& win);

private:
	int edgeWidth;

	Bag_t& bag;
	std::map<ItemType, std::pair<sf::Texture, sf::Sprite>> gui;
	std::map<ItemType, std::pair<sf::Font, sf::Text>> fontsAndText;

	sf::Font bagFont;
	sf::Text bagText;
};

#endif //PLAYERSBAG_HPP