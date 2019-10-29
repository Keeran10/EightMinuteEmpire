#include "Map.h"
#include "MapLoader.h"
#include <iostream>

City::City()
{
}

City::City(string color, string owner)
{
}

City::~City()
{
}

Army::Army()
{
}

Army::Army(string color, string owner)
{
}

Army::~Army()
{
}

// Region member functions 
Region::Region(){}

Region::Region(int region_id, int continent_id) 
{	
	id = new int(region_id);
	this->continent_id = new int(continent_id);
	adjacents = new std::vector<std::pair<Region, int>>();
}

Region::~Region() 
{ 
}

void Region::setOwner(std::string* owner) { this->owner = owner; }

// Adds the adjacent region to both concerned regions 
void Region::AddAdjacent(Region region, int cost)
{
	std::pair<Region, int> adjacent;

	if (this->GetId() == region.GetId())
	{
		std::cout << "Invalid -- Region " << region.GetId() << " can't be adjacent to itself." << std::endl;
		return;
	}

	// from calling region to adjacent
	adjacent.first = region;
	adjacent.second = cost;
	adjacents->push_back(adjacent);

	// from adjacent to calling region for bi-directionality
	adjacent.first = *this;
	region.adjacents->push_back(adjacent);
}

// Checks if two regions are adjacent and returns the cost of travel between them
int Region::IsAdjacent(Region region)
{
	for (auto const& adjacent : *region.adjacents)
	{
		if (adjacent.first.GetId() == this->GetId())
		{
			return adjacent.second;
		}
	}
	return 0;
}

// Checks how many armies a specific user has on this region
int Region::CountArmies(string name)
{
	int ctr = 0;

	for (Army* army : *armies)
	{
		if (army->GetOwner() == name) ctr++;
	}

	return ctr;
}


// Continent member functions
Continent::Continent(){}

Continent::Continent(int id) 
{ 
	this->id = new int(id);
	regions = new std::map<int, Region>();
}

Continent::~Continent()
{
}


void Continent::AddRegion(Region* region)
{
	if (region->GetContinentId() != this->GetId())
	{
		std::cout << "Invalid -- Region " << region->GetId() << " does not belong to continent " << this->GetId() << "." << std::endl;
	}

	std::map<int, Region>::iterator itr = regions->find(region->GetId());

	if (itr == regions->end())
	{
		regions->operator[]((*region).GetId()) = *region;
		return;
	}
	std::cout << "Invalid -- Region " << region->GetId() << " already exists in continent " << region->GetContinentId() << "." << std::endl;
}


// Map
Map::Map() 
{
	continents = new std::map<int, Continent>();
}

Map::~Map()
{
	/**/
	delete continents;
	continents = NULL;
	std::cout << "Deleted continents from map." << std::endl;
	/**/
}

void Map::AddContinent(Continent* continent)
{
	if (!continent) 
	{
		std::cout << "Invalid -- Continent can't be null." << std::endl;
		delete continent;
		continent = NULL;
		return;
	}
	if (!continent->GetId())
	{
		std::cout << "Invalid -- Continent's id can't be null." << std::endl;
		delete continent;
		continent = NULL;
		return;
	}
	continents->operator[](continent->GetId()) = *continent;
}

void Map::AddRegion(Region* region)
{
	if (!region)
	{
		std::cout << "Invalid -- Region can't be null." << std::endl;
		delete region;
		region = NULL;
		return;
	}
	if (!region->GetContinentId())
	{
		std::cout << "Invalid -- Region's continent can't be null." << std::endl;
		delete region;
		region = NULL;
		return;
	}

	std::map<int, Continent>::iterator itr = continents->find(region->GetContinentId());

	if (itr == continents->end())
	{
		continents->operator[](region->GetContinentId()) = *new Continent(region->GetContinentId());
		continents->at(region->GetContinentId()).AddRegion(region);
		return;
	}
	continents->at(region->GetContinentId()).AddRegion(region);
}

Region* Map::GetRegion(int region_id)
{
	for (auto cit = continents->begin(); cit != continents->end(); cit++)
	{
		Continent continent = cit->second;

		for (std::pair<int, Region> region_pair : continent.GetRegions())
		{
			if (region_pair.second.GetId() == region_id) 
			{
				return &region_pair.second;
			}
		}
	}
	return NULL;
}

void Map::GetPlayerRegions(string name)
{
	cout << name << "'s regions: ";

	for (auto cit = continents->begin(); cit != continents->end(); cit++)
	{
		Continent continent = cit->second;

		for (std::pair<int, Region> region_pair : continent.GetRegions())
		{
			int count = region_pair.second.CountArmies(name);
			if (count > 0)
			{
				cout << region_pair.second.GetId() << " (armies = " << count << "), ";
			}
		}
	}

	cout << endl;
}

void Map::PrintMap() {
	
	if (!this) 
	{
		std::cout << "No Map detected." << std::endl;
		return;
	}

	std::cout << std::endl;

	for (auto cit = continents->begin(); cit != continents->end(); cit++)
	{
		Continent continent = cit->second;
		int key = cit->first;

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "continent " << cit->second.GetId() << std::endl;
		std::cout << "-----------------------------------------" << std::endl;

		std::map<int, Region> regions = continent.GetRegions();

		for (auto rit = regions.begin(); rit != regions.end(); ++rit)
		{
			Region region = rit->second;

			std::cout << "region " << region.GetId() << " -> c" << region.GetContinentId() << std::endl;
			std::cout << "adjacents: ";

			std::vector<std::pair<Region, int>> adjacents = region.GetAdjacents();

			for (auto const& adjacent : adjacents)
			{
				std::cout << "(" << adjacent.first.GetId() << ", " << adjacent.second << "), ";
			}

			std::cout << std::endl;
		}
	}
}

void MapDriver() 
{
	int a(1), b(1), c(2), d(3), e(4), f(5), g(2), h(6);

	Map* game_map = new Map();
	Continent* continent1 = new Continent(a);
	Continent* continent2 = new Continent(g);

	Region* region1 = new Region(b, continent1->GetId());
	Region* region2 = new Region(c, continent1->GetId());
	Region* region3 = new Region(d, continent1->GetId());
	Region* region4 = new Region(e, continent1->GetId());
	Region* region5 = new Region(f, continent1->GetId());
	Region* region6 = new Region(h, continent2->GetId());

	game_map->AddRegion(region1);
	game_map->AddRegion(region2);
	game_map->AddRegion(region3);
	game_map->AddRegion(region4);
	game_map->AddRegion(region5);
	game_map->AddRegion(region6);

	region1->AddAdjacent(*region2, 1);
	region1->AddAdjacent(*region3, 1);
	region1->AddAdjacent(*region4, 1);
	region1->AddAdjacent(*region5, 3);
	region2->AddAdjacent(*region3, 1);
	region2->AddAdjacent(*region4, 1);
	region3->AddAdjacent(*region5, 1);
	region4->AddAdjacent(*region5, 1);

	// Invalid inputs; should expect errors
	game_map->AddRegion(region5); // duplicate value
	game_map->AddRegion(region6); // region in more than 1 continent exception
	region5->AddAdjacent(*region5, 1); // adding edge to self not allowed
	continent1 = NULL;
	game_map->AddRegion(region1); // null exception 

	game_map->PrintMap();
}

void MapLoaderDriver()
{
	// errors
	MapLoader* ml1 = new MapLoader("game_map_err0.txt");
	MapLoader* ml2 = new MapLoader("game_map_err1.txt");
	MapLoader* ml3 = new MapLoader("game_map_err2.txt");
	MapLoader* ml4 = new MapLoader("game_map_err3.txt");

	// success
	MapLoader* ml = new MapLoader("game_map.txt");

	ml->GetMap()->PrintMap();
}