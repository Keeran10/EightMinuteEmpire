#include <iostream>
#include "Map.h"

class MapLoader
{
private:
	Map* map;
	bool isValid;
	
public:
	MapLoader();
	MapLoader(string file_path);
	~MapLoader();
	void LoadMap(Map* map, string file_path);
	inline bool getIsValid() { return isValid; }
	Map* GetMap();
};

inline Map* MapLoader::GetMap() { return map; }