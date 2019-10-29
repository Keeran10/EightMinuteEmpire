#include <iostream>
#include <string>
#include <fstream>
#include "MapLoader.h"

MapLoader::MapLoader() : map(nullptr)
{
}

MapLoader::MapLoader(string file_path)
{
	map = new Map();
	isValid = LoadMap(map, file_path);
}

MapLoader::~MapLoader()
{
	delete map;
	map = NULL;
	cout << "Deleted map from error file." << endl;
}

void CleanUp(int ERROR_CODE, string file_path, string line, MapLoader* ml)
{
	if (ERROR_CODE == 0)
		cout << "Invalid map: " <<  file_path  << " -- File does not exist." << endl;
	if (ERROR_CODE == 1)
		cout << "Invalid map: " << file_path << " -- Continent id expected, but received " << line << " instead." << endl;
	if (ERROR_CODE == 2)
		cout << "Invalid map: " << file_path << " -- Continent id can't be negative or zero: " << line << endl;
	if (ERROR_CODE == 3)
		cout << "Invalid map: " << file_path << " -- Region id expected, but received " << line << " instead." << endl;
	if (ERROR_CODE == 4)
		cout << "Invalid map: " << file_path << " -- Region id can't be negative or zero: " << line << endl;
	if (ERROR_CODE == 5)
		cout << "Invalid map: " << file_path << " -- Continent " << line << " was not initialized at the top." << endl;
	if (ERROR_CODE == 6)
		cout << "Invalid map: " << file_path << " -- adjacent id expected, but received " << line << " instead." << endl;
	if (ERROR_CODE == 7)
		cout << "Invalid map: " << file_path << " -- cost expected, but received " << line << " instead." << endl;
	if (ERROR_CODE == 8)
		cout << "Invalid map: " << file_path << " -- region " << line << " already exists." << endl;
	if (ERROR_CODE == 9)
		cout << "Invalid map: " << file_path << " -- Unrecognized input: " << line << endl;

	delete ml;
}

bool MapLoader::LoadMap(Map* map, string file_path)
{
	ifstream file(file_path);
	string line;
	int continent_id = 0;
	int region_id = 0;
	int adj_id(0), cost(0);
	bool success = true;
	bool parsingRegions = false;
	bool parsingContinents = false;
	bool parsingAdjacents = false;
	bool continentLock = false;
	bool regionLock = false;
	bool adjacentNext = false;
	bool costNext = false;

	if (!file.is_open())
	{
		CleanUp(0, file_path, "", this);
		return false;
	}

	while (file >> line)
	{

		if (line == "continent")
		{
			parsingContinents = true;
			continue;
		}
		else if (line == "region")
		{
			parsingRegions = true;
			continue;
		}
		else if (line == "done")
		{
			parsingRegions = false;
			continue;
		}
		else if (line == "adjacent")
		{
			parsingAdjacents = true;
			continue;
		}
		else if (line == "c")
		{
			continentLock = false;
			continue;
		}
		else if (line == "r")
		{
			regionLock = false;
			continue;
		}
		else if (line == "end")
		{
			cout << "Valid map: " << file_path << " -- SUCCESS." << endl;
			return true;
		}

		else if (parsingContinents)
		{
			try
			{
				continent_id = stoi(line);
			}
			catch (...)
			{
				CleanUp(1, file_path, line, this);
				return false;
			}
			if (continent_id > 0)
			{
				map->AddContinent(new Continent(continent_id));
				parsingContinents = false;
				continue;
			}
			else
			{
				CleanUp(2, file_path, line, this);
				return false;
			}
		}
		else if (parsingRegions)
		{
			try
			{
				region_id = stoi(line);
			}
			catch (...)
			{
				CleanUp(3, file_path, line, this);
				return false;
			}
			if (region_id > 0)
			{
				if (map->GetRegion(region_id))
				{
					CleanUp(8, file_path, line, this);
					return false;
				}
				map->GetContinents().at(continent_id).AddRegion(new Region(region_id, continent_id));
			}
			else
			{

				CleanUp(4, file_path, line, this);
				return false;
			}
		}
		else if (parsingAdjacents)
		{
			if (!continentLock)
			{
				try
				{
					continent_id = stoi(line);

					// Must check for non-existent continents
					for (auto& continent_pair : map->GetContinents()) 
					{
						if(continent_id == continent_pair.second.GetId()) continentLock = true;
					}
					if(!continentLock)
					{
						CleanUp(5, file_path, line, this);
						return false;
					}
				}
				catch (...)
				{
					CleanUp(1, file_path, line, this);
					return false;
				}

			}
			if (!regionLock)
			{
				try
				{
					region_id = stoi(line);
					regionLock = true;
					continue;
				}
				catch (...)
				{
					CleanUp(3, file_path, line, this);
					return false;
				}
			}
			else
			{
				if (adj_id > 0 && cost > 0)
				{
					// must check that bi-directionality is enforced.
					map->GetContinents().at(continent_id).GetRegions().at(region_id).AddAdjacent(*map->GetRegion(adj_id), cost);
					adj_id = 0;
					cost = 0;
					continue;
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
						adj_id = stoi(line);
						continue;
					}
					catch (...)
					{
						CleanUp(6, file_path, line, this);
						return false;
					}	
				}
				if (costNext)
				{
					try
					{
						cost = stoi(line);
						continue;
					}
					catch (...)
					{
						CleanUp(7, file_path, line, this);
						return false;
					}
				}
			}
		}
		else 
		{
			CleanUp(9, file_path, line, this);
			return false;
		}
	}
}