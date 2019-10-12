/**
#include <iostream>
#include "MapLoader.h"

int main()
{
	// errors
	MapLoader* ml1 = new MapLoader("game_map_err0.txt");
	MapLoader* ml2 = new MapLoader("game_map_err1.txt");
	MapLoader* ml3 = new MapLoader("game_map_err2.txt");
	MapLoader* ml4 = new MapLoader("game_map_err3.txt");

	// success
	MapLoader* ml = new MapLoader("game_map.txt");

	ml->GetMap()->PrintMap();
	return 0;
}
/**/
