#include "GridView.hpp"

GridView::GridView(FieldGrid& _grid) : grid(_grid) {}

//void GridView::loadPictures(std::initializer_list<std::string> fpList) {
//    std::initializer_list<std::string>::iterator it;
//
//    int i = 0;
//    for (it = fpList.begin(); it != fpList.end(); it++)
//        filePaths.insert(std::pair<Type, std::string>(static_cast<Type>(i++), *it));
//}

void GridView::loadPicsFromFile() {

    std::ifstream file;
    try {
        file.open("GridSprites.txt");
        if (file.fail()) throw FileOpenExcept();
    }
    catch (FileOpenExcept& ex) {
        std::cout << ex.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string tmpPth;
    for (int i = 0; i < 4; i++) {
        try {
            std::getline(file, tmpPth);
            std::cout << i << std::endl;
            if (file.eof() && i < 3)
                throw std::ios_base::failure("Error reading file path to a sprite(there are less)");
        }
        catch (std::ios_base::failure& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Error code: " << ex.code().value() << std::endl;
            exit(EXIT_FAILURE);
        }
        //filePaths.insert(std::pair<Type, std::string>(static_cast<Type>(i), tmpPth));
        sf::Texture* t = new sf::Texture;
        t->loadFromFile(tmpPth);
        sf::Sprite* s = new sf::Sprite;
        s->setTexture(*t);
        sprites.insert(std::pair<Type, std::pair<sf::Texture*, sf::Sprite*>>(static_cast<Type>(i), std::pair<sf::Texture*, sf::Sprite*>(t, s)));
        //std::pair<sf::Texture*, sf::Sprite*> tmp = std::pair<sf::Texture*, sf::Sprite*>(t, s);
        
    }

}

void GridView::draw(sf::RenderWindow& window) {
    // sf::RenderWindow window(sf::VideoMode(grid.getWidth()*(int)TileSize::Size,
    //     grid.getHeight()*(int)TileSize::Size), "Game");

    // sf::Clock clock;

    // while(window.isOpen()){
    //     double time = clock.getElapsedTime().asMicroseconds();
    //     clock.restart();
    //     time = time / 800;

    //     sf::Event event;
    //     while(window.pollEvent(event)){

    //         if (event.type == sf::Event::Closed){
    //             window.close();
    //         }
    //     }

    //sf::Texture texture;
    //sf::Sprite sprite;

    FieldGrid::iterator it = grid.begin();
    for (it; it != grid.end(); ++it) {
        /*texture.loadFromFile(filePaths[(*it).GetType()]);
        sprite.setTexture(texture);*/
        //sprite.setTextureRect(sf::IntRect(0, 0, int(TileSize::Size), int(TileSize::Size)));
        //sprite.setPosition(int((*it).GetX()), int((*it).GetY()));
        //window.draw(sprite);
        sprites[(*it).GetType()].second->setPosition(int((*it).GetX()), int((*it).GetY()));
        window.draw(*(sprites[(*it).GetType()].second));
    }

    // window.display();


// }
}