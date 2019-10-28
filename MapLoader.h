#include <iostream>
#include "Map.h"

class MapLoader
{
private:
	Map* map;
	
public:
	MapLoader();
	MapLoader(string file_path);
	~MapLoader();
	void LoadMap(Map* map, string file_path);
	Map* GetMap();
};

inline Map* MapLoader::GetMap() { return map; }