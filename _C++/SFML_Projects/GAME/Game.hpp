#ifndef GAME_HPP
#define GAME_HPP

#include"EntityView.hpp"
#include"Player.hpp"
#include"EnemyFactory.hpp"
#include"ItemFactory.hpp"
#include<list>
#include"GridView.hpp"
#include"Controller.hpp"

using pairEnemy = std::pair<Enemy*, EntityView*>;
using pairItem = std::pair<Item*, EntityView*>;

class Game{
public:

    Game()
    {
        GridCreator creator;
        grid = new FieldGrid(creator);
        gridView = new GridView(*grid);
        gridView->loadPicsFromFile();

        player = new Player(100, 50, grid->GetStartPosition(), 0.5);
        playerView = new EntityView(*player, "P.png");
        pControl = new PlayerController(*player);

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

    void HaveFun()
    {

        sf::RenderWindow window(sf::VideoMode(grid->getWidth()*(int)TileSize::Size,
            grid->getHeight()*(int)TileSize::Size), "Game");

        sf::Clock clock;

        while(window.isOpen()){
            double time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;

            sf::Event event;

            while(window.pollEvent(event)){

                if (event.type == sf::Event::Closed){
                    window.close();
                }
            }

            window.clear();

            pControl->Control();
            player->Update(time, *grid, playerView->getPosition().x, playerView->getPosition().x);
            if (player->GetHP() <= 0)
                window.close();
            window.draw(playerView->GetSprite());

            for (std::list<pairEnemy>::iterator it = enemies.begin(); it != enemies.end(); ++it){
                it->first->Update(time, *grid, it->second->getPosition().x, it->second->getPosition().y);
                window.draw(it->second->GetSprite());
            }
            for (std::list<pairItem>::iterator it = items.begin(); it != items.end(); ++it){
                window.draw(it->second->GetSprite());
            }

            gridView->draw(window);

            window.display();

        }

    }


private:

    Player* player;
    EntityView* playerView;

    // std::list<Enemy*>& enemies;
    std::list<pairEnemy> enemies;

    // std::list<Item*>& items;
    // std::list<std::pair<Item*, EntityView*>> items;
    std::list<pairItem> items;

    FieldGrid* grid;
    GridView* gridView;

    PlayerController* pControl;

};



#endif ///GAME_HPP