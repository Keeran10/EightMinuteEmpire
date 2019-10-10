/**/
#include <iostream>
#include "MapLoader.h"

int main()
{
	MapLoader* ml = new MapLoader("game_map.txt");
	ml->GetMap()->PrintMap();
	return 0;
}
/**/