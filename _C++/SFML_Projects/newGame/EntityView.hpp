// #pragma once
#ifndef ENTITYVIEW_HPP
#define ENTITYVIEW_HPP

#include<SFML/Graphics.hpp>
#include"Entity.hpp"

class EntityView
{
public:
    EntityView(Entity& ent, const std::string& picPath);

    const sf::Sprite& GetSprite() const;

    // using sf::Sprite::setPosition;
    // using sf::Sprite::setRotation;
    // using sf::Sprite::setScale;
    // using sf::Sprite::setTexture;
    // using sf::Sprite::move;
    // using sf::Sprite::rotate;
    // using sf::Texture::loadFromFile;
    // using sf::Sprite::getPosition;
    // // using sf::Texture::update;

    float getPositionX();
    float getPositionY();

    int getSizeX();
    int getSizeY();

    void updateView(sf::RenderWindow& win);

    void ChangeSprite(const std::string& newPicPath);

    // Player& GetPlayerRef();

    // void draw(sf::RenderWindow& window);

private:
    Entity& entity;

    sf::Texture texture;
    sf::Sprite sprite;

    std::string picPath;
};

#endif //ENTITYVIEW_HPP