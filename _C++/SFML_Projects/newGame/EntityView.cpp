#include "EntityView.hpp"

EntityView::EntityView(Entity& ent, const std::string& _picPath) : entity(ent), picPath(_picPath) {
    if (!texture.loadFromFile(_picPath))
        exit(EXIT_FAILURE);
    sprite.setTexture(texture);
    // if (!sf::Texture::loadFromFile(picPath)) exit(EXIT_FAILURE);
    // sf::Sprite::setTexture(static_cast<sf::Texture>(*this));
}

const sf::Sprite& EntityView::GetSprite() const {
    // return static_cast<const sf::Sprite&>(*this);
    return sprite;
}

void EntityView::ChangeSprite(const std::string& newPicPath) {
    // sf::Texture::loadFromFile(newPicPath);
    // sf::Sprite::setTexture(static_cast<sf::Texture>(*this));
    texture.loadFromFile(newPicPath);
    sprite.setTexture(texture);
}
float EntityView::getPositionX(){
        return sprite.getPosition().x;
}
float EntityView::getPositionY(){
    return sprite.getPosition().x;
}

int EntityView::getSizeX(){
    return texture.getSize().x;
}
int EntityView::getSizeY(){
    return texture.getSize().y;
}

void EntityView::updateView(sf::RenderWindow& win){
    // texture.loadFromFile(picPath);
    // sprite.setTexture(texture);
    sprite.setPosition(entity.GetX(), entity.GetY());
    win.draw(sprite);
}

// Player& EntityView::GetPlayerRef() {
//     return player;
// }

// void EntityView::draw(sf::RenderWindow& window) {
//     window.draw(sprite);
// }