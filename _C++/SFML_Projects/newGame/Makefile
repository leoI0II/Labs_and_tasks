all: PROJECT

PROJECT: Point.o Exceptions.o Entity.o Enemy.o Character.o FieldGrid.o Bullet.o Weapon.o Player.o Item.o Tile.o BuildDirector.o Controller.o EnemyFactory.o EntityView.o GridCreator.o GridView.o ItemFactory.o TileBuilder.o Game.o Source.o
	g++ Point.o Exceptions.o FieldGrid.o Player.o Item.o Tile.o Character.o Enemy.o Bullet.o Weapon.o BuildDirector.o Controller.o EnemyFactory.o EntityView.o GridCreator.o GridView.o ItemFactory.o TileBuilder.o Game.o Source.o -o newGame -lsfml-graphics -lsfml-window -lsfml-system
Source.o:
	g++ -c Source.cpp
Game.o:
	g++ -c Game.cpp
Entity.o:
	g++ -c Entity.hpp
Controller.o:
	g++ -c Controller.cpp
EntityView.o:
	g++ -c EntityView.cpp
GridView.o:
	g++ -c GridView.cpp
EnemyFactory.o:
	g++ -c EnemyFactory.cpp
ItemFactory.o:
	g++ -c ItemFactory.cpp
FieldGrid.o:
	g++ -c FieldGrid.cpp
GridCreator.o:
	g++ -c GridCreator.cpp
BuildDirector.o:
	g++ -c BuildDirector.cpp
TileBuilder.o:
	g++ -c TileBuilder.cpp
Tile.o:
	g++ -c Tile.cpp
Enemy.o:
	g++ -c Enemy.cpp
Item.o:
	g++ -c Item.cpp
Player.o:
	g++ -c Player.cpp
Character.o:
	g++ -c Character.cpp
Bullet.o:
	g++ -c Bullet.cpp
Weapon.o:
	g++ -c Weapon.cpp
Exceptions.o:
	g++ -c Exceptions.cpp
Point.o:
	g++ -c Point.cpp
clean:
	rm -rf *.o
