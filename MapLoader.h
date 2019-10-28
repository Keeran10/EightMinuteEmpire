#include <iostream>
#include "Map.h"

class MapLoader
{
private:
	Map* map;
	bool isValid;
	
public:
	MapLoader();
	MapLoader(std::string file_path);
	~MapLoader();
	bool LoadMap(Map* map, std::string file_path);
	inline bool getIsValid() { return isValid; }
	Map* GetMap();
};

inline Map* MapLoader::GetMap() { return map; }