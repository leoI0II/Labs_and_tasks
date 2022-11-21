#include "Game.hpp"

Game::Game()
{
    GridCreator creator;
    grid = new FieldGrid(creator);
    gridView = new GridView(*grid);
    gridView->loadPicsFromFile();

    Point tmp = grid->GetStartPosition();
    tmp.SetPosition(tmp.GetX()+40, tmp.GetY()+40);
    player = new Player(100, 50, tmp, 0.15);
    playerView = new EntityView(*player, "P.png");
    pControl = new Controller(*player);

    Enemy1Fact enemy1F;
    Enemy2Fact enemy2F;
    Enemy3Fact enemy3F;

    Enemy* en1 = enemy1F.CreateEnemy(*grid);
    Enemy* en2 = enemy2F.CreateEnemy(*grid);
    Enemy* en3 = enemy3F.CreateEnemy(*grid);

    enemies.push_back(std::make_pair(en1, new EntityView(*en1, "E1.png")));
    enemies.push_back(std::make_pair(en2, new EntityView(*en2, "E2.png")));
    enemies.push_back(std::make_pair(en3, new EntityView(*en3, "E3.png")));

    LittleHealthBottleFactory LHBF;
    BigHealthBottleFactory BHBF;
    AmmoFactory AF;

    Item* lh = LHBF.CreateItem(*grid);
    Item* bh = BHBF.CreateItem(*grid);
    Item* am = AF.CreateItem(*grid);

    items.push_back(std::make_pair(lh, new EntityView(*lh, "L.png")));
    items.push_back(std::make_pair(bh, new EntityView(*bh, "B.png")));
    items.push_back(std::make_pair(am, new EntityView(*am, "A.png")));

}

void Game::HaveFun()
{

    sf::RenderWindow window(sf::VideoMode(grid->getWidth() * (int)TileSize::Size,
        grid->getHeight() * (int)TileSize::Size), "Game");

    sf::Clock clock;

    while (window.isOpen()) {
        double time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved){
                std::cout << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl;
            }
        }

        window.clear();

        gridView->draw(window);

        pControl->Control();
        player->Update(time, *grid, playerView->getSizeX(), playerView->getSizeY());
        if (player->GetHP() <= 0)
            window.close();
        // window.draw(playerView->GetSprite());
        playerView->updateView(window);

        // for (std::list<pairEnemy>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        //     it->first->Update(time, *grid, it->second->getPositionX(), it->second->getPositionY());
        //     // window.draw(it->second->GetSprite());
        //     it->second->updateView(window);
        // }
        // for (std::list<pairItem>::iterator it = items.begin(); it != items.end(); ++it) {
        //     // window.draw(it->second->GetSprite());
        //     it->second->updateView(window);
        // }

        // sf::Texture text;
        // text.loadFromFile("P.png");
        // sf::Sprite sprite;
        // sprite.setTexture(text);
        // sprite.setPosition(300, 300);

        // window.draw(sprite);

        window.display();

    }

}