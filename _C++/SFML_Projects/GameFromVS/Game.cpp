#include "Game.hpp"

Game::Game()
{
    InitGrid();
    InitPlayer();

    srand(time(NULL));

    InitEnemies();
    InitItems();

    InitBag();
    InitLogger();
    
    InitWindow();
}

Game::~Game()
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
}

void Game::HaveFun()
{
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
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "Space pressed" << std::endl;
                    player->SetFireState(true);
                }
            }
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

void Game::InitWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(grid->getWidth() * (int)TileSize::Size,
        grid->getHeight() * (int)TileSize::Size), "Game");
}

void Game::InitGrid()
{
    GridCreator creator;
    grid = new FieldGrid(creator);
    gridView = new GridView(*grid);
    gridView->loadPicsFromFile();
}

void Game::InitPlayer()
{
    Point tmp = grid->GetStartPosition();
    //std::cout << tmp.GetX() << " " << tmp.GetY() << std::endl;
    //tmp.SetPosition(tmp.GetX() + int(TileSize::Size)/2, tmp.GetY() + int(TileSize::Size) / 2);
    //std::cout << tmp.GetX() << " " << tmp.GetY() << std::endl;
    player = new Player(600, 30, tmp, 0.2);
    playerView = new EntityView(*player, "P.png");
    pControl = new Controller(*player);
}

void Game::InitEnemies()
{
    Enemy1Fact enemy1F;
    Enemy2Fact enemy2F;
    Enemy3Fact enemy3F;

    Enemy* en1 = enemy1F.CreateEnemy(*grid);
    Enemy* en2 = enemy2F.CreateEnemy(*grid);
    Enemy* en3 = enemy3F.CreateEnemy(*grid);

    enemies.push_back(std::make_pair(en1, new EntityView(*en1, "E1.png")));
    enemies.push_back(std::make_pair(en2, new EntityView(*en2, "E2.png")));
    enemies.push_back(std::make_pair(en3, new EntityView(*en3, "E3.png")));
}

void Game::InitItems()
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

void Game::InitBag()
{
    bagView = new PlayersBagView(player->GetBag(), *grid);
}

void Game::InitLogger()
{
    logger = new Logger<LogType::BOTH>();
}

bool Game::IsWindowOpen()
{
    return window->isOpen();
}

void Game::UpdateObjects(double time)
{
    std::list<pairEnemy>::iterator EnemyIter;
    std::list<pairBullet>::iterator BulletIter;
    std::list<pairItem>::iterator ItemIter;

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
    if (grid->GetTile(player->GetY()/int(TileSize::Size),
        player->GetX()/int(TileSize::Size)).GetType() == Type::Exit) {

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

void Game::RenderObjects()
{
    std::list<pairEnemy>::iterator EnemyIter;
    std::list<pairItem>::iterator ItemIter;
    std::list<pairBullet>::iterator BulletIter;

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

void Game::Display()
{
    window->display();
}

void Game::PrintLog()
{
    logger->logTime();
    logger->log(*player);
    for (auto it = enemies.begin(); it != enemies.end(); ++it) {
        logger->log(*(it->first));
    }
}