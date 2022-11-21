#include"CreateGrid.hpp"

GridCreator::GridCreator(){
    std::string fileName = TakeFile();

    std::ifstream file;

    try{
        file.open(fileName);
        if (file.fail())
            throw FileOpenExcept();
        FindParams(file);
    }
    catch (FileOpenExcept& ex){
        std::cout << ex.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    catch (TileCountError& ex){
        std::cout << ex.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ifstream _file(fileName);

    int type;

    // tiles = std::shared_ptr<tileArr_t[]>(new tileArr_t[gridHeight]);
    // for (int i = 0; i < gridHeight; i++){
    //     tiles[i] = std::shared_ptr<Tile[]>(new Tile[gridWidth]);
    //     for (int j = 0; j < gridWidth; j++){
    //         _file >> type;
    //         tiles[i][j] = Tile(Point(j * int(TileSize::Size), i * int(TileSize::Size)),
    //             static_cast<Type>(type), (type != 3 ? Status::Available : Status::NotAvailable));
    //     }
    // }

    // _file.close();

    BuildDirector director;
    std::shared_ptr<ITileBuilder> exit(new ExitTileBuilder());
    std::shared_ptr<ITileBuilder> common(new CommonTileBuilder());
    std::shared_ptr<ITileBuilder> entry(new EntryTileBuilder());
    std::shared_ptr<ITileBuilder> wall(new WallTileBuilder());
    // ITileBuilder* exit = new ExitTileBuilder();
    // ITileBuilder* common = new CommonTileBuilder();
    // ITileBuilder* entry = new EntryTileBuilder();
    // ITileBuilder* wall = new WallTileBuilder();


    tiles = std::shared_ptr<tileArr_t[]>(new tileArr_t[gridHeight]);
    for (int i = 0; i < gridHeight; i++){
        tiles[i] = std::shared_ptr<Tile[]>(new Tile[gridWidth]);
        for (int j = 0; j < gridWidth; j++){
            _file >> type;
            if (static_cast<Type>(type) == Type::Exit){
                endPosition = Point(j * int(TileSize::Size), i * int(TileSize::Size));
                director.SetBuilder(exit);
                director.BuildTile(endPosition);
                // tiles[i][j] = *(director.GetTile());
                tiles[i][j] = exit->GetTile();
            }
            else if (static_cast<Type>(type) == Type::Common){
                director.SetBuilder(common);
                director.BuildTile(Point(j * int(TileSize::Size), i * int(TileSize::Size)));
                // tiles[i][j] = *(director.GetTile());
                tiles[i][j] = common->GetTile();
            }
            else if (static_cast<Type>(type) == Type::Entry){
                startPosition = Point(j * int(TileSize::Size), i * int(TileSize::Size));
                director.SetBuilder(entry);
                director.BuildTile(startPosition);
                // tiles[i][j] = *(director.GetTile());
                tiles[i][j] = entry->GetTile();
            }
            else {
                director.SetBuilder(wall);
                director.BuildTile(Point(j * int(TileSize::Size), i * int(TileSize::Size)));
                // tiles[i][j] = *(director.GetTile());
                tiles[i][j] = wall->GetTile();
                
            }
        }
    }
    // delete exit;
    // delete common;
    // delete entry;
    // delete wall;
    
    _file.close();

    // player = randomPosPlayer();
    
    // enemies.push_back(randomPosEnemy(EnemyType::enemy1));
    // enemies.push_back(randomPosEnemy(EnemyType::enemy2));
    // enemies.push_back(randomPosEnemy(EnemyType::enemy3));

    // items.push_back(randomPosItem(ItemType::Ammo));
    // items.push_back(randomPosItem(ItemType::BigHealthBottle));
    // items.push_back(randomPosItem(ItemType::LittleHealthBottle));
    
}

grid_t& GridCreator::GetGrid(){
    return tiles;
}
int GridCreator::GetHeight(){
    return gridHeight;
}
int GridCreator::GetWidth(){
    return gridWidth;
}
Point& GridCreator::GetStartPos(){
    return startPosition;
}
Point& GridCreator::GetEndPos(){
    return endPosition;
}


const std::string GridCreator::TakeFile(){
    std::ifstream conf("GridConf.txt");
    std::string fileName;
    std::getline(conf, fileName);
    return fileName;
}

void GridCreator::FindParams(std::ifstream& file){

    gridWidth = gridHeight = 0;

    int tmpW = 0, data;
    std::string sstr;
    std::getline(file, sstr);
    gridHeight++;
    std::istringstream ss(sstr);
    while(ss >> data)
        gridWidth++;
    
    while(std::getline(file, sstr)){
        gridHeight++;
        std::istringstream ss(sstr);
        while(ss >> data)
            tmpW++;
        if (gridWidth != tmpW)
            throw TileCountError();
        tmpW = 0;
    }
    // file.seekg(std::ios_base::beg);
    file.close();
}