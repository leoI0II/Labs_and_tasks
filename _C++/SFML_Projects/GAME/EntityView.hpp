#ifndef ENTITYVIEW_HPP
#define ENTITYVIEW_HPP

#include"Entity.hpp"
#include<SFML/Graphics.hpp>

class EntityView : sf::Texture, sf::Sprite {
public:
    EntityView(Entity& ent, std::string picPath) : entity(ent) {
        if(!sf::Texture::loadFromFile(picPath)) exit(EXIT_FAILURE);
        sf::Sprite::setTexture(static_cast<sf::Texture>(*this));
    }

    const sf::Sprite& GetSprite() const {
        return static_cast<const sf::Sprite&>(*this);
    }

    using sf::Sprite::setPosition;
    using sf::Sprite::setRotation;
    using sf::Sprite::setScale;
    using sf::Sprite::setTexture;
    using sf::Sprite::move;
    using sf::Sprite::rotate;
    using sf::Texture::loadFromFile;
    using sf::Sprite::getPosition;
    // using sf::Texture::update;

    void ChangeSprite(std::string newPicPath){
        sf::Texture::loadFromFile(newPicPath);
        sf::Sprite::setTexture(static_cast<sf::Texture>(*this));
    }

    // Player& GetPlayerRef() {
    //     return player;
    // }

    // void draw(sf::RenderWindow& window) {
    //     window.draw(sprite);
    // }

private:
    Entity& entity;

    // sf::Texture texture;
    // sf::Sprite sprite;
};



#endif //ENTITYVIEW_HPP