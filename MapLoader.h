#include <iostream>
#include "Map.h"

class MapLoader
{
private:
	Map* map;
	
public:
	MapLoader();
	MapLoader(std::string file_path);
	~MapLoader();
	void LoadMap(Map* map, std::string file_path);
	Map* GetMap();
};

inline Map* MapLoader::GetMap() { return map; }