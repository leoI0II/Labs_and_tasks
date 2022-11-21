all: game

game: Point.o Tile.o ITileBuilder.o TileBuilder.o BuildDirector.o
	g++ Point.o Tile.o ITileBuilder.o TileBuilder.o BuildDirector.o -o game

BuildDirector.o:
	g++ -c BuildDirector.hpp

TileBuilder.o:
	g++ -c TileBuilder.hpp

ITileBuilder.o:
	g++ -c ITileBuilder.hpp

Tile.o:
	g++ -c Tile.hpp

Point.o:
	g++ -c Point.hpp

clean:
	rm -rf *.o game
