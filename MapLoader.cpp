#include <iostream>
#include <string>
#include <fstream>
#include "MapLoader.h"

MapLoader::MapLoader() : map(nullptr)
{
}

MapLoader::MapLoader(std::string file_path)
{
	map = new Map();
	LoadMap(map, file_path);
}

MapLoader::~MapLoader()
{
}

void MapLoader::LoadMap(Map* map, std::string file_path)
{
	std::ifstream file(file_path);
	std::string line;
	int continent_id = 0;
	int region_id = 0;
	int adj_id(0), cost(0);
	bool parsingRegions = false;
	bool parsingContinents = false;
	bool parsingAdjacents = false;
	bool continentLock = false;
	bool regionLock = false;
	bool adjacentNext = false;
	bool costNext = false;

	if (!file.is_open())
	{
		std::cout << "Invalid map file format -- File " << file_path << " does not exist." << std::endl;
		return;
	}

	while (file >> line)
	{

		if (line == "continent")
		{
			parsingContinents = true;
			continue;
		}
		if (line == "region")
		{
			parsingRegions = true;
			continue;
		}
		if (line == "done")
		{
			parsingRegions = false;
			continue;
		}
		if (line == "adjacent")
		{
			parsingAdjacents = true;
			continue;
		}
		if (line == "c")
		{
			continentLock = false;
			continue;
		}
		if (line == "r")
		{
			regionLock = false;
			continue;
		}
		if (line == "end")
		{
			return;
		}

		if (parsingContinents)
		{
			try
			{
				continent_id = std::stoi(line);
			}
			catch (...)
			{
				std::cout << "Invalid map file format -- Continent id expected, but received " << line << " instead." << std::endl;
				return;
			}
			if (continent_id > 0)
			{
				map->AddContinent(new Continent(continent_id));
				parsingContinents = false;
				continue;
			}
			else
			{
				std::cout << "Invalid map file format -- Continent id can't be negative or zero: " << continent_id << std::endl;
				return;
			}
		}
		if (parsingRegions)
		{
			try
			{
				region_id = std::stoi(line);
			}
			catch (...)
			{
				std::cout << "Invalid map file format -- Region id expected, but received " << line << " instead." << std::endl;
				return;
			}
			if (region_id > 0)
			{
				map->GetContinents().at(continent_id).AddRegion(new Region(region_id, continent_id));
				continue;
			}
			else
			{

				std::cout << "Invalid map file format -- Region id can't be negative or zero: " << region_id << std::endl;
				return;
			}
		}
		if (parsingAdjacents)
		{
			if (!continentLock)
			{
				try
				{
					continent_id = std::stoi(line);
					continentLock = true;
					continue;
					// Must check for non-existent continents
					/** 
					std::map<int, Continent>::iterator itr = map->GetContinents().find(continent_id);
				
					if (itr != map->GetContinents().end())
					{
						continentLock = true;
						continue;
					}
					else
					{
						std::cout << "Invalid map file format -- Continent " << continent_id << " was not initialized at the top." << std::endl;
						return;
					}
					/**/
				}
				catch (...)
				{
					std::cout << "Invalid map file format -- Continent id expected, but received " << line << " instead." << std::endl;
					return;
				}

			}
			if (!regionLock)
			{
				try
				{
					region_id = std::stoi(line);
					regionLock = true;
					continue;
				}
				catch (...)
				{
					std::cout << "Invalid map file format -- Region id expected, but received " << line << " instead." << std::endl;
					return;
				}
			}
			else
			{
				if (adj_id > 0 && cost > 0)
				{
					// must check that bi-directionality is enforced.
					map->GetContinents().at(continent_id).GetRegions().at(region_id).AddAdjacent(map->GetRegion(adj_id), cost);
					adj_id = 0;
					cost = 0;
				}
				if (line == "(")
				{
					adjacentNext = true;
					continue;
				}
				if (line == ",")
				{
					adjacentNext = false;
					costNext = true;
					continue;
				}
				if (line == ")")
				{
					costNext = false;
					continue;
				}
				if (adjacentNext)
				{
					try
					{
						adj_id = std::stoi(line);
						continue;
					}
					catch (...)
					{
						std::cout << "Invalid map file format -- id or cost expected, but received " << line << " instead." << std::endl;
						return;
					}	
				}
				if (costNext)
				{
					try
					{
						cost = std::stoi(line);
						continue;
					}
					catch (...)
					{
						std::cout << "Invalid map file format -- id or cost expected, but received " << line << " instead." << std::endl;
						return;
					}
				}
			}
		}
	}
}