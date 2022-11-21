#include "PlayersBagView.hpp"

PlayersBagView::PlayersBagView(Bag_t& _bag, FieldGrid& grid) : bag(_bag)
{
	edgeWidth = grid.getWidth() * int(TileSize::Size) - 1;

	gui[ItemType::LittleHealthBottle].first.loadFromFile("L_.png");
	gui[ItemType::LittleHealthBottle].second.setTexture(
		gui[ItemType::LittleHealthBottle].first);
	gui[ItemType::LittleHealthBottle].second.setPosition(edgeWidth - int(TileSize::Size), 0);

	gui[ItemType::BigHealthBottle].first.loadFromFile("B_.png");
	gui[ItemType::BigHealthBottle].second.setTexture(
		gui[ItemType::BigHealthBottle].first);
	gui[ItemType::BigHealthBottle].second.setPosition(edgeWidth - 2 * int(TileSize::Size), 0);

	gui[ItemType::Ammo].first.loadFromFile("A_.png");
	gui[ItemType::Ammo].second.setTexture(
		gui[ItemType::Ammo].first);
	gui[ItemType::Ammo].second.setPosition(edgeWidth - 3 * int(TileSize::Size), 0);

	fontsAndText[ItemType::LittleHealthBottle].first.loadFromFile("Pixellettersfull-BnJ5.ttf");
	fontsAndText[ItemType::LittleHealthBottle].second.setFont(
		fontsAndText[ItemType::LittleHealthBottle].first);
	fontsAndText[ItemType::LittleHealthBottle].second.setFillColor(sf::Color::Red);
	fontsAndText[ItemType::LittleHealthBottle].second.setStyle(sf::Text::Style::Bold);
	fontsAndText[ItemType::LittleHealthBottle].second.setCharacterSize(40);
	fontsAndText[ItemType::LittleHealthBottle].second.setPosition(
		gui[ItemType::LittleHealthBottle].second.getPosition().x, 0);

	fontsAndText[ItemType::BigHealthBottle].first.loadFromFile("Pixellettersfull-BnJ5.ttf");
	fontsAndText[ItemType::BigHealthBottle].second.setFont(
		fontsAndText[ItemType::BigHealthBottle].first);
	fontsAndText[ItemType::BigHealthBottle].second.setFillColor(sf::Color::Red);
	fontsAndText[ItemType::BigHealthBottle].second.setStyle(sf::Text::Style::Bold);
	fontsAndText[ItemType::BigHealthBottle].second.setCharacterSize(40);
	fontsAndText[ItemType::BigHealthBottle].second.setPosition(
		gui[ItemType::BigHealthBottle].second.getPosition().x, 0);

	fontsAndText[ItemType::Ammo].first.loadFromFile("Pixellettersfull-BnJ5.ttf");
	fontsAndText[ItemType::Ammo].second.setFont(
		fontsAndText[ItemType::Ammo].first);
	fontsAndText[ItemType::Ammo].second.setFillColor(sf::Color::Red);
	fontsAndText[ItemType::Ammo].second.setStyle(sf::Text::Style::Bold);
	fontsAndText[ItemType::Ammo].second.setCharacterSize(40);
	fontsAndText[ItemType::Ammo].second.setPosition(
		gui[ItemType::Ammo].second.getPosition().x, 0);


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
	win.draw(gui[ItemType::LittleHealthBottle].second);
	win.draw(gui[ItemType::BigHealthBottle].second);
	win.draw(gui[ItemType::Ammo].second);

	fontsAndText[ItemType::LittleHealthBottle].second.
			setString("x " + std::to_string(bag[ItemType::LittleHealthBottle].size()));
	win.draw(fontsAndText[ItemType::LittleHealthBottle].second);
	
	fontsAndText[ItemType::BigHealthBottle].second.
		setString("x " + std::to_string(bag[ItemType::BigHealthBottle].size()));
	win.draw(fontsAndText[ItemType::BigHealthBottle].second);

	fontsAndText[ItemType::Ammo].second.
		setString("x " + std::to_string(bag[ItemType::Ammo].size()));
	win.draw(fontsAndText[ItemType::Ammo].second);

	win.draw(bagText);
}
