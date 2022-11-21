#include "PlayersBagView.hpp"

PlayersBagView::PlayersBagView(Bag_t& _bag, FieldGrid& grid) : bag(_bag)
{
	edgeWidth = grid.getWidth() * int(TileSize::Size) - 1;

	gui[std::type_index(typeid(LittleHealthBottle))].first.loadFromFile("L_.png");
	gui[std::type_index(typeid(LittleHealthBottle))].second.setTexture(
		gui[std::type_index(typeid(LittleHealthBottle))].first);
	gui[std::type_index(typeid(LittleHealthBottle))].second.setPosition(edgeWidth - int(TileSize::Size), 0);

	gui[std::type_index(typeid(BigHealthBottle))].first.loadFromFile("B_.png");
	gui[std::type_index(typeid(BigHealthBottle))].second.setTexture(
		gui[std::type_index(typeid(BigHealthBottle))].first);
	gui[std::type_index(typeid(BigHealthBottle))].second.setPosition(edgeWidth - 2 * int(TileSize::Size), 0);

	gui[std::type_index(typeid(Ammo))].first.loadFromFile("A_.png");
	gui[std::type_index(typeid(Ammo))].second.setTexture(
		gui[std::type_index(typeid(Ammo))].first);
	gui[std::type_index(typeid(Ammo))].second.setPosition(edgeWidth - 3 * int(TileSize::Size), 0);

	fontsAndText[std::type_index(typeid(LittleHealthBottle))].first.loadFromFile("Pixellettersfull-BnJ5.ttf");
	fontsAndText[std::type_index(typeid(LittleHealthBottle))].second.setFont(
		fontsAndText[std::type_index(typeid(LittleHealthBottle))].first);
	fontsAndText[std::type_index(typeid(LittleHealthBottle))].second.setFillColor(sf::Color::Red);
	fontsAndText[std::type_index(typeid(LittleHealthBottle))].second.setStyle(sf::Text::Style::Bold);
	fontsAndText[std::type_index(typeid(LittleHealthBottle))].second.setCharacterSize(40);
	fontsAndText[std::type_index(typeid(LittleHealthBottle))].second.setPosition(
		gui[std::type_index(typeid(LittleHealthBottle))].second.getPosition().x, 0);

	fontsAndText[std::type_index(typeid(BigHealthBottle))].first.loadFromFile("Pixellettersfull-BnJ5.ttf");
	fontsAndText[std::type_index(typeid(BigHealthBottle))].second.setFont(
		fontsAndText[std::type_index(typeid(BigHealthBottle))].first);
	fontsAndText[std::type_index(typeid(BigHealthBottle))].second.setFillColor(sf::Color::Red);
	fontsAndText[std::type_index(typeid(BigHealthBottle))].second.setStyle(sf::Text::Style::Bold);
	fontsAndText[std::type_index(typeid(BigHealthBottle))].second.setCharacterSize(40);
	fontsAndText[std::type_index(typeid(BigHealthBottle))].second.setPosition(
		gui[std::type_index(typeid(BigHealthBottle))].second.getPosition().x, 0);

	fontsAndText[std::type_index(typeid(Ammo))].first.loadFromFile("Pixellettersfull-BnJ5.ttf");
	fontsAndText[std::type_index(typeid(Ammo))].second.setFont(
		fontsAndText[std::type_index(typeid(Ammo))].first);
	fontsAndText[std::type_index(typeid(Ammo))].second.setFillColor(sf::Color::Red);
	fontsAndText[std::type_index(typeid(Ammo))].second.setStyle(sf::Text::Style::Bold);
	fontsAndText[std::type_index(typeid(Ammo))].second.setCharacterSize(40);
	fontsAndText[std::type_index(typeid(Ammo))].second.setPosition(
		gui[std::type_index(typeid(Ammo))].second.getPosition().x, 0);


	bagFont.loadFromFile("Pixellettersfull-BnJ5.ttf");
	bagText.setFont(bagFont);
	bagText.setFillColor(sf::Color::Black);
	bagText.setStyle(sf::Text::Style::Bold);
	bagText.setCharacterSize(50);
	bagText.setString("Player's bag:");
	bagText.setPosition(edgeWidth-int(TileSize::Size)*3 - 230, -10);
}

void PlayersBagView::UpdateView(sf::RenderWindow& win)
{
	win.draw(gui[std::type_index(typeid(LittleHealthBottle))].second);
	win.draw(gui[std::type_index(typeid(BigHealthBottle))].second);
	win.draw(gui[std::type_index(typeid(Ammo))].second);

	fontsAndText[std::type_index(typeid(LittleHealthBottle))].second.
			setString("x " + std::to_string(bag[std::type_index(typeid(LittleHealthBottle))].size()));
	win.draw(fontsAndText[std::type_index(typeid(LittleHealthBottle))].second);
	
	fontsAndText[std::type_index(typeid(BigHealthBottle))].second.
		setString("x " + std::to_string(bag[std::type_index(typeid(BigHealthBottle))].size()));
	win.draw(fontsAndText[std::type_index(typeid(BigHealthBottle))].second);

	fontsAndText[std::type_index(typeid(Ammo))].second.
		setString("x " + std::to_string(bag[std::type_index(typeid(Ammo))].size()));
	win.draw(fontsAndText[std::type_index(typeid(Ammo))].second);

	win.draw(bagText);
}
