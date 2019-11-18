#include <iostream>
#include "Map.h"

class MapLoader
{
private:
	static Map* map;
	bool isValid;
	
public:
	MapLoader();
	MapLoader(string file_path);
	~MapLoader();
	bool LoadMap(Map* map, string file_path);
	inline bool getIsValid() { return isValid; }
	static Map* GetMap(); //changed this to static to get map in SingletonDriver.cpp 
};

inline Map* MapLoader::GetMap() { return map; }