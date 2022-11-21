// #pragma once
#ifndef GAME_HPP
#define GAME_HPP

#define _CRT_SECURE_NO_WARNINGS
#include"EntityView.hpp"
#include"Player.hpp"
#include"EnemyFactory.hpp"
#include"ItemFactory.hpp"
#include<list>
#include<vector>
#include"GridView.hpp"
#include"Controller.hpp"
#include"PlayersBagView.hpp"
#include"CAFLogger.hpp"
#include<chrono>
#include<ctime>
#include"GameStats.hpp"
#include"EnemyKillerEvent.hpp"
#include"TimeEvent.hpp"

using pairEnemy = std::pair<Enemy*, EntityView*>;
using pairItem = std::pair<Item*, EntityView*>;
using pairBullet = std::pair<Bullet*, EntityView*>;

template<class TimeEv, class EKE>
class Game
{
public:
    Game();
    ~Game();

    void HaveFun();

    void InitWindow();
    void InitGrid();
    void InitPlayer();
    void InitEnemies();
    void InitItems();
    void InitBag();
    //void InitLogger();
    void InitStats();

    bool IsWindowOpen();

    void UpdateObjects(double time);
    void RenderObjects();
    void Display();
    void PrintLog();
    bool checkTimeEvents();
    bool checkEKE();

    Player* GetPlayer();

private:
    sf::RenderWindow* window;

    Player* player;
    EntityView* playerView;
    CAFLogger* playerLogger;

    // std::list<Enemy*>& enemies;
    std::vector<pairEnemy> enemies;
    std::vector<CAFLogger*> enemiesLoggers;

    // std::list<Item*>& items;
    // std::list<std::pair<Item*, EntityView*>> items;
    std::vector<pairItem> items;
    std::vector<pairBullet> bullets;

    FieldGrid* grid;
    GridView* gridView;

    Controller* pControl;

    PlayersBagView* bagView;

    GameStats* stats;

    TimeEv* timeEvent;
    EKE* eke;
};

#endif //GAME_HPP

template<class TimeEv, class EKE>
Game<TimeEv, EKE>::Game()
{
    InitGrid();
    InitPlayer();

    srand(time(NULL));

    InitEnemies();
    InitItems();

    InitBag();
    InitStats();

    timeEvent = new TimeEv();
    eke = new EKE();

    InitWindow();
}

template<class TimeEv, class EKE>
Game<TimeEv, EKE>::~Game()
{
    delete window;

    delete player;
    delete playerView;

    for (auto it = enemies.begin(); it != enemies.end(); ++it) {
        delete it->first;
        delete it->second;
    }
    for (auto it = items.begin(); it != items.end(); ++it) {
        delete it->first;
        delete it->second;
    }
    for (auto it = bullets.begin(); it != bullets.end(); ++it) {
        delete it->first;
        delete it->second;
    }

    delete grid;
    delete gridView;

    delete pControl;
    delete bagView;
    delete playerLogger;
    for (auto it = enemiesLoggers.begin(); it != enemiesLoggers.end(); ++it)
        delete* it;
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::HaveFun()
{
    stats->startTime();

    sf::Clock clock;
    while (IsWindowOpen()) {
        /*double time = clock.getElapsedTime().asMicroseconds();*/
        int time = clock.restart().asMilliseconds();
        //clock.restart();
        //time = time / 1200;
        window->setFramerateLimit(60);

        sf::Event event;

        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window->close();
                return;
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "Space pressed" << std::endl;
                    player->SetFireState(true);
                }
            }
        }
        if (checkTimeEvents()) {
            window->close();
            return;
        }
        if (checkEKE()) {
            window->close();
            return;
        }

        //Log
        PrintLog();

        //UpdateStates
        UpdateObjects(time);

        //std::cout << "Player HP = " << player->GetHP() << std::endl;

        //Render
        RenderObjects();

        //Display
        Display();
    }
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(grid->getWidth() * (int)TileSize::Size,
        grid->getHeight() * (int)TileSize::Size), "Game");
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitGrid()
{
    GridCreator creator;
    grid = new FieldGrid(creator);
    gridView = new GridView(*grid);
    gridView->loadPicsFromFile();
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitPlayer()
{
    Point tmp = grid->GetStartPosition();
    //std::cout << tmp.GetX() << " " << tmp.GetY() << std::endl;
    //tmp.SetPosition(tmp.GetX() + int(TileSize::Size)/2, tmp.GetY() + int(TileSize::Size) / 2);
    //std::cout << tmp.GetX() << " " << tmp.GetY() << std::endl;
    player = new Player(600, 30, tmp, 0.2);
    playerView = new EntityView(*player, "P.png");
    pControl = new Controller(*player);
    playerLogger = new CAFLogger(player);
    player->AttachObserver(playerLogger);
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitEnemies()
{
    Enemy1Fact enemy1F;
    Enemy2Fact enemy2F;
    Enemy3Fact enemy3F;

    Enemy* en1 = enemy1F.CreateEnemy(*grid);
    Enemy* en2 = enemy2F.CreateEnemy(*grid);
    Enemy* en3 = enemy3F.CreateEnemy(*grid);

    enemies.push_back(std::make_pair(en1, new EntityView(*en1, "E1.png")));
    enemiesLoggers.push_back(new CAFLogger(enemies[0].first));
    enemies[0].first->AttachObserver(enemiesLoggers[0]);

    enemies.push_back(std::make_pair(en2, new EntityView(*en2, "E2.png")));
    enemiesLoggers.push_back(new CAFLogger(enemies[1].first));
    enemies[1].first->AttachObserver(enemiesLoggers[1]);

    enemies.push_back(std::make_pair(en3, new EntityView(*en3, "E3.png")));
    enemiesLoggers.push_back(new CAFLogger(enemies[2].first));
    enemies[2].first->AttachObserver(enemiesLoggers[2]);
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitItems()
{
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

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitBag()
{
    bagView = new PlayersBagView(player->GetBag(), *grid);
}

//template<class TimeEv, class EKE>
//void Game<TimeEv, EKE>::InitLogger()
//{
//    logger = new Logger<LogType::BOTH>();
//}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitStats()
{
    stats = new GameStats(GetPlayer());
}

template<class TimeEv, class EKE>
bool Game<TimeEv, EKE>::IsWindowOpen()
{
    return window->isOpen();
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::UpdateObjects(double time)
{
    std::vector<pairEnemy>::iterator EnemyIter;
    std::vector<pairBullet>::iterator BulletIter;
    std::vector<pairItem>::iterator ItemIter;

    pControl->Control();
    if (player->GetFireState()) {
        Bullet* tmp = player->Fire();
        int dir = static_cast<int>(player->GetPlayerCheckingDirection());
        std::string path = "bullet" + std::to_string(dir) + ".png";
        bullets.push_back(std::make_pair(tmp, new EntityView(*tmp, path)));
        bullets.back().first->SetLifeBulletState(true);
        player->SetFireState(false);
    }
    player->Update(time, *grid, playerView->getSizeX(), playerView->getSizeY());
    if (player->GetHP() <= 0) {
        window->close();
        return;
    }
    if (grid->GetTile(player->GetY() / int(TileSize::Size),
        player->GetX() / int(TileSize::Size)).GetType() == Type::Exit) {

        std::cout << "Finish was reached!!" << std::endl << "Congratulation!" << std::endl;
        window->close();
        return;
    }
    //std::cout << "Player current tile " << player->GetY() / int(TileSize::Size) <<
    //    " " << player->GetX() / int(TileSize::Size) << std::endl;
    //int i = 0;
    for (EnemyIter = enemies.begin(); EnemyIter != enemies.end(); /*++EnemyIter*/) {
        EnemyIter->first->Update(time, *grid, EnemyIter->second->getSizeX(), EnemyIter->second->getSizeY());
        if (EnemyIter->first->GetHP() <= 0) {
            EnemyIter = enemies.erase(EnemyIter);
            stats->kill();
            continue;
        }
        ++EnemyIter;
        //std::cout << "Enemy" << i++ << " " << EnemyIter->first << " current tile " <<
        //    EnemyIter->first->GetY() / int(TileSize::Size) << " " << EnemyIter->first->GetX() / int(TileSize::Size)
        //    << " Current health " << EnemyIter->first->GetHP() << std::endl;
    }
    for (BulletIter = bullets.begin(); BulletIter != bullets.end(); /*++BulletIter*/) {
        BulletIter->first->Update(time, *grid, BulletIter->second->getSizeX(), BulletIter->second->getSizeY());
        if (!BulletIter->first->GetLifeBulletState()) {
            BulletIter = bullets.erase(BulletIter);
            continue;
        }
        ++BulletIter;
    }
    for (ItemIter = items.begin(); ItemIter != items.end(); ) {
        if (!ItemIter->first->GetStateItem()) {
            ItemIter = items.erase(ItemIter);
            continue;
        }
        ++ItemIter;
    }
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::RenderObjects()
{
    std::vector<pairEnemy>::iterator EnemyIter;
    std::vector<pairItem>::iterator ItemIter;
    std::vector<pairBullet>::iterator BulletIter;

    window->clear();

    gridView->draw(*window);
    for (ItemIter = items.begin(); ItemIter != items.end(); ++ItemIter) {
        ItemIter->second->updateView(*window, *grid);
    }
    for (EnemyIter = enemies.begin(); EnemyIter != enemies.end(); ++EnemyIter) {
        EnemyIter->second->updateView(*window, *grid);
    }
    for (BulletIter = bullets.begin(); BulletIter != bullets.end(); ++BulletIter) {
        BulletIter->second->updateView(*window, *grid);
    }
    playerView->updateView(*window, *grid);

    bagView->UpdateView(*window);
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::Display()
{
    window->display();
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::PrintLog()
{
    player->Notify();

    for (auto& enemy : enemies)
        enemy.first->Notify();
}

template<class TimeEv, class EKE>
bool Game<TimeEv, EKE>::checkTimeEvents()
{
    auto tmpEnd = std::chrono::steady_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::seconds>(tmpEnd - stats->GetStartTime());
    if ((*timeEvent)(dur)) {
        std::cout << "You Lose!" << std::endl;
        return true;
    }
    return false;
}

template<class TimeEv, class EKE>
bool Game<TimeEv, EKE>::checkEKE()
{
    if ((*eke)(stats->getHowMuchKills())) {
        std::cout << "Its enough! Congrats! You win!" << std::endl;
        return true;
    }
    return false;
}

template<class TimeEv, class EKE>
Player* Game<TimeEv, EKE>::GetPlayer()
{
    return player;
}
